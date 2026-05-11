#include "td_api.h"

#include "td/utils/common.h"
#include "td/utils/format.h"
#include "td/utils/logging.h"
#include "td/utils/SliceBuilder.h"
#include "td/utils/tl_parsers.h"
#include "td/utils/tl_storers.h"
#include "td/utils/TlStorerToString.h"

namespace td {
namespace td_api {


activeStoryStateLive::activeStoryStateLive()
  : story_id_()
{}

activeStoryStateLive::activeStoryStateLive(int32 story_id_)
  : story_id_(story_id_)
{}

const std::int32_t activeStoryStateLive::ID;

void activeStoryStateLive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "activeStoryStateLive");
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

activeStoryStateUnread::activeStoryStateUnread() {
}

const std::int32_t activeStoryStateUnread::ID;

void activeStoryStateUnread::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "activeStoryStateUnread");
    s.store_class_end();
  }
}

activeStoryStateRead::activeStoryStateRead() {
}

const std::int32_t activeStoryStateRead::ID;

void activeStoryStateRead::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "activeStoryStateRead");
    s.store_class_end();
  }
}

advertisementSponsor::advertisementSponsor()
  : url_()
  , photo_()
  , info_()
{}

advertisementSponsor::advertisementSponsor(string const &url_, object_ptr<photo> &&photo_, string const &info_)
  : url_(url_)
  , photo_(std::move(photo_))
  , info_(info_)
{}

const std::int32_t advertisementSponsor::ID;

void advertisementSponsor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "advertisementSponsor");
    s.store_field("url", url_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("info", info_);
    s.store_class_end();
  }
}

backgroundTypeWallpaper::backgroundTypeWallpaper()
  : is_blurred_()
  , is_moving_()
{}

backgroundTypeWallpaper::backgroundTypeWallpaper(bool is_blurred_, bool is_moving_)
  : is_blurred_(is_blurred_)
  , is_moving_(is_moving_)
{}

const std::int32_t backgroundTypeWallpaper::ID;

void backgroundTypeWallpaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgroundTypeWallpaper");
    s.store_field("is_blurred", is_blurred_);
    s.store_field("is_moving", is_moving_);
    s.store_class_end();
  }
}

backgroundTypePattern::backgroundTypePattern()
  : fill_()
  , intensity_()
  , is_inverted_()
  , is_moving_()
{}

backgroundTypePattern::backgroundTypePattern(object_ptr<BackgroundFill> &&fill_, int32 intensity_, bool is_inverted_, bool is_moving_)
  : fill_(std::move(fill_))
  , intensity_(intensity_)
  , is_inverted_(is_inverted_)
  , is_moving_(is_moving_)
{}

const std::int32_t backgroundTypePattern::ID;

void backgroundTypePattern::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgroundTypePattern");
    s.store_object_field("fill", static_cast<const BaseObject *>(fill_.get()));
    s.store_field("intensity", intensity_);
    s.store_field("is_inverted", is_inverted_);
    s.store_field("is_moving", is_moving_);
    s.store_class_end();
  }
}

backgroundTypeFill::backgroundTypeFill()
  : fill_()
{}

backgroundTypeFill::backgroundTypeFill(object_ptr<BackgroundFill> &&fill_)
  : fill_(std::move(fill_))
{}

const std::int32_t backgroundTypeFill::ID;

void backgroundTypeFill::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgroundTypeFill");
    s.store_object_field("fill", static_cast<const BaseObject *>(fill_.get()));
    s.store_class_end();
  }
}

backgroundTypeChatTheme::backgroundTypeChatTheme()
  : theme_name_()
{}

backgroundTypeChatTheme::backgroundTypeChatTheme(string const &theme_name_)
  : theme_name_(theme_name_)
{}

const std::int32_t backgroundTypeChatTheme::ID;

void backgroundTypeChatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgroundTypeChatTheme");
    s.store_field("theme_name", theme_name_);
    s.store_class_end();
  }
}

backgrounds::backgrounds()
  : backgrounds_()
{}

backgrounds::backgrounds(array<object_ptr<background>> &&backgrounds_)
  : backgrounds_(std::move(backgrounds_))
{}

const std::int32_t backgrounds::ID;

void backgrounds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgrounds");
    { s.store_vector_begin("backgrounds", backgrounds_.size()); for (const auto &_value : backgrounds_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

businessChatLinks::businessChatLinks()
  : links_()
{}

businessChatLinks::businessChatLinks(array<object_ptr<businessChatLink>> &&links_)
  : links_(std::move(links_))
{}

const std::int32_t businessChatLinks::ID;

void businessChatLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessChatLinks");
    { s.store_vector_begin("links", links_.size()); for (const auto &_value : links_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

businessMessages::businessMessages()
  : messages_()
{}

businessMessages::businessMessages(array<object_ptr<businessMessage>> &&messages_)
  : messages_(std::move(messages_))
{}

const std::int32_t businessMessages::ID;

void businessMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessMessages");
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

businessOpeningHours::businessOpeningHours()
  : time_zone_id_()
  , opening_hours_()
{}

businessOpeningHours::businessOpeningHours(string const &time_zone_id_, array<object_ptr<businessOpeningHoursInterval>> &&opening_hours_)
  : time_zone_id_(time_zone_id_)
  , opening_hours_(std::move(opening_hours_))
{}

const std::int32_t businessOpeningHours::ID;

void businessOpeningHours::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessOpeningHours");
    s.store_field("time_zone_id", time_zone_id_);
    { s.store_vector_begin("opening_hours", opening_hours_.size()); for (const auto &_value : opening_hours_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

callProblemEcho::callProblemEcho() {
}

const std::int32_t callProblemEcho::ID;

void callProblemEcho::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemEcho");
    s.store_class_end();
  }
}

callProblemNoise::callProblemNoise() {
}

const std::int32_t callProblemNoise::ID;

void callProblemNoise::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemNoise");
    s.store_class_end();
  }
}

callProblemInterruptions::callProblemInterruptions() {
}

const std::int32_t callProblemInterruptions::ID;

void callProblemInterruptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemInterruptions");
    s.store_class_end();
  }
}

callProblemDistortedSpeech::callProblemDistortedSpeech() {
}

const std::int32_t callProblemDistortedSpeech::ID;

void callProblemDistortedSpeech::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemDistortedSpeech");
    s.store_class_end();
  }
}

callProblemSilentLocal::callProblemSilentLocal() {
}

const std::int32_t callProblemSilentLocal::ID;

void callProblemSilentLocal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemSilentLocal");
    s.store_class_end();
  }
}

callProblemSilentRemote::callProblemSilentRemote() {
}

const std::int32_t callProblemSilentRemote::ID;

void callProblemSilentRemote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemSilentRemote");
    s.store_class_end();
  }
}

callProblemDropped::callProblemDropped() {
}

const std::int32_t callProblemDropped::ID;

void callProblemDropped::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemDropped");
    s.store_class_end();
  }
}

callProblemDistortedVideo::callProblemDistortedVideo() {
}

const std::int32_t callProblemDistortedVideo::ID;

void callProblemDistortedVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemDistortedVideo");
    s.store_class_end();
  }
}

callProblemPixelatedVideo::callProblemPixelatedVideo() {
}

const std::int32_t callProblemPixelatedVideo::ID;

void callProblemPixelatedVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemPixelatedVideo");
    s.store_class_end();
  }
}

callStatePending::callStatePending()
  : is_created_()
  , is_received_()
{}

callStatePending::callStatePending(bool is_created_, bool is_received_)
  : is_created_(is_created_)
  , is_received_(is_received_)
{}

const std::int32_t callStatePending::ID;

void callStatePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callStatePending");
    s.store_field("is_created", is_created_);
    s.store_field("is_received", is_received_);
    s.store_class_end();
  }
}

callStateExchangingKeys::callStateExchangingKeys() {
}

const std::int32_t callStateExchangingKeys::ID;

void callStateExchangingKeys::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callStateExchangingKeys");
    s.store_class_end();
  }
}

callStateReady::callStateReady()
  : protocol_()
  , servers_()
  , config_()
  , encryption_key_()
  , emojis_()
  , allow_p2p_()
  , is_group_call_supported_()
  , custom_parameters_()
{}

callStateReady::callStateReady(object_ptr<callProtocol> &&protocol_, array<object_ptr<callServer>> &&servers_, string const &config_, bytes const &encryption_key_, array<string> &&emojis_, bool allow_p2p_, bool is_group_call_supported_, string const &custom_parameters_)
  : protocol_(std::move(protocol_))
  , servers_(std::move(servers_))
  , config_(config_)
  , encryption_key_(std::move(encryption_key_))
  , emojis_(std::move(emojis_))
  , allow_p2p_(allow_p2p_)
  , is_group_call_supported_(is_group_call_supported_)
  , custom_parameters_(custom_parameters_)
{}

const std::int32_t callStateReady::ID;

void callStateReady::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callStateReady");
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    { s.store_vector_begin("servers", servers_.size()); for (const auto &_value : servers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("config", config_);
    s.store_bytes_field("encryption_key", encryption_key_);
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("allow_p2p", allow_p2p_);
    s.store_field("is_group_call_supported", is_group_call_supported_);
    s.store_field("custom_parameters", custom_parameters_);
    s.store_class_end();
  }
}

callStateHangingUp::callStateHangingUp() {
}

const std::int32_t callStateHangingUp::ID;

void callStateHangingUp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callStateHangingUp");
    s.store_class_end();
  }
}

callStateDiscarded::callStateDiscarded()
  : reason_()
  , need_rating_()
  , need_debug_information_()
  , need_log_()
{}

callStateDiscarded::callStateDiscarded(object_ptr<CallDiscardReason> &&reason_, bool need_rating_, bool need_debug_information_, bool need_log_)
  : reason_(std::move(reason_))
  , need_rating_(need_rating_)
  , need_debug_information_(need_debug_information_)
  , need_log_(need_log_)
{}

const std::int32_t callStateDiscarded::ID;

void callStateDiscarded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callStateDiscarded");
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_field("need_rating", need_rating_);
    s.store_field("need_debug_information", need_debug_information_);
    s.store_field("need_log", need_log_);
    s.store_class_end();
  }
}

callStateError::callStateError()
  : error_()
{}

callStateError::callStateError(object_ptr<error> &&error_)
  : error_(std::move(error_))
{}

const std::int32_t callStateError::ID;

void callStateError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callStateError");
    s.store_object_field("error", static_cast<const BaseObject *>(error_.get()));
    s.store_class_end();
  }
}

canTransferOwnershipResultOk::canTransferOwnershipResultOk() {
}

const std::int32_t canTransferOwnershipResultOk::ID;

void canTransferOwnershipResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canTransferOwnershipResultOk");
    s.store_class_end();
  }
}

canTransferOwnershipResultPasswordNeeded::canTransferOwnershipResultPasswordNeeded() {
}

const std::int32_t canTransferOwnershipResultPasswordNeeded::ID;

void canTransferOwnershipResultPasswordNeeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canTransferOwnershipResultPasswordNeeded");
    s.store_class_end();
  }
}

canTransferOwnershipResultPasswordTooFresh::canTransferOwnershipResultPasswordTooFresh()
  : retry_after_()
{}

canTransferOwnershipResultPasswordTooFresh::canTransferOwnershipResultPasswordTooFresh(int32 retry_after_)
  : retry_after_(retry_after_)
{}

const std::int32_t canTransferOwnershipResultPasswordTooFresh::ID;

void canTransferOwnershipResultPasswordTooFresh::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canTransferOwnershipResultPasswordTooFresh");
    s.store_field("retry_after", retry_after_);
    s.store_class_end();
  }
}

canTransferOwnershipResultSessionTooFresh::canTransferOwnershipResultSessionTooFresh()
  : retry_after_()
{}

canTransferOwnershipResultSessionTooFresh::canTransferOwnershipResultSessionTooFresh(int32 retry_after_)
  : retry_after_(retry_after_)
{}

const std::int32_t canTransferOwnershipResultSessionTooFresh::ID;

void canTransferOwnershipResultSessionTooFresh::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canTransferOwnershipResultSessionTooFresh");
    s.store_field("retry_after", retry_after_);
    s.store_class_end();
  }
}

chatActionBarReportSpam::chatActionBarReportSpam()
  : can_unarchive_()
{}

chatActionBarReportSpam::chatActionBarReportSpam(bool can_unarchive_)
  : can_unarchive_(can_unarchive_)
{}

const std::int32_t chatActionBarReportSpam::ID;

void chatActionBarReportSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionBarReportSpam");
    s.store_field("can_unarchive", can_unarchive_);
    s.store_class_end();
  }
}

chatActionBarInviteMembers::chatActionBarInviteMembers() {
}

const std::int32_t chatActionBarInviteMembers::ID;

void chatActionBarInviteMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionBarInviteMembers");
    s.store_class_end();
  }
}

chatActionBarReportAddBlock::chatActionBarReportAddBlock()
  : can_unarchive_()
  , account_info_()
{}

chatActionBarReportAddBlock::chatActionBarReportAddBlock(bool can_unarchive_, object_ptr<accountInfo> &&account_info_)
  : can_unarchive_(can_unarchive_)
  , account_info_(std::move(account_info_))
{}

const std::int32_t chatActionBarReportAddBlock::ID;

void chatActionBarReportAddBlock::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionBarReportAddBlock");
    s.store_field("can_unarchive", can_unarchive_);
    s.store_object_field("account_info", static_cast<const BaseObject *>(account_info_.get()));
    s.store_class_end();
  }
}

chatActionBarAddContact::chatActionBarAddContact() {
}

const std::int32_t chatActionBarAddContact::ID;

void chatActionBarAddContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionBarAddContact");
    s.store_class_end();
  }
}

chatActionBarSharePhoneNumber::chatActionBarSharePhoneNumber() {
}

const std::int32_t chatActionBarSharePhoneNumber::ID;

void chatActionBarSharePhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionBarSharePhoneNumber");
    s.store_class_end();
  }
}

chatActionBarJoinRequest::chatActionBarJoinRequest()
  : title_()
  , is_channel_()
  , request_date_()
{}

chatActionBarJoinRequest::chatActionBarJoinRequest(string const &title_, bool is_channel_, int32 request_date_)
  : title_(title_)
  , is_channel_(is_channel_)
  , request_date_(request_date_)
{}

const std::int32_t chatActionBarJoinRequest::ID;

void chatActionBarJoinRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionBarJoinRequest");
    s.store_field("title", title_);
    s.store_field("is_channel", is_channel_);
    s.store_field("request_date", request_date_);
    s.store_class_end();
  }
}

chatInviteLinkMembers::chatInviteLinkMembers()
  : total_count_()
  , members_()
{}

chatInviteLinkMembers::chatInviteLinkMembers(int32 total_count_, array<object_ptr<chatInviteLinkMember>> &&members_)
  : total_count_(total_count_)
  , members_(std::move(members_))
{}

const std::int32_t chatInviteLinkMembers::ID;

void chatInviteLinkMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLinkMembers");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("members", members_.size()); for (const auto &_value : members_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatRevenueTransactions::chatRevenueTransactions()
  : ton_amount_()
  , transactions_()
  , next_offset_()
{}

chatRevenueTransactions::chatRevenueTransactions(int53 ton_amount_, array<object_ptr<chatRevenueTransaction>> &&transactions_, string const &next_offset_)
  : ton_amount_(ton_amount_)
  , transactions_(std::move(transactions_))
  , next_offset_(next_offset_)
{}

const std::int32_t chatRevenueTransactions::ID;

void chatRevenueTransactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatRevenueTransactions");
    s.store_field("ton_amount", ton_amount_);
    { s.store_vector_begin("transactions", transactions_.size()); for (const auto &_value : transactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

checkStickerSetNameResultOk::checkStickerSetNameResultOk() {
}

const std::int32_t checkStickerSetNameResultOk::ID;

void checkStickerSetNameResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkStickerSetNameResultOk");
    s.store_class_end();
  }
}

checkStickerSetNameResultNameInvalid::checkStickerSetNameResultNameInvalid() {
}

const std::int32_t checkStickerSetNameResultNameInvalid::ID;

void checkStickerSetNameResultNameInvalid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkStickerSetNameResultNameInvalid");
    s.store_class_end();
  }
}

checkStickerSetNameResultNameOccupied::checkStickerSetNameResultNameOccupied() {
}

const std::int32_t checkStickerSetNameResultNameOccupied::ID;

void checkStickerSetNameResultNameOccupied::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkStickerSetNameResultNameOccupied");
    s.store_class_end();
  }
}

closedVectorPath::closedVectorPath()
  : commands_()
{}

closedVectorPath::closedVectorPath(array<object_ptr<VectorPathCommand>> &&commands_)
  : commands_(std::move(commands_))
{}

const std::int32_t closedVectorPath::ID;

void closedVectorPath::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "closedVectorPath");
    { s.store_vector_begin("commands", commands_.size()); for (const auto &_value : commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

connectionStateWaitingForNetwork::connectionStateWaitingForNetwork() {
}

const std::int32_t connectionStateWaitingForNetwork::ID;

void connectionStateWaitingForNetwork::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectionStateWaitingForNetwork");
    s.store_class_end();
  }
}

connectionStateConnectingToProxy::connectionStateConnectingToProxy() {
}

const std::int32_t connectionStateConnectingToProxy::ID;

void connectionStateConnectingToProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectionStateConnectingToProxy");
    s.store_class_end();
  }
}

connectionStateConnecting::connectionStateConnecting() {
}

const std::int32_t connectionStateConnecting::ID;

void connectionStateConnecting::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectionStateConnecting");
    s.store_class_end();
  }
}

connectionStateUpdating::connectionStateUpdating() {
}

const std::int32_t connectionStateUpdating::ID;

void connectionStateUpdating::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectionStateUpdating");
    s.store_class_end();
  }
}

connectionStateReady::connectionStateReady() {
}

const std::int32_t connectionStateReady::ID;

void connectionStateReady::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectionStateReady");
    s.store_class_end();
  }
}

customRequestResult::customRequestResult()
  : result_()
{}

customRequestResult::customRequestResult(string const &result_)
  : result_(result_)
{}

const std::int32_t customRequestResult::ID;

void customRequestResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "customRequestResult");
    s.store_field("result", result_);
    s.store_class_end();
  }
}

emailAddressAuthenticationCode::emailAddressAuthenticationCode()
  : code_()
{}

emailAddressAuthenticationCode::emailAddressAuthenticationCode(string const &code_)
  : code_(code_)
{}

const std::int32_t emailAddressAuthenticationCode::ID;

void emailAddressAuthenticationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailAddressAuthenticationCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

emailAddressAuthenticationAppleId::emailAddressAuthenticationAppleId()
  : token_()
{}

emailAddressAuthenticationAppleId::emailAddressAuthenticationAppleId(string const &token_)
  : token_(token_)
{}

const std::int32_t emailAddressAuthenticationAppleId::ID;

void emailAddressAuthenticationAppleId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailAddressAuthenticationAppleId");
    s.store_field("token", token_);
    s.store_class_end();
  }
}

emailAddressAuthenticationGoogleId::emailAddressAuthenticationGoogleId()
  : token_()
{}

emailAddressAuthenticationGoogleId::emailAddressAuthenticationGoogleId(string const &token_)
  : token_(token_)
{}

const std::int32_t emailAddressAuthenticationGoogleId::ID;

void emailAddressAuthenticationGoogleId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailAddressAuthenticationGoogleId");
    s.store_field("token", token_);
    s.store_class_end();
  }
}

emojiChatTheme::emojiChatTheme()
  : name_()
  , light_settings_()
  , dark_settings_()
{}

emojiChatTheme::emojiChatTheme(string const &name_, object_ptr<themeSettings> &&light_settings_, object_ptr<themeSettings> &&dark_settings_)
  : name_(name_)
  , light_settings_(std::move(light_settings_))
  , dark_settings_(std::move(dark_settings_))
{}

const std::int32_t emojiChatTheme::ID;

void emojiChatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiChatTheme");
    s.store_field("name", name_);
    s.store_object_field("light_settings", static_cast<const BaseObject *>(light_settings_.get()));
    s.store_object_field("dark_settings", static_cast<const BaseObject *>(dark_settings_.get()));
    s.store_class_end();
  }
}

emojiStatusTypeCustomEmoji::emojiStatusTypeCustomEmoji()
  : custom_emoji_id_()
{}

emojiStatusTypeCustomEmoji::emojiStatusTypeCustomEmoji(int64 custom_emoji_id_)
  : custom_emoji_id_(custom_emoji_id_)
{}

const std::int32_t emojiStatusTypeCustomEmoji::ID;

void emojiStatusTypeCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiStatusTypeCustomEmoji");
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_class_end();
  }
}

emojiStatusTypeUpgradedGift::emojiStatusTypeUpgradedGift()
  : upgraded_gift_id_()
  , gift_title_()
  , gift_name_()
  , model_custom_emoji_id_()
  , symbol_custom_emoji_id_()
  , backdrop_colors_()
{}

emojiStatusTypeUpgradedGift::emojiStatusTypeUpgradedGift(int64 upgraded_gift_id_, string const &gift_title_, string const &gift_name_, int64 model_custom_emoji_id_, int64 symbol_custom_emoji_id_, object_ptr<upgradedGiftBackdropColors> &&backdrop_colors_)
  : upgraded_gift_id_(upgraded_gift_id_)
  , gift_title_(gift_title_)
  , gift_name_(gift_name_)
  , model_custom_emoji_id_(model_custom_emoji_id_)
  , symbol_custom_emoji_id_(symbol_custom_emoji_id_)
  , backdrop_colors_(std::move(backdrop_colors_))
{}

const std::int32_t emojiStatusTypeUpgradedGift::ID;

void emojiStatusTypeUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiStatusTypeUpgradedGift");
    s.store_field("upgraded_gift_id", upgraded_gift_id_);
    s.store_field("gift_title", gift_title_);
    s.store_field("gift_name", gift_name_);
    s.store_field("model_custom_emoji_id", model_custom_emoji_id_);
    s.store_field("symbol_custom_emoji_id", symbol_custom_emoji_id_);
    s.store_object_field("backdrop_colors", static_cast<const BaseObject *>(backdrop_colors_.get()));
    s.store_class_end();
  }
}

emojiStatuses::emojiStatuses()
  : emoji_statuses_()
{}

emojiStatuses::emojiStatuses(array<object_ptr<emojiStatus>> &&emoji_statuses_)
  : emoji_statuses_(std::move(emoji_statuses_))
{}

const std::int32_t emojiStatuses::ID;

void emojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiStatuses");
    { s.store_vector_begin("emoji_statuses", emoji_statuses_.size()); for (const auto &_value : emoji_statuses_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

foundAffiliatePrograms::foundAffiliatePrograms()
  : total_count_()
  , programs_()
  , next_offset_()
{}

foundAffiliatePrograms::foundAffiliatePrograms(int32 total_count_, array<object_ptr<foundAffiliateProgram>> &&programs_, string const &next_offset_)
  : total_count_(total_count_)
  , programs_(std::move(programs_))
  , next_offset_(next_offset_)
{}

const std::int32_t foundAffiliatePrograms::ID;

void foundAffiliatePrograms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundAffiliatePrograms");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("programs", programs_.size()); for (const auto &_value : programs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

gift::gift()
  : id_()
  , publisher_chat_id_()
  , sticker_()
  , star_count_()
  , default_sell_star_count_()
  , upgrade_star_count_()
  , upgrade_variant_count_()
  , has_colors_()
  , is_for_birthday_()
  , is_premium_()
  , auction_info_()
  , next_send_date_()
  , user_limits_()
  , overall_limits_()
  , background_()
  , first_send_date_()
  , last_send_date_()
{}

gift::gift(int64 id_, int53 publisher_chat_id_, object_ptr<sticker> &&sticker_, int53 star_count_, int53 default_sell_star_count_, int53 upgrade_star_count_, int32 upgrade_variant_count_, bool has_colors_, bool is_for_birthday_, bool is_premium_, object_ptr<giftAuction> &&auction_info_, int32 next_send_date_, object_ptr<giftPurchaseLimits> &&user_limits_, object_ptr<giftPurchaseLimits> &&overall_limits_, object_ptr<giftBackground> &&background_, int32 first_send_date_, int32 last_send_date_)
  : id_(id_)
  , publisher_chat_id_(publisher_chat_id_)
  , sticker_(std::move(sticker_))
  , star_count_(star_count_)
  , default_sell_star_count_(default_sell_star_count_)
  , upgrade_star_count_(upgrade_star_count_)
  , upgrade_variant_count_(upgrade_variant_count_)
  , has_colors_(has_colors_)
  , is_for_birthday_(is_for_birthday_)
  , is_premium_(is_premium_)
  , auction_info_(std::move(auction_info_))
  , next_send_date_(next_send_date_)
  , user_limits_(std::move(user_limits_))
  , overall_limits_(std::move(overall_limits_))
  , background_(std::move(background_))
  , first_send_date_(first_send_date_)
  , last_send_date_(last_send_date_)
{}

const std::int32_t gift::ID;

void gift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "gift");
    s.store_field("id", id_);
    s.store_field("publisher_chat_id", publisher_chat_id_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("star_count", star_count_);
    s.store_field("default_sell_star_count", default_sell_star_count_);
    s.store_field("upgrade_star_count", upgrade_star_count_);
    s.store_field("upgrade_variant_count", upgrade_variant_count_);
    s.store_field("has_colors", has_colors_);
    s.store_field("is_for_birthday", is_for_birthday_);
    s.store_field("is_premium", is_premium_);
    s.store_object_field("auction_info", static_cast<const BaseObject *>(auction_info_.get()));
    s.store_field("next_send_date", next_send_date_);
    s.store_object_field("user_limits", static_cast<const BaseObject *>(user_limits_.get()));
    s.store_object_field("overall_limits", static_cast<const BaseObject *>(overall_limits_.get()));
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_field("first_send_date", first_send_date_);
    s.store_field("last_send_date", last_send_date_);
    s.store_class_end();
  }
}

giftsForCrafting::giftsForCrafting()
  : total_count_()
  , gifts_()
  , attribute_persistence_probabilities_()
  , next_offset_()
{}

giftsForCrafting::giftsForCrafting(int32 total_count_, array<object_ptr<receivedGift>> &&gifts_, array<object_ptr<attributeCraftPersistenceProbability>> &&attribute_persistence_probabilities_, string const &next_offset_)
  : total_count_(total_count_)
  , gifts_(std::move(gifts_))
  , attribute_persistence_probabilities_(std::move(attribute_persistence_probabilities_))
  , next_offset_(next_offset_)
{}

const std::int32_t giftsForCrafting::ID;

void giftsForCrafting::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftsForCrafting");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("gifts", gifts_.size()); for (const auto &_value : gifts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("attribute_persistence_probabilities", attribute_persistence_probabilities_.size()); for (const auto &_value : attribute_persistence_probabilities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

inputSuggestedPostInfo::inputSuggestedPostInfo()
  : price_()
  , send_date_()
{}

inputSuggestedPostInfo::inputSuggestedPostInfo(object_ptr<SuggestedPostPrice> &&price_, int32 send_date_)
  : price_(std::move(price_))
  , send_date_(send_date_)
{}

const std::int32_t inputSuggestedPostInfo::ID;

void inputSuggestedPostInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSuggestedPostInfo");
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_field("send_date", send_date_);
    s.store_class_end();
  }
}

inputThumbnail::inputThumbnail()
  : thumbnail_()
  , width_()
  , height_()
{}

inputThumbnail::inputThumbnail(object_ptr<InputFile> &&thumbnail_, int32 width_, int32 height_)
  : thumbnail_(std::move(thumbnail_))
  , width_(width_)
  , height_(height_)
{}

const std::int32_t inputThumbnail::ID;

void inputThumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputThumbnail");
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_class_end();
  }
}

keyboardButtonSourceMessage::keyboardButtonSourceMessage()
  : chat_id_()
  , message_id_()
{}

keyboardButtonSourceMessage::keyboardButtonSourceMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t keyboardButtonSourceMessage::ID;

void keyboardButtonSourceMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonSourceMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

keyboardButtonSourceWebApp::keyboardButtonSourceWebApp()
  : bot_user_id_()
  , prepared_button_id_()
{}

keyboardButtonSourceWebApp::keyboardButtonSourceWebApp(int53 bot_user_id_, string const &prepared_button_id_)
  : bot_user_id_(bot_user_id_)
  , prepared_button_id_(prepared_button_id_)
{}

const std::int32_t keyboardButtonSourceWebApp::ID;

void keyboardButtonSourceWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonSourceWebApp");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("prepared_button_id", prepared_button_id_);
    s.store_class_end();
  }
}

labeledPricePart::labeledPricePart()
  : label_()
  , amount_()
{}

labeledPricePart::labeledPricePart(string const &label_, int53 amount_)
  : label_(label_)
  , amount_(amount_)
{}

const std::int32_t labeledPricePart::ID;

void labeledPricePart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "labeledPricePart");
    s.store_field("label", label_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

maskPointForehead::maskPointForehead() {
}

const std::int32_t maskPointForehead::ID;

void maskPointForehead::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "maskPointForehead");
    s.store_class_end();
  }
}

maskPointEyes::maskPointEyes() {
}

const std::int32_t maskPointEyes::ID;

void maskPointEyes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "maskPointEyes");
    s.store_class_end();
  }
}

maskPointMouth::maskPointMouth() {
}

const std::int32_t maskPointMouth::ID;

void maskPointMouth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "maskPointMouth");
    s.store_class_end();
  }
}

maskPointChin::maskPointChin() {
}

const std::int32_t maskPointChin::ID;

void maskPointChin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "maskPointChin");
    s.store_class_end();
  }
}

message::message()
  : id_()
  , sender_id_()
  , chat_id_()
  , sending_state_()
  , scheduling_state_()
  , is_outgoing_()
  , is_pinned_()
  , is_from_offline_()
  , can_be_saved_()
  , has_timestamped_media_()
  , is_channel_post_()
  , is_paid_star_suggested_post_()
  , is_paid_ton_suggested_post_()
  , contains_unread_mention_()
  , date_()
  , edit_date_()
  , forward_info_()
  , import_info_()
  , interaction_info_()
  , unread_reactions_()
  , fact_check_()
  , suggested_post_info_()
  , reply_to_()
  , topic_id_()
  , self_destruct_type_()
  , self_destruct_in_()
  , auto_delete_in_()
  , via_bot_user_id_()
  , sender_business_bot_user_id_()
  , sender_boost_count_()
  , sender_tag_()
  , paid_message_star_count_()
  , author_signature_()
  , media_album_id_()
  , effect_id_()
  , restriction_info_()
  , summary_language_code_()
  , content_()
  , reply_markup_()
{}

message::message(int53 id_, object_ptr<MessageSender> &&sender_id_, int53 chat_id_, object_ptr<MessageSendingState> &&sending_state_, object_ptr<MessageSchedulingState> &&scheduling_state_, bool is_outgoing_, bool is_pinned_, bool is_from_offline_, bool can_be_saved_, bool has_timestamped_media_, bool is_channel_post_, bool is_paid_star_suggested_post_, bool is_paid_ton_suggested_post_, bool contains_unread_mention_, int32 date_, int32 edit_date_, object_ptr<messageForwardInfo> &&forward_info_, object_ptr<messageImportInfo> &&import_info_, object_ptr<messageInteractionInfo> &&interaction_info_, array<object_ptr<unreadReaction>> &&unread_reactions_, object_ptr<factCheck> &&fact_check_, object_ptr<suggestedPostInfo> &&suggested_post_info_, object_ptr<MessageReplyTo> &&reply_to_, object_ptr<MessageTopic> &&topic_id_, object_ptr<MessageSelfDestructType> &&self_destruct_type_, double self_destruct_in_, double auto_delete_in_, int53 via_bot_user_id_, int53 sender_business_bot_user_id_, int32 sender_boost_count_, string const &sender_tag_, int53 paid_message_star_count_, string const &author_signature_, int64 media_album_id_, int64 effect_id_, object_ptr<restrictionInfo> &&restriction_info_, string const &summary_language_code_, object_ptr<MessageContent> &&content_, object_ptr<ReplyMarkup> &&reply_markup_)
  : id_(id_)
  , sender_id_(std::move(sender_id_))
  , chat_id_(chat_id_)
  , sending_state_(std::move(sending_state_))
  , scheduling_state_(std::move(scheduling_state_))
  , is_outgoing_(is_outgoing_)
  , is_pinned_(is_pinned_)
  , is_from_offline_(is_from_offline_)
  , can_be_saved_(can_be_saved_)
  , has_timestamped_media_(has_timestamped_media_)
  , is_channel_post_(is_channel_post_)
  , is_paid_star_suggested_post_(is_paid_star_suggested_post_)
  , is_paid_ton_suggested_post_(is_paid_ton_suggested_post_)
  , contains_unread_mention_(contains_unread_mention_)
  , date_(date_)
  , edit_date_(edit_date_)
  , forward_info_(std::move(forward_info_))
  , import_info_(std::move(import_info_))
  , interaction_info_(std::move(interaction_info_))
  , unread_reactions_(std::move(unread_reactions_))
  , fact_check_(std::move(fact_check_))
  , suggested_post_info_(std::move(suggested_post_info_))
  , reply_to_(std::move(reply_to_))
  , topic_id_(std::move(topic_id_))
  , self_destruct_type_(std::move(self_destruct_type_))
  , self_destruct_in_(self_destruct_in_)
  , auto_delete_in_(auto_delete_in_)
  , via_bot_user_id_(via_bot_user_id_)
  , sender_business_bot_user_id_(sender_business_bot_user_id_)
  , sender_boost_count_(sender_boost_count_)
  , sender_tag_(sender_tag_)
  , paid_message_star_count_(paid_message_star_count_)
  , author_signature_(author_signature_)
  , media_album_id_(media_album_id_)
  , effect_id_(effect_id_)
  , restriction_info_(std::move(restriction_info_))
  , summary_language_code_(summary_language_code_)
  , content_(std::move(content_))
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t message::ID;

void message::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "message");
    s.store_field("id", id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("chat_id", chat_id_);
    s.store_object_field("sending_state", static_cast<const BaseObject *>(sending_state_.get()));
    s.store_object_field("scheduling_state", static_cast<const BaseObject *>(scheduling_state_.get()));
    s.store_field("is_outgoing", is_outgoing_);
    s.store_field("is_pinned", is_pinned_);
    s.store_field("is_from_offline", is_from_offline_);
    s.store_field("can_be_saved", can_be_saved_);
    s.store_field("has_timestamped_media", has_timestamped_media_);
    s.store_field("is_channel_post", is_channel_post_);
    s.store_field("is_paid_star_suggested_post", is_paid_star_suggested_post_);
    s.store_field("is_paid_ton_suggested_post", is_paid_ton_suggested_post_);
    s.store_field("contains_unread_mention", contains_unread_mention_);
    s.store_field("date", date_);
    s.store_field("edit_date", edit_date_);
    s.store_object_field("forward_info", static_cast<const BaseObject *>(forward_info_.get()));
    s.store_object_field("import_info", static_cast<const BaseObject *>(import_info_.get()));
    s.store_object_field("interaction_info", static_cast<const BaseObject *>(interaction_info_.get()));
    { s.store_vector_begin("unread_reactions", unread_reactions_.size()); for (const auto &_value : unread_reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("fact_check", static_cast<const BaseObject *>(fact_check_.get()));
    s.store_object_field("suggested_post_info", static_cast<const BaseObject *>(suggested_post_info_.get()));
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("self_destruct_type", static_cast<const BaseObject *>(self_destruct_type_.get()));
    s.store_field("self_destruct_in", self_destruct_in_);
    s.store_field("auto_delete_in", auto_delete_in_);
    s.store_field("via_bot_user_id", via_bot_user_id_);
    s.store_field("sender_business_bot_user_id", sender_business_bot_user_id_);
    s.store_field("sender_boost_count", sender_boost_count_);
    s.store_field("sender_tag", sender_tag_);
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_field("author_signature", author_signature_);
    s.store_field("media_album_id", media_album_id_);
    s.store_field("effect_id", effect_id_);
    s.store_object_field("restriction_info", static_cast<const BaseObject *>(restriction_info_.get()));
    s.store_field("summary_language_code", summary_language_code_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

messageText::messageText()
  : text_()
  , link_preview_()
  , link_preview_options_()
{}

messageText::messageText(object_ptr<formattedText> &&text_, object_ptr<linkPreview> &&link_preview_, object_ptr<linkPreviewOptions> &&link_preview_options_)
  : text_(std::move(text_))
  , link_preview_(std::move(link_preview_))
  , link_preview_options_(std::move(link_preview_options_))
{}

const std::int32_t messageText::ID;

void messageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageText");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("link_preview", static_cast<const BaseObject *>(link_preview_.get()));
    s.store_object_field("link_preview_options", static_cast<const BaseObject *>(link_preview_options_.get()));
    s.store_class_end();
  }
}

messageAnimation::messageAnimation()
  : animation_()
  , caption_()
  , show_caption_above_media_()
  , has_spoiler_()
  , is_secret_()
{}

messageAnimation::messageAnimation(object_ptr<animation> &&animation_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_, bool has_spoiler_, bool is_secret_)
  : animation_(std::move(animation_))
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
  , has_spoiler_(has_spoiler_)
  , is_secret_(is_secret_)
{}

const std::int32_t messageAnimation::ID;

void messageAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_field("has_spoiler", has_spoiler_);
    s.store_field("is_secret", is_secret_);
    s.store_class_end();
  }
}

messageAudio::messageAudio()
  : audio_()
  , caption_()
{}

messageAudio::messageAudio(object_ptr<audio> &&audio_, object_ptr<formattedText> &&caption_)
  : audio_(std::move(audio_))
  , caption_(std::move(caption_))
{}

const std::int32_t messageAudio::ID;

void messageAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageAudio");
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

messageDocument::messageDocument()
  : document_()
  , caption_()
{}

messageDocument::messageDocument(object_ptr<document> &&document_, object_ptr<formattedText> &&caption_)
  : document_(std::move(document_))
  , caption_(std::move(caption_))
{}

const std::int32_t messageDocument::ID;

void messageDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageDocument");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

messagePaidMedia::messagePaidMedia()
  : star_count_()
  , media_()
  , caption_()
  , show_caption_above_media_()
{}

messagePaidMedia::messagePaidMedia(int53 star_count_, array<object_ptr<PaidMedia>> &&media_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_)
  : star_count_(star_count_)
  , media_(std::move(media_))
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
{}

const std::int32_t messagePaidMedia::ID;

void messagePaidMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePaidMedia");
    s.store_field("star_count", star_count_);
    { s.store_vector_begin("media", media_.size()); for (const auto &_value : media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_class_end();
  }
}

messagePhoto::messagePhoto()
  : photo_()
  , video_()
  , caption_()
  , show_caption_above_media_()
  , has_spoiler_()
  , is_secret_()
{}

messagePhoto::messagePhoto(object_ptr<photo> &&photo_, object_ptr<video> &&video_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_, bool has_spoiler_, bool is_secret_)
  : photo_(std::move(photo_))
  , video_(std::move(video_))
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
  , has_spoiler_(has_spoiler_)
  , is_secret_(is_secret_)
{}

const std::int32_t messagePhoto::ID;

void messagePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_field("has_spoiler", has_spoiler_);
    s.store_field("is_secret", is_secret_);
    s.store_class_end();
  }
}

messageSticker::messageSticker()
  : sticker_()
  , is_premium_()
{}

messageSticker::messageSticker(object_ptr<sticker> &&sticker_, bool is_premium_)
  : sticker_(std::move(sticker_))
  , is_premium_(is_premium_)
{}

const std::int32_t messageSticker::ID;

void messageSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("is_premium", is_premium_);
    s.store_class_end();
  }
}

messageVideo::messageVideo()
  : video_()
  , alternative_videos_()
  , storyboards_()
  , cover_()
  , start_timestamp_()
  , caption_()
  , show_caption_above_media_()
  , has_spoiler_()
  , is_secret_()
{}

messageVideo::messageVideo(object_ptr<video> &&video_, array<object_ptr<alternativeVideo>> &&alternative_videos_, array<object_ptr<videoStoryboard>> &&storyboards_, object_ptr<photo> &&cover_, int32 start_timestamp_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_, bool has_spoiler_, bool is_secret_)
  : video_(std::move(video_))
  , alternative_videos_(std::move(alternative_videos_))
  , storyboards_(std::move(storyboards_))
  , cover_(std::move(cover_))
  , start_timestamp_(start_timestamp_)
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
  , has_spoiler_(has_spoiler_)
  , is_secret_(is_secret_)
{}

const std::int32_t messageVideo::ID;

void messageVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    { s.store_vector_begin("alternative_videos", alternative_videos_.size()); for (const auto &_value : alternative_videos_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("storyboards", storyboards_.size()); for (const auto &_value : storyboards_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("cover", static_cast<const BaseObject *>(cover_.get()));
    s.store_field("start_timestamp", start_timestamp_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_field("has_spoiler", has_spoiler_);
    s.store_field("is_secret", is_secret_);
    s.store_class_end();
  }
}

messageVideoNote::messageVideoNote()
  : video_note_()
  , is_viewed_()
  , is_secret_()
{}

messageVideoNote::messageVideoNote(object_ptr<videoNote> &&video_note_, bool is_viewed_, bool is_secret_)
  : video_note_(std::move(video_note_))
  , is_viewed_(is_viewed_)
  , is_secret_(is_secret_)
{}

const std::int32_t messageVideoNote::ID;

void messageVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVideoNote");
    s.store_object_field("video_note", static_cast<const BaseObject *>(video_note_.get()));
    s.store_field("is_viewed", is_viewed_);
    s.store_field("is_secret", is_secret_);
    s.store_class_end();
  }
}

messageVoiceNote::messageVoiceNote()
  : voice_note_()
  , caption_()
  , is_listened_()
{}

messageVoiceNote::messageVoiceNote(object_ptr<voiceNote> &&voice_note_, object_ptr<formattedText> &&caption_, bool is_listened_)
  : voice_note_(std::move(voice_note_))
  , caption_(std::move(caption_))
  , is_listened_(is_listened_)
{}

const std::int32_t messageVoiceNote::ID;

void messageVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVoiceNote");
    s.store_object_field("voice_note", static_cast<const BaseObject *>(voice_note_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("is_listened", is_listened_);
    s.store_class_end();
  }
}

messageExpiredPhoto::messageExpiredPhoto() {
}

const std::int32_t messageExpiredPhoto::ID;

void messageExpiredPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageExpiredPhoto");
    s.store_class_end();
  }
}

messageExpiredVideo::messageExpiredVideo() {
}

const std::int32_t messageExpiredVideo::ID;

void messageExpiredVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageExpiredVideo");
    s.store_class_end();
  }
}

messageExpiredVideoNote::messageExpiredVideoNote() {
}

const std::int32_t messageExpiredVideoNote::ID;

void messageExpiredVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageExpiredVideoNote");
    s.store_class_end();
  }
}

messageExpiredVoiceNote::messageExpiredVoiceNote() {
}

const std::int32_t messageExpiredVoiceNote::ID;

void messageExpiredVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageExpiredVoiceNote");
    s.store_class_end();
  }
}

messageLocation::messageLocation()
  : location_()
  , live_period_()
  , expires_in_()
  , heading_()
  , proximity_alert_radius_()
{}

messageLocation::messageLocation(object_ptr<location> &&location_, int32 live_period_, int32 expires_in_, int32 heading_, int32 proximity_alert_radius_)
  : location_(std::move(location_))
  , live_period_(live_period_)
  , expires_in_(expires_in_)
  , heading_(heading_)
  , proximity_alert_radius_(proximity_alert_radius_)
{}

const std::int32_t messageLocation::ID;

void messageLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("live_period", live_period_);
    s.store_field("expires_in", expires_in_);
    s.store_field("heading", heading_);
    s.store_field("proximity_alert_radius", proximity_alert_radius_);
    s.store_class_end();
  }
}

messageVenue::messageVenue()
  : venue_()
{}

messageVenue::messageVenue(object_ptr<venue> &&venue_)
  : venue_(std::move(venue_))
{}

const std::int32_t messageVenue::ID;

void messageVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVenue");
    s.store_object_field("venue", static_cast<const BaseObject *>(venue_.get()));
    s.store_class_end();
  }
}

messageContact::messageContact()
  : contact_()
{}

messageContact::messageContact(object_ptr<contact> &&contact_)
  : contact_(std::move(contact_))
{}

const std::int32_t messageContact::ID;

void messageContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageContact");
    s.store_object_field("contact", static_cast<const BaseObject *>(contact_.get()));
    s.store_class_end();
  }
}

messageAnimatedEmoji::messageAnimatedEmoji()
  : animated_emoji_()
  , emoji_()
{}

messageAnimatedEmoji::messageAnimatedEmoji(object_ptr<animatedEmoji> &&animated_emoji_, string const &emoji_)
  : animated_emoji_(std::move(animated_emoji_))
  , emoji_(emoji_)
{}

const std::int32_t messageAnimatedEmoji::ID;

void messageAnimatedEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageAnimatedEmoji");
    s.store_object_field("animated_emoji", static_cast<const BaseObject *>(animated_emoji_.get()));
    s.store_field("emoji", emoji_);
    s.store_class_end();
  }
}

messageDice::messageDice()
  : initial_state_()
  , final_state_()
  , emoji_()
  , value_()
  , success_animation_frame_number_()
{}

messageDice::messageDice(object_ptr<DiceStickers> &&initial_state_, object_ptr<DiceStickers> &&final_state_, string const &emoji_, int32 value_, int32 success_animation_frame_number_)
  : initial_state_(std::move(initial_state_))
  , final_state_(std::move(final_state_))
  , emoji_(emoji_)
  , value_(value_)
  , success_animation_frame_number_(success_animation_frame_number_)
{}

const std::int32_t messageDice::ID;

void messageDice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageDice");
    s.store_object_field("initial_state", static_cast<const BaseObject *>(initial_state_.get()));
    s.store_object_field("final_state", static_cast<const BaseObject *>(final_state_.get()));
    s.store_field("emoji", emoji_);
    s.store_field("value", value_);
    s.store_field("success_animation_frame_number", success_animation_frame_number_);
    s.store_class_end();
  }
}

messageGame::messageGame()
  : game_()
{}

messageGame::messageGame(object_ptr<game> &&game_)
  : game_(std::move(game_))
{}

const std::int32_t messageGame::ID;

void messageGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGame");
    s.store_object_field("game", static_cast<const BaseObject *>(game_.get()));
    s.store_class_end();
  }
}

messagePoll::messagePoll()
  : poll_()
  , description_()
  , media_()
  , can_add_option_()
{}

messagePoll::messagePoll(object_ptr<poll> &&poll_, object_ptr<formattedText> &&description_, object_ptr<MessageContent> &&media_, bool can_add_option_)
  : poll_(std::move(poll_))
  , description_(std::move(description_))
  , media_(std::move(media_))
  , can_add_option_(can_add_option_)
{}

const std::int32_t messagePoll::ID;

void messagePoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePoll");
    s.store_object_field("poll", static_cast<const BaseObject *>(poll_.get()));
    s.store_object_field("description", static_cast<const BaseObject *>(description_.get()));
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_field("can_add_option", can_add_option_);
    s.store_class_end();
  }
}

messageStakeDice::messageStakeDice()
  : initial_state_()
  , final_state_()
  , value_()
  , stake_toncoin_amount_()
  , prize_toncoin_amount_()
{}

messageStakeDice::messageStakeDice(object_ptr<DiceStickers> &&initial_state_, object_ptr<DiceStickers> &&final_state_, int32 value_, int53 stake_toncoin_amount_, int53 prize_toncoin_amount_)
  : initial_state_(std::move(initial_state_))
  , final_state_(std::move(final_state_))
  , value_(value_)
  , stake_toncoin_amount_(stake_toncoin_amount_)
  , prize_toncoin_amount_(prize_toncoin_amount_)
{}

const std::int32_t messageStakeDice::ID;

void messageStakeDice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageStakeDice");
    s.store_object_field("initial_state", static_cast<const BaseObject *>(initial_state_.get()));
    s.store_object_field("final_state", static_cast<const BaseObject *>(final_state_.get()));
    s.store_field("value", value_);
    s.store_field("stake_toncoin_amount", stake_toncoin_amount_);
    s.store_field("prize_toncoin_amount", prize_toncoin_amount_);
    s.store_class_end();
  }
}

messageStory::messageStory()
  : story_poster_chat_id_()
  , story_id_()
  , via_mention_()
{}

messageStory::messageStory(int53 story_poster_chat_id_, int32 story_id_, bool via_mention_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , via_mention_(via_mention_)
{}

const std::int32_t messageStory::ID;

void messageStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_field("via_mention", via_mention_);
    s.store_class_end();
  }
}

messageChecklist::messageChecklist()
  : list_()
{}

messageChecklist::messageChecklist(object_ptr<checklist> &&list_)
  : list_(std::move(list_))
{}

const std::int32_t messageChecklist::ID;

void messageChecklist::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChecklist");
    s.store_object_field("list", static_cast<const BaseObject *>(list_.get()));
    s.store_class_end();
  }
}

messageInvoice::messageInvoice()
  : product_info_()
  , currency_()
  , total_amount_()
  , start_parameter_()
  , is_test_()
  , need_shipping_address_()
  , receipt_message_id_()
  , paid_media_()
  , paid_media_caption_()
{}

messageInvoice::messageInvoice(object_ptr<productInfo> &&product_info_, string const &currency_, int53 total_amount_, string const &start_parameter_, bool is_test_, bool need_shipping_address_, int53 receipt_message_id_, object_ptr<PaidMedia> &&paid_media_, object_ptr<formattedText> &&paid_media_caption_)
  : product_info_(std::move(product_info_))
  , currency_(currency_)
  , total_amount_(total_amount_)
  , start_parameter_(start_parameter_)
  , is_test_(is_test_)
  , need_shipping_address_(need_shipping_address_)
  , receipt_message_id_(receipt_message_id_)
  , paid_media_(std::move(paid_media_))
  , paid_media_caption_(std::move(paid_media_caption_))
{}

const std::int32_t messageInvoice::ID;

void messageInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageInvoice");
    s.store_object_field("product_info", static_cast<const BaseObject *>(product_info_.get()));
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_field("start_parameter", start_parameter_);
    s.store_field("is_test", is_test_);
    s.store_field("need_shipping_address", need_shipping_address_);
    s.store_field("receipt_message_id", receipt_message_id_);
    s.store_object_field("paid_media", static_cast<const BaseObject *>(paid_media_.get()));
    s.store_object_field("paid_media_caption", static_cast<const BaseObject *>(paid_media_caption_.get()));
    s.store_class_end();
  }
}

messageCall::messageCall()
  : unique_id_()
  , is_video_()
  , discard_reason_()
  , duration_()
{}

messageCall::messageCall(int64 unique_id_, bool is_video_, object_ptr<CallDiscardReason> &&discard_reason_, int32 duration_)
  : unique_id_(unique_id_)
  , is_video_(is_video_)
  , discard_reason_(std::move(discard_reason_))
  , duration_(duration_)
{}

const std::int32_t messageCall::ID;

void messageCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageCall");
    s.store_field("unique_id", unique_id_);
    s.store_field("is_video", is_video_);
    s.store_object_field("discard_reason", static_cast<const BaseObject *>(discard_reason_.get()));
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

messageGroupCall::messageGroupCall()
  : unique_id_()
  , is_active_()
  , was_missed_()
  , is_video_()
  , duration_()
  , other_participant_ids_()
{}

messageGroupCall::messageGroupCall(int64 unique_id_, bool is_active_, bool was_missed_, bool is_video_, int32 duration_, array<object_ptr<MessageSender>> &&other_participant_ids_)
  : unique_id_(unique_id_)
  , is_active_(is_active_)
  , was_missed_(was_missed_)
  , is_video_(is_video_)
  , duration_(duration_)
  , other_participant_ids_(std::move(other_participant_ids_))
{}

const std::int32_t messageGroupCall::ID;

void messageGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGroupCall");
    s.store_field("unique_id", unique_id_);
    s.store_field("is_active", is_active_);
    s.store_field("was_missed", was_missed_);
    s.store_field("is_video", is_video_);
    s.store_field("duration", duration_);
    { s.store_vector_begin("other_participant_ids", other_participant_ids_.size()); for (const auto &_value : other_participant_ids_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageVideoChatScheduled::messageVideoChatScheduled()
  : group_call_id_()
  , start_date_()
{}

messageVideoChatScheduled::messageVideoChatScheduled(int32 group_call_id_, int32 start_date_)
  : group_call_id_(group_call_id_)
  , start_date_(start_date_)
{}

const std::int32_t messageVideoChatScheduled::ID;

void messageVideoChatScheduled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVideoChatScheduled");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("start_date", start_date_);
    s.store_class_end();
  }
}

messageVideoChatStarted::messageVideoChatStarted()
  : group_call_id_()
{}

messageVideoChatStarted::messageVideoChatStarted(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t messageVideoChatStarted::ID;

void messageVideoChatStarted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVideoChatStarted");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

messageVideoChatEnded::messageVideoChatEnded()
  : duration_()
{}

messageVideoChatEnded::messageVideoChatEnded(int32 duration_)
  : duration_(duration_)
{}

const std::int32_t messageVideoChatEnded::ID;

void messageVideoChatEnded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVideoChatEnded");
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

messageInviteVideoChatParticipants::messageInviteVideoChatParticipants()
  : group_call_id_()
  , user_ids_()
{}

messageInviteVideoChatParticipants::messageInviteVideoChatParticipants(int32 group_call_id_, array<int53> &&user_ids_)
  : group_call_id_(group_call_id_)
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t messageInviteVideoChatParticipants::ID;

void messageInviteVideoChatParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageInviteVideoChatParticipants");
    s.store_field("group_call_id", group_call_id_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messagePollOptionAdded::messagePollOptionAdded()
  : poll_message_id_()
  , option_id_()
  , text_()
{}

messagePollOptionAdded::messagePollOptionAdded(int53 poll_message_id_, string const &option_id_, object_ptr<formattedText> &&text_)
  : poll_message_id_(poll_message_id_)
  , option_id_(option_id_)
  , text_(std::move(text_))
{}

const std::int32_t messagePollOptionAdded::ID;

void messagePollOptionAdded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePollOptionAdded");
    s.store_field("poll_message_id", poll_message_id_);
    s.store_field("option_id", option_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

messagePollOptionDeleted::messagePollOptionDeleted()
  : poll_message_id_()
  , option_id_()
  , text_()
{}

messagePollOptionDeleted::messagePollOptionDeleted(int53 poll_message_id_, string const &option_id_, object_ptr<formattedText> &&text_)
  : poll_message_id_(poll_message_id_)
  , option_id_(option_id_)
  , text_(std::move(text_))
{}

const std::int32_t messagePollOptionDeleted::ID;

void messagePollOptionDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePollOptionDeleted");
    s.store_field("poll_message_id", poll_message_id_);
    s.store_field("option_id", option_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

messageBasicGroupChatCreate::messageBasicGroupChatCreate()
  : title_()
  , member_user_ids_()
{}

messageBasicGroupChatCreate::messageBasicGroupChatCreate(string const &title_, array<int53> &&member_user_ids_)
  : title_(title_)
  , member_user_ids_(std::move(member_user_ids_))
{}

const std::int32_t messageBasicGroupChatCreate::ID;

void messageBasicGroupChatCreate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageBasicGroupChatCreate");
    s.store_field("title", title_);
    { s.store_vector_begin("member_user_ids", member_user_ids_.size()); for (const auto &_value : member_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageSupergroupChatCreate::messageSupergroupChatCreate()
  : title_()
{}

messageSupergroupChatCreate::messageSupergroupChatCreate(string const &title_)
  : title_(title_)
{}

const std::int32_t messageSupergroupChatCreate::ID;

void messageSupergroupChatCreate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSupergroupChatCreate");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

messageChatChangeTitle::messageChatChangeTitle()
  : title_()
{}

messageChatChangeTitle::messageChatChangeTitle(string const &title_)
  : title_(title_)
{}

const std::int32_t messageChatChangeTitle::ID;

void messageChatChangeTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatChangeTitle");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

messageChatChangePhoto::messageChatChangePhoto()
  : photo_()
{}

messageChatChangePhoto::messageChatChangePhoto(object_ptr<chatPhoto> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t messageChatChangePhoto::ID;

void messageChatChangePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatChangePhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

messageChatDeletePhoto::messageChatDeletePhoto() {
}

const std::int32_t messageChatDeletePhoto::ID;

void messageChatDeletePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatDeletePhoto");
    s.store_class_end();
  }
}

messageChatOwnerLeft::messageChatOwnerLeft()
  : new_owner_user_id_()
{}

messageChatOwnerLeft::messageChatOwnerLeft(int53 new_owner_user_id_)
  : new_owner_user_id_(new_owner_user_id_)
{}

const std::int32_t messageChatOwnerLeft::ID;

void messageChatOwnerLeft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatOwnerLeft");
    s.store_field("new_owner_user_id", new_owner_user_id_);
    s.store_class_end();
  }
}

messageChatOwnerChanged::messageChatOwnerChanged()
  : new_owner_user_id_()
{}

messageChatOwnerChanged::messageChatOwnerChanged(int53 new_owner_user_id_)
  : new_owner_user_id_(new_owner_user_id_)
{}

const std::int32_t messageChatOwnerChanged::ID;

void messageChatOwnerChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatOwnerChanged");
    s.store_field("new_owner_user_id", new_owner_user_id_);
    s.store_class_end();
  }
}

messageChatHasProtectedContentToggled::messageChatHasProtectedContentToggled()
  : request_message_id_()
  , old_has_protected_content_()
  , new_has_protected_content_()
{}

messageChatHasProtectedContentToggled::messageChatHasProtectedContentToggled(int53 request_message_id_, bool old_has_protected_content_, bool new_has_protected_content_)
  : request_message_id_(request_message_id_)
  , old_has_protected_content_(old_has_protected_content_)
  , new_has_protected_content_(new_has_protected_content_)
{}

const std::int32_t messageChatHasProtectedContentToggled::ID;

void messageChatHasProtectedContentToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatHasProtectedContentToggled");
    s.store_field("request_message_id", request_message_id_);
    s.store_field("old_has_protected_content", old_has_protected_content_);
    s.store_field("new_has_protected_content", new_has_protected_content_);
    s.store_class_end();
  }
}

messageChatHasProtectedContentDisableRequested::messageChatHasProtectedContentDisableRequested()
  : is_expired_()
{}

messageChatHasProtectedContentDisableRequested::messageChatHasProtectedContentDisableRequested(bool is_expired_)
  : is_expired_(is_expired_)
{}

const std::int32_t messageChatHasProtectedContentDisableRequested::ID;

void messageChatHasProtectedContentDisableRequested::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatHasProtectedContentDisableRequested");
    s.store_field("is_expired", is_expired_);
    s.store_class_end();
  }
}

messageChatAddMembers::messageChatAddMembers()
  : member_user_ids_()
{}

messageChatAddMembers::messageChatAddMembers(array<int53> &&member_user_ids_)
  : member_user_ids_(std::move(member_user_ids_))
{}

const std::int32_t messageChatAddMembers::ID;

void messageChatAddMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatAddMembers");
    { s.store_vector_begin("member_user_ids", member_user_ids_.size()); for (const auto &_value : member_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageChatJoinByLink::messageChatJoinByLink() {
}

const std::int32_t messageChatJoinByLink::ID;

void messageChatJoinByLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatJoinByLink");
    s.store_class_end();
  }
}

messageChatJoinByRequest::messageChatJoinByRequest() {
}

const std::int32_t messageChatJoinByRequest::ID;

void messageChatJoinByRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatJoinByRequest");
    s.store_class_end();
  }
}

messageChatDeleteMember::messageChatDeleteMember()
  : user_id_()
{}

messageChatDeleteMember::messageChatDeleteMember(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t messageChatDeleteMember::ID;

void messageChatDeleteMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatDeleteMember");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

messageChatUpgradeTo::messageChatUpgradeTo()
  : supergroup_id_()
{}

messageChatUpgradeTo::messageChatUpgradeTo(int53 supergroup_id_)
  : supergroup_id_(supergroup_id_)
{}

const std::int32_t messageChatUpgradeTo::ID;

void messageChatUpgradeTo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatUpgradeTo");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_class_end();
  }
}

messageChatUpgradeFrom::messageChatUpgradeFrom()
  : title_()
  , basic_group_id_()
{}

messageChatUpgradeFrom::messageChatUpgradeFrom(string const &title_, int53 basic_group_id_)
  : title_(title_)
  , basic_group_id_(basic_group_id_)
{}

const std::int32_t messageChatUpgradeFrom::ID;

void messageChatUpgradeFrom::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatUpgradeFrom");
    s.store_field("title", title_);
    s.store_field("basic_group_id", basic_group_id_);
    s.store_class_end();
  }
}

messagePinMessage::messagePinMessage()
  : message_id_()
{}

messagePinMessage::messagePinMessage(int53 message_id_)
  : message_id_(message_id_)
{}

const std::int32_t messagePinMessage::ID;

void messagePinMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePinMessage");
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

messageScreenshotTaken::messageScreenshotTaken() {
}

const std::int32_t messageScreenshotTaken::ID;

void messageScreenshotTaken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageScreenshotTaken");
    s.store_class_end();
  }
}

messageChatSetBackground::messageChatSetBackground()
  : old_background_message_id_()
  , background_()
  , only_for_self_()
{}

messageChatSetBackground::messageChatSetBackground(int53 old_background_message_id_, object_ptr<chatBackground> &&background_, bool only_for_self_)
  : old_background_message_id_(old_background_message_id_)
  , background_(std::move(background_))
  , only_for_self_(only_for_self_)
{}

const std::int32_t messageChatSetBackground::ID;

void messageChatSetBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatSetBackground");
    s.store_field("old_background_message_id", old_background_message_id_);
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_field("only_for_self", only_for_self_);
    s.store_class_end();
  }
}

messageChatSetTheme::messageChatSetTheme()
  : theme_()
{}

messageChatSetTheme::messageChatSetTheme(object_ptr<ChatTheme> &&theme_)
  : theme_(std::move(theme_))
{}

const std::int32_t messageChatSetTheme::ID;

void messageChatSetTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatSetTheme");
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

messageChatSetMessageAutoDeleteTime::messageChatSetMessageAutoDeleteTime()
  : message_auto_delete_time_()
  , from_user_id_()
{}

messageChatSetMessageAutoDeleteTime::messageChatSetMessageAutoDeleteTime(int32 message_auto_delete_time_, int53 from_user_id_)
  : message_auto_delete_time_(message_auto_delete_time_)
  , from_user_id_(from_user_id_)
{}

const std::int32_t messageChatSetMessageAutoDeleteTime::ID;

void messageChatSetMessageAutoDeleteTime::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatSetMessageAutoDeleteTime");
    s.store_field("message_auto_delete_time", message_auto_delete_time_);
    s.store_field("from_user_id", from_user_id_);
    s.store_class_end();
  }
}

messageChatBoost::messageChatBoost()
  : boost_count_()
{}

messageChatBoost::messageChatBoost(int32 boost_count_)
  : boost_count_(boost_count_)
{}

const std::int32_t messageChatBoost::ID;

void messageChatBoost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatBoost");
    s.store_field("boost_count", boost_count_);
    s.store_class_end();
  }
}

messageForumTopicCreated::messageForumTopicCreated()
  : name_()
  , is_name_implicit_()
  , icon_()
{}

messageForumTopicCreated::messageForumTopicCreated(string const &name_, bool is_name_implicit_, object_ptr<forumTopicIcon> &&icon_)
  : name_(name_)
  , is_name_implicit_(is_name_implicit_)
  , icon_(std::move(icon_))
{}

const std::int32_t messageForumTopicCreated::ID;

void messageForumTopicCreated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageForumTopicCreated");
    s.store_field("name", name_);
    s.store_field("is_name_implicit", is_name_implicit_);
    s.store_object_field("icon", static_cast<const BaseObject *>(icon_.get()));
    s.store_class_end();
  }
}

messageForumTopicEdited::messageForumTopicEdited()
  : name_()
  , edit_icon_custom_emoji_id_()
  , icon_custom_emoji_id_()
{}

messageForumTopicEdited::messageForumTopicEdited(string const &name_, bool edit_icon_custom_emoji_id_, int64 icon_custom_emoji_id_)
  : name_(name_)
  , edit_icon_custom_emoji_id_(edit_icon_custom_emoji_id_)
  , icon_custom_emoji_id_(icon_custom_emoji_id_)
{}

const std::int32_t messageForumTopicEdited::ID;

void messageForumTopicEdited::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageForumTopicEdited");
    s.store_field("name", name_);
    s.store_field("edit_icon_custom_emoji_id", edit_icon_custom_emoji_id_);
    s.store_field("icon_custom_emoji_id", icon_custom_emoji_id_);
    s.store_class_end();
  }
}

messageForumTopicIsClosedToggled::messageForumTopicIsClosedToggled()
  : is_closed_()
{}

messageForumTopicIsClosedToggled::messageForumTopicIsClosedToggled(bool is_closed_)
  : is_closed_(is_closed_)
{}

const std::int32_t messageForumTopicIsClosedToggled::ID;

void messageForumTopicIsClosedToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageForumTopicIsClosedToggled");
    s.store_field("is_closed", is_closed_);
    s.store_class_end();
  }
}

messageForumTopicIsHiddenToggled::messageForumTopicIsHiddenToggled()
  : is_hidden_()
{}

messageForumTopicIsHiddenToggled::messageForumTopicIsHiddenToggled(bool is_hidden_)
  : is_hidden_(is_hidden_)
{}

const std::int32_t messageForumTopicIsHiddenToggled::ID;

void messageForumTopicIsHiddenToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageForumTopicIsHiddenToggled");
    s.store_field("is_hidden", is_hidden_);
    s.store_class_end();
  }
}

messageSuggestProfilePhoto::messageSuggestProfilePhoto()
  : photo_()
{}

messageSuggestProfilePhoto::messageSuggestProfilePhoto(object_ptr<chatPhoto> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t messageSuggestProfilePhoto::ID;

void messageSuggestProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSuggestProfilePhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

messageSuggestBirthdate::messageSuggestBirthdate()
  : birthdate_()
{}

messageSuggestBirthdate::messageSuggestBirthdate(object_ptr<birthdate> &&birthdate_)
  : birthdate_(std::move(birthdate_))
{}

const std::int32_t messageSuggestBirthdate::ID;

void messageSuggestBirthdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSuggestBirthdate");
    s.store_object_field("birthdate", static_cast<const BaseObject *>(birthdate_.get()));
    s.store_class_end();
  }
}

messageCustomServiceAction::messageCustomServiceAction()
  : text_()
{}

messageCustomServiceAction::messageCustomServiceAction(string const &text_)
  : text_(text_)
{}

const std::int32_t messageCustomServiceAction::ID;

void messageCustomServiceAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageCustomServiceAction");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

messageGameScore::messageGameScore()
  : game_message_id_()
  , game_id_()
  , score_()
{}

messageGameScore::messageGameScore(int53 game_message_id_, int64 game_id_, int32 score_)
  : game_message_id_(game_message_id_)
  , game_id_(game_id_)
  , score_(score_)
{}

const std::int32_t messageGameScore::ID;

void messageGameScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGameScore");
    s.store_field("game_message_id", game_message_id_);
    s.store_field("game_id", game_id_);
    s.store_field("score", score_);
    s.store_class_end();
  }
}

messageManagedBotCreated::messageManagedBotCreated()
  : bot_user_id_()
{}

messageManagedBotCreated::messageManagedBotCreated(int53 bot_user_id_)
  : bot_user_id_(bot_user_id_)
{}

const std::int32_t messageManagedBotCreated::ID;

void messageManagedBotCreated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageManagedBotCreated");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

messagePaymentSuccessful::messagePaymentSuccessful()
  : invoice_chat_id_()
  , invoice_message_id_()
  , currency_()
  , total_amount_()
  , subscription_until_date_()
  , is_recurring_()
  , is_first_recurring_()
  , invoice_name_()
{}

messagePaymentSuccessful::messagePaymentSuccessful(int53 invoice_chat_id_, int53 invoice_message_id_, string const &currency_, int53 total_amount_, int32 subscription_until_date_, bool is_recurring_, bool is_first_recurring_, string const &invoice_name_)
  : invoice_chat_id_(invoice_chat_id_)
  , invoice_message_id_(invoice_message_id_)
  , currency_(currency_)
  , total_amount_(total_amount_)
  , subscription_until_date_(subscription_until_date_)
  , is_recurring_(is_recurring_)
  , is_first_recurring_(is_first_recurring_)
  , invoice_name_(invoice_name_)
{}

const std::int32_t messagePaymentSuccessful::ID;

void messagePaymentSuccessful::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePaymentSuccessful");
    s.store_field("invoice_chat_id", invoice_chat_id_);
    s.store_field("invoice_message_id", invoice_message_id_);
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_field("subscription_until_date", subscription_until_date_);
    s.store_field("is_recurring", is_recurring_);
    s.store_field("is_first_recurring", is_first_recurring_);
    s.store_field("invoice_name", invoice_name_);
    s.store_class_end();
  }
}

messagePaymentSuccessfulBot::messagePaymentSuccessfulBot()
  : currency_()
  , total_amount_()
  , subscription_until_date_()
  , is_recurring_()
  , is_first_recurring_()
  , invoice_payload_()
  , shipping_option_id_()
  , order_info_()
  , telegram_payment_charge_id_()
  , provider_payment_charge_id_()
{}

messagePaymentSuccessfulBot::messagePaymentSuccessfulBot(string const &currency_, int53 total_amount_, int32 subscription_until_date_, bool is_recurring_, bool is_first_recurring_, bytes const &invoice_payload_, string const &shipping_option_id_, object_ptr<orderInfo> &&order_info_, string const &telegram_payment_charge_id_, string const &provider_payment_charge_id_)
  : currency_(currency_)
  , total_amount_(total_amount_)
  , subscription_until_date_(subscription_until_date_)
  , is_recurring_(is_recurring_)
  , is_first_recurring_(is_first_recurring_)
  , invoice_payload_(std::move(invoice_payload_))
  , shipping_option_id_(shipping_option_id_)
  , order_info_(std::move(order_info_))
  , telegram_payment_charge_id_(telegram_payment_charge_id_)
  , provider_payment_charge_id_(provider_payment_charge_id_)
{}

const std::int32_t messagePaymentSuccessfulBot::ID;

void messagePaymentSuccessfulBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePaymentSuccessfulBot");
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_field("subscription_until_date", subscription_until_date_);
    s.store_field("is_recurring", is_recurring_);
    s.store_field("is_first_recurring", is_first_recurring_);
    s.store_bytes_field("invoice_payload", invoice_payload_);
    s.store_field("shipping_option_id", shipping_option_id_);
    s.store_object_field("order_info", static_cast<const BaseObject *>(order_info_.get()));
    s.store_field("telegram_payment_charge_id", telegram_payment_charge_id_);
    s.store_field("provider_payment_charge_id", provider_payment_charge_id_);
    s.store_class_end();
  }
}

messagePaymentRefunded::messagePaymentRefunded()
  : owner_id_()
  , currency_()
  , total_amount_()
  , invoice_payload_()
  , telegram_payment_charge_id_()
  , provider_payment_charge_id_()
{}

messagePaymentRefunded::messagePaymentRefunded(object_ptr<MessageSender> &&owner_id_, string const &currency_, int53 total_amount_, bytes const &invoice_payload_, string const &telegram_payment_charge_id_, string const &provider_payment_charge_id_)
  : owner_id_(std::move(owner_id_))
  , currency_(currency_)
  , total_amount_(total_amount_)
  , invoice_payload_(std::move(invoice_payload_))
  , telegram_payment_charge_id_(telegram_payment_charge_id_)
  , provider_payment_charge_id_(provider_payment_charge_id_)
{}

const std::int32_t messagePaymentRefunded::ID;

void messagePaymentRefunded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePaymentRefunded");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_bytes_field("invoice_payload", invoice_payload_);
    s.store_field("telegram_payment_charge_id", telegram_payment_charge_id_);
    s.store_field("provider_payment_charge_id", provider_payment_charge_id_);
    s.store_class_end();
  }
}

messageGiftedPremium::messageGiftedPremium()
  : gifter_user_id_()
  , receiver_user_id_()
  , text_()
  , currency_()
  , amount_()
  , cryptocurrency_()
  , cryptocurrency_amount_()
  , month_count_()
  , day_count_()
  , sticker_()
{}

messageGiftedPremium::messageGiftedPremium(int53 gifter_user_id_, int53 receiver_user_id_, object_ptr<formattedText> &&text_, string const &currency_, int53 amount_, string const &cryptocurrency_, int64 cryptocurrency_amount_, int32 month_count_, int32 day_count_, object_ptr<sticker> &&sticker_)
  : gifter_user_id_(gifter_user_id_)
  , receiver_user_id_(receiver_user_id_)
  , text_(std::move(text_))
  , currency_(currency_)
  , amount_(amount_)
  , cryptocurrency_(cryptocurrency_)
  , cryptocurrency_amount_(cryptocurrency_amount_)
  , month_count_(month_count_)
  , day_count_(day_count_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t messageGiftedPremium::ID;

void messageGiftedPremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGiftedPremium");
    s.store_field("gifter_user_id", gifter_user_id_);
    s.store_field("receiver_user_id", receiver_user_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("cryptocurrency", cryptocurrency_);
    s.store_field("cryptocurrency_amount", cryptocurrency_amount_);
    s.store_field("month_count", month_count_);
    s.store_field("day_count", day_count_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

messagePremiumGiftCode::messagePremiumGiftCode()
  : creator_id_()
  , text_()
  , is_from_giveaway_()
  , is_unclaimed_()
  , currency_()
  , amount_()
  , cryptocurrency_()
  , cryptocurrency_amount_()
  , month_count_()
  , day_count_()
  , sticker_()
  , code_()
{}

messagePremiumGiftCode::messagePremiumGiftCode(object_ptr<MessageSender> &&creator_id_, object_ptr<formattedText> &&text_, bool is_from_giveaway_, bool is_unclaimed_, string const &currency_, int53 amount_, string const &cryptocurrency_, int64 cryptocurrency_amount_, int32 month_count_, int32 day_count_, object_ptr<sticker> &&sticker_, string const &code_)
  : creator_id_(std::move(creator_id_))
  , text_(std::move(text_))
  , is_from_giveaway_(is_from_giveaway_)
  , is_unclaimed_(is_unclaimed_)
  , currency_(currency_)
  , amount_(amount_)
  , cryptocurrency_(cryptocurrency_)
  , cryptocurrency_amount_(cryptocurrency_amount_)
  , month_count_(month_count_)
  , day_count_(day_count_)
  , sticker_(std::move(sticker_))
  , code_(code_)
{}

const std::int32_t messagePremiumGiftCode::ID;

void messagePremiumGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePremiumGiftCode");
    s.store_object_field("creator_id", static_cast<const BaseObject *>(creator_id_.get()));
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("is_from_giveaway", is_from_giveaway_);
    s.store_field("is_unclaimed", is_unclaimed_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("cryptocurrency", cryptocurrency_);
    s.store_field("cryptocurrency_amount", cryptocurrency_amount_);
    s.store_field("month_count", month_count_);
    s.store_field("day_count", day_count_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("code", code_);
    s.store_class_end();
  }
}

messageGiveawayCreated::messageGiveawayCreated()
  : star_count_()
{}

messageGiveawayCreated::messageGiveawayCreated(int53 star_count_)
  : star_count_(star_count_)
{}

const std::int32_t messageGiveawayCreated::ID;

void messageGiveawayCreated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGiveawayCreated");
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

messageGiveaway::messageGiveaway()
  : parameters_()
  , winner_count_()
  , prize_()
  , sticker_()
{}

messageGiveaway::messageGiveaway(object_ptr<giveawayParameters> &&parameters_, int32 winner_count_, object_ptr<GiveawayPrize> &&prize_, object_ptr<sticker> &&sticker_)
  : parameters_(std::move(parameters_))
  , winner_count_(winner_count_)
  , prize_(std::move(prize_))
  , sticker_(std::move(sticker_))
{}

const std::int32_t messageGiveaway::ID;

void messageGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGiveaway");
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_field("winner_count", winner_count_);
    s.store_object_field("prize", static_cast<const BaseObject *>(prize_.get()));
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

messageGiveawayCompleted::messageGiveawayCompleted()
  : giveaway_message_id_()
  , winner_count_()
  , is_star_giveaway_()
  , unclaimed_prize_count_()
{}

messageGiveawayCompleted::messageGiveawayCompleted(int53 giveaway_message_id_, int32 winner_count_, bool is_star_giveaway_, int32 unclaimed_prize_count_)
  : giveaway_message_id_(giveaway_message_id_)
  , winner_count_(winner_count_)
  , is_star_giveaway_(is_star_giveaway_)
  , unclaimed_prize_count_(unclaimed_prize_count_)
{}

const std::int32_t messageGiveawayCompleted::ID;

void messageGiveawayCompleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGiveawayCompleted");
    s.store_field("giveaway_message_id", giveaway_message_id_);
    s.store_field("winner_count", winner_count_);
    s.store_field("is_star_giveaway", is_star_giveaway_);
    s.store_field("unclaimed_prize_count", unclaimed_prize_count_);
    s.store_class_end();
  }
}

messageGiveawayWinners::messageGiveawayWinners()
  : boosted_chat_id_()
  , giveaway_message_id_()
  , additional_chat_count_()
  , actual_winners_selection_date_()
  , only_new_members_()
  , was_refunded_()
  , prize_()
  , prize_description_()
  , winner_count_()
  , winner_user_ids_()
  , unclaimed_prize_count_()
{}

messageGiveawayWinners::messageGiveawayWinners(int53 boosted_chat_id_, int53 giveaway_message_id_, int32 additional_chat_count_, int32 actual_winners_selection_date_, bool only_new_members_, bool was_refunded_, object_ptr<GiveawayPrize> &&prize_, string const &prize_description_, int32 winner_count_, array<int53> &&winner_user_ids_, int32 unclaimed_prize_count_)
  : boosted_chat_id_(boosted_chat_id_)
  , giveaway_message_id_(giveaway_message_id_)
  , additional_chat_count_(additional_chat_count_)
  , actual_winners_selection_date_(actual_winners_selection_date_)
  , only_new_members_(only_new_members_)
  , was_refunded_(was_refunded_)
  , prize_(std::move(prize_))
  , prize_description_(prize_description_)
  , winner_count_(winner_count_)
  , winner_user_ids_(std::move(winner_user_ids_))
  , unclaimed_prize_count_(unclaimed_prize_count_)
{}

const std::int32_t messageGiveawayWinners::ID;

void messageGiveawayWinners::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGiveawayWinners");
    s.store_field("boosted_chat_id", boosted_chat_id_);
    s.store_field("giveaway_message_id", giveaway_message_id_);
    s.store_field("additional_chat_count", additional_chat_count_);
    s.store_field("actual_winners_selection_date", actual_winners_selection_date_);
    s.store_field("only_new_members", only_new_members_);
    s.store_field("was_refunded", was_refunded_);
    s.store_object_field("prize", static_cast<const BaseObject *>(prize_.get()));
    s.store_field("prize_description", prize_description_);
    s.store_field("winner_count", winner_count_);
    { s.store_vector_begin("winner_user_ids", winner_user_ids_.size()); for (const auto &_value : winner_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("unclaimed_prize_count", unclaimed_prize_count_);
    s.store_class_end();
  }
}

messageGiftedStars::messageGiftedStars()
  : gifter_user_id_()
  , receiver_user_id_()
  , currency_()
  , amount_()
  , cryptocurrency_()
  , cryptocurrency_amount_()
  , star_count_()
  , transaction_id_()
  , sticker_()
{}

messageGiftedStars::messageGiftedStars(int53 gifter_user_id_, int53 receiver_user_id_, string const &currency_, int53 amount_, string const &cryptocurrency_, int64 cryptocurrency_amount_, int53 star_count_, string const &transaction_id_, object_ptr<sticker> &&sticker_)
  : gifter_user_id_(gifter_user_id_)
  , receiver_user_id_(receiver_user_id_)
  , currency_(currency_)
  , amount_(amount_)
  , cryptocurrency_(cryptocurrency_)
  , cryptocurrency_amount_(cryptocurrency_amount_)
  , star_count_(star_count_)
  , transaction_id_(transaction_id_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t messageGiftedStars::ID;

void messageGiftedStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGiftedStars");
    s.store_field("gifter_user_id", gifter_user_id_);
    s.store_field("receiver_user_id", receiver_user_id_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("cryptocurrency", cryptocurrency_);
    s.store_field("cryptocurrency_amount", cryptocurrency_amount_);
    s.store_field("star_count", star_count_);
    s.store_field("transaction_id", transaction_id_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

messageGiftedTon::messageGiftedTon()
  : gifter_user_id_()
  , receiver_user_id_()
  , ton_amount_()
  , transaction_id_()
  , sticker_()
{}

messageGiftedTon::messageGiftedTon(int53 gifter_user_id_, int53 receiver_user_id_, int53 ton_amount_, string const &transaction_id_, object_ptr<sticker> &&sticker_)
  : gifter_user_id_(gifter_user_id_)
  , receiver_user_id_(receiver_user_id_)
  , ton_amount_(ton_amount_)
  , transaction_id_(transaction_id_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t messageGiftedTon::ID;

void messageGiftedTon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGiftedTon");
    s.store_field("gifter_user_id", gifter_user_id_);
    s.store_field("receiver_user_id", receiver_user_id_);
    s.store_field("ton_amount", ton_amount_);
    s.store_field("transaction_id", transaction_id_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

messageGiveawayPrizeStars::messageGiveawayPrizeStars()
  : star_count_()
  , transaction_id_()
  , boosted_chat_id_()
  , giveaway_message_id_()
  , is_unclaimed_()
  , sticker_()
{}

messageGiveawayPrizeStars::messageGiveawayPrizeStars(int53 star_count_, string const &transaction_id_, int53 boosted_chat_id_, int53 giveaway_message_id_, bool is_unclaimed_, object_ptr<sticker> &&sticker_)
  : star_count_(star_count_)
  , transaction_id_(transaction_id_)
  , boosted_chat_id_(boosted_chat_id_)
  , giveaway_message_id_(giveaway_message_id_)
  , is_unclaimed_(is_unclaimed_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t messageGiveawayPrizeStars::ID;

void messageGiveawayPrizeStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGiveawayPrizeStars");
    s.store_field("star_count", star_count_);
    s.store_field("transaction_id", transaction_id_);
    s.store_field("boosted_chat_id", boosted_chat_id_);
    s.store_field("giveaway_message_id", giveaway_message_id_);
    s.store_field("is_unclaimed", is_unclaimed_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

messageGift::messageGift()
  : gift_()
  , sender_id_()
  , receiver_id_()
  , received_gift_id_()
  , text_()
  , unique_gift_number_()
  , sell_star_count_()
  , prepaid_upgrade_star_count_()
  , is_upgrade_separate_()
  , is_from_auction_()
  , is_private_()
  , is_saved_()
  , is_prepaid_upgrade_()
  , can_be_upgraded_()
  , was_converted_()
  , was_upgraded_()
  , was_refunded_()
  , upgraded_received_gift_id_()
  , prepaid_upgrade_hash_()
{}

messageGift::messageGift(object_ptr<gift> &&gift_, object_ptr<MessageSender> &&sender_id_, object_ptr<MessageSender> &&receiver_id_, string const &received_gift_id_, object_ptr<formattedText> &&text_, int32 unique_gift_number_, int53 sell_star_count_, int53 prepaid_upgrade_star_count_, bool is_upgrade_separate_, bool is_from_auction_, bool is_private_, bool is_saved_, bool is_prepaid_upgrade_, bool can_be_upgraded_, bool was_converted_, bool was_upgraded_, bool was_refunded_, string const &upgraded_received_gift_id_, string const &prepaid_upgrade_hash_)
  : gift_(std::move(gift_))
  , sender_id_(std::move(sender_id_))
  , receiver_id_(std::move(receiver_id_))
  , received_gift_id_(received_gift_id_)
  , text_(std::move(text_))
  , unique_gift_number_(unique_gift_number_)
  , sell_star_count_(sell_star_count_)
  , prepaid_upgrade_star_count_(prepaid_upgrade_star_count_)
  , is_upgrade_separate_(is_upgrade_separate_)
  , is_from_auction_(is_from_auction_)
  , is_private_(is_private_)
  , is_saved_(is_saved_)
  , is_prepaid_upgrade_(is_prepaid_upgrade_)
  , can_be_upgraded_(can_be_upgraded_)
  , was_converted_(was_converted_)
  , was_upgraded_(was_upgraded_)
  , was_refunded_(was_refunded_)
  , upgraded_received_gift_id_(upgraded_received_gift_id_)
  , prepaid_upgrade_hash_(prepaid_upgrade_hash_)
{}

const std::int32_t messageGift::ID;

void messageGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGift");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_object_field("receiver_id", static_cast<const BaseObject *>(receiver_id_.get()));
    s.store_field("received_gift_id", received_gift_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("unique_gift_number", unique_gift_number_);
    s.store_field("sell_star_count", sell_star_count_);
    s.store_field("prepaid_upgrade_star_count", prepaid_upgrade_star_count_);
    s.store_field("is_upgrade_separate", is_upgrade_separate_);
    s.store_field("is_from_auction", is_from_auction_);
    s.store_field("is_private", is_private_);
    s.store_field("is_saved", is_saved_);
    s.store_field("is_prepaid_upgrade", is_prepaid_upgrade_);
    s.store_field("can_be_upgraded", can_be_upgraded_);
    s.store_field("was_converted", was_converted_);
    s.store_field("was_upgraded", was_upgraded_);
    s.store_field("was_refunded", was_refunded_);
    s.store_field("upgraded_received_gift_id", upgraded_received_gift_id_);
    s.store_field("prepaid_upgrade_hash", prepaid_upgrade_hash_);
    s.store_class_end();
  }
}

messageUpgradedGift::messageUpgradedGift()
  : gift_()
  , sender_id_()
  , receiver_id_()
  , origin_()
  , received_gift_id_()
  , is_saved_()
  , can_be_transferred_()
  , was_transferred_()
  , transfer_star_count_()
  , drop_original_details_star_count_()
  , next_transfer_date_()
  , next_resale_date_()
  , export_date_()
  , craft_date_()
{}

messageUpgradedGift::messageUpgradedGift(object_ptr<upgradedGift> &&gift_, object_ptr<MessageSender> &&sender_id_, object_ptr<MessageSender> &&receiver_id_, object_ptr<UpgradedGiftOrigin> &&origin_, string const &received_gift_id_, bool is_saved_, bool can_be_transferred_, bool was_transferred_, int53 transfer_star_count_, int53 drop_original_details_star_count_, int32 next_transfer_date_, int32 next_resale_date_, int32 export_date_, int32 craft_date_)
  : gift_(std::move(gift_))
  , sender_id_(std::move(sender_id_))
  , receiver_id_(std::move(receiver_id_))
  , origin_(std::move(origin_))
  , received_gift_id_(received_gift_id_)
  , is_saved_(is_saved_)
  , can_be_transferred_(can_be_transferred_)
  , was_transferred_(was_transferred_)
  , transfer_star_count_(transfer_star_count_)
  , drop_original_details_star_count_(drop_original_details_star_count_)
  , next_transfer_date_(next_transfer_date_)
  , next_resale_date_(next_resale_date_)
  , export_date_(export_date_)
  , craft_date_(craft_date_)
{}

const std::int32_t messageUpgradedGift::ID;

void messageUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageUpgradedGift");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_object_field("receiver_id", static_cast<const BaseObject *>(receiver_id_.get()));
    s.store_object_field("origin", static_cast<const BaseObject *>(origin_.get()));
    s.store_field("received_gift_id", received_gift_id_);
    s.store_field("is_saved", is_saved_);
    s.store_field("can_be_transferred", can_be_transferred_);
    s.store_field("was_transferred", was_transferred_);
    s.store_field("transfer_star_count", transfer_star_count_);
    s.store_field("drop_original_details_star_count", drop_original_details_star_count_);
    s.store_field("next_transfer_date", next_transfer_date_);
    s.store_field("next_resale_date", next_resale_date_);
    s.store_field("export_date", export_date_);
    s.store_field("craft_date", craft_date_);
    s.store_class_end();
  }
}

messageRefundedUpgradedGift::messageRefundedUpgradedGift()
  : gift_()
  , sender_id_()
  , receiver_id_()
  , origin_()
{}

messageRefundedUpgradedGift::messageRefundedUpgradedGift(object_ptr<gift> &&gift_, object_ptr<MessageSender> &&sender_id_, object_ptr<MessageSender> &&receiver_id_, object_ptr<UpgradedGiftOrigin> &&origin_)
  : gift_(std::move(gift_))
  , sender_id_(std::move(sender_id_))
  , receiver_id_(std::move(receiver_id_))
  , origin_(std::move(origin_))
{}

const std::int32_t messageRefundedUpgradedGift::ID;

void messageRefundedUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageRefundedUpgradedGift");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_object_field("receiver_id", static_cast<const BaseObject *>(receiver_id_.get()));
    s.store_object_field("origin", static_cast<const BaseObject *>(origin_.get()));
    s.store_class_end();
  }
}

messageUpgradedGiftPurchaseOffer::messageUpgradedGiftPurchaseOffer()
  : gift_()
  , state_()
  , price_()
  , expiration_date_()
{}

messageUpgradedGiftPurchaseOffer::messageUpgradedGiftPurchaseOffer(object_ptr<upgradedGift> &&gift_, object_ptr<GiftPurchaseOfferState> &&state_, object_ptr<GiftResalePrice> &&price_, int32 expiration_date_)
  : gift_(std::move(gift_))
  , state_(std::move(state_))
  , price_(std::move(price_))
  , expiration_date_(expiration_date_)
{}

const std::int32_t messageUpgradedGiftPurchaseOffer::ID;

void messageUpgradedGiftPurchaseOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageUpgradedGiftPurchaseOffer");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_field("expiration_date", expiration_date_);
    s.store_class_end();
  }
}

messageUpgradedGiftPurchaseOfferRejected::messageUpgradedGiftPurchaseOfferRejected()
  : gift_()
  , price_()
  , offer_message_id_()
  , was_expired_()
{}

messageUpgradedGiftPurchaseOfferRejected::messageUpgradedGiftPurchaseOfferRejected(object_ptr<upgradedGift> &&gift_, object_ptr<GiftResalePrice> &&price_, int53 offer_message_id_, bool was_expired_)
  : gift_(std::move(gift_))
  , price_(std::move(price_))
  , offer_message_id_(offer_message_id_)
  , was_expired_(was_expired_)
{}

const std::int32_t messageUpgradedGiftPurchaseOfferRejected::ID;

void messageUpgradedGiftPurchaseOfferRejected::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageUpgradedGiftPurchaseOfferRejected");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_field("offer_message_id", offer_message_id_);
    s.store_field("was_expired", was_expired_);
    s.store_class_end();
  }
}

messagePaidMessagesRefunded::messagePaidMessagesRefunded()
  : message_count_()
  , star_count_()
{}

messagePaidMessagesRefunded::messagePaidMessagesRefunded(int32 message_count_, int53 star_count_)
  : message_count_(message_count_)
  , star_count_(star_count_)
{}

const std::int32_t messagePaidMessagesRefunded::ID;

void messagePaidMessagesRefunded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePaidMessagesRefunded");
    s.store_field("message_count", message_count_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

messagePaidMessagePriceChanged::messagePaidMessagePriceChanged()
  : paid_message_star_count_()
{}

messagePaidMessagePriceChanged::messagePaidMessagePriceChanged(int53 paid_message_star_count_)
  : paid_message_star_count_(paid_message_star_count_)
{}

const std::int32_t messagePaidMessagePriceChanged::ID;

void messagePaidMessagePriceChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePaidMessagePriceChanged");
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_class_end();
  }
}

messageDirectMessagePriceChanged::messageDirectMessagePriceChanged()
  : is_enabled_()
  , paid_message_star_count_()
{}

messageDirectMessagePriceChanged::messageDirectMessagePriceChanged(bool is_enabled_, int53 paid_message_star_count_)
  : is_enabled_(is_enabled_)
  , paid_message_star_count_(paid_message_star_count_)
{}

const std::int32_t messageDirectMessagePriceChanged::ID;

void messageDirectMessagePriceChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageDirectMessagePriceChanged");
    s.store_field("is_enabled", is_enabled_);
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_class_end();
  }
}

messageChecklistTasksDone::messageChecklistTasksDone()
  : checklist_message_id_()
  , marked_as_done_task_ids_()
  , marked_as_not_done_task_ids_()
{}

messageChecklistTasksDone::messageChecklistTasksDone(int53 checklist_message_id_, array<int32> &&marked_as_done_task_ids_, array<int32> &&marked_as_not_done_task_ids_)
  : checklist_message_id_(checklist_message_id_)
  , marked_as_done_task_ids_(std::move(marked_as_done_task_ids_))
  , marked_as_not_done_task_ids_(std::move(marked_as_not_done_task_ids_))
{}

const std::int32_t messageChecklistTasksDone::ID;

void messageChecklistTasksDone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChecklistTasksDone");
    s.store_field("checklist_message_id", checklist_message_id_);
    { s.store_vector_begin("marked_as_done_task_ids", marked_as_done_task_ids_.size()); for (const auto &_value : marked_as_done_task_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("marked_as_not_done_task_ids", marked_as_not_done_task_ids_.size()); for (const auto &_value : marked_as_not_done_task_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageChecklistTasksAdded::messageChecklistTasksAdded()
  : checklist_message_id_()
  , tasks_()
{}

messageChecklistTasksAdded::messageChecklistTasksAdded(int53 checklist_message_id_, array<object_ptr<checklistTask>> &&tasks_)
  : checklist_message_id_(checklist_message_id_)
  , tasks_(std::move(tasks_))
{}

const std::int32_t messageChecklistTasksAdded::ID;

void messageChecklistTasksAdded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChecklistTasksAdded");
    s.store_field("checklist_message_id", checklist_message_id_);
    { s.store_vector_begin("tasks", tasks_.size()); for (const auto &_value : tasks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageSuggestedPostApprovalFailed::messageSuggestedPostApprovalFailed()
  : suggested_post_message_id_()
  , price_()
{}

messageSuggestedPostApprovalFailed::messageSuggestedPostApprovalFailed(int53 suggested_post_message_id_, object_ptr<SuggestedPostPrice> &&price_)
  : suggested_post_message_id_(suggested_post_message_id_)
  , price_(std::move(price_))
{}

const std::int32_t messageSuggestedPostApprovalFailed::ID;

void messageSuggestedPostApprovalFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSuggestedPostApprovalFailed");
    s.store_field("suggested_post_message_id", suggested_post_message_id_);
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_class_end();
  }
}

messageSuggestedPostApproved::messageSuggestedPostApproved()
  : suggested_post_message_id_()
  , price_()
  , send_date_()
{}

messageSuggestedPostApproved::messageSuggestedPostApproved(int53 suggested_post_message_id_, object_ptr<SuggestedPostPrice> &&price_, int32 send_date_)
  : suggested_post_message_id_(suggested_post_message_id_)
  , price_(std::move(price_))
  , send_date_(send_date_)
{}

const std::int32_t messageSuggestedPostApproved::ID;

void messageSuggestedPostApproved::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSuggestedPostApproved");
    s.store_field("suggested_post_message_id", suggested_post_message_id_);
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_field("send_date", send_date_);
    s.store_class_end();
  }
}

messageSuggestedPostDeclined::messageSuggestedPostDeclined()
  : suggested_post_message_id_()
  , comment_()
{}

messageSuggestedPostDeclined::messageSuggestedPostDeclined(int53 suggested_post_message_id_, string const &comment_)
  : suggested_post_message_id_(suggested_post_message_id_)
  , comment_(comment_)
{}

const std::int32_t messageSuggestedPostDeclined::ID;

void messageSuggestedPostDeclined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSuggestedPostDeclined");
    s.store_field("suggested_post_message_id", suggested_post_message_id_);
    s.store_field("comment", comment_);
    s.store_class_end();
  }
}

messageSuggestedPostPaid::messageSuggestedPostPaid()
  : suggested_post_message_id_()
  , star_amount_()
  , ton_amount_()
{}

messageSuggestedPostPaid::messageSuggestedPostPaid(int53 suggested_post_message_id_, object_ptr<starAmount> &&star_amount_, int53 ton_amount_)
  : suggested_post_message_id_(suggested_post_message_id_)
  , star_amount_(std::move(star_amount_))
  , ton_amount_(ton_amount_)
{}

const std::int32_t messageSuggestedPostPaid::ID;

void messageSuggestedPostPaid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSuggestedPostPaid");
    s.store_field("suggested_post_message_id", suggested_post_message_id_);
    s.store_object_field("star_amount", static_cast<const BaseObject *>(star_amount_.get()));
    s.store_field("ton_amount", ton_amount_);
    s.store_class_end();
  }
}

messageSuggestedPostRefunded::messageSuggestedPostRefunded()
  : suggested_post_message_id_()
  , reason_()
{}

messageSuggestedPostRefunded::messageSuggestedPostRefunded(int53 suggested_post_message_id_, object_ptr<SuggestedPostRefundReason> &&reason_)
  : suggested_post_message_id_(suggested_post_message_id_)
  , reason_(std::move(reason_))
{}

const std::int32_t messageSuggestedPostRefunded::ID;

void messageSuggestedPostRefunded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSuggestedPostRefunded");
    s.store_field("suggested_post_message_id", suggested_post_message_id_);
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_class_end();
  }
}

messageContactRegistered::messageContactRegistered() {
}

const std::int32_t messageContactRegistered::ID;

void messageContactRegistered::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageContactRegistered");
    s.store_class_end();
  }
}

messageUsersShared::messageUsersShared()
  : users_()
  , button_id_()
{}

messageUsersShared::messageUsersShared(array<object_ptr<sharedUser>> &&users_, int32 button_id_)
  : users_(std::move(users_))
  , button_id_(button_id_)
{}

const std::int32_t messageUsersShared::ID;

void messageUsersShared::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageUsersShared");
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("button_id", button_id_);
    s.store_class_end();
  }
}

messageChatShared::messageChatShared()
  : chat_()
  , button_id_()
{}

messageChatShared::messageChatShared(object_ptr<sharedChat> &&chat_, int32 button_id_)
  : chat_(std::move(chat_))
  , button_id_(button_id_)
{}

const std::int32_t messageChatShared::ID;

void messageChatShared::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatShared");
    s.store_object_field("chat", static_cast<const BaseObject *>(chat_.get()));
    s.store_field("button_id", button_id_);
    s.store_class_end();
  }
}

messageBotWriteAccessAllowed::messageBotWriteAccessAllowed()
  : reason_()
{}

messageBotWriteAccessAllowed::messageBotWriteAccessAllowed(object_ptr<BotWriteAccessAllowReason> &&reason_)
  : reason_(std::move(reason_))
{}

const std::int32_t messageBotWriteAccessAllowed::ID;

void messageBotWriteAccessAllowed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageBotWriteAccessAllowed");
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_class_end();
  }
}

messageWebAppDataSent::messageWebAppDataSent()
  : button_text_()
{}

messageWebAppDataSent::messageWebAppDataSent(string const &button_text_)
  : button_text_(button_text_)
{}

const std::int32_t messageWebAppDataSent::ID;

void messageWebAppDataSent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageWebAppDataSent");
    s.store_field("button_text", button_text_);
    s.store_class_end();
  }
}

messageWebAppDataReceived::messageWebAppDataReceived()
  : button_text_()
  , data_()
{}

messageWebAppDataReceived::messageWebAppDataReceived(string const &button_text_, string const &data_)
  : button_text_(button_text_)
  , data_(data_)
{}

const std::int32_t messageWebAppDataReceived::ID;

void messageWebAppDataReceived::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageWebAppDataReceived");
    s.store_field("button_text", button_text_);
    s.store_field("data", data_);
    s.store_class_end();
  }
}

messagePassportDataSent::messagePassportDataSent()
  : types_()
{}

messagePassportDataSent::messagePassportDataSent(array<object_ptr<PassportElementType>> &&types_)
  : types_(std::move(types_))
{}

const std::int32_t messagePassportDataSent::ID;

void messagePassportDataSent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePassportDataSent");
    { s.store_vector_begin("types", types_.size()); for (const auto &_value : types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messagePassportDataReceived::messagePassportDataReceived()
  : elements_()
  , credentials_()
{}

messagePassportDataReceived::messagePassportDataReceived(array<object_ptr<encryptedPassportElement>> &&elements_, object_ptr<encryptedCredentials> &&credentials_)
  : elements_(std::move(elements_))
  , credentials_(std::move(credentials_))
{}

const std::int32_t messagePassportDataReceived::ID;

void messagePassportDataReceived::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePassportDataReceived");
    { s.store_vector_begin("elements", elements_.size()); for (const auto &_value : elements_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("credentials", static_cast<const BaseObject *>(credentials_.get()));
    s.store_class_end();
  }
}

messageProximityAlertTriggered::messageProximityAlertTriggered()
  : traveler_id_()
  , watcher_id_()
  , distance_()
{}

messageProximityAlertTriggered::messageProximityAlertTriggered(object_ptr<MessageSender> &&traveler_id_, object_ptr<MessageSender> &&watcher_id_, int32 distance_)
  : traveler_id_(std::move(traveler_id_))
  , watcher_id_(std::move(watcher_id_))
  , distance_(distance_)
{}

const std::int32_t messageProximityAlertTriggered::ID;

void messageProximityAlertTriggered::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageProximityAlertTriggered");
    s.store_object_field("traveler_id", static_cast<const BaseObject *>(traveler_id_.get()));
    s.store_object_field("watcher_id", static_cast<const BaseObject *>(watcher_id_.get()));
    s.store_field("distance", distance_);
    s.store_class_end();
  }
}

messageUnsupported::messageUnsupported() {
}

const std::int32_t messageUnsupported::ID;

void messageUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageUnsupported");
    s.store_class_end();
  }
}

messageImportInfo::messageImportInfo()
  : sender_name_()
  , date_()
{}

messageImportInfo::messageImportInfo(string const &sender_name_, int32 date_)
  : sender_name_(sender_name_)
  , date_(date_)
{}

const std::int32_t messageImportInfo::ID;

void messageImportInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageImportInfo");
    s.store_field("sender_name", sender_name_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

messageInteractionInfo::messageInteractionInfo()
  : view_count_()
  , forward_count_()
  , reply_info_()
  , reactions_()
{}

messageInteractionInfo::messageInteractionInfo(int32 view_count_, int32 forward_count_, object_ptr<messageReplyInfo> &&reply_info_, object_ptr<messageReactions> &&reactions_)
  : view_count_(view_count_)
  , forward_count_(forward_count_)
  , reply_info_(std::move(reply_info_))
  , reactions_(std::move(reactions_))
{}

const std::int32_t messageInteractionInfo::ID;

void messageInteractionInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageInteractionInfo");
    s.store_field("view_count", view_count_);
    s.store_field("forward_count", forward_count_);
    s.store_object_field("reply_info", static_cast<const BaseObject *>(reply_info_.get()));
    s.store_object_field("reactions", static_cast<const BaseObject *>(reactions_.get()));
    s.store_class_end();
  }
}

minithumbnail::minithumbnail()
  : width_()
  , height_()
  , data_()
{}

minithumbnail::minithumbnail(int32 width_, int32 height_, bytes const &data_)
  : width_(width_)
  , height_(height_)
  , data_(std::move(data_))
{}

const std::int32_t minithumbnail::ID;

void minithumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "minithumbnail");
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

newChatPrivacySettings::newChatPrivacySettings()
  : allow_new_chats_from_unknown_users_()
  , incoming_paid_message_star_count_()
{}

newChatPrivacySettings::newChatPrivacySettings(bool allow_new_chats_from_unknown_users_, int53 incoming_paid_message_star_count_)
  : allow_new_chats_from_unknown_users_(allow_new_chats_from_unknown_users_)
  , incoming_paid_message_star_count_(incoming_paid_message_star_count_)
{}

const std::int32_t newChatPrivacySettings::ID;

void newChatPrivacySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "newChatPrivacySettings");
    s.store_field("allow_new_chats_from_unknown_users", allow_new_chats_from_unknown_users_);
    s.store_field("incoming_paid_message_star_count", incoming_paid_message_star_count_);
    s.store_class_end();
  }
}

notificationGroupTypeMessages::notificationGroupTypeMessages() {
}

const std::int32_t notificationGroupTypeMessages::ID;

void notificationGroupTypeMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationGroupTypeMessages");
    s.store_class_end();
  }
}

notificationGroupTypeMentions::notificationGroupTypeMentions() {
}

const std::int32_t notificationGroupTypeMentions::ID;

void notificationGroupTypeMentions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationGroupTypeMentions");
    s.store_class_end();
  }
}

notificationGroupTypeSecretChat::notificationGroupTypeSecretChat() {
}

const std::int32_t notificationGroupTypeSecretChat::ID;

void notificationGroupTypeSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationGroupTypeSecretChat");
    s.store_class_end();
  }
}

notificationGroupTypeCalls::notificationGroupTypeCalls() {
}

const std::int32_t notificationGroupTypeCalls::ID;

void notificationGroupTypeCalls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationGroupTypeCalls");
    s.store_class_end();
  }
}

orderInfo::orderInfo()
  : name_()
  , phone_number_()
  , email_address_()
  , shipping_address_()
{}

orderInfo::orderInfo(string const &name_, string const &phone_number_, string const &email_address_, object_ptr<address> &&shipping_address_)
  : name_(name_)
  , phone_number_(phone_number_)
  , email_address_(email_address_)
  , shipping_address_(std::move(shipping_address_))
{}

const std::int32_t orderInfo::ID;

void orderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "orderInfo");
    s.store_field("name", name_);
    s.store_field("phone_number", phone_number_);
    s.store_field("email_address", email_address_);
    s.store_object_field("shipping_address", static_cast<const BaseObject *>(shipping_address_.get()));
    s.store_class_end();
  }
}

pageBlockCaption::pageBlockCaption()
  : text_()
  , credit_()
{}

pageBlockCaption::pageBlockCaption(object_ptr<RichText> &&text_, object_ptr<RichText> &&credit_)
  : text_(std::move(text_))
  , credit_(std::move(credit_))
{}

const std::int32_t pageBlockCaption::ID;

void pageBlockCaption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockCaption");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("credit", static_cast<const BaseObject *>(credit_.get()));
    s.store_class_end();
  }
}

pageBlockTableCell::pageBlockTableCell()
  : text_()
  , is_header_()
  , colspan_()
  , rowspan_()
  , align_()
  , valign_()
{}

pageBlockTableCell::pageBlockTableCell(object_ptr<RichText> &&text_, bool is_header_, int32 colspan_, int32 rowspan_, object_ptr<PageBlockHorizontalAlignment> &&align_, object_ptr<PageBlockVerticalAlignment> &&valign_)
  : text_(std::move(text_))
  , is_header_(is_header_)
  , colspan_(colspan_)
  , rowspan_(rowspan_)
  , align_(std::move(align_))
  , valign_(std::move(valign_))
{}

const std::int32_t pageBlockTableCell::ID;

void pageBlockTableCell::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockTableCell");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("is_header", is_header_);
    s.store_field("colspan", colspan_);
    s.store_field("rowspan", rowspan_);
    s.store_object_field("align", static_cast<const BaseObject *>(align_.get()));
    s.store_object_field("valign", static_cast<const BaseObject *>(valign_.get()));
    s.store_class_end();
  }
}

passportSuitableElement::passportSuitableElement()
  : type_()
  , is_selfie_required_()
  , is_translation_required_()
  , is_native_name_required_()
{}

passportSuitableElement::passportSuitableElement(object_ptr<PassportElementType> &&type_, bool is_selfie_required_, bool is_translation_required_, bool is_native_name_required_)
  : type_(std::move(type_))
  , is_selfie_required_(is_selfie_required_)
  , is_translation_required_(is_translation_required_)
  , is_native_name_required_(is_native_name_required_)
{}

const std::int32_t passportSuitableElement::ID;

void passportSuitableElement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportSuitableElement");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("is_selfie_required", is_selfie_required_);
    s.store_field("is_translation_required", is_translation_required_);
    s.store_field("is_native_name_required", is_native_name_required_);
    s.store_class_end();
  }
}

point::point()
  : x_()
  , y_()
{}

point::point(double x_, double y_)
  : x_(x_)
  , y_(y_)
{}

const std::int32_t point::ID;

void point::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "point");
    s.store_field("x", x_);
    s.store_field("y", y_);
    s.store_class_end();
  }
}

pollOption::pollOption()
  : id_()
  , text_()
  , media_()
  , voter_count_()
  , vote_percentage_()
  , recent_voter_ids_()
  , is_chosen_()
  , is_being_chosen_()
  , author_()
  , addition_date_()
{}

pollOption::pollOption(string const &id_, object_ptr<formattedText> &&text_, object_ptr<MessageContent> &&media_, int32 voter_count_, int32 vote_percentage_, array<object_ptr<MessageSender>> &&recent_voter_ids_, bool is_chosen_, bool is_being_chosen_, object_ptr<MessageSender> &&author_, int32 addition_date_)
  : id_(id_)
  , text_(std::move(text_))
  , media_(std::move(media_))
  , voter_count_(voter_count_)
  , vote_percentage_(vote_percentage_)
  , recent_voter_ids_(std::move(recent_voter_ids_))
  , is_chosen_(is_chosen_)
  , is_being_chosen_(is_being_chosen_)
  , author_(std::move(author_))
  , addition_date_(addition_date_)
{}

const std::int32_t pollOption::ID;

void pollOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollOption");
    s.store_field("id", id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_field("voter_count", voter_count_);
    s.store_field("vote_percentage", vote_percentage_);
    { s.store_vector_begin("recent_voter_ids", recent_voter_ids_.size()); for (const auto &_value : recent_voter_ids_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("is_chosen", is_chosen_);
    s.store_field("is_being_chosen", is_being_chosen_);
    s.store_object_field("author", static_cast<const BaseObject *>(author_.get()));
    s.store_field("addition_date", addition_date_);
    s.store_class_end();
  }
}

pollVoter::pollVoter()
  : voter_id_()
  , date_()
{}

pollVoter::pollVoter(object_ptr<MessageSender> &&voter_id_, int32 date_)
  : voter_id_(std::move(voter_id_))
  , date_(date_)
{}

const std::int32_t pollVoter::ID;

void pollVoter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollVoter");
    s.store_object_field("voter_id", static_cast<const BaseObject *>(voter_id_.get()));
    s.store_field("date", date_);
    s.store_class_end();
  }
}

premiumFeaturePromotionAnimation::premiumFeaturePromotionAnimation()
  : feature_()
  , animation_()
{}

premiumFeaturePromotionAnimation::premiumFeaturePromotionAnimation(object_ptr<PremiumFeature> &&feature_, object_ptr<animation> &&animation_)
  : feature_(std::move(feature_))
  , animation_(std::move(animation_))
{}

const std::int32_t premiumFeaturePromotionAnimation::ID;

void premiumFeaturePromotionAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeaturePromotionAnimation");
    s.store_object_field("feature", static_cast<const BaseObject *>(feature_.get()));
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

premiumGiftPaymentOption::premiumGiftPaymentOption()
  : currency_()
  , amount_()
  , star_count_()
  , discount_percentage_()
  , month_count_()
  , store_product_id_()
  , sticker_()
{}

premiumGiftPaymentOption::premiumGiftPaymentOption(string const &currency_, int53 amount_, int53 star_count_, int32 discount_percentage_, int32 month_count_, string const &store_product_id_, object_ptr<sticker> &&sticker_)
  : currency_(currency_)
  , amount_(amount_)
  , star_count_(star_count_)
  , discount_percentage_(discount_percentage_)
  , month_count_(month_count_)
  , store_product_id_(store_product_id_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t premiumGiftPaymentOption::ID;

void premiumGiftPaymentOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumGiftPaymentOption");
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("star_count", star_count_);
    s.store_field("discount_percentage", discount_percentage_);
    s.store_field("month_count", month_count_);
    s.store_field("store_product_id", store_product_id_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

preparedInlineMessageId::preparedInlineMessageId()
  : id_()
  , expiration_date_()
{}

preparedInlineMessageId::preparedInlineMessageId(string const &id_, int32 expiration_date_)
  : id_(id_)
  , expiration_date_(expiration_date_)
{}

const std::int32_t preparedInlineMessageId::ID;

void preparedInlineMessageId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "preparedInlineMessageId");
    s.store_field("id", id_);
    s.store_field("expiration_date", expiration_date_);
    s.store_class_end();
  }
}

replyMarkupRemoveKeyboard::replyMarkupRemoveKeyboard()
  : is_personal_()
{}

replyMarkupRemoveKeyboard::replyMarkupRemoveKeyboard(bool is_personal_)
  : is_personal_(is_personal_)
{}

const std::int32_t replyMarkupRemoveKeyboard::ID;

void replyMarkupRemoveKeyboard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyMarkupRemoveKeyboard");
    s.store_field("is_personal", is_personal_);
    s.store_class_end();
  }
}

replyMarkupForceReply::replyMarkupForceReply()
  : is_personal_()
  , input_field_placeholder_()
{}

replyMarkupForceReply::replyMarkupForceReply(bool is_personal_, string const &input_field_placeholder_)
  : is_personal_(is_personal_)
  , input_field_placeholder_(input_field_placeholder_)
{}

const std::int32_t replyMarkupForceReply::ID;

void replyMarkupForceReply::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyMarkupForceReply");
    s.store_field("is_personal", is_personal_);
    s.store_field("input_field_placeholder", input_field_placeholder_);
    s.store_class_end();
  }
}

replyMarkupShowKeyboard::replyMarkupShowKeyboard()
  : rows_()
  , is_persistent_()
  , resize_keyboard_()
  , one_time_()
  , is_personal_()
  , input_field_placeholder_()
{}

replyMarkupShowKeyboard::replyMarkupShowKeyboard(array<array<object_ptr<keyboardButton>>> &&rows_, bool is_persistent_, bool resize_keyboard_, bool one_time_, bool is_personal_, string const &input_field_placeholder_)
  : rows_(std::move(rows_))
  , is_persistent_(is_persistent_)
  , resize_keyboard_(resize_keyboard_)
  , one_time_(one_time_)
  , is_personal_(is_personal_)
  , input_field_placeholder_(input_field_placeholder_)
{}

const std::int32_t replyMarkupShowKeyboard::ID;

void replyMarkupShowKeyboard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyMarkupShowKeyboard");
    { s.store_vector_begin("rows", rows_.size()); for (const auto &_value : rows_) { { s.store_vector_begin("", _value.size()); for (const auto &_value2 : _value) { s.store_object_field("", static_cast<const BaseObject *>(_value2.get())); } s.store_class_end(); } } s.store_class_end(); }
    s.store_field("is_persistent", is_persistent_);
    s.store_field("resize_keyboard", resize_keyboard_);
    s.store_field("one_time", one_time_);
    s.store_field("is_personal", is_personal_);
    s.store_field("input_field_placeholder", input_field_placeholder_);
    s.store_class_end();
  }
}

replyMarkupInlineKeyboard::replyMarkupInlineKeyboard()
  : rows_()
{}

replyMarkupInlineKeyboard::replyMarkupInlineKeyboard(array<array<object_ptr<inlineKeyboardButton>>> &&rows_)
  : rows_(std::move(rows_))
{}

const std::int32_t replyMarkupInlineKeyboard::ID;

void replyMarkupInlineKeyboard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyMarkupInlineKeyboard");
    { s.store_vector_begin("rows", rows_.size()); for (const auto &_value : rows_) { { s.store_vector_begin("", _value.size()); for (const auto &_value2 : _value) { s.store_object_field("", static_cast<const BaseObject *>(_value2.get())); } s.store_class_end(); } } s.store_class_end(); }
    s.store_class_end();
  }
}

scopeAutosaveSettings::scopeAutosaveSettings()
  : autosave_photos_()
  , autosave_videos_()
  , max_video_file_size_()
{}

scopeAutosaveSettings::scopeAutosaveSettings(bool autosave_photos_, bool autosave_videos_, int53 max_video_file_size_)
  : autosave_photos_(autosave_photos_)
  , autosave_videos_(autosave_videos_)
  , max_video_file_size_(max_video_file_size_)
{}

const std::int32_t scopeAutosaveSettings::ID;

void scopeAutosaveSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "scopeAutosaveSettings");
    s.store_field("autosave_photos", autosave_photos_);
    s.store_field("autosave_videos", autosave_videos_);
    s.store_field("max_video_file_size", max_video_file_size_);
    s.store_class_end();
  }
}

starGiveawayWinnerOption::starGiveawayWinnerOption()
  : winner_count_()
  , won_star_count_()
  , is_default_()
{}

starGiveawayWinnerOption::starGiveawayWinnerOption(int32 winner_count_, int53 won_star_count_, bool is_default_)
  : winner_count_(winner_count_)
  , won_star_count_(won_star_count_)
  , is_default_(is_default_)
{}

const std::int32_t starGiveawayWinnerOption::ID;

void starGiveawayWinnerOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiveawayWinnerOption");
    s.store_field("winner_count", winner_count_);
    s.store_field("won_star_count", won_star_count_);
    s.store_field("is_default", is_default_);
    s.store_class_end();
  }
}

stickerSetInfo::stickerSetInfo()
  : id_()
  , title_()
  , name_()
  , thumbnail_()
  , thumbnail_outline_()
  , is_owned_()
  , is_installed_()
  , is_archived_()
  , is_official_()
  , sticker_type_()
  , needs_repainting_()
  , is_allowed_as_chat_emoji_status_()
  , is_viewed_()
  , size_()
  , covers_()
{}

stickerSetInfo::stickerSetInfo(int64 id_, string const &title_, string const &name_, object_ptr<thumbnail> &&thumbnail_, object_ptr<outline> &&thumbnail_outline_, bool is_owned_, bool is_installed_, bool is_archived_, bool is_official_, object_ptr<StickerType> &&sticker_type_, bool needs_repainting_, bool is_allowed_as_chat_emoji_status_, bool is_viewed_, int32 size_, array<object_ptr<sticker>> &&covers_)
  : id_(id_)
  , title_(title_)
  , name_(name_)
  , thumbnail_(std::move(thumbnail_))
  , thumbnail_outline_(std::move(thumbnail_outline_))
  , is_owned_(is_owned_)
  , is_installed_(is_installed_)
  , is_archived_(is_archived_)
  , is_official_(is_official_)
  , sticker_type_(std::move(sticker_type_))
  , needs_repainting_(needs_repainting_)
  , is_allowed_as_chat_emoji_status_(is_allowed_as_chat_emoji_status_)
  , is_viewed_(is_viewed_)
  , size_(size_)
  , covers_(std::move(covers_))
{}

const std::int32_t stickerSetInfo::ID;

void stickerSetInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerSetInfo");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("name", name_);
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("thumbnail_outline", static_cast<const BaseObject *>(thumbnail_outline_.get()));
    s.store_field("is_owned", is_owned_);
    s.store_field("is_installed", is_installed_);
    s.store_field("is_archived", is_archived_);
    s.store_field("is_official", is_official_);
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("needs_repainting", needs_repainting_);
    s.store_field("is_allowed_as_chat_emoji_status", is_allowed_as_chat_emoji_status_);
    s.store_field("is_viewed", is_viewed_);
    s.store_field("size", size_);
    { s.store_vector_begin("covers", covers_.size()); for (const auto &_value : covers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

stickerTypeRegular::stickerTypeRegular() {
}

const std::int32_t stickerTypeRegular::ID;

void stickerTypeRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerTypeRegular");
    s.store_class_end();
  }
}

stickerTypeMask::stickerTypeMask() {
}

const std::int32_t stickerTypeMask::ID;

void stickerTypeMask::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerTypeMask");
    s.store_class_end();
  }
}

stickerTypeCustomEmoji::stickerTypeCustomEmoji() {
}

const std::int32_t stickerTypeCustomEmoji::ID;

void stickerTypeCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerTypeCustomEmoji");
    s.store_class_end();
  }
}

stickers::stickers()
  : stickers_()
{}

stickers::stickers(array<object_ptr<sticker>> &&stickers_)
  : stickers_(std::move(stickers_))
{}

const std::int32_t stickers::ID;

void stickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers");
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

storePaymentPurposePremiumSubscription::storePaymentPurposePremiumSubscription()
  : is_restore_()
  , is_upgrade_()
{}

storePaymentPurposePremiumSubscription::storePaymentPurposePremiumSubscription(bool is_restore_, bool is_upgrade_)
  : is_restore_(is_restore_)
  , is_upgrade_(is_upgrade_)
{}

const std::int32_t storePaymentPurposePremiumSubscription::ID;

void storePaymentPurposePremiumSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storePaymentPurposePremiumSubscription");
    s.store_field("is_restore", is_restore_);
    s.store_field("is_upgrade", is_upgrade_);
    s.store_class_end();
  }
}

storePaymentPurposePremiumGift::storePaymentPurposePremiumGift()
  : currency_()
  , amount_()
  , user_id_()
  , text_()
{}

storePaymentPurposePremiumGift::storePaymentPurposePremiumGift(string const &currency_, int53 amount_, int53 user_id_, object_ptr<formattedText> &&text_)
  : currency_(currency_)
  , amount_(amount_)
  , user_id_(user_id_)
  , text_(std::move(text_))
{}

const std::int32_t storePaymentPurposePremiumGift::ID;

void storePaymentPurposePremiumGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storePaymentPurposePremiumGift");
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("user_id", user_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

storePaymentPurposePremiumGiftCodes::storePaymentPurposePremiumGiftCodes()
  : boosted_chat_id_()
  , currency_()
  , amount_()
  , user_ids_()
  , text_()
{}

storePaymentPurposePremiumGiftCodes::storePaymentPurposePremiumGiftCodes(int53 boosted_chat_id_, string const &currency_, int53 amount_, array<int53> &&user_ids_, object_ptr<formattedText> &&text_)
  : boosted_chat_id_(boosted_chat_id_)
  , currency_(currency_)
  , amount_(amount_)
  , user_ids_(std::move(user_ids_))
  , text_(std::move(text_))
{}

const std::int32_t storePaymentPurposePremiumGiftCodes::ID;

void storePaymentPurposePremiumGiftCodes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storePaymentPurposePremiumGiftCodes");
    s.store_field("boosted_chat_id", boosted_chat_id_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

storePaymentPurposePremiumGiveaway::storePaymentPurposePremiumGiveaway()
  : parameters_()
  , currency_()
  , amount_()
{}

storePaymentPurposePremiumGiveaway::storePaymentPurposePremiumGiveaway(object_ptr<giveawayParameters> &&parameters_, string const &currency_, int53 amount_)
  : parameters_(std::move(parameters_))
  , currency_(currency_)
  , amount_(amount_)
{}

const std::int32_t storePaymentPurposePremiumGiveaway::ID;

void storePaymentPurposePremiumGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storePaymentPurposePremiumGiveaway");
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

storePaymentPurposeStarGiveaway::storePaymentPurposeStarGiveaway()
  : parameters_()
  , currency_()
  , amount_()
  , winner_count_()
  , star_count_()
{}

storePaymentPurposeStarGiveaway::storePaymentPurposeStarGiveaway(object_ptr<giveawayParameters> &&parameters_, string const &currency_, int53 amount_, int32 winner_count_, int53 star_count_)
  : parameters_(std::move(parameters_))
  , currency_(currency_)
  , amount_(amount_)
  , winner_count_(winner_count_)
  , star_count_(star_count_)
{}

const std::int32_t storePaymentPurposeStarGiveaway::ID;

void storePaymentPurposeStarGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storePaymentPurposeStarGiveaway");
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("winner_count", winner_count_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

storePaymentPurposeStars::storePaymentPurposeStars()
  : currency_()
  , amount_()
  , star_count_()
  , chat_id_()
{}

storePaymentPurposeStars::storePaymentPurposeStars(string const &currency_, int53 amount_, int53 star_count_, int53 chat_id_)
  : currency_(currency_)
  , amount_(amount_)
  , star_count_(star_count_)
  , chat_id_(chat_id_)
{}

const std::int32_t storePaymentPurposeStars::ID;

void storePaymentPurposeStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storePaymentPurposeStars");
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("star_count", star_count_);
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

storePaymentPurposeGiftedStars::storePaymentPurposeGiftedStars()
  : user_id_()
  , currency_()
  , amount_()
  , star_count_()
{}

storePaymentPurposeGiftedStars::storePaymentPurposeGiftedStars(int53 user_id_, string const &currency_, int53 amount_, int53 star_count_)
  : user_id_(user_id_)
  , currency_(currency_)
  , amount_(amount_)
  , star_count_(star_count_)
{}

const std::int32_t storePaymentPurposeGiftedStars::ID;

void storePaymentPurposeGiftedStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storePaymentPurposeGiftedStars");
    s.store_field("user_id", user_id_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

storyArea::storyArea()
  : position_()
  , type_()
{}

storyArea::storyArea(object_ptr<storyAreaPosition> &&position_, object_ptr<StoryAreaType> &&type_)
  : position_(std::move(position_))
  , type_(std::move(type_))
{}

const std::int32_t storyArea::ID;

void storyArea::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyArea");
    s.store_object_field("position", static_cast<const BaseObject *>(position_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

storyAreaTypeLocation::storyAreaTypeLocation()
  : location_()
  , address_()
{}

storyAreaTypeLocation::storyAreaTypeLocation(object_ptr<location> &&location_, object_ptr<locationAddress> &&address_)
  : location_(std::move(location_))
  , address_(std::move(address_))
{}

const std::int32_t storyAreaTypeLocation::ID;

void storyAreaTypeLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAreaTypeLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_object_field("address", static_cast<const BaseObject *>(address_.get()));
    s.store_class_end();
  }
}

storyAreaTypeVenue::storyAreaTypeVenue()
  : venue_()
{}

storyAreaTypeVenue::storyAreaTypeVenue(object_ptr<venue> &&venue_)
  : venue_(std::move(venue_))
{}

const std::int32_t storyAreaTypeVenue::ID;

void storyAreaTypeVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAreaTypeVenue");
    s.store_object_field("venue", static_cast<const BaseObject *>(venue_.get()));
    s.store_class_end();
  }
}

storyAreaTypeSuggestedReaction::storyAreaTypeSuggestedReaction()
  : reaction_type_()
  , total_count_()
  , is_dark_()
  , is_flipped_()
{}

storyAreaTypeSuggestedReaction::storyAreaTypeSuggestedReaction(object_ptr<ReactionType> &&reaction_type_, int32 total_count_, bool is_dark_, bool is_flipped_)
  : reaction_type_(std::move(reaction_type_))
  , total_count_(total_count_)
  , is_dark_(is_dark_)
  , is_flipped_(is_flipped_)
{}

const std::int32_t storyAreaTypeSuggestedReaction::ID;

void storyAreaTypeSuggestedReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAreaTypeSuggestedReaction");
    s.store_object_field("reaction_type", static_cast<const BaseObject *>(reaction_type_.get()));
    s.store_field("total_count", total_count_);
    s.store_field("is_dark", is_dark_);
    s.store_field("is_flipped", is_flipped_);
    s.store_class_end();
  }
}

storyAreaTypeMessage::storyAreaTypeMessage()
  : chat_id_()
  , message_id_()
{}

storyAreaTypeMessage::storyAreaTypeMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t storyAreaTypeMessage::ID;

void storyAreaTypeMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAreaTypeMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

storyAreaTypeLink::storyAreaTypeLink()
  : url_()
{}

storyAreaTypeLink::storyAreaTypeLink(string const &url_)
  : url_(url_)
{}

const std::int32_t storyAreaTypeLink::ID;

void storyAreaTypeLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAreaTypeLink");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

storyAreaTypeWeather::storyAreaTypeWeather()
  : temperature_()
  , emoji_()
  , background_color_()
{}

storyAreaTypeWeather::storyAreaTypeWeather(double temperature_, string const &emoji_, int32 background_color_)
  : temperature_(temperature_)
  , emoji_(emoji_)
  , background_color_(background_color_)
{}

const std::int32_t storyAreaTypeWeather::ID;

void storyAreaTypeWeather::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAreaTypeWeather");
    s.store_field("temperature", temperature_);
    s.store_field("emoji", emoji_);
    s.store_field("background_color", background_color_);
    s.store_class_end();
  }
}

storyAreaTypeUpgradedGift::storyAreaTypeUpgradedGift()
  : gift_name_()
{}

storyAreaTypeUpgradedGift::storyAreaTypeUpgradedGift(string const &gift_name_)
  : gift_name_(gift_name_)
{}

const std::int32_t storyAreaTypeUpgradedGift::ID;

void storyAreaTypeUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAreaTypeUpgradedGift");
    s.store_field("gift_name", gift_name_);
    s.store_class_end();
  }
}

supergroup::supergroup()
  : id_()
  , usernames_()
  , date_()
  , status_()
  , member_count_()
  , boost_level_()
  , has_automatic_translation_()
  , has_linked_chat_()
  , has_location_()
  , sign_messages_()
  , show_message_sender_()
  , join_to_send_messages_()
  , join_by_request_()
  , is_slow_mode_enabled_()
  , is_channel_()
  , is_broadcast_group_()
  , is_forum_()
  , is_direct_messages_group_()
  , is_administered_direct_messages_group_()
  , verification_status_()
  , has_direct_messages_group_()
  , has_forum_tabs_()
  , restriction_info_()
  , paid_message_star_count_()
  , active_story_state_()
{}

supergroup::supergroup(int53 id_, object_ptr<usernames> &&usernames_, int32 date_, object_ptr<ChatMemberStatus> &&status_, int32 member_count_, int32 boost_level_, bool has_automatic_translation_, bool has_linked_chat_, bool has_location_, bool sign_messages_, bool show_message_sender_, bool join_to_send_messages_, bool join_by_request_, bool is_slow_mode_enabled_, bool is_channel_, bool is_broadcast_group_, bool is_forum_, bool is_direct_messages_group_, bool is_administered_direct_messages_group_, object_ptr<verificationStatus> &&verification_status_, bool has_direct_messages_group_, bool has_forum_tabs_, object_ptr<restrictionInfo> &&restriction_info_, int53 paid_message_star_count_, object_ptr<ActiveStoryState> &&active_story_state_)
  : id_(id_)
  , usernames_(std::move(usernames_))
  , date_(date_)
  , status_(std::move(status_))
  , member_count_(member_count_)
  , boost_level_(boost_level_)
  , has_automatic_translation_(has_automatic_translation_)
  , has_linked_chat_(has_linked_chat_)
  , has_location_(has_location_)
  , sign_messages_(sign_messages_)
  , show_message_sender_(show_message_sender_)
  , join_to_send_messages_(join_to_send_messages_)
  , join_by_request_(join_by_request_)
  , is_slow_mode_enabled_(is_slow_mode_enabled_)
  , is_channel_(is_channel_)
  , is_broadcast_group_(is_broadcast_group_)
  , is_forum_(is_forum_)
  , is_direct_messages_group_(is_direct_messages_group_)
  , is_administered_direct_messages_group_(is_administered_direct_messages_group_)
  , verification_status_(std::move(verification_status_))
  , has_direct_messages_group_(has_direct_messages_group_)
  , has_forum_tabs_(has_forum_tabs_)
  , restriction_info_(std::move(restriction_info_))
  , paid_message_star_count_(paid_message_star_count_)
  , active_story_state_(std::move(active_story_state_))
{}

const std::int32_t supergroup::ID;

void supergroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroup");
    s.store_field("id", id_);
    s.store_object_field("usernames", static_cast<const BaseObject *>(usernames_.get()));
    s.store_field("date", date_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_field("member_count", member_count_);
    s.store_field("boost_level", boost_level_);
    s.store_field("has_automatic_translation", has_automatic_translation_);
    s.store_field("has_linked_chat", has_linked_chat_);
    s.store_field("has_location", has_location_);
    s.store_field("sign_messages", sign_messages_);
    s.store_field("show_message_sender", show_message_sender_);
    s.store_field("join_to_send_messages", join_to_send_messages_);
    s.store_field("join_by_request", join_by_request_);
    s.store_field("is_slow_mode_enabled", is_slow_mode_enabled_);
    s.store_field("is_channel", is_channel_);
    s.store_field("is_broadcast_group", is_broadcast_group_);
    s.store_field("is_forum", is_forum_);
    s.store_field("is_direct_messages_group", is_direct_messages_group_);
    s.store_field("is_administered_direct_messages_group", is_administered_direct_messages_group_);
    s.store_object_field("verification_status", static_cast<const BaseObject *>(verification_status_.get()));
    s.store_field("has_direct_messages_group", has_direct_messages_group_);
    s.store_field("has_forum_tabs", has_forum_tabs_);
    s.store_object_field("restriction_info", static_cast<const BaseObject *>(restriction_info_.get()));
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_object_field("active_story_state", static_cast<const BaseObject *>(active_story_state_.get()));
    s.store_class_end();
  }
}

tMeUrls::tMeUrls()
  : urls_()
{}

tMeUrls::tMeUrls(array<object_ptr<tMeUrl>> &&urls_)
  : urls_(std::move(urls_))
{}

const std::int32_t tMeUrls::ID;

void tMeUrls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tMeUrls");
    { s.store_vector_begin("urls", urls_.size()); for (const auto &_value : urls_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

testInt::testInt()
  : value_()
{}

testInt::testInt(int32 value_)
  : value_(value_)
{}

const std::int32_t testInt::ID;

void testInt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testInt");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

textCompositionStyle::textCompositionStyle()
  : name_()
  , custom_emoji_id_()
  , title_()
{}

textCompositionStyle::textCompositionStyle(string const &name_, int64 custom_emoji_id_, string const &title_)
  : name_(name_)
  , custom_emoji_id_(custom_emoji_id_)
  , title_(title_)
{}

const std::int32_t textCompositionStyle::ID;

void textCompositionStyle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textCompositionStyle");
    s.store_field("name", name_);
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

upgradedGiftBackdropColors::upgradedGiftBackdropColors()
  : center_color_()
  , edge_color_()
  , symbol_color_()
  , text_color_()
{}

upgradedGiftBackdropColors::upgradedGiftBackdropColors(int32 center_color_, int32 edge_color_, int32 symbol_color_, int32 text_color_)
  : center_color_(center_color_)
  , edge_color_(edge_color_)
  , symbol_color_(symbol_color_)
  , text_color_(text_color_)
{}

const std::int32_t upgradedGiftBackdropColors::ID;

void upgradedGiftBackdropColors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftBackdropColors");
    s.store_field("center_color", center_color_);
    s.store_field("edge_color", edge_color_);
    s.store_field("symbol_color", symbol_color_);
    s.store_field("text_color", text_color_);
    s.store_class_end();
  }
}

upgradedGiftModel::upgradedGiftModel()
  : name_()
  , sticker_()
  , rarity_()
  , is_crafted_()
{}

upgradedGiftModel::upgradedGiftModel(string const &name_, object_ptr<sticker> &&sticker_, object_ptr<UpgradedGiftAttributeRarity> &&rarity_, bool is_crafted_)
  : name_(name_)
  , sticker_(std::move(sticker_))
  , rarity_(std::move(rarity_))
  , is_crafted_(is_crafted_)
{}

const std::int32_t upgradedGiftModel::ID;

void upgradedGiftModel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftModel");
    s.store_field("name", name_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_object_field("rarity", static_cast<const BaseObject *>(rarity_.get()));
    s.store_field("is_crafted", is_crafted_);
    s.store_class_end();
  }
}

upgradedGiftSymbol::upgradedGiftSymbol()
  : name_()
  , sticker_()
  , rarity_()
{}

upgradedGiftSymbol::upgradedGiftSymbol(string const &name_, object_ptr<sticker> &&sticker_, object_ptr<UpgradedGiftAttributeRarity> &&rarity_)
  : name_(name_)
  , sticker_(std::move(sticker_))
  , rarity_(std::move(rarity_))
{}

const std::int32_t upgradedGiftSymbol::ID;

void upgradedGiftSymbol::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftSymbol");
    s.store_field("name", name_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_object_field("rarity", static_cast<const BaseObject *>(rarity_.get()));
    s.store_class_end();
  }
}

upgradedGiftValueInfo::upgradedGiftValueInfo()
  : currency_()
  , value_()
  , is_value_average_()
  , initial_sale_date_()
  , initial_sale_star_count_()
  , initial_sale_price_()
  , last_sale_date_()
  , last_sale_price_()
  , is_last_sale_on_fragment_()
  , minimum_price_()
  , average_sale_price_()
  , telegram_listed_gift_count_()
  , fragment_listed_gift_count_()
  , fragment_url_()
{}

upgradedGiftValueInfo::upgradedGiftValueInfo(string const &currency_, int53 value_, bool is_value_average_, int32 initial_sale_date_, int53 initial_sale_star_count_, int53 initial_sale_price_, int32 last_sale_date_, int53 last_sale_price_, bool is_last_sale_on_fragment_, int53 minimum_price_, int53 average_sale_price_, int32 telegram_listed_gift_count_, int32 fragment_listed_gift_count_, string const &fragment_url_)
  : currency_(currency_)
  , value_(value_)
  , is_value_average_(is_value_average_)
  , initial_sale_date_(initial_sale_date_)
  , initial_sale_star_count_(initial_sale_star_count_)
  , initial_sale_price_(initial_sale_price_)
  , last_sale_date_(last_sale_date_)
  , last_sale_price_(last_sale_price_)
  , is_last_sale_on_fragment_(is_last_sale_on_fragment_)
  , minimum_price_(minimum_price_)
  , average_sale_price_(average_sale_price_)
  , telegram_listed_gift_count_(telegram_listed_gift_count_)
  , fragment_listed_gift_count_(fragment_listed_gift_count_)
  , fragment_url_(fragment_url_)
{}

const std::int32_t upgradedGiftValueInfo::ID;

void upgradedGiftValueInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftValueInfo");
    s.store_field("currency", currency_);
    s.store_field("value", value_);
    s.store_field("is_value_average", is_value_average_);
    s.store_field("initial_sale_date", initial_sale_date_);
    s.store_field("initial_sale_star_count", initial_sale_star_count_);
    s.store_field("initial_sale_price", initial_sale_price_);
    s.store_field("last_sale_date", last_sale_date_);
    s.store_field("last_sale_price", last_sale_price_);
    s.store_field("is_last_sale_on_fragment", is_last_sale_on_fragment_);
    s.store_field("minimum_price", minimum_price_);
    s.store_field("average_sale_price", average_sale_price_);
    s.store_field("telegram_listed_gift_count", telegram_listed_gift_count_);
    s.store_field("fragment_listed_gift_count", fragment_listed_gift_count_);
    s.store_field("fragment_url", fragment_url_);
    s.store_class_end();
  }
}

userAuctionBid::userAuctionBid()
  : star_count_()
  , bid_date_()
  , next_bid_star_count_()
  , owner_id_()
  , was_returned_()
{}

userAuctionBid::userAuctionBid(int53 star_count_, int32 bid_date_, int53 next_bid_star_count_, object_ptr<MessageSender> &&owner_id_, bool was_returned_)
  : star_count_(star_count_)
  , bid_date_(bid_date_)
  , next_bid_star_count_(next_bid_star_count_)
  , owner_id_(std::move(owner_id_))
  , was_returned_(was_returned_)
{}

const std::int32_t userAuctionBid::ID;

void userAuctionBid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userAuctionBid");
    s.store_field("star_count", star_count_);
    s.store_field("bid_date", bid_date_);
    s.store_field("next_bid_star_count", next_bid_star_count_);
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("was_returned", was_returned_);
    s.store_class_end();
  }
}

userStatusEmpty::userStatusEmpty() {
}

const std::int32_t userStatusEmpty::ID;

void userStatusEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusEmpty");
    s.store_class_end();
  }
}

userStatusOnline::userStatusOnline()
  : expires_()
{}

userStatusOnline::userStatusOnline(int32 expires_)
  : expires_(expires_)
{}

const std::int32_t userStatusOnline::ID;

void userStatusOnline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusOnline");
    s.store_field("expires", expires_);
    s.store_class_end();
  }
}

userStatusOffline::userStatusOffline()
  : was_online_()
{}

userStatusOffline::userStatusOffline(int32 was_online_)
  : was_online_(was_online_)
{}

const std::int32_t userStatusOffline::ID;

void userStatusOffline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusOffline");
    s.store_field("was_online", was_online_);
    s.store_class_end();
  }
}

userStatusRecently::userStatusRecently()
  : by_my_privacy_settings_()
{}

userStatusRecently::userStatusRecently(bool by_my_privacy_settings_)
  : by_my_privacy_settings_(by_my_privacy_settings_)
{}

const std::int32_t userStatusRecently::ID;

void userStatusRecently::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusRecently");
    s.store_field("by_my_privacy_settings", by_my_privacy_settings_);
    s.store_class_end();
  }
}

userStatusLastWeek::userStatusLastWeek()
  : by_my_privacy_settings_()
{}

userStatusLastWeek::userStatusLastWeek(bool by_my_privacy_settings_)
  : by_my_privacy_settings_(by_my_privacy_settings_)
{}

const std::int32_t userStatusLastWeek::ID;

void userStatusLastWeek::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusLastWeek");
    s.store_field("by_my_privacy_settings", by_my_privacy_settings_);
    s.store_class_end();
  }
}

userStatusLastMonth::userStatusLastMonth()
  : by_my_privacy_settings_()
{}

userStatusLastMonth::userStatusLastMonth(bool by_my_privacy_settings_)
  : by_my_privacy_settings_(by_my_privacy_settings_)
{}

const std::int32_t userStatusLastMonth::ID;

void userStatusLastMonth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusLastMonth");
    s.store_field("by_my_privacy_settings", by_my_privacy_settings_);
    s.store_class_end();
  }
}

usernames::usernames()
  : active_usernames_()
  , disabled_usernames_()
  , editable_username_()
  , collectible_usernames_()
{}

usernames::usernames(array<string> &&active_usernames_, array<string> &&disabled_usernames_, string const &editable_username_, array<string> &&collectible_usernames_)
  : active_usernames_(std::move(active_usernames_))
  , disabled_usernames_(std::move(disabled_usernames_))
  , editable_username_(editable_username_)
  , collectible_usernames_(std::move(collectible_usernames_))
{}

const std::int32_t usernames::ID;

void usernames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "usernames");
    { s.store_vector_begin("active_usernames", active_usernames_.size()); for (const auto &_value : active_usernames_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("disabled_usernames", disabled_usernames_.size()); for (const auto &_value : disabled_usernames_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("editable_username", editable_username_);
    { s.store_vector_begin("collectible_usernames", collectible_usernames_.size()); for (const auto &_value : collectible_usernames_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

vectorPathCommandLine::vectorPathCommandLine()
  : end_point_()
{}

vectorPathCommandLine::vectorPathCommandLine(object_ptr<point> &&end_point_)
  : end_point_(std::move(end_point_))
{}

const std::int32_t vectorPathCommandLine::ID;

void vectorPathCommandLine::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "vectorPathCommandLine");
    s.store_object_field("end_point", static_cast<const BaseObject *>(end_point_.get()));
    s.store_class_end();
  }
}

vectorPathCommandCubicBezierCurve::vectorPathCommandCubicBezierCurve()
  : start_control_point_()
  , end_control_point_()
  , end_point_()
{}

vectorPathCommandCubicBezierCurve::vectorPathCommandCubicBezierCurve(object_ptr<point> &&start_control_point_, object_ptr<point> &&end_control_point_, object_ptr<point> &&end_point_)
  : start_control_point_(std::move(start_control_point_))
  , end_control_point_(std::move(end_control_point_))
  , end_point_(std::move(end_point_))
{}

const std::int32_t vectorPathCommandCubicBezierCurve::ID;

void vectorPathCommandCubicBezierCurve::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "vectorPathCommandCubicBezierCurve");
    s.store_object_field("start_control_point", static_cast<const BaseObject *>(start_control_point_.get()));
    s.store_object_field("end_control_point", static_cast<const BaseObject *>(end_control_point_.get()));
    s.store_object_field("end_point", static_cast<const BaseObject *>(end_point_.get()));
    s.store_class_end();
  }
}

videoMessageAdvertisement::videoMessageAdvertisement()
  : unique_id_()
  , text_()
  , min_display_duration_()
  , max_display_duration_()
  , can_be_reported_()
  , sponsor_()
  , title_()
  , additional_info_()
{}

videoMessageAdvertisement::videoMessageAdvertisement(int53 unique_id_, string const &text_, int32 min_display_duration_, int32 max_display_duration_, bool can_be_reported_, object_ptr<advertisementSponsor> &&sponsor_, string const &title_, string const &additional_info_)
  : unique_id_(unique_id_)
  , text_(text_)
  , min_display_duration_(min_display_duration_)
  , max_display_duration_(max_display_duration_)
  , can_be_reported_(can_be_reported_)
  , sponsor_(std::move(sponsor_))
  , title_(title_)
  , additional_info_(additional_info_)
{}

const std::int32_t videoMessageAdvertisement::ID;

void videoMessageAdvertisement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "videoMessageAdvertisement");
    s.store_field("unique_id", unique_id_);
    s.store_field("text", text_);
    s.store_field("min_display_duration", min_display_duration_);
    s.store_field("max_display_duration", max_display_duration_);
    s.store_field("can_be_reported", can_be_reported_);
    s.store_object_field("sponsor", static_cast<const BaseObject *>(sponsor_.get()));
    s.store_field("title", title_);
    s.store_field("additional_info", additional_info_);
    s.store_class_end();
  }
}

webAppInfo::webAppInfo()
  : launch_id_()
  , url_()
{}

webAppInfo::webAppInfo(int64 launch_id_, string const &url_)
  : launch_id_(launch_id_)
  , url_(url_)
{}

const std::int32_t webAppInfo::ID;

void webAppInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webAppInfo");
    s.store_field("launch_id", launch_id_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

activateStoryStealthMode::activateStoryStealthMode() {
}

const std::int32_t activateStoryStealthMode::ID;

void activateStoryStealthMode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "activateStoryStealthMode");
    s.store_class_end();
  }
}

addBotMediaPreview::addBotMediaPreview()
  : bot_user_id_()
  , language_code_()
  , content_()
{}

addBotMediaPreview::addBotMediaPreview(int53 bot_user_id_, string const &language_code_, object_ptr<InputStoryContent> &&content_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
  , content_(std::move(content_))
{}

const std::int32_t addBotMediaPreview::ID;

void addBotMediaPreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addBotMediaPreview");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_class_end();
  }
}

addLogMessage::addLogMessage()
  : verbosity_level_()
  , text_()
{}

addLogMessage::addLogMessage(int32 verbosity_level_, string const &text_)
  : verbosity_level_(verbosity_level_)
  , text_(text_)
{}

const std::int32_t addLogMessage::ID;

void addLogMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addLogMessage");
    s.store_field("verbosity_level", verbosity_level_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

addOffer::addOffer()
  : chat_id_()
  , message_id_()
  , options_()
{}

addOffer::addOffer(int53 chat_id_, int53 message_id_, object_ptr<messageSendOptions> &&options_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , options_(std::move(options_))
{}

const std::int32_t addOffer::ID;

void addOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addOffer");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("options", static_cast<const BaseObject *>(options_.get()));
    s.store_class_end();
  }
}

addQuickReplyShortcutMessage::addQuickReplyShortcutMessage()
  : shortcut_name_()
  , reply_to_message_id_()
  , input_message_content_()
{}

addQuickReplyShortcutMessage::addQuickReplyShortcutMessage(string const &shortcut_name_, int53 reply_to_message_id_, object_ptr<InputMessageContent> &&input_message_content_)
  : shortcut_name_(shortcut_name_)
  , reply_to_message_id_(reply_to_message_id_)
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t addQuickReplyShortcutMessage::ID;

void addQuickReplyShortcutMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addQuickReplyShortcutMessage");
    s.store_field("shortcut_name", shortcut_name_);
    s.store_field("reply_to_message_id", reply_to_message_id_);
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

addSavedNotificationSound::addSavedNotificationSound()
  : sound_()
{}

addSavedNotificationSound::addSavedNotificationSound(object_ptr<InputFile> &&sound_)
  : sound_(std::move(sound_))
{}

const std::int32_t addSavedNotificationSound::ID;

void addSavedNotificationSound::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addSavedNotificationSound");
    s.store_object_field("sound", static_cast<const BaseObject *>(sound_.get()));
    s.store_class_end();
  }
}

addStickerToSet::addStickerToSet()
  : user_id_()
  , name_()
  , sticker_()
{}

addStickerToSet::addStickerToSet(int53 user_id_, string const &name_, object_ptr<inputSticker> &&sticker_)
  : user_id_(user_id_)
  , name_(name_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t addStickerToSet::ID;

void addStickerToSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addStickerToSet");
    s.store_field("user_id", user_id_);
    s.store_field("name", name_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

boostChat::boostChat()
  : chat_id_()
  , slot_ids_()
{}

boostChat::boostChat(int53 chat_id_, array<int32> &&slot_ids_)
  : chat_id_(chat_id_)
  , slot_ids_(std::move(slot_ids_))
{}

const std::int32_t boostChat::ID;

void boostChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "boostChat");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("slot_ids", slot_ids_.size()); for (const auto &_value : slot_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

cancelDownloadFile::cancelDownloadFile()
  : file_id_()
  , only_if_pending_()
{}

cancelDownloadFile::cancelDownloadFile(int32 file_id_, bool only_if_pending_)
  : file_id_(file_id_)
  , only_if_pending_(only_if_pending_)
{}

const std::int32_t cancelDownloadFile::ID;

void cancelDownloadFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "cancelDownloadFile");
    s.store_field("file_id", file_id_);
    s.store_field("only_if_pending", only_if_pending_);
    s.store_class_end();
  }
}

checkPremiumGiftCode::checkPremiumGiftCode()
  : code_()
{}

checkPremiumGiftCode::checkPremiumGiftCode(string const &code_)
  : code_(code_)
{}

const std::int32_t checkPremiumGiftCode::ID;

void checkPremiumGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkPremiumGiftCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

createBusinessChatLink::createBusinessChatLink()
  : link_info_()
{}

createBusinessChatLink::createBusinessChatLink(object_ptr<inputBusinessChatLink> &&link_info_)
  : link_info_(std::move(link_info_))
{}

const std::int32_t createBusinessChatLink::ID;

void createBusinessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createBusinessChatLink");
    s.store_object_field("link_info", static_cast<const BaseObject *>(link_info_.get()));
    s.store_class_end();
  }
}

createTemporaryPassword::createTemporaryPassword()
  : password_()
  , valid_for_()
{}

createTemporaryPassword::createTemporaryPassword(string const &password_, int32 valid_for_)
  : password_(password_)
  , valid_for_(valid_for_)
{}

const std::int32_t createTemporaryPassword::ID;

void createTemporaryPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createTemporaryPassword");
    s.store_field("password", password_);
    s.store_field("valid_for", valid_for_);
    s.store_class_end();
  }
}

decryptGroupCallData::decryptGroupCallData()
  : group_call_id_()
  , participant_id_()
  , data_channel_()
  , data_()
{}

decryptGroupCallData::decryptGroupCallData(int32 group_call_id_, object_ptr<MessageSender> &&participant_id_, object_ptr<GroupCallDataChannel> &&data_channel_, bytes const &data_)
  : group_call_id_(group_call_id_)
  , participant_id_(std::move(participant_id_))
  , data_channel_(std::move(data_channel_))
  , data_(std::move(data_))
{}

const std::int32_t decryptGroupCallData::ID;

void decryptGroupCallData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "decryptGroupCallData");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_object_field("data_channel", static_cast<const BaseObject *>(data_channel_.get()));
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

deleteChat::deleteChat()
  : chat_id_()
{}

deleteChat::deleteChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t deleteChat::ID;

void deleteChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

deleteChatFolder::deleteChatFolder()
  : chat_folder_id_()
  , leave_chat_ids_()
{}

deleteChatFolder::deleteChatFolder(int32 chat_folder_id_, array<int53> &&leave_chat_ids_)
  : chat_folder_id_(chat_folder_id_)
  , leave_chat_ids_(std::move(leave_chat_ids_))
{}

const std::int32_t deleteChatFolder::ID;

void deleteChatFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChatFolder");
    s.store_field("chat_folder_id", chat_folder_id_);
    { s.store_vector_begin("leave_chat_ids", leave_chat_ids_.size()); for (const auto &_value : leave_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

deleteMessages::deleteMessages()
  : chat_id_()
  , message_ids_()
  , revoke_()
{}

deleteMessages::deleteMessages(int53 chat_id_, array<int53> &&message_ids_, bool revoke_)
  : chat_id_(chat_id_)
  , message_ids_(std::move(message_ids_))
  , revoke_(revoke_)
{}

const std::int32_t deleteMessages::ID;

void deleteMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteMessages");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("revoke", revoke_);
    s.store_class_end();
  }
}

deleteSavedOrderInfo::deleteSavedOrderInfo() {
}

const std::int32_t deleteSavedOrderInfo::ID;

void deleteSavedOrderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteSavedOrderInfo");
    s.store_class_end();
  }
}

disconnectWebsite::disconnectWebsite()
  : website_id_()
{}

disconnectWebsite::disconnectWebsite(int64 website_id_)
  : website_id_(website_id_)
{}

const std::int32_t disconnectWebsite::ID;

void disconnectWebsite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "disconnectWebsite");
    s.store_field("website_id", website_id_);
    s.store_class_end();
  }
}

editBusinessMessageReplyMarkup::editBusinessMessageReplyMarkup()
  : business_connection_id_()
  , chat_id_()
  , message_id_()
  , reply_markup_()
{}

editBusinessMessageReplyMarkup::editBusinessMessageReplyMarkup(string const &business_connection_id_, int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t editBusinessMessageReplyMarkup::ID;

void editBusinessMessageReplyMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editBusinessMessageReplyMarkup");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

getBackgroundUrl::getBackgroundUrl()
  : name_()
  , type_()
{}

getBackgroundUrl::getBackgroundUrl(string const &name_, object_ptr<BackgroundType> &&type_)
  : name_(name_)
  , type_(std::move(type_))
{}

const std::int32_t getBackgroundUrl::ID;

void getBackgroundUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBackgroundUrl");
    s.store_field("name", name_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

getBasicGroup::getBasicGroup()
  : basic_group_id_()
{}

getBasicGroup::getBasicGroup(int53 basic_group_id_)
  : basic_group_id_(basic_group_id_)
{}

const std::int32_t getBasicGroup::ID;

void getBasicGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBasicGroup");
    s.store_field("basic_group_id", basic_group_id_);
    s.store_class_end();
  }
}

getBasicGroupFullInfo::getBasicGroupFullInfo()
  : basic_group_id_()
{}

getBasicGroupFullInfo::getBasicGroupFullInfo(int53 basic_group_id_)
  : basic_group_id_(basic_group_id_)
{}

const std::int32_t getBasicGroupFullInfo::ID;

void getBasicGroupFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBasicGroupFullInfo");
    s.store_field("basic_group_id", basic_group_id_);
    s.store_class_end();
  }
}

getBotToken::getBotToken()
  : bot_user_id_()
  , revoke_()
{}

getBotToken::getBotToken(int53 bot_user_id_, bool revoke_)
  : bot_user_id_(bot_user_id_)
  , revoke_(revoke_)
{}

const std::int32_t getBotToken::ID;

void getBotToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBotToken");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("revoke", revoke_);
    s.store_class_end();
  }
}

getChatAvailableMessageSenders::getChatAvailableMessageSenders()
  : chat_id_()
{}

getChatAvailableMessageSenders::getChatAvailableMessageSenders(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatAvailableMessageSenders::ID;

void getChatAvailableMessageSenders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatAvailableMessageSenders");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatNotificationSettingsExceptions::getChatNotificationSettingsExceptions()
  : scope_()
  , compare_sound_()
{}

getChatNotificationSettingsExceptions::getChatNotificationSettingsExceptions(object_ptr<NotificationSettingsScope> &&scope_, bool compare_sound_)
  : scope_(std::move(scope_))
  , compare_sound_(compare_sound_)
{}

const std::int32_t getChatNotificationSettingsExceptions::ID;

void getChatNotificationSettingsExceptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatNotificationSettingsExceptions");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_field("compare_sound", compare_sound_);
    s.store_class_end();
  }
}

getChatPinnedMessage::getChatPinnedMessage()
  : chat_id_()
{}

getChatPinnedMessage::getChatPinnedMessage(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatPinnedMessage::ID;

void getChatPinnedMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatPinnedMessage");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatSparseMessagePositions::getChatSparseMessagePositions()
  : chat_id_()
  , filter_()
  , from_message_id_()
  , limit_()
  , saved_messages_topic_id_()
{}

getChatSparseMessagePositions::getChatSparseMessagePositions(int53 chat_id_, object_ptr<SearchMessagesFilter> &&filter_, int53 from_message_id_, int32 limit_, int53 saved_messages_topic_id_)
  : chat_id_(chat_id_)
  , filter_(std::move(filter_))
  , from_message_id_(from_message_id_)
  , limit_(limit_)
  , saved_messages_topic_id_(saved_messages_topic_id_)
{}

const std::int32_t getChatSparseMessagePositions::ID;

void getChatSparseMessagePositions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatSparseMessagePositions");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("from_message_id", from_message_id_);
    s.store_field("limit", limit_);
    s.store_field("saved_messages_topic_id", saved_messages_topic_id_);
    s.store_class_end();
  }
}

getForumTopicHistory::getForumTopicHistory()
  : chat_id_()
  , forum_topic_id_()
  , from_message_id_()
  , offset_()
  , limit_()
{}

getForumTopicHistory::getForumTopicHistory(int53 chat_id_, int32 forum_topic_id_, int53 from_message_id_, int32 offset_, int32 limit_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
  , from_message_id_(from_message_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getForumTopicHistory::ID;

void getForumTopicHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getForumTopicHistory");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_field("from_message_id", from_message_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getGiftUpgradePreview::getGiftUpgradePreview()
  : regular_gift_id_()
{}

getGiftUpgradePreview::getGiftUpgradePreview(int64 regular_gift_id_)
  : regular_gift_id_(regular_gift_id_)
{}

const std::int32_t getGiftUpgradePreview::ID;

void getGiftUpgradePreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGiftUpgradePreview");
    s.store_field("regular_gift_id", regular_gift_id_);
    s.store_class_end();
  }
}

getJsonString::getJsonString()
  : json_value_()
{}

getJsonString::getJsonString(object_ptr<JsonValue> &&json_value_)
  : json_value_(std::move(json_value_))
{}

const std::int32_t getJsonString::ID;

void getJsonString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getJsonString");
    s.store_object_field("json_value", static_cast<const BaseObject *>(json_value_.get()));
    s.store_class_end();
  }
}

getLoginPasskeys::getLoginPasskeys() {
}

const std::int32_t getLoginPasskeys::ID;

void getLoginPasskeys::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLoginPasskeys");
    s.store_class_end();
  }
}

getOption::getOption()
  : name_()
{}

getOption::getOption(string const &name_)
  : name_(name_)
{}

const std::int32_t getOption::ID;

void getOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getOption");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

getPaidMessageRevenue::getPaidMessageRevenue()
  : user_id_()
{}

getPaidMessageRevenue::getPaidMessageRevenue(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t getPaidMessageRevenue::ID;

void getPaidMessageRevenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPaidMessageRevenue");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getPaymentForm::getPaymentForm()
  : input_invoice_()
  , theme_()
{}

getPaymentForm::getPaymentForm(object_ptr<InputInvoice> &&input_invoice_, object_ptr<themeParameters> &&theme_)
  : input_invoice_(std::move(input_invoice_))
  , theme_(std::move(theme_))
{}

const std::int32_t getPaymentForm::ID;

void getPaymentForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPaymentForm");
    s.store_object_field("input_invoice", static_cast<const BaseObject *>(input_invoice_.get()));
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

getPollVoters::getPollVoters()
  : chat_id_()
  , message_id_()
  , option_id_()
  , offset_()
  , limit_()
{}

getPollVoters::getPollVoters(int53 chat_id_, int53 message_id_, int32 option_id_, int32 offset_, int32 limit_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , option_id_(option_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getPollVoters::ID;

void getPollVoters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPollVoters");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("option_id", option_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getPreferredCountryLanguage::getPreferredCountryLanguage()
  : country_code_()
{}

getPreferredCountryLanguage::getPreferredCountryLanguage(string const &country_code_)
  : country_code_(country_code_)
{}

const std::int32_t getPreferredCountryLanguage::ID;

void getPreferredCountryLanguage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPreferredCountryLanguage");
    s.store_field("country_code", country_code_);
    s.store_class_end();
  }
}

getPremiumInfoSticker::getPremiumInfoSticker()
  : month_count_()
{}

getPremiumInfoSticker::getPremiumInfoSticker(int32 month_count_)
  : month_count_(month_count_)
{}

const std::int32_t getPremiumInfoSticker::ID;

void getPremiumInfoSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPremiumInfoSticker");
    s.store_field("month_count", month_count_);
    s.store_class_end();
  }
}

getPremiumLimit::getPremiumLimit()
  : limit_type_()
{}

getPremiumLimit::getPremiumLimit(object_ptr<PremiumLimitType> &&limit_type_)
  : limit_type_(std::move(limit_type_))
{}

const std::int32_t getPremiumLimit::ID;

void getPremiumLimit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPremiumLimit");
    s.store_object_field("limit_type", static_cast<const BaseObject *>(limit_type_.get()));
    s.store_class_end();
  }
}

getReceivedGift::getReceivedGift()
  : received_gift_id_()
{}

getReceivedGift::getReceivedGift(string const &received_gift_id_)
  : received_gift_id_(received_gift_id_)
{}

const std::int32_t getReceivedGift::ID;

void getReceivedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getReceivedGift");
    s.store_field("received_gift_id", received_gift_id_);
    s.store_class_end();
  }
}

getRecoveryEmailAddress::getRecoveryEmailAddress()
  : password_()
{}

getRecoveryEmailAddress::getRecoveryEmailAddress(string const &password_)
  : password_(password_)
{}

const std::int32_t getRecoveryEmailAddress::ID;

void getRecoveryEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecoveryEmailAddress");
    s.store_field("password", password_);
    s.store_class_end();
  }
}

getSavedMessagesTopicMessageByDate::getSavedMessagesTopicMessageByDate()
  : saved_messages_topic_id_()
  , date_()
{}

getSavedMessagesTopicMessageByDate::getSavedMessagesTopicMessageByDate(int53 saved_messages_topic_id_, int32 date_)
  : saved_messages_topic_id_(saved_messages_topic_id_)
  , date_(date_)
{}

const std::int32_t getSavedMessagesTopicMessageByDate::ID;

void getSavedMessagesTopicMessageByDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSavedMessagesTopicMessageByDate");
    s.store_field("saved_messages_topic_id", saved_messages_topic_id_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

getStakeDiceState::getStakeDiceState() {
}

const std::int32_t getStakeDiceState::ID;

void getStakeDiceState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStakeDiceState");
    s.store_class_end();
  }
}

getStarRevenueStatistics::getStarRevenueStatistics()
  : owner_id_()
  , is_dark_()
{}

getStarRevenueStatistics::getStarRevenueStatistics(object_ptr<MessageSender> &&owner_id_, bool is_dark_)
  : owner_id_(std::move(owner_id_))
  , is_dark_(is_dark_)
{}

const std::int32_t getStarRevenueStatistics::ID;

void getStarRevenueStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStarRevenueStatistics");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("is_dark", is_dark_);
    s.store_class_end();
  }
}

getStickerOutlineSvgPath::getStickerOutlineSvgPath()
  : sticker_file_id_()
  , for_animated_emoji_()
  , for_clicked_animated_emoji_message_()
{}

getStickerOutlineSvgPath::getStickerOutlineSvgPath(int32 sticker_file_id_, bool for_animated_emoji_, bool for_clicked_animated_emoji_message_)
  : sticker_file_id_(sticker_file_id_)
  , for_animated_emoji_(for_animated_emoji_)
  , for_clicked_animated_emoji_message_(for_clicked_animated_emoji_message_)
{}

const std::int32_t getStickerOutlineSvgPath::ID;

void getStickerOutlineSvgPath::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStickerOutlineSvgPath");
    s.store_field("sticker_file_id", sticker_file_id_);
    s.store_field("for_animated_emoji", for_animated_emoji_);
    s.store_field("for_clicked_animated_emoji_message", for_clicked_animated_emoji_message_);
    s.store_class_end();
  }
}

getStorageStatistics::getStorageStatistics()
  : chat_limit_()
{}

getStorageStatistics::getStorageStatistics(int32 chat_limit_)
  : chat_limit_(chat_limit_)
{}

const std::int32_t getStorageStatistics::ID;

void getStorageStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStorageStatistics");
    s.store_field("chat_limit", chat_limit_);
    s.store_class_end();
  }
}

getStoryInteractions::getStoryInteractions()
  : story_id_()
  , query_()
  , only_contacts_()
  , prefer_forwards_()
  , prefer_with_reaction_()
  , offset_()
  , limit_()
{}

getStoryInteractions::getStoryInteractions(int32 story_id_, string const &query_, bool only_contacts_, bool prefer_forwards_, bool prefer_with_reaction_, string const &offset_, int32 limit_)
  : story_id_(story_id_)
  , query_(query_)
  , only_contacts_(only_contacts_)
  , prefer_forwards_(prefer_forwards_)
  , prefer_with_reaction_(prefer_with_reaction_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getStoryInteractions::ID;

void getStoryInteractions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStoryInteractions");
    s.store_field("story_id", story_id_);
    s.store_field("query", query_);
    s.store_field("only_contacts", only_contacts_);
    s.store_field("prefer_forwards", prefer_forwards_);
    s.store_field("prefer_with_reaction", prefer_with_reaction_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getStoryNotificationSettingsExceptions::getStoryNotificationSettingsExceptions() {
}

const std::int32_t getStoryNotificationSettingsExceptions::ID;

void getStoryNotificationSettingsExceptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStoryNotificationSettingsExceptions");
    s.store_class_end();
  }
}

getSuitableDiscussionChats::getSuitableDiscussionChats() {
}

const std::int32_t getSuitableDiscussionChats::ID;

void getSuitableDiscussionChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSuitableDiscussionChats");
    s.store_class_end();
  }
}

getTemporaryPasswordState::getTemporaryPasswordState() {
}

const std::int32_t getTemporaryPasswordState::ID;

void getTemporaryPasswordState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTemporaryPasswordState");
    s.store_class_end();
  }
}

getTrendingStickerSets::getTrendingStickerSets()
  : sticker_type_()
  , offset_()
  , limit_()
{}

getTrendingStickerSets::getTrendingStickerSets(object_ptr<StickerType> &&sticker_type_, int32 offset_, int32 limit_)
  : sticker_type_(std::move(sticker_type_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getTrendingStickerSets::ID;

void getTrendingStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTrendingStickerSets");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getUser::getUser()
  : user_id_()
{}

getUser::getUser(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t getUser::ID;

void getUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUser");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getUserLink::getUserLink() {
}

const std::int32_t getUserLink::ID;

void getUserLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUserLink");
    s.store_class_end();
  }
}

inviteGroupCallParticipant::inviteGroupCallParticipant()
  : group_call_id_()
  , user_id_()
  , is_video_()
{}

inviteGroupCallParticipant::inviteGroupCallParticipant(int32 group_call_id_, int53 user_id_, bool is_video_)
  : group_call_id_(group_call_id_)
  , user_id_(user_id_)
  , is_video_(is_video_)
{}

const std::int32_t inviteGroupCallParticipant::ID;

void inviteGroupCallParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inviteGroupCallParticipant");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("user_id", user_id_);
    s.store_field("is_video", is_video_);
    s.store_class_end();
  }
}

loadQuickReplyShortcuts::loadQuickReplyShortcuts() {
}

const std::int32_t loadQuickReplyShortcuts::ID;

void loadQuickReplyShortcuts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loadQuickReplyShortcuts");
    s.store_class_end();
  }
}

readFilePart::readFilePart()
  : file_id_()
  , offset_()
  , count_()
{}

readFilePart::readFilePart(int32 file_id_, int53 offset_, int53 count_)
  : file_id_(file_id_)
  , offset_(offset_)
  , count_(count_)
{}

const std::int32_t readFilePart::ID;

void readFilePart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readFilePart");
    s.store_field("file_id", file_id_);
    s.store_field("offset", offset_);
    s.store_field("count", count_);
    s.store_class_end();
  }
}

recoverAuthenticationPassword::recoverAuthenticationPassword()
  : recovery_code_()
  , new_password_()
  , new_hint_()
{}

recoverAuthenticationPassword::recoverAuthenticationPassword(string const &recovery_code_, string const &new_password_, string const &new_hint_)
  : recovery_code_(recovery_code_)
  , new_password_(new_password_)
  , new_hint_(new_hint_)
{}

const std::int32_t recoverAuthenticationPassword::ID;

void recoverAuthenticationPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recoverAuthenticationPassword");
    s.store_field("recovery_code", recovery_code_);
    s.store_field("new_password", new_password_);
    s.store_field("new_hint", new_hint_);
    s.store_class_end();
  }
}

removeContacts::removeContacts()
  : user_ids_()
{}

removeContacts::removeContacts(array<int53> &&user_ids_)
  : user_ids_(std::move(user_ids_))
{}

const std::int32_t removeContacts::ID;

void removeContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeContacts");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

removeMessageReaction::removeMessageReaction()
  : chat_id_()
  , message_id_()
  , reaction_type_()
{}

removeMessageReaction::removeMessageReaction(int53 chat_id_, int53 message_id_, object_ptr<ReactionType> &&reaction_type_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reaction_type_(std::move(reaction_type_))
{}

const std::int32_t removeMessageReaction::ID;

void removeMessageReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeMessageReaction");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reaction_type", static_cast<const BaseObject *>(reaction_type_.get()));
    s.store_class_end();
  }
}

removeSavedNotificationSound::removeSavedNotificationSound()
  : notification_sound_id_()
{}

removeSavedNotificationSound::removeSavedNotificationSound(int64 notification_sound_id_)
  : notification_sound_id_(notification_sound_id_)
{}

const std::int32_t removeSavedNotificationSound::ID;

void removeSavedNotificationSound::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeSavedNotificationSound");
    s.store_field("notification_sound_id", notification_sound_id_);
    s.store_class_end();
  }
}

removeStoryAlbumStories::removeStoryAlbumStories()
  : chat_id_()
  , story_album_id_()
  , story_ids_()
{}

removeStoryAlbumStories::removeStoryAlbumStories(int53 chat_id_, int32 story_album_id_, array<int32> &&story_ids_)
  : chat_id_(chat_id_)
  , story_album_id_(story_album_id_)
  , story_ids_(std::move(story_ids_))
{}

const std::int32_t removeStoryAlbumStories::ID;

void removeStoryAlbumStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeStoryAlbumStories");
    s.store_field("chat_id", chat_id_);
    s.store_field("story_album_id", story_album_id_);
    { s.store_vector_begin("story_ids", story_ids_.size()); for (const auto &_value : story_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

reorderGiftCollectionGifts::reorderGiftCollectionGifts()
  : owner_id_()
  , collection_id_()
  , received_gift_ids_()
{}

reorderGiftCollectionGifts::reorderGiftCollectionGifts(object_ptr<MessageSender> &&owner_id_, int32 collection_id_, array<string> &&received_gift_ids_)
  : owner_id_(std::move(owner_id_))
  , collection_id_(collection_id_)
  , received_gift_ids_(std::move(received_gift_ids_))
{}

const std::int32_t reorderGiftCollectionGifts::ID;

void reorderGiftCollectionGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderGiftCollectionGifts");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("collection_id", collection_id_);
    { s.store_vector_begin("received_gift_ids", received_gift_ids_.size()); for (const auto &_value : received_gift_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

reorderStoryAlbums::reorderStoryAlbums()
  : chat_id_()
  , story_album_ids_()
{}

reorderStoryAlbums::reorderStoryAlbums(int53 chat_id_, array<int32> &&story_album_ids_)
  : chat_id_(chat_id_)
  , story_album_ids_(std::move(story_album_ids_))
{}

const std::int32_t reorderStoryAlbums::ID;

void reorderStoryAlbums::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderStoryAlbums");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("story_album_ids", story_album_ids_.size()); for (const auto &_value : story_album_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

replaceLiveStoryRtmpUrl::replaceLiveStoryRtmpUrl()
  : chat_id_()
{}

replaceLiveStoryRtmpUrl::replaceLiveStoryRtmpUrl(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t replaceLiveStoryRtmpUrl::ID;

void replaceLiveStoryRtmpUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replaceLiveStoryRtmpUrl");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

reportSupergroupAntiSpamFalsePositive::reportSupergroupAntiSpamFalsePositive()
  : supergroup_id_()
  , message_id_()
{}

reportSupergroupAntiSpamFalsePositive::reportSupergroupAntiSpamFalsePositive(int53 supergroup_id_, int53 message_id_)
  : supergroup_id_(supergroup_id_)
  , message_id_(message_id_)
{}

const std::int32_t reportSupergroupAntiSpamFalsePositive::ID;

void reportSupergroupAntiSpamFalsePositive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportSupergroupAntiSpamFalsePositive");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

resendPhoneNumberCode::resendPhoneNumberCode()
  : reason_()
{}

resendPhoneNumberCode::resendPhoneNumberCode(object_ptr<ResendCodeReason> &&reason_)
  : reason_(std::move(reason_))
{}

const std::int32_t resendPhoneNumberCode::ID;

void resendPhoneNumberCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendPhoneNumberCode");
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_class_end();
  }
}

saveApplicationLogEvent::saveApplicationLogEvent()
  : type_()
  , chat_id_()
  , data_()
{}

saveApplicationLogEvent::saveApplicationLogEvent(string const &type_, int53 chat_id_, object_ptr<JsonValue> &&data_)
  : type_(type_)
  , chat_id_(chat_id_)
  , data_(std::move(data_))
{}

const std::int32_t saveApplicationLogEvent::ID;

void saveApplicationLogEvent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "saveApplicationLogEvent");
    s.store_field("type", type_);
    s.store_field("chat_id", chat_id_);
    s.store_object_field("data", static_cast<const BaseObject *>(data_.get()));
    s.store_class_end();
  }
}

searchCallMessages::searchCallMessages()
  : offset_()
  , limit_()
  , only_missed_()
{}

searchCallMessages::searchCallMessages(string const &offset_, int32 limit_, bool only_missed_)
  : offset_(offset_)
  , limit_(limit_)
  , only_missed_(only_missed_)
{}

const std::int32_t searchCallMessages::ID;

void searchCallMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchCallMessages");
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("only_missed", only_missed_);
    s.store_class_end();
  }
}

searchEmojis::searchEmojis()
  : text_()
  , input_language_codes_()
{}

searchEmojis::searchEmojis(string const &text_, array<string> &&input_language_codes_)
  : text_(text_)
  , input_language_codes_(std::move(input_language_codes_))
{}

const std::int32_t searchEmojis::ID;

void searchEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchEmojis");
    s.store_field("text", text_);
    { s.store_vector_begin("input_language_codes", input_language_codes_.size()); for (const auto &_value : input_language_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

searchMessages::searchMessages()
  : chat_list_()
  , query_()
  , offset_()
  , limit_()
  , filter_()
  , chat_type_filter_()
  , min_date_()
  , max_date_()
{}

searchMessages::searchMessages(object_ptr<ChatList> &&chat_list_, string const &query_, string const &offset_, int32 limit_, object_ptr<SearchMessagesFilter> &&filter_, object_ptr<SearchMessagesChatTypeFilter> &&chat_type_filter_, int32 min_date_, int32 max_date_)
  : chat_list_(std::move(chat_list_))
  , query_(query_)
  , offset_(offset_)
  , limit_(limit_)
  , filter_(std::move(filter_))
  , chat_type_filter_(std::move(chat_type_filter_))
  , min_date_(min_date_)
  , max_date_(max_date_)
{}

const std::int32_t searchMessages::ID;

void searchMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessages");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_field("query", query_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_object_field("chat_type_filter", static_cast<const BaseObject *>(chat_type_filter_.get()));
    s.store_field("min_date", min_date_);
    s.store_field("max_date", max_date_);
    s.store_class_end();
  }
}

searchPublicChat::searchPublicChat()
  : username_()
{}

searchPublicChat::searchPublicChat(string const &username_)
  : username_(username_)
{}

const std::int32_t searchPublicChat::ID;

void searchPublicChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchPublicChat");
    s.store_field("username", username_);
    s.store_class_end();
  }
}

searchPublicStoriesByVenue::searchPublicStoriesByVenue()
  : venue_provider_()
  , venue_id_()
  , offset_()
  , limit_()
{}

searchPublicStoriesByVenue::searchPublicStoriesByVenue(string const &venue_provider_, string const &venue_id_, string const &offset_, int32 limit_)
  : venue_provider_(venue_provider_)
  , venue_id_(venue_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t searchPublicStoriesByVenue::ID;

void searchPublicStoriesByVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchPublicStoriesByVenue");
    s.store_field("venue_provider", venue_provider_);
    s.store_field("venue_id", venue_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchUserByPhoneNumber::searchUserByPhoneNumber()
  : phone_number_()
  , only_local_()
{}

searchUserByPhoneNumber::searchUserByPhoneNumber(string const &phone_number_, bool only_local_)
  : phone_number_(phone_number_)
  , only_local_(only_local_)
{}

const std::int32_t searchUserByPhoneNumber::ID;

void searchUserByPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchUserByPhoneNumber");
    s.store_field("phone_number", phone_number_);
    s.store_field("only_local", only_local_);
    s.store_class_end();
  }
}

sellGift::sellGift()
  : business_connection_id_()
  , received_gift_id_()
{}

sellGift::sellGift(string const &business_connection_id_, string const &received_gift_id_)
  : business_connection_id_(business_connection_id_)
  , received_gift_id_(received_gift_id_)
{}

const std::int32_t sellGift::ID;

void sellGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sellGift");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("received_gift_id", received_gift_id_);
    s.store_class_end();
  }
}

sendBotStartMessage::sendBotStartMessage()
  : bot_user_id_()
  , chat_id_()
  , parameter_()
{}

sendBotStartMessage::sendBotStartMessage(int53 bot_user_id_, int53 chat_id_, string const &parameter_)
  : bot_user_id_(bot_user_id_)
  , chat_id_(chat_id_)
  , parameter_(parameter_)
{}

const std::int32_t sendBotStartMessage::ID;

void sendBotStartMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendBotStartMessage");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("parameter", parameter_);
    s.store_class_end();
  }
}

sendCustomRequest::sendCustomRequest()
  : method_()
  , parameters_()
{}

sendCustomRequest::sendCustomRequest(string const &method_, string const &parameters_)
  : method_(method_)
  , parameters_(parameters_)
{}

const std::int32_t sendCustomRequest::ID;

void sendCustomRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendCustomRequest");
    s.store_field("method", method_);
    s.store_field("parameters", parameters_);
    s.store_class_end();
  }
}

sendGift::sendGift()
  : gift_id_()
  , owner_id_()
  , text_()
  , is_private_()
  , pay_for_upgrade_()
{}

sendGift::sendGift(int64 gift_id_, object_ptr<MessageSender> &&owner_id_, object_ptr<formattedText> &&text_, bool is_private_, bool pay_for_upgrade_)
  : gift_id_(gift_id_)
  , owner_id_(std::move(owner_id_))
  , text_(std::move(text_))
  , is_private_(is_private_)
  , pay_for_upgrade_(pay_for_upgrade_)
{}

const std::int32_t sendGift::ID;

void sendGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendGift");
    s.store_field("gift_id", gift_id_);
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("is_private", is_private_);
    s.store_field("pay_for_upgrade", pay_for_upgrade_);
    s.store_class_end();
  }
}

sendInlineQueryResultMessage::sendInlineQueryResultMessage()
  : chat_id_()
  , topic_id_()
  , reply_to_()
  , options_()
  , query_id_()
  , result_id_()
  , hide_via_bot_()
{}

sendInlineQueryResultMessage::sendInlineQueryResultMessage(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, object_ptr<InputMessageReplyTo> &&reply_to_, object_ptr<messageSendOptions> &&options_, int64 query_id_, string const &result_id_, bool hide_via_bot_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , reply_to_(std::move(reply_to_))
  , options_(std::move(options_))
  , query_id_(query_id_)
  , result_id_(result_id_)
  , hide_via_bot_(hide_via_bot_)
{}

const std::int32_t sendInlineQueryResultMessage::ID;

void sendInlineQueryResultMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendInlineQueryResultMessage");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_object_field("options", static_cast<const BaseObject *>(options_.get()));
    s.store_field("query_id", query_id_);
    s.store_field("result_id", result_id_);
    s.store_field("hide_via_bot", hide_via_bot_);
    s.store_class_end();
  }
}

sendTextMessageDraft::sendTextMessageDraft()
  : chat_id_()
  , forum_topic_id_()
  , draft_id_()
  , text_()
{}

sendTextMessageDraft::sendTextMessageDraft(int53 chat_id_, int32 forum_topic_id_, int64 draft_id_, object_ptr<formattedText> &&text_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
  , draft_id_(draft_id_)
  , text_(std::move(text_))
{}

const std::int32_t sendTextMessageDraft::ID;

void sendTextMessageDraft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendTextMessageDraft");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_field("draft_id", draft_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

setBotInfoShortDescription::setBotInfoShortDescription()
  : bot_user_id_()
  , language_code_()
  , short_description_()
{}

setBotInfoShortDescription::setBotInfoShortDescription(int53 bot_user_id_, string const &language_code_, string const &short_description_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
  , short_description_(short_description_)
{}

const std::int32_t setBotInfoShortDescription::ID;

void setBotInfoShortDescription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBotInfoShortDescription");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    s.store_field("short_description", short_description_);
    s.store_class_end();
  }
}

setBusinessConnectedBot::setBusinessConnectedBot()
  : bot_()
{}

setBusinessConnectedBot::setBusinessConnectedBot(object_ptr<businessConnectedBot> &&bot_)
  : bot_(std::move(bot_))
{}

const std::int32_t setBusinessConnectedBot::ID;

void setBusinessConnectedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessConnectedBot");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_class_end();
  }
}

setChatDiscussionGroup::setChatDiscussionGroup()
  : chat_id_()
  , discussion_chat_id_()
{}

setChatDiscussionGroup::setChatDiscussionGroup(int53 chat_id_, int53 discussion_chat_id_)
  : chat_id_(chat_id_)
  , discussion_chat_id_(discussion_chat_id_)
{}

const std::int32_t setChatDiscussionGroup::ID;

void setChatDiscussionGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatDiscussionGroup");
    s.store_field("chat_id", chat_id_);
    s.store_field("discussion_chat_id", discussion_chat_id_);
    s.store_class_end();
  }
}

setChatTitle::setChatTitle()
  : chat_id_()
  , title_()
{}

setChatTitle::setChatTitle(int53 chat_id_, string const &title_)
  : chat_id_(chat_id_)
  , title_(title_)
{}

const std::int32_t setChatTitle::ID;

void setChatTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatTitle");
    s.store_field("chat_id", chat_id_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

setCustomLanguagePackString::setCustomLanguagePackString()
  : language_pack_id_()
  , new_string_()
{}

setCustomLanguagePackString::setCustomLanguagePackString(string const &language_pack_id_, object_ptr<languagePackString> &&new_string_)
  : language_pack_id_(language_pack_id_)
  , new_string_(std::move(new_string_))
{}

const std::int32_t setCustomLanguagePackString::ID;

void setCustomLanguagePackString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setCustomLanguagePackString");
    s.store_field("language_pack_id", language_pack_id_);
    s.store_object_field("new_string", static_cast<const BaseObject *>(new_string_.get()));
    s.store_class_end();
  }
}

setDirectMessagesChatTopicIsMarkedAsUnread::setDirectMessagesChatTopicIsMarkedAsUnread()
  : chat_id_()
  , topic_id_()
  , is_marked_as_unread_()
{}

setDirectMessagesChatTopicIsMarkedAsUnread::setDirectMessagesChatTopicIsMarkedAsUnread(int53 chat_id_, int53 topic_id_, bool is_marked_as_unread_)
  : chat_id_(chat_id_)
  , topic_id_(topic_id_)
  , is_marked_as_unread_(is_marked_as_unread_)
{}

const std::int32_t setDirectMessagesChatTopicIsMarkedAsUnread::ID;

void setDirectMessagesChatTopicIsMarkedAsUnread::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setDirectMessagesChatTopicIsMarkedAsUnread");
    s.store_field("chat_id", chat_id_);
    s.store_field("topic_id", topic_id_);
    s.store_field("is_marked_as_unread", is_marked_as_unread_);
    s.store_class_end();
  }
}

setForumTopicNotificationSettings::setForumTopicNotificationSettings()
  : chat_id_()
  , forum_topic_id_()
  , notification_settings_()
{}

setForumTopicNotificationSettings::setForumTopicNotificationSettings(int53 chat_id_, int32 forum_topic_id_, object_ptr<chatNotificationSettings> &&notification_settings_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
  , notification_settings_(std::move(notification_settings_))
{}

const std::int32_t setForumTopicNotificationSettings::ID;

void setForumTopicNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setForumTopicNotificationSettings");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_class_end();
  }
}

setGameScore::setGameScore()
  : chat_id_()
  , message_id_()
  , edit_message_()
  , user_id_()
  , score_()
  , force_()
{}

setGameScore::setGameScore(int53 chat_id_, int53 message_id_, bool edit_message_, int53 user_id_, int32 score_, bool force_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , edit_message_(edit_message_)
  , user_id_(user_id_)
  , score_(score_)
  , force_(force_)
{}

const std::int32_t setGameScore::ID;

void setGameScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setGameScore");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("edit_message", edit_message_);
    s.store_field("user_id", user_id_);
    s.store_field("score", score_);
    s.store_field("force", force_);
    s.store_class_end();
  }
}

setMainProfileTab::setMainProfileTab()
  : main_profile_tab_()
{}

setMainProfileTab::setMainProfileTab(object_ptr<ProfileTab> &&main_profile_tab_)
  : main_profile_tab_(std::move(main_profile_tab_))
{}

const std::int32_t setMainProfileTab::ID;

void setMainProfileTab::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setMainProfileTab");
    s.store_object_field("main_profile_tab", static_cast<const BaseObject *>(main_profile_tab_.get()));
    s.store_class_end();
  }
}

setStickerKeywords::setStickerKeywords()
  : sticker_()
  , keywords_()
{}

setStickerKeywords::setStickerKeywords(object_ptr<InputFile> &&sticker_, array<string> &&keywords_)
  : sticker_(std::move(sticker_))
  , keywords_(std::move(keywords_))
{}

const std::int32_t setStickerKeywords::ID;

void setStickerKeywords::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setStickerKeywords");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    { s.store_vector_begin("keywords", keywords_.size()); for (const auto &_value : keywords_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

setStickerMaskPosition::setStickerMaskPosition()
  : sticker_()
  , mask_position_()
{}

setStickerMaskPosition::setStickerMaskPosition(object_ptr<InputFile> &&sticker_, object_ptr<maskPosition> &&mask_position_)
  : sticker_(std::move(sticker_))
  , mask_position_(std::move(mask_position_))
{}

const std::int32_t setStickerMaskPosition::ID;

void setStickerMaskPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setStickerMaskPosition");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_object_field("mask_position", static_cast<const BaseObject *>(mask_position_.get()));
    s.store_class_end();
  }
}

setStickerSetThumbnail::setStickerSetThumbnail()
  : user_id_()
  , name_()
  , thumbnail_()
  , format_()
{}

setStickerSetThumbnail::setStickerSetThumbnail(int53 user_id_, string const &name_, object_ptr<InputFile> &&thumbnail_, object_ptr<StickerFormat> &&format_)
  : user_id_(user_id_)
  , name_(name_)
  , thumbnail_(std::move(thumbnail_))
  , format_(std::move(format_))
{}

const std::int32_t setStickerSetThumbnail::ID;

void setStickerSetThumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setStickerSetThumbnail");
    s.store_field("user_id", user_id_);
    s.store_field("name", name_);
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("format", static_cast<const BaseObject *>(format_.get()));
    s.store_class_end();
  }
}

setUserPersonalProfilePhoto::setUserPersonalProfilePhoto()
  : user_id_()
  , photo_()
{}

setUserPersonalProfilePhoto::setUserPersonalProfilePhoto(int53 user_id_, object_ptr<InputChatPhoto> &&photo_)
  : user_id_(user_id_)
  , photo_(std::move(photo_))
{}

const std::int32_t setUserPersonalProfilePhoto::ID;

void setUserPersonalProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setUserPersonalProfilePhoto");
    s.store_field("user_id", user_id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

setVideoChatDefaultParticipant::setVideoChatDefaultParticipant()
  : chat_id_()
  , default_participant_id_()
{}

setVideoChatDefaultParticipant::setVideoChatDefaultParticipant(int53 chat_id_, object_ptr<MessageSender> &&default_participant_id_)
  : chat_id_(chat_id_)
  , default_participant_id_(std::move(default_participant_id_))
{}

const std::int32_t setVideoChatDefaultParticipant::ID;

void setVideoChatDefaultParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setVideoChatDefaultParticipant");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("default_participant_id", static_cast<const BaseObject *>(default_participant_id_.get()));
    s.store_class_end();
  }
}

testSquareInt::testSquareInt()
  : x_()
{}

testSquareInt::testSquareInt(int32 x_)
  : x_(x_)
{}

const std::int32_t testSquareInt::ID;

void testSquareInt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testSquareInt");
    s.store_field("x", x_);
    s.store_class_end();
  }
}

toggleChatIsTranslatable::toggleChatIsTranslatable()
  : chat_id_()
  , is_translatable_()
{}

toggleChatIsTranslatable::toggleChatIsTranslatable(int53 chat_id_, bool is_translatable_)
  : chat_id_(chat_id_)
  , is_translatable_(is_translatable_)
{}

const std::int32_t toggleChatIsTranslatable::ID;

void toggleChatIsTranslatable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleChatIsTranslatable");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_translatable", is_translatable_);
    s.store_class_end();
  }
}

toggleSavedMessagesTopicIsPinned::toggleSavedMessagesTopicIsPinned()
  : saved_messages_topic_id_()
  , is_pinned_()
{}

toggleSavedMessagesTopicIsPinned::toggleSavedMessagesTopicIsPinned(int53 saved_messages_topic_id_, bool is_pinned_)
  : saved_messages_topic_id_(saved_messages_topic_id_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t toggleSavedMessagesTopicIsPinned::ID;

void toggleSavedMessagesTopicIsPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSavedMessagesTopicIsPinned");
    s.store_field("saved_messages_topic_id", saved_messages_topic_id_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

toggleSupergroupJoinByRequest::toggleSupergroupJoinByRequest()
  : supergroup_id_()
  , join_by_request_()
{}

toggleSupergroupJoinByRequest::toggleSupergroupJoinByRequest(int53 supergroup_id_, bool join_by_request_)
  : supergroup_id_(supergroup_id_)
  , join_by_request_(join_by_request_)
{}

const std::int32_t toggleSupergroupJoinByRequest::ID;

void toggleSupergroupJoinByRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupJoinByRequest");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("join_by_request", join_by_request_);
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
