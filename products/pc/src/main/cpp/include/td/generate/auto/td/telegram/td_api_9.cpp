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


acceptedGiftTypes::acceptedGiftTypes()
  : unlimited_gifts_()
  , limited_gifts_()
  , upgraded_gifts_()
  , gifts_from_channels_()
  , premium_subscription_()
{}

acceptedGiftTypes::acceptedGiftTypes(bool unlimited_gifts_, bool limited_gifts_, bool upgraded_gifts_, bool gifts_from_channels_, bool premium_subscription_)
  : unlimited_gifts_(unlimited_gifts_)
  , limited_gifts_(limited_gifts_)
  , upgraded_gifts_(upgraded_gifts_)
  , gifts_from_channels_(gifts_from_channels_)
  , premium_subscription_(premium_subscription_)
{}

const std::int32_t acceptedGiftTypes::ID;

void acceptedGiftTypes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "acceptedGiftTypes");
    s.store_field("unlimited_gifts", unlimited_gifts_);
    s.store_field("limited_gifts", limited_gifts_);
    s.store_field("upgraded_gifts", upgraded_gifts_);
    s.store_field("gifts_from_channels", gifts_from_channels_);
    s.store_field("premium_subscription", premium_subscription_);
    s.store_class_end();
  }
}

addedReactions::addedReactions()
  : total_count_()
  , reactions_()
  , next_offset_()
{}

addedReactions::addedReactions(int32 total_count_, array<object_ptr<addedReaction>> &&reactions_, string const &next_offset_)
  : total_count_(total_count_)
  , reactions_(std::move(reactions_))
  , next_offset_(next_offset_)
{}

const std::int32_t addedReactions::ID;

void addedReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addedReactions");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

address::address()
  : country_code_()
  , state_()
  , city_()
  , street_line1_()
  , street_line2_()
  , postal_code_()
{}

address::address(string const &country_code_, string const &state_, string const &city_, string const &street_line1_, string const &street_line2_, string const &postal_code_)
  : country_code_(country_code_)
  , state_(state_)
  , city_(city_)
  , street_line1_(street_line1_)
  , street_line2_(street_line2_)
  , postal_code_(postal_code_)
{}

const std::int32_t address::ID;

void address::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "address");
    s.store_field("country_code", country_code_);
    s.store_field("state", state_);
    s.store_field("city", city_);
    s.store_field("street_line1", street_line1_);
    s.store_field("street_line2", street_line2_);
    s.store_field("postal_code", postal_code_);
    s.store_class_end();
  }
}

affiliateTypeCurrentUser::affiliateTypeCurrentUser() {
}

const std::int32_t affiliateTypeCurrentUser::ID;

void affiliateTypeCurrentUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "affiliateTypeCurrentUser");
    s.store_class_end();
  }
}

affiliateTypeBot::affiliateTypeBot()
  : user_id_()
{}

affiliateTypeBot::affiliateTypeBot(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t affiliateTypeBot::ID;

void affiliateTypeBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "affiliateTypeBot");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

affiliateTypeChannel::affiliateTypeChannel()
  : chat_id_()
{}

affiliateTypeChannel::affiliateTypeChannel(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t affiliateTypeChannel::ID;

void affiliateTypeChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "affiliateTypeChannel");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

auctionStateActive::auctionStateActive()
  : start_date_()
  , end_date_()
  , min_bid_()
  , bid_levels_()
  , top_bidder_user_ids_()
  , rounds_()
  , current_round_end_date_()
  , current_round_number_()
  , total_round_count_()
  , distributed_item_count_()
  , left_item_count_()
  , acquired_item_count_()
  , user_bid_()
{}

auctionStateActive::auctionStateActive(int32 start_date_, int32 end_date_, int53 min_bid_, array<object_ptr<auctionBid>> &&bid_levels_, array<int53> &&top_bidder_user_ids_, array<object_ptr<auctionRound>> &&rounds_, int32 current_round_end_date_, int32 current_round_number_, int32 total_round_count_, int32 distributed_item_count_, int32 left_item_count_, int32 acquired_item_count_, object_ptr<userAuctionBid> &&user_bid_)
  : start_date_(start_date_)
  , end_date_(end_date_)
  , min_bid_(min_bid_)
  , bid_levels_(std::move(bid_levels_))
  , top_bidder_user_ids_(std::move(top_bidder_user_ids_))
  , rounds_(std::move(rounds_))
  , current_round_end_date_(current_round_end_date_)
  , current_round_number_(current_round_number_)
  , total_round_count_(total_round_count_)
  , distributed_item_count_(distributed_item_count_)
  , left_item_count_(left_item_count_)
  , acquired_item_count_(acquired_item_count_)
  , user_bid_(std::move(user_bid_))
{}

const std::int32_t auctionStateActive::ID;

void auctionStateActive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auctionStateActive");
    s.store_field("start_date", start_date_);
    s.store_field("end_date", end_date_);
    s.store_field("min_bid", min_bid_);
    { s.store_vector_begin("bid_levels", bid_levels_.size()); for (const auto &_value : bid_levels_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("top_bidder_user_ids", top_bidder_user_ids_.size()); for (const auto &_value : top_bidder_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("rounds", rounds_.size()); for (const auto &_value : rounds_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("current_round_end_date", current_round_end_date_);
    s.store_field("current_round_number", current_round_number_);
    s.store_field("total_round_count", total_round_count_);
    s.store_field("distributed_item_count", distributed_item_count_);
    s.store_field("left_item_count", left_item_count_);
    s.store_field("acquired_item_count", acquired_item_count_);
    s.store_object_field("user_bid", static_cast<const BaseObject *>(user_bid_.get()));
    s.store_class_end();
  }
}

auctionStateFinished::auctionStateFinished()
  : start_date_()
  , end_date_()
  , average_price_()
  , acquired_item_count_()
  , telegram_listed_item_count_()
  , fragment_listed_item_count_()
  , fragment_url_()
{}

auctionStateFinished::auctionStateFinished(int32 start_date_, int32 end_date_, int53 average_price_, int32 acquired_item_count_, int32 telegram_listed_item_count_, int32 fragment_listed_item_count_, string const &fragment_url_)
  : start_date_(start_date_)
  , end_date_(end_date_)
  , average_price_(average_price_)
  , acquired_item_count_(acquired_item_count_)
  , telegram_listed_item_count_(telegram_listed_item_count_)
  , fragment_listed_item_count_(fragment_listed_item_count_)
  , fragment_url_(fragment_url_)
{}

const std::int32_t auctionStateFinished::ID;

void auctionStateFinished::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auctionStateFinished");
    s.store_field("start_date", start_date_);
    s.store_field("end_date", end_date_);
    s.store_field("average_price", average_price_);
    s.store_field("acquired_item_count", acquired_item_count_);
    s.store_field("telegram_listed_item_count", telegram_listed_item_count_);
    s.store_field("fragment_listed_item_count", fragment_listed_item_count_);
    s.store_field("fragment_url", fragment_url_);
    s.store_class_end();
  }
}

authorizationStateWaitTdlibParameters::authorizationStateWaitTdlibParameters() {
}

const std::int32_t authorizationStateWaitTdlibParameters::ID;

void authorizationStateWaitTdlibParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitTdlibParameters");
    s.store_class_end();
  }
}

authorizationStateWaitPhoneNumber::authorizationStateWaitPhoneNumber() {
}

const std::int32_t authorizationStateWaitPhoneNumber::ID;

void authorizationStateWaitPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitPhoneNumber");
    s.store_class_end();
  }
}

authorizationStateWaitPremiumPurchase::authorizationStateWaitPremiumPurchase()
  : store_product_id_()
  , support_email_address_()
  , support_email_subject_()
{}

authorizationStateWaitPremiumPurchase::authorizationStateWaitPremiumPurchase(string const &store_product_id_, string const &support_email_address_, string const &support_email_subject_)
  : store_product_id_(store_product_id_)
  , support_email_address_(support_email_address_)
  , support_email_subject_(support_email_subject_)
{}

const std::int32_t authorizationStateWaitPremiumPurchase::ID;

void authorizationStateWaitPremiumPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitPremiumPurchase");
    s.store_field("store_product_id", store_product_id_);
    s.store_field("support_email_address", support_email_address_);
    s.store_field("support_email_subject", support_email_subject_);
    s.store_class_end();
  }
}

authorizationStateWaitEmailAddress::authorizationStateWaitEmailAddress()
  : allow_apple_id_()
  , allow_google_id_()
{}

authorizationStateWaitEmailAddress::authorizationStateWaitEmailAddress(bool allow_apple_id_, bool allow_google_id_)
  : allow_apple_id_(allow_apple_id_)
  , allow_google_id_(allow_google_id_)
{}

const std::int32_t authorizationStateWaitEmailAddress::ID;

void authorizationStateWaitEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitEmailAddress");
    s.store_field("allow_apple_id", allow_apple_id_);
    s.store_field("allow_google_id", allow_google_id_);
    s.store_class_end();
  }
}

authorizationStateWaitEmailCode::authorizationStateWaitEmailCode()
  : allow_apple_id_()
  , allow_google_id_()
  , code_info_()
  , email_address_reset_state_()
{}

authorizationStateWaitEmailCode::authorizationStateWaitEmailCode(bool allow_apple_id_, bool allow_google_id_, object_ptr<emailAddressAuthenticationCodeInfo> &&code_info_, object_ptr<EmailAddressResetState> &&email_address_reset_state_)
  : allow_apple_id_(allow_apple_id_)
  , allow_google_id_(allow_google_id_)
  , code_info_(std::move(code_info_))
  , email_address_reset_state_(std::move(email_address_reset_state_))
{}

const std::int32_t authorizationStateWaitEmailCode::ID;

void authorizationStateWaitEmailCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitEmailCode");
    s.store_field("allow_apple_id", allow_apple_id_);
    s.store_field("allow_google_id", allow_google_id_);
    s.store_object_field("code_info", static_cast<const BaseObject *>(code_info_.get()));
    s.store_object_field("email_address_reset_state", static_cast<const BaseObject *>(email_address_reset_state_.get()));
    s.store_class_end();
  }
}

authorizationStateWaitCode::authorizationStateWaitCode()
  : code_info_()
{}

authorizationStateWaitCode::authorizationStateWaitCode(object_ptr<authenticationCodeInfo> &&code_info_)
  : code_info_(std::move(code_info_))
{}

const std::int32_t authorizationStateWaitCode::ID;

void authorizationStateWaitCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitCode");
    s.store_object_field("code_info", static_cast<const BaseObject *>(code_info_.get()));
    s.store_class_end();
  }
}

authorizationStateWaitOtherDeviceConfirmation::authorizationStateWaitOtherDeviceConfirmation()
  : link_()
{}

authorizationStateWaitOtherDeviceConfirmation::authorizationStateWaitOtherDeviceConfirmation(string const &link_)
  : link_(link_)
{}

const std::int32_t authorizationStateWaitOtherDeviceConfirmation::ID;

void authorizationStateWaitOtherDeviceConfirmation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitOtherDeviceConfirmation");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

authorizationStateWaitRegistration::authorizationStateWaitRegistration()
  : terms_of_service_()
{}

authorizationStateWaitRegistration::authorizationStateWaitRegistration(object_ptr<termsOfService> &&terms_of_service_)
  : terms_of_service_(std::move(terms_of_service_))
{}

const std::int32_t authorizationStateWaitRegistration::ID;

void authorizationStateWaitRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitRegistration");
    s.store_object_field("terms_of_service", static_cast<const BaseObject *>(terms_of_service_.get()));
    s.store_class_end();
  }
}

authorizationStateWaitPassword::authorizationStateWaitPassword()
  : password_hint_()
  , has_recovery_email_address_()
  , has_passport_data_()
  , recovery_email_address_pattern_()
{}

authorizationStateWaitPassword::authorizationStateWaitPassword(string const &password_hint_, bool has_recovery_email_address_, bool has_passport_data_, string const &recovery_email_address_pattern_)
  : password_hint_(password_hint_)
  , has_recovery_email_address_(has_recovery_email_address_)
  , has_passport_data_(has_passport_data_)
  , recovery_email_address_pattern_(recovery_email_address_pattern_)
{}

const std::int32_t authorizationStateWaitPassword::ID;

void authorizationStateWaitPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitPassword");
    s.store_field("password_hint", password_hint_);
    s.store_field("has_recovery_email_address", has_recovery_email_address_);
    s.store_field("has_passport_data", has_passport_data_);
    s.store_field("recovery_email_address_pattern", recovery_email_address_pattern_);
    s.store_class_end();
  }
}

authorizationStateReady::authorizationStateReady() {
}

const std::int32_t authorizationStateReady::ID;

void authorizationStateReady::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateReady");
    s.store_class_end();
  }
}

authorizationStateLoggingOut::authorizationStateLoggingOut() {
}

const std::int32_t authorizationStateLoggingOut::ID;

void authorizationStateLoggingOut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateLoggingOut");
    s.store_class_end();
  }
}

authorizationStateClosing::authorizationStateClosing() {
}

const std::int32_t authorizationStateClosing::ID;

void authorizationStateClosing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateClosing");
    s.store_class_end();
  }
}

authorizationStateClosed::authorizationStateClosed() {
}

const std::int32_t authorizationStateClosed::ID;

void authorizationStateClosed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateClosed");
    s.store_class_end();
  }
}

autosaveSettings::autosaveSettings()
  : private_chat_settings_()
  , group_settings_()
  , channel_settings_()
  , exceptions_()
{}

autosaveSettings::autosaveSettings(object_ptr<scopeAutosaveSettings> &&private_chat_settings_, object_ptr<scopeAutosaveSettings> &&group_settings_, object_ptr<scopeAutosaveSettings> &&channel_settings_, array<object_ptr<autosaveSettingsException>> &&exceptions_)
  : private_chat_settings_(std::move(private_chat_settings_))
  , group_settings_(std::move(group_settings_))
  , channel_settings_(std::move(channel_settings_))
  , exceptions_(std::move(exceptions_))
{}

const std::int32_t autosaveSettings::ID;

void autosaveSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autosaveSettings");
    s.store_object_field("private_chat_settings", static_cast<const BaseObject *>(private_chat_settings_.get()));
    s.store_object_field("group_settings", static_cast<const BaseObject *>(group_settings_.get()));
    s.store_object_field("channel_settings", static_cast<const BaseObject *>(channel_settings_.get()));
    { s.store_vector_begin("exceptions", exceptions_.size()); for (const auto &_value : exceptions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

businessBotManageBar::businessBotManageBar()
  : bot_user_id_()
  , manage_url_()
  , is_bot_paused_()
  , can_bot_reply_()
{}

businessBotManageBar::businessBotManageBar(int53 bot_user_id_, string const &manage_url_, bool is_bot_paused_, bool can_bot_reply_)
  : bot_user_id_(bot_user_id_)
  , manage_url_(manage_url_)
  , is_bot_paused_(is_bot_paused_)
  , can_bot_reply_(can_bot_reply_)
{}

const std::int32_t businessBotManageBar::ID;

void businessBotManageBar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessBotManageBar");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("manage_url", manage_url_);
    s.store_field("is_bot_paused", is_bot_paused_);
    s.store_field("can_bot_reply", can_bot_reply_);
    s.store_class_end();
  }
}

chatEvent::chatEvent()
  : id_()
  , date_()
  , member_id_()
  , action_()
{}

chatEvent::chatEvent(int64 id_, int32 date_, object_ptr<MessageSender> &&member_id_, object_ptr<ChatEventAction> &&action_)
  : id_(id_)
  , date_(date_)
  , member_id_(std::move(member_id_))
  , action_(std::move(action_))
{}

const std::int32_t chatEvent::ID;

void chatEvent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEvent");
    s.store_field("id", id_);
    s.store_field("date", date_);
    s.store_object_field("member_id", static_cast<const BaseObject *>(member_id_.get()));
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

chatFolderIcon::chatFolderIcon()
  : name_()
{}

chatFolderIcon::chatFolderIcon(string const &name_)
  : name_(name_)
{}

const std::int32_t chatFolderIcon::ID;

void chatFolderIcon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatFolderIcon");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

chatInviteLinks::chatInviteLinks()
  : total_count_()
  , invite_links_()
{}

chatInviteLinks::chatInviteLinks(int32 total_count_, array<object_ptr<chatInviteLink>> &&invite_links_)
  : total_count_(total_count_)
  , invite_links_(std::move(invite_links_))
{}

const std::int32_t chatInviteLinks::ID;

void chatInviteLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLinks");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("invite_links", invite_links_.size()); for (const auto &_value : invite_links_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatMemberStatusCreator::chatMemberStatusCreator()
  : is_anonymous_()
  , is_member_()
{}

chatMemberStatusCreator::chatMemberStatusCreator(bool is_anonymous_, bool is_member_)
  : is_anonymous_(is_anonymous_)
  , is_member_(is_member_)
{}

const std::int32_t chatMemberStatusCreator::ID;

void chatMemberStatusCreator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMemberStatusCreator");
    s.store_field("is_anonymous", is_anonymous_);
    s.store_field("is_member", is_member_);
    s.store_class_end();
  }
}

chatMemberStatusAdministrator::chatMemberStatusAdministrator()
  : can_be_edited_()
  , rights_()
{}

chatMemberStatusAdministrator::chatMemberStatusAdministrator(bool can_be_edited_, object_ptr<chatAdministratorRights> &&rights_)
  : can_be_edited_(can_be_edited_)
  , rights_(std::move(rights_))
{}

const std::int32_t chatMemberStatusAdministrator::ID;

void chatMemberStatusAdministrator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMemberStatusAdministrator");
    s.store_field("can_be_edited", can_be_edited_);
    s.store_object_field("rights", static_cast<const BaseObject *>(rights_.get()));
    s.store_class_end();
  }
}

chatMemberStatusMember::chatMemberStatusMember()
  : member_until_date_()
{}

chatMemberStatusMember::chatMemberStatusMember(int32 member_until_date_)
  : member_until_date_(member_until_date_)
{}

const std::int32_t chatMemberStatusMember::ID;

void chatMemberStatusMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMemberStatusMember");
    s.store_field("member_until_date", member_until_date_);
    s.store_class_end();
  }
}

chatMemberStatusRestricted::chatMemberStatusRestricted()
  : is_member_()
  , restricted_until_date_()
  , permissions_()
{}

chatMemberStatusRestricted::chatMemberStatusRestricted(bool is_member_, int32 restricted_until_date_, object_ptr<chatPermissions> &&permissions_)
  : is_member_(is_member_)
  , restricted_until_date_(restricted_until_date_)
  , permissions_(std::move(permissions_))
{}

const std::int32_t chatMemberStatusRestricted::ID;

void chatMemberStatusRestricted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMemberStatusRestricted");
    s.store_field("is_member", is_member_);
    s.store_field("restricted_until_date", restricted_until_date_);
    s.store_object_field("permissions", static_cast<const BaseObject *>(permissions_.get()));
    s.store_class_end();
  }
}

chatMemberStatusLeft::chatMemberStatusLeft() {
}

const std::int32_t chatMemberStatusLeft::ID;

void chatMemberStatusLeft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMemberStatusLeft");
    s.store_class_end();
  }
}

chatMemberStatusBanned::chatMemberStatusBanned()
  : banned_until_date_()
{}

chatMemberStatusBanned::chatMemberStatusBanned(int32 banned_until_date_)
  : banned_until_date_(banned_until_date_)
{}

const std::int32_t chatMemberStatusBanned::ID;

void chatMemberStatusBanned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMemberStatusBanned");
    s.store_field("banned_until_date", banned_until_date_);
    s.store_class_end();
  }
}

chatStatisticsInteractionInfo::chatStatisticsInteractionInfo()
  : object_type_()
  , view_count_()
  , forward_count_()
  , reaction_count_()
{}

chatStatisticsInteractionInfo::chatStatisticsInteractionInfo(object_ptr<ChatStatisticsObjectType> &&object_type_, int32 view_count_, int32 forward_count_, int32 reaction_count_)
  : object_type_(std::move(object_type_))
  , view_count_(view_count_)
  , forward_count_(forward_count_)
  , reaction_count_(reaction_count_)
{}

const std::int32_t chatStatisticsInteractionInfo::ID;

void chatStatisticsInteractionInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsInteractionInfo");
    s.store_object_field("object_type", static_cast<const BaseObject *>(object_type_.get()));
    s.store_field("view_count", view_count_);
    s.store_field("forward_count", forward_count_);
    s.store_field("reaction_count", reaction_count_);
    s.store_class_end();
  }
}

checklistTask::checklistTask()
  : id_()
  , text_()
  , completed_by_()
  , completion_date_()
{}

checklistTask::checklistTask(int32 id_, object_ptr<formattedText> &&text_, object_ptr<MessageSender> &&completed_by_, int32 completion_date_)
  : id_(id_)
  , text_(std::move(text_))
  , completed_by_(std::move(completed_by_))
  , completion_date_(completion_date_)
{}

const std::int32_t checklistTask::ID;

void checklistTask::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checklistTask");
    s.store_field("id", id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("completed_by", static_cast<const BaseObject *>(completed_by_.get()));
    s.store_field("completion_date", completion_date_);
    s.store_class_end();
  }
}

connectedAffiliatePrograms::connectedAffiliatePrograms()
  : total_count_()
  , programs_()
  , next_offset_()
{}

connectedAffiliatePrograms::connectedAffiliatePrograms(int32 total_count_, array<object_ptr<connectedAffiliateProgram>> &&programs_, string const &next_offset_)
  : total_count_(total_count_)
  , programs_(std::move(programs_))
  , next_offset_(next_offset_)
{}

const std::int32_t connectedAffiliatePrograms::ID;

void connectedAffiliatePrograms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectedAffiliatePrograms");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("programs", programs_.size()); for (const auto &_value : programs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

contact::contact()
  : phone_number_()
  , first_name_()
  , last_name_()
  , vcard_()
  , user_id_()
{}

contact::contact(string const &phone_number_, string const &first_name_, string const &last_name_, string const &vcard_, int53 user_id_)
  : phone_number_(phone_number_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , vcard_(vcard_)
  , user_id_(user_id_)
{}

const std::int32_t contact::ID;

void contact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contact");
    s.store_field("phone_number", phone_number_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_field("vcard", vcard_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

craftGiftResultSuccess::craftGiftResultSuccess()
  : gift_()
  , received_gift_id_()
{}

craftGiftResultSuccess::craftGiftResultSuccess(object_ptr<upgradedGift> &&gift_, string const &received_gift_id_)
  : gift_(std::move(gift_))
  , received_gift_id_(received_gift_id_)
{}

const std::int32_t craftGiftResultSuccess::ID;

void craftGiftResultSuccess::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "craftGiftResultSuccess");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_field("received_gift_id", received_gift_id_);
    s.store_class_end();
  }
}

craftGiftResultTooEarly::craftGiftResultTooEarly()
  : retry_after_()
{}

craftGiftResultTooEarly::craftGiftResultTooEarly(int32 retry_after_)
  : retry_after_(retry_after_)
{}

const std::int32_t craftGiftResultTooEarly::ID;

void craftGiftResultTooEarly::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "craftGiftResultTooEarly");
    s.store_field("retry_after", retry_after_);
    s.store_class_end();
  }
}

craftGiftResultInvalidGift::craftGiftResultInvalidGift() {
}

const std::int32_t craftGiftResultInvalidGift::ID;

void craftGiftResultInvalidGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "craftGiftResultInvalidGift");
    s.store_class_end();
  }
}

craftGiftResultFail::craftGiftResultFail() {
}

const std::int32_t craftGiftResultFail::ID;

void craftGiftResultFail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "craftGiftResultFail");
    s.store_class_end();
  }
}

diffEntityTypeInsert::diffEntityTypeInsert() {
}

const std::int32_t diffEntityTypeInsert::ID;

void diffEntityTypeInsert::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "diffEntityTypeInsert");
    s.store_class_end();
  }
}

diffEntityTypeReplace::diffEntityTypeReplace()
  : old_text_()
{}

diffEntityTypeReplace::diffEntityTypeReplace(string const &old_text_)
  : old_text_(old_text_)
{}

const std::int32_t diffEntityTypeReplace::ID;

void diffEntityTypeReplace::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "diffEntityTypeReplace");
    s.store_field("old_text", old_text_);
    s.store_class_end();
  }
}

diffEntityTypeDelete::diffEntityTypeDelete() {
}

const std::int32_t diffEntityTypeDelete::ID;

void diffEntityTypeDelete::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "diffEntityTypeDelete");
    s.store_class_end();
  }
}

forumTopic::forumTopic()
  : info_()
  , last_message_()
  , order_()
  , is_pinned_()
  , unread_count_()
  , last_read_inbox_message_id_()
  , last_read_outbox_message_id_()
  , unread_mention_count_()
  , unread_reaction_count_()
  , unread_poll_vote_count_()
  , notification_settings_()
  , draft_message_()
{}

forumTopic::forumTopic(object_ptr<forumTopicInfo> &&info_, object_ptr<message> &&last_message_, int64 order_, bool is_pinned_, int32 unread_count_, int53 last_read_inbox_message_id_, int53 last_read_outbox_message_id_, int32 unread_mention_count_, int32 unread_reaction_count_, int32 unread_poll_vote_count_, object_ptr<chatNotificationSettings> &&notification_settings_, object_ptr<draftMessage> &&draft_message_)
  : info_(std::move(info_))
  , last_message_(std::move(last_message_))
  , order_(order_)
  , is_pinned_(is_pinned_)
  , unread_count_(unread_count_)
  , last_read_inbox_message_id_(last_read_inbox_message_id_)
  , last_read_outbox_message_id_(last_read_outbox_message_id_)
  , unread_mention_count_(unread_mention_count_)
  , unread_reaction_count_(unread_reaction_count_)
  , unread_poll_vote_count_(unread_poll_vote_count_)
  , notification_settings_(std::move(notification_settings_))
  , draft_message_(std::move(draft_message_))
{}

const std::int32_t forumTopic::ID;

void forumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "forumTopic");
    s.store_object_field("info", static_cast<const BaseObject *>(info_.get()));
    s.store_object_field("last_message", static_cast<const BaseObject *>(last_message_.get()));
    s.store_field("order", order_);
    s.store_field("is_pinned", is_pinned_);
    s.store_field("unread_count", unread_count_);
    s.store_field("last_read_inbox_message_id", last_read_inbox_message_id_);
    s.store_field("last_read_outbox_message_id", last_read_outbox_message_id_);
    s.store_field("unread_mention_count", unread_mention_count_);
    s.store_field("unread_reaction_count", unread_reaction_count_);
    s.store_field("unread_poll_vote_count", unread_poll_vote_count_);
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_object_field("draft_message", static_cast<const BaseObject *>(draft_message_.get()));
    s.store_class_end();
  }
}

forumTopics::forumTopics()
  : total_count_()
  , topics_()
  , next_offset_date_()
  , next_offset_message_id_()
  , next_offset_forum_topic_id_()
{}

forumTopics::forumTopics(int32 total_count_, array<object_ptr<forumTopic>> &&topics_, int32 next_offset_date_, int53 next_offset_message_id_, int32 next_offset_forum_topic_id_)
  : total_count_(total_count_)
  , topics_(std::move(topics_))
  , next_offset_date_(next_offset_date_)
  , next_offset_message_id_(next_offset_message_id_)
  , next_offset_forum_topic_id_(next_offset_forum_topic_id_)
{}

const std::int32_t forumTopics::ID;

void forumTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "forumTopics");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("topics", topics_.size()); for (const auto &_value : topics_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset_date", next_offset_date_);
    s.store_field("next_offset_message_id", next_offset_message_id_);
    s.store_field("next_offset_forum_topic_id", next_offset_forum_topic_id_);
    s.store_class_end();
  }
}

foundAffiliateProgram::foundAffiliateProgram()
  : bot_user_id_()
  , info_()
{}

foundAffiliateProgram::foundAffiliateProgram(int53 bot_user_id_, object_ptr<affiliateProgramInfo> &&info_)
  : bot_user_id_(bot_user_id_)
  , info_(std::move(info_))
{}

const std::int32_t foundAffiliateProgram::ID;

void foundAffiliateProgram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundAffiliateProgram");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_object_field("info", static_cast<const BaseObject *>(info_.get()));
    s.store_class_end();
  }
}

foundChatBoosts::foundChatBoosts()
  : total_count_()
  , boosts_()
  , next_offset_()
{}

foundChatBoosts::foundChatBoosts(int32 total_count_, array<object_ptr<chatBoost>> &&boosts_, string const &next_offset_)
  : total_count_(total_count_)
  , boosts_(std::move(boosts_))
  , next_offset_(next_offset_)
{}

const std::int32_t foundChatBoosts::ID;

void foundChatBoosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundChatBoosts");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("boosts", boosts_.size()); for (const auto &_value : boosts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

gameHighScore::gameHighScore()
  : position_()
  , user_id_()
  , score_()
{}

gameHighScore::gameHighScore(int32 position_, int53 user_id_, int32 score_)
  : position_(position_)
  , user_id_(user_id_)
  , score_(score_)
{}

const std::int32_t gameHighScore::ID;

void gameHighScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "gameHighScore");
    s.store_field("position", position_);
    s.store_field("user_id", user_id_);
    s.store_field("score", score_);
    s.store_class_end();
  }
}

giftChatThemes::giftChatThemes()
  : themes_()
  , next_offset_()
{}

giftChatThemes::giftChatThemes(array<object_ptr<giftChatTheme>> &&themes_, string const &next_offset_)
  : themes_(std::move(themes_))
  , next_offset_(next_offset_)
{}

const std::int32_t giftChatThemes::ID;

void giftChatThemes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftChatThemes");
    { s.store_vector_begin("themes", themes_.size()); for (const auto &_value : themes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

groupCallDataChannelMain::groupCallDataChannelMain() {
}

const std::int32_t groupCallDataChannelMain::ID;

void groupCallDataChannelMain::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallDataChannelMain");
    s.store_class_end();
  }
}

groupCallDataChannelScreenSharing::groupCallDataChannelScreenSharing() {
}

const std::int32_t groupCallDataChannelScreenSharing::ID;

void groupCallDataChannelScreenSharing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallDataChannelScreenSharing");
    s.store_class_end();
  }
}

groupCallStreams::groupCallStreams()
  : streams_()
{}

groupCallStreams::groupCallStreams(array<object_ptr<groupCallStream>> &&streams_)
  : streams_(std::move(streams_))
{}

const std::int32_t groupCallStreams::ID;

void groupCallStreams::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallStreams");
    { s.store_vector_begin("streams", streams_.size()); for (const auto &_value : streams_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

groupCallVideoSourceGroup::groupCallVideoSourceGroup()
  : semantics_()
  , source_ids_()
{}

groupCallVideoSourceGroup::groupCallVideoSourceGroup(string const &semantics_, array<int32> &&source_ids_)
  : semantics_(semantics_)
  , source_ids_(std::move(source_ids_))
{}

const std::int32_t groupCallVideoSourceGroup::ID;

void groupCallVideoSourceGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallVideoSourceGroup");
    s.store_field("semantics", semantics_);
    { s.store_vector_begin("source_ids", source_ids_.size()); for (const auto &_value : source_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

importedContacts::importedContacts()
  : user_ids_()
  , importer_count_()
{}

importedContacts::importedContacts(array<int53> &&user_ids_, array<int32> &&importer_count_)
  : user_ids_(std::move(user_ids_))
  , importer_count_(std::move(importer_count_))
{}

const std::int32_t importedContacts::ID;

void importedContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "importedContacts");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("importer_count", importer_count_.size()); for (const auto &_value : importer_count_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeUrl::inlineKeyboardButtonTypeUrl()
  : url_()
{}

inlineKeyboardButtonTypeUrl::inlineKeyboardButtonTypeUrl(string const &url_)
  : url_(url_)
{}

const std::int32_t inlineKeyboardButtonTypeUrl::ID;

void inlineKeyboardButtonTypeUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeUrl");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeLoginUrl::inlineKeyboardButtonTypeLoginUrl()
  : url_()
  , id_()
  , forward_text_()
{}

inlineKeyboardButtonTypeLoginUrl::inlineKeyboardButtonTypeLoginUrl(string const &url_, int53 id_, string const &forward_text_)
  : url_(url_)
  , id_(id_)
  , forward_text_(forward_text_)
{}

const std::int32_t inlineKeyboardButtonTypeLoginUrl::ID;

void inlineKeyboardButtonTypeLoginUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeLoginUrl");
    s.store_field("url", url_);
    s.store_field("id", id_);
    s.store_field("forward_text", forward_text_);
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeWebApp::inlineKeyboardButtonTypeWebApp()
  : url_()
{}

inlineKeyboardButtonTypeWebApp::inlineKeyboardButtonTypeWebApp(string const &url_)
  : url_(url_)
{}

const std::int32_t inlineKeyboardButtonTypeWebApp::ID;

void inlineKeyboardButtonTypeWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeWebApp");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeCallback::inlineKeyboardButtonTypeCallback()
  : data_()
{}

inlineKeyboardButtonTypeCallback::inlineKeyboardButtonTypeCallback(bytes const &data_)
  : data_(std::move(data_))
{}

const std::int32_t inlineKeyboardButtonTypeCallback::ID;

void inlineKeyboardButtonTypeCallback::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeCallback");
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeCallbackWithPassword::inlineKeyboardButtonTypeCallbackWithPassword()
  : data_()
{}

inlineKeyboardButtonTypeCallbackWithPassword::inlineKeyboardButtonTypeCallbackWithPassword(bytes const &data_)
  : data_(std::move(data_))
{}

const std::int32_t inlineKeyboardButtonTypeCallbackWithPassword::ID;

void inlineKeyboardButtonTypeCallbackWithPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeCallbackWithPassword");
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeCallbackGame::inlineKeyboardButtonTypeCallbackGame() {
}

const std::int32_t inlineKeyboardButtonTypeCallbackGame::ID;

void inlineKeyboardButtonTypeCallbackGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeCallbackGame");
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeSwitchInline::inlineKeyboardButtonTypeSwitchInline()
  : query_()
  , target_chat_()
{}

inlineKeyboardButtonTypeSwitchInline::inlineKeyboardButtonTypeSwitchInline(string const &query_, object_ptr<TargetChat> &&target_chat_)
  : query_(query_)
  , target_chat_(std::move(target_chat_))
{}

const std::int32_t inlineKeyboardButtonTypeSwitchInline::ID;

void inlineKeyboardButtonTypeSwitchInline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeSwitchInline");
    s.store_field("query", query_);
    s.store_object_field("target_chat", static_cast<const BaseObject *>(target_chat_.get()));
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeBuy::inlineKeyboardButtonTypeBuy() {
}

const std::int32_t inlineKeyboardButtonTypeBuy::ID;

void inlineKeyboardButtonTypeBuy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeBuy");
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeUser::inlineKeyboardButtonTypeUser()
  : user_id_()
{}

inlineKeyboardButtonTypeUser::inlineKeyboardButtonTypeUser(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t inlineKeyboardButtonTypeUser::ID;

void inlineKeyboardButtonTypeUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeUser");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeCopyText::inlineKeyboardButtonTypeCopyText()
  : text_()
{}

inlineKeyboardButtonTypeCopyText::inlineKeyboardButtonTypeCopyText(string const &text_)
  : text_(text_)
{}

const std::int32_t inlineKeyboardButtonTypeCopyText::ID;

void inlineKeyboardButtonTypeCopyText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeCopyText");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

inlineQueryResultsButtonTypeStartBot::inlineQueryResultsButtonTypeStartBot()
  : parameter_()
{}

inlineQueryResultsButtonTypeStartBot::inlineQueryResultsButtonTypeStartBot(string const &parameter_)
  : parameter_(parameter_)
{}

const std::int32_t inlineQueryResultsButtonTypeStartBot::ID;

void inlineQueryResultsButtonTypeStartBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultsButtonTypeStartBot");
    s.store_field("parameter", parameter_);
    s.store_class_end();
  }
}

inlineQueryResultsButtonTypeWebApp::inlineQueryResultsButtonTypeWebApp()
  : url_()
{}

inlineQueryResultsButtonTypeWebApp::inlineQueryResultsButtonTypeWebApp(string const &url_)
  : url_(url_)
{}

const std::int32_t inlineQueryResultsButtonTypeWebApp::ID;

void inlineQueryResultsButtonTypeWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultsButtonTypeWebApp");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

inputStoryArea::inputStoryArea()
  : position_()
  , type_()
{}

inputStoryArea::inputStoryArea(object_ptr<storyAreaPosition> &&position_, object_ptr<InputStoryAreaType> &&type_)
  : position_(std::move(position_))
  , type_(std::move(type_))
{}

const std::int32_t inputStoryArea::ID;

void inputStoryArea::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryArea");
    s.store_object_field("position", static_cast<const BaseObject *>(position_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

inputStoryContentPhoto::inputStoryContentPhoto()
  : photo_()
  , added_sticker_file_ids_()
{}

inputStoryContentPhoto::inputStoryContentPhoto(object_ptr<InputFile> &&photo_, array<int32> &&added_sticker_file_ids_)
  : photo_(std::move(photo_))
  , added_sticker_file_ids_(std::move(added_sticker_file_ids_))
{}

const std::int32_t inputStoryContentPhoto::ID;

void inputStoryContentPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryContentPhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    { s.store_vector_begin("added_sticker_file_ids", added_sticker_file_ids_.size()); for (const auto &_value : added_sticker_file_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputStoryContentVideo::inputStoryContentVideo()
  : video_()
  , added_sticker_file_ids_()
  , duration_()
  , cover_frame_timestamp_()
  , is_animation_()
{}

inputStoryContentVideo::inputStoryContentVideo(object_ptr<InputFile> &&video_, array<int32> &&added_sticker_file_ids_, double duration_, double cover_frame_timestamp_, bool is_animation_)
  : video_(std::move(video_))
  , added_sticker_file_ids_(std::move(added_sticker_file_ids_))
  , duration_(duration_)
  , cover_frame_timestamp_(cover_frame_timestamp_)
  , is_animation_(is_animation_)
{}

const std::int32_t inputStoryContentVideo::ID;

void inputStoryContentVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryContentVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    { s.store_vector_begin("added_sticker_file_ids", added_sticker_file_ids_.size()); for (const auto &_value : added_sticker_file_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("duration", duration_);
    s.store_field("cover_frame_timestamp", cover_frame_timestamp_);
    s.store_field("is_animation", is_animation_);
    s.store_class_end();
  }
}

inviteGroupCallParticipantResultUserPrivacyRestricted::inviteGroupCallParticipantResultUserPrivacyRestricted() {
}

const std::int32_t inviteGroupCallParticipantResultUserPrivacyRestricted::ID;

void inviteGroupCallParticipantResultUserPrivacyRestricted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inviteGroupCallParticipantResultUserPrivacyRestricted");
    s.store_class_end();
  }
}

inviteGroupCallParticipantResultUserAlreadyParticipant::inviteGroupCallParticipantResultUserAlreadyParticipant() {
}

const std::int32_t inviteGroupCallParticipantResultUserAlreadyParticipant::ID;

void inviteGroupCallParticipantResultUserAlreadyParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inviteGroupCallParticipantResultUserAlreadyParticipant");
    s.store_class_end();
  }
}

inviteGroupCallParticipantResultUserWasBanned::inviteGroupCallParticipantResultUserWasBanned() {
}

const std::int32_t inviteGroupCallParticipantResultUserWasBanned::ID;

void inviteGroupCallParticipantResultUserWasBanned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inviteGroupCallParticipantResultUserWasBanned");
    s.store_class_end();
  }
}

inviteGroupCallParticipantResultSuccess::inviteGroupCallParticipantResultSuccess()
  : chat_id_()
  , message_id_()
{}

inviteGroupCallParticipantResultSuccess::inviteGroupCallParticipantResultSuccess(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t inviteGroupCallParticipantResultSuccess::ID;

void inviteGroupCallParticipantResultSuccess::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inviteGroupCallParticipantResultSuccess");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

liveStoryDonors::liveStoryDonors()
  : total_star_count_()
  , top_donors_()
{}

liveStoryDonors::liveStoryDonors(int53 total_star_count_, array<object_ptr<paidReactor>> &&top_donors_)
  : total_star_count_(total_star_count_)
  , top_donors_(std::move(top_donors_))
{}

const std::int32_t liveStoryDonors::ID;

void liveStoryDonors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "liveStoryDonors");
    s.store_field("total_star_count", total_star_count_);
    { s.store_vector_begin("top_donors", top_donors_.size()); for (const auto &_value : top_donors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

location::location()
  : latitude_()
  , longitude_()
  , horizontal_accuracy_()
{}

location::location(double latitude_, double longitude_, double horizontal_accuracy_)
  : latitude_(latitude_)
  , longitude_(longitude_)
  , horizontal_accuracy_(horizontal_accuracy_)
{}

const std::int32_t location::ID;

void location::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "location");
    s.store_field("latitude", latitude_);
    s.store_field("longitude", longitude_);
    s.store_field("horizontal_accuracy", horizontal_accuracy_);
    s.store_class_end();
  }
}

messageCalendar::messageCalendar()
  : total_count_()
  , days_()
{}

messageCalendar::messageCalendar(int32 total_count_, array<object_ptr<messageCalendarDay>> &&days_)
  : total_count_(total_count_)
  , days_(std::move(days_))
{}

const std::int32_t messageCalendar::ID;

void messageCalendar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageCalendar");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("days", days_.size()); for (const auto &_value : days_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageCalendarDay::messageCalendarDay()
  : total_count_()
  , message_()
{}

messageCalendarDay::messageCalendarDay(int32 total_count_, object_ptr<message> &&message_)
  : total_count_(total_count_)
  , message_(std::move(message_))
{}

const std::int32_t messageCalendarDay::ID;

void messageCalendarDay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageCalendarDay");
    s.store_field("total_count", total_count_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

messageForwardInfo::messageForwardInfo()
  : origin_()
  , date_()
  , source_()
  , public_service_announcement_type_()
{}

messageForwardInfo::messageForwardInfo(object_ptr<MessageOrigin> &&origin_, int32 date_, object_ptr<forwardSource> &&source_, string const &public_service_announcement_type_)
  : origin_(std::move(origin_))
  , date_(date_)
  , source_(std::move(source_))
  , public_service_announcement_type_(public_service_announcement_type_)
{}

const std::int32_t messageForwardInfo::ID;

void messageForwardInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageForwardInfo");
    s.store_object_field("origin", static_cast<const BaseObject *>(origin_.get()));
    s.store_field("date", date_);
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_field("public_service_announcement_type", public_service_announcement_type_);
    s.store_class_end();
  }
}

messageLink::messageLink()
  : link_()
  , is_public_()
{}

messageLink::messageLink(string const &link_, bool is_public_)
  : link_(link_)
  , is_public_(is_public_)
{}

const std::int32_t messageLink::ID;

void messageLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageLink");
    s.store_field("link", link_);
    s.store_field("is_public", is_public_);
    s.store_class_end();
  }
}

messageProperties::messageProperties()
  : can_add_offer_()
  , can_add_tasks_()
  , can_be_approved_()
  , can_be_copied_()
  , can_be_copied_to_secret_chat_()
  , can_be_declined_()
  , can_be_deleted_only_for_self_()
  , can_be_deleted_for_all_users_()
  , can_be_edited_()
  , can_be_forwarded_()
  , can_be_paid_()
  , can_be_pinned_()
  , can_be_replied_()
  , can_be_replied_in_another_chat_()
  , can_be_saved_()
  , can_be_shared_in_story_()
  , can_edit_media_()
  , can_edit_scheduling_state_()
  , can_edit_suggested_post_info_()
  , can_get_author_()
  , can_get_embedding_code_()
  , can_get_link_()
  , can_get_media_timestamp_links_()
  , can_get_message_thread_()
  , can_get_read_date_()
  , can_get_statistics_()
  , can_get_video_advertisements_()
  , can_get_viewers_()
  , can_mark_tasks_as_done_()
  , can_recognize_speech_()
  , can_report_chat_()
  , can_report_reactions_()
  , can_report_supergroup_spam_()
  , can_set_fact_check_()
  , has_protected_content_by_current_user_()
  , has_protected_content_by_other_user_()
  , need_show_statistics_()
{}

messageProperties::messageProperties(bool can_add_offer_, bool can_add_tasks_, bool can_be_approved_, bool can_be_copied_, bool can_be_copied_to_secret_chat_, bool can_be_declined_, bool can_be_deleted_only_for_self_, bool can_be_deleted_for_all_users_, bool can_be_edited_, bool can_be_forwarded_, bool can_be_paid_, bool can_be_pinned_, bool can_be_replied_, bool can_be_replied_in_another_chat_, bool can_be_saved_, bool can_be_shared_in_story_, bool can_edit_media_, bool can_edit_scheduling_state_, bool can_edit_suggested_post_info_, bool can_get_author_, bool can_get_embedding_code_, bool can_get_link_, bool can_get_media_timestamp_links_, bool can_get_message_thread_, bool can_get_read_date_, bool can_get_statistics_, bool can_get_video_advertisements_, bool can_get_viewers_, bool can_mark_tasks_as_done_, bool can_recognize_speech_, bool can_report_chat_, bool can_report_reactions_, bool can_report_supergroup_spam_, bool can_set_fact_check_, bool has_protected_content_by_current_user_, bool has_protected_content_by_other_user_, bool need_show_statistics_)
  : can_add_offer_(can_add_offer_)
  , can_add_tasks_(can_add_tasks_)
  , can_be_approved_(can_be_approved_)
  , can_be_copied_(can_be_copied_)
  , can_be_copied_to_secret_chat_(can_be_copied_to_secret_chat_)
  , can_be_declined_(can_be_declined_)
  , can_be_deleted_only_for_self_(can_be_deleted_only_for_self_)
  , can_be_deleted_for_all_users_(can_be_deleted_for_all_users_)
  , can_be_edited_(can_be_edited_)
  , can_be_forwarded_(can_be_forwarded_)
  , can_be_paid_(can_be_paid_)
  , can_be_pinned_(can_be_pinned_)
  , can_be_replied_(can_be_replied_)
  , can_be_replied_in_another_chat_(can_be_replied_in_another_chat_)
  , can_be_saved_(can_be_saved_)
  , can_be_shared_in_story_(can_be_shared_in_story_)
  , can_edit_media_(can_edit_media_)
  , can_edit_scheduling_state_(can_edit_scheduling_state_)
  , can_edit_suggested_post_info_(can_edit_suggested_post_info_)
  , can_get_author_(can_get_author_)
  , can_get_embedding_code_(can_get_embedding_code_)
  , can_get_link_(can_get_link_)
  , can_get_media_timestamp_links_(can_get_media_timestamp_links_)
  , can_get_message_thread_(can_get_message_thread_)
  , can_get_read_date_(can_get_read_date_)
  , can_get_statistics_(can_get_statistics_)
  , can_get_video_advertisements_(can_get_video_advertisements_)
  , can_get_viewers_(can_get_viewers_)
  , can_mark_tasks_as_done_(can_mark_tasks_as_done_)
  , can_recognize_speech_(can_recognize_speech_)
  , can_report_chat_(can_report_chat_)
  , can_report_reactions_(can_report_reactions_)
  , can_report_supergroup_spam_(can_report_supergroup_spam_)
  , can_set_fact_check_(can_set_fact_check_)
  , has_protected_content_by_current_user_(has_protected_content_by_current_user_)
  , has_protected_content_by_other_user_(has_protected_content_by_other_user_)
  , need_show_statistics_(need_show_statistics_)
{}

const std::int32_t messageProperties::ID;

void messageProperties::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageProperties");
    s.store_field("can_add_offer", can_add_offer_);
    s.store_field("can_add_tasks", can_add_tasks_);
    s.store_field("can_be_approved", can_be_approved_);
    s.store_field("can_be_copied", can_be_copied_);
    s.store_field("can_be_copied_to_secret_chat", can_be_copied_to_secret_chat_);
    s.store_field("can_be_declined", can_be_declined_);
    s.store_field("can_be_deleted_only_for_self", can_be_deleted_only_for_self_);
    s.store_field("can_be_deleted_for_all_users", can_be_deleted_for_all_users_);
    s.store_field("can_be_edited", can_be_edited_);
    s.store_field("can_be_forwarded", can_be_forwarded_);
    s.store_field("can_be_paid", can_be_paid_);
    s.store_field("can_be_pinned", can_be_pinned_);
    s.store_field("can_be_replied", can_be_replied_);
    s.store_field("can_be_replied_in_another_chat", can_be_replied_in_another_chat_);
    s.store_field("can_be_saved", can_be_saved_);
    s.store_field("can_be_shared_in_story", can_be_shared_in_story_);
    s.store_field("can_edit_media", can_edit_media_);
    s.store_field("can_edit_scheduling_state", can_edit_scheduling_state_);
    s.store_field("can_edit_suggested_post_info", can_edit_suggested_post_info_);
    s.store_field("can_get_author", can_get_author_);
    s.store_field("can_get_embedding_code", can_get_embedding_code_);
    s.store_field("can_get_link", can_get_link_);
    s.store_field("can_get_media_timestamp_links", can_get_media_timestamp_links_);
    s.store_field("can_get_message_thread", can_get_message_thread_);
    s.store_field("can_get_read_date", can_get_read_date_);
    s.store_field("can_get_statistics", can_get_statistics_);
    s.store_field("can_get_video_advertisements", can_get_video_advertisements_);
    s.store_field("can_get_viewers", can_get_viewers_);
    s.store_field("can_mark_tasks_as_done", can_mark_tasks_as_done_);
    s.store_field("can_recognize_speech", can_recognize_speech_);
    s.store_field("can_report_chat", can_report_chat_);
    s.store_field("can_report_reactions", can_report_reactions_);
    s.store_field("can_report_supergroup_spam", can_report_supergroup_spam_);
    s.store_field("can_set_fact_check", can_set_fact_check_);
    s.store_field("has_protected_content_by_current_user", has_protected_content_by_current_user_);
    s.store_field("has_protected_content_by_other_user", has_protected_content_by_other_user_);
    s.store_field("need_show_statistics", need_show_statistics_);
    s.store_class_end();
  }
}

messageReaction::messageReaction()
  : type_()
  , total_count_()
  , is_chosen_()
  , used_sender_id_()
  , recent_sender_ids_()
{}

messageReaction::messageReaction(object_ptr<ReactionType> &&type_, int32 total_count_, bool is_chosen_, object_ptr<MessageSender> &&used_sender_id_, array<object_ptr<MessageSender>> &&recent_sender_ids_)
  : type_(std::move(type_))
  , total_count_(total_count_)
  , is_chosen_(is_chosen_)
  , used_sender_id_(std::move(used_sender_id_))
  , recent_sender_ids_(std::move(recent_sender_ids_))
{}

const std::int32_t messageReaction::ID;

void messageReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReaction");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("total_count", total_count_);
    s.store_field("is_chosen", is_chosen_);
    s.store_object_field("used_sender_id", static_cast<const BaseObject *>(used_sender_id_.get()));
    { s.store_vector_begin("recent_sender_ids", recent_sender_ids_.size()); for (const auto &_value : recent_sender_ids_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageSchedulingStateSendAtDate::messageSchedulingStateSendAtDate()
  : send_date_()
  , repeat_period_()
{}

messageSchedulingStateSendAtDate::messageSchedulingStateSendAtDate(int32 send_date_, int32 repeat_period_)
  : send_date_(send_date_)
  , repeat_period_(repeat_period_)
{}

const std::int32_t messageSchedulingStateSendAtDate::ID;

void messageSchedulingStateSendAtDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSchedulingStateSendAtDate");
    s.store_field("send_date", send_date_);
    s.store_field("repeat_period", repeat_period_);
    s.store_class_end();
  }
}

messageSchedulingStateSendWhenOnline::messageSchedulingStateSendWhenOnline() {
}

const std::int32_t messageSchedulingStateSendWhenOnline::ID;

void messageSchedulingStateSendWhenOnline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSchedulingStateSendWhenOnline");
    s.store_class_end();
  }
}

messageSchedulingStateSendWhenVideoProcessed::messageSchedulingStateSendWhenVideoProcessed()
  : send_date_()
{}

messageSchedulingStateSendWhenVideoProcessed::messageSchedulingStateSendWhenVideoProcessed(int32 send_date_)
  : send_date_(send_date_)
{}

const std::int32_t messageSchedulingStateSendWhenVideoProcessed::ID;

void messageSchedulingStateSendWhenVideoProcessed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSchedulingStateSendWhenVideoProcessed");
    s.store_field("send_date", send_date_);
    s.store_class_end();
  }
}

messageStatistics::messageStatistics()
  : message_interaction_graph_()
  , message_reaction_graph_()
{}

messageStatistics::messageStatistics(object_ptr<StatisticalGraph> &&message_interaction_graph_, object_ptr<StatisticalGraph> &&message_reaction_graph_)
  : message_interaction_graph_(std::move(message_interaction_graph_))
  , message_reaction_graph_(std::move(message_reaction_graph_))
{}

const std::int32_t messageStatistics::ID;

void messageStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageStatistics");
    s.store_object_field("message_interaction_graph", static_cast<const BaseObject *>(message_interaction_graph_.get()));
    s.store_object_field("message_reaction_graph", static_cast<const BaseObject *>(message_reaction_graph_.get()));
    s.store_class_end();
  }
}

notificationGroup::notificationGroup()
  : id_()
  , type_()
  , chat_id_()
  , total_count_()
  , notifications_()
{}

notificationGroup::notificationGroup(int32 id_, object_ptr<NotificationGroupType> &&type_, int53 chat_id_, int32 total_count_, array<object_ptr<notification>> &&notifications_)
  : id_(id_)
  , type_(std::move(type_))
  , chat_id_(chat_id_)
  , total_count_(total_count_)
  , notifications_(std::move(notifications_))
{}

const std::int32_t notificationGroup::ID;

void notificationGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationGroup");
    s.store_field("id", id_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("chat_id", chat_id_);
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("notifications", notifications_.size()); for (const auto &_value : notifications_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

oauthLinkInfo::oauthLinkInfo()
  : user_id_()
  , url_()
  , domain_()
  , from_app_()
  , verified_app_name_()
  , bot_user_id_()
  , request_write_access_()
  , request_phone_number_access_()
  , browser_()
  , platform_()
  , ip_address_()
  , location_()
  , match_code_first_()
  , match_codes_()
{}

oauthLinkInfo::oauthLinkInfo(int53 user_id_, string const &url_, string const &domain_, bool from_app_, string const &verified_app_name_, int53 bot_user_id_, bool request_write_access_, bool request_phone_number_access_, string const &browser_, string const &platform_, string const &ip_address_, string const &location_, bool match_code_first_, array<string> &&match_codes_)
  : user_id_(user_id_)
  , url_(url_)
  , domain_(domain_)
  , from_app_(from_app_)
  , verified_app_name_(verified_app_name_)
  , bot_user_id_(bot_user_id_)
  , request_write_access_(request_write_access_)
  , request_phone_number_access_(request_phone_number_access_)
  , browser_(browser_)
  , platform_(platform_)
  , ip_address_(ip_address_)
  , location_(location_)
  , match_code_first_(match_code_first_)
  , match_codes_(std::move(match_codes_))
{}

const std::int32_t oauthLinkInfo::ID;

void oauthLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "oauthLinkInfo");
    s.store_field("user_id", user_id_);
    s.store_field("url", url_);
    s.store_field("domain", domain_);
    s.store_field("from_app", from_app_);
    s.store_field("verified_app_name", verified_app_name_);
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("request_write_access", request_write_access_);
    s.store_field("request_phone_number_access", request_phone_number_access_);
    s.store_field("browser", browser_);
    s.store_field("platform", platform_);
    s.store_field("ip_address", ip_address_);
    s.store_field("location", location_);
    s.store_field("match_code_first", match_code_first_);
    { s.store_vector_begin("match_codes", match_codes_.size()); for (const auto &_value : match_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

outline::outline()
  : paths_()
{}

outline::outline(array<object_ptr<closedVectorPath>> &&paths_)
  : paths_(std::move(paths_))
{}

const std::int32_t outline::ID;

void outline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "outline");
    { s.store_vector_begin("paths", paths_.size()); for (const auto &_value : paths_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

pageBlockVerticalAlignmentTop::pageBlockVerticalAlignmentTop() {
}

const std::int32_t pageBlockVerticalAlignmentTop::ID;

void pageBlockVerticalAlignmentTop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockVerticalAlignmentTop");
    s.store_class_end();
  }
}

pageBlockVerticalAlignmentMiddle::pageBlockVerticalAlignmentMiddle() {
}

const std::int32_t pageBlockVerticalAlignmentMiddle::ID;

void pageBlockVerticalAlignmentMiddle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockVerticalAlignmentMiddle");
    s.store_class_end();
  }
}

pageBlockVerticalAlignmentBottom::pageBlockVerticalAlignmentBottom() {
}

const std::int32_t pageBlockVerticalAlignmentBottom::ID;

void pageBlockVerticalAlignmentBottom::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockVerticalAlignmentBottom");
    s.store_class_end();
  }
}

paidReactionTypeRegular::paidReactionTypeRegular() {
}

const std::int32_t paidReactionTypeRegular::ID;

void paidReactionTypeRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidReactionTypeRegular");
    s.store_class_end();
  }
}

paidReactionTypeAnonymous::paidReactionTypeAnonymous() {
}

const std::int32_t paidReactionTypeAnonymous::ID;

void paidReactionTypeAnonymous::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidReactionTypeAnonymous");
    s.store_class_end();
  }
}

paidReactionTypeChat::paidReactionTypeChat()
  : chat_id_()
{}

paidReactionTypeChat::paidReactionTypeChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t paidReactionTypeChat::ID;

void paidReactionTypeChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidReactionTypeChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

passportElementError::passportElementError()
  : type_()
  , message_()
  , source_()
{}

passportElementError::passportElementError(object_ptr<PassportElementType> &&type_, string const &message_, object_ptr<PassportElementErrorSource> &&source_)
  : type_(std::move(type_))
  , message_(message_)
  , source_(std::move(source_))
{}

const std::int32_t passportElementError::ID;

void passportElementError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementError");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("message", message_);
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_class_end();
  }
}

passportElementErrorSourceUnspecified::passportElementErrorSourceUnspecified() {
}

const std::int32_t passportElementErrorSourceUnspecified::ID;

void passportElementErrorSourceUnspecified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceUnspecified");
    s.store_class_end();
  }
}

passportElementErrorSourceDataField::passportElementErrorSourceDataField()
  : field_name_()
{}

passportElementErrorSourceDataField::passportElementErrorSourceDataField(string const &field_name_)
  : field_name_(field_name_)
{}

const std::int32_t passportElementErrorSourceDataField::ID;

void passportElementErrorSourceDataField::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceDataField");
    s.store_field("field_name", field_name_);
    s.store_class_end();
  }
}

passportElementErrorSourceFrontSide::passportElementErrorSourceFrontSide() {
}

const std::int32_t passportElementErrorSourceFrontSide::ID;

void passportElementErrorSourceFrontSide::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceFrontSide");
    s.store_class_end();
  }
}

passportElementErrorSourceReverseSide::passportElementErrorSourceReverseSide() {
}

const std::int32_t passportElementErrorSourceReverseSide::ID;

void passportElementErrorSourceReverseSide::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceReverseSide");
    s.store_class_end();
  }
}

passportElementErrorSourceSelfie::passportElementErrorSourceSelfie() {
}

const std::int32_t passportElementErrorSourceSelfie::ID;

void passportElementErrorSourceSelfie::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceSelfie");
    s.store_class_end();
  }
}

passportElementErrorSourceTranslationFile::passportElementErrorSourceTranslationFile()
  : file_index_()
{}

passportElementErrorSourceTranslationFile::passportElementErrorSourceTranslationFile(int32 file_index_)
  : file_index_(file_index_)
{}

const std::int32_t passportElementErrorSourceTranslationFile::ID;

void passportElementErrorSourceTranslationFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceTranslationFile");
    s.store_field("file_index", file_index_);
    s.store_class_end();
  }
}

passportElementErrorSourceTranslationFiles::passportElementErrorSourceTranslationFiles() {
}

const std::int32_t passportElementErrorSourceTranslationFiles::ID;

void passportElementErrorSourceTranslationFiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceTranslationFiles");
    s.store_class_end();
  }
}

passportElementErrorSourceFile::passportElementErrorSourceFile()
  : file_index_()
{}

passportElementErrorSourceFile::passportElementErrorSourceFile(int32 file_index_)
  : file_index_(file_index_)
{}

const std::int32_t passportElementErrorSourceFile::ID;

void passportElementErrorSourceFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceFile");
    s.store_field("file_index", file_index_);
    s.store_class_end();
  }
}

passportElementErrorSourceFiles::passportElementErrorSourceFiles() {
}

const std::int32_t passportElementErrorSourceFiles::ID;

void passportElementErrorSourceFiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceFiles");
    s.store_class_end();
  }
}

passportElementsWithErrors::passportElementsWithErrors()
  : elements_()
  , errors_()
{}

passportElementsWithErrors::passportElementsWithErrors(array<object_ptr<PassportElement>> &&elements_, array<object_ptr<passportElementError>> &&errors_)
  : elements_(std::move(elements_))
  , errors_(std::move(errors_))
{}

const std::int32_t passportElementsWithErrors::ID;

void passportElementsWithErrors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementsWithErrors");
    { s.store_vector_begin("elements", elements_.size()); for (const auto &_value : elements_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("errors", errors_.size()); for (const auto &_value : errors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

passwordState::passwordState()
  : has_password_()
  , password_hint_()
  , has_recovery_email_address_()
  , has_passport_data_()
  , recovery_email_address_code_info_()
  , login_email_address_pattern_()
  , pending_reset_date_()
{}

passwordState::passwordState(bool has_password_, string const &password_hint_, bool has_recovery_email_address_, bool has_passport_data_, object_ptr<emailAddressAuthenticationCodeInfo> &&recovery_email_address_code_info_, string const &login_email_address_pattern_, int32 pending_reset_date_)
  : has_password_(has_password_)
  , password_hint_(password_hint_)
  , has_recovery_email_address_(has_recovery_email_address_)
  , has_passport_data_(has_passport_data_)
  , recovery_email_address_code_info_(std::move(recovery_email_address_code_info_))
  , login_email_address_pattern_(login_email_address_pattern_)
  , pending_reset_date_(pending_reset_date_)
{}

const std::int32_t passwordState::ID;

void passwordState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passwordState");
    s.store_field("has_password", has_password_);
    s.store_field("password_hint", password_hint_);
    s.store_field("has_recovery_email_address", has_recovery_email_address_);
    s.store_field("has_passport_data", has_passport_data_);
    s.store_object_field("recovery_email_address_code_info", static_cast<const BaseObject *>(recovery_email_address_code_info_.get()));
    s.store_field("login_email_address_pattern", login_email_address_pattern_);
    s.store_field("pending_reset_date", pending_reset_date_);
    s.store_class_end();
  }
}

phoneNumberCodeTypeChange::phoneNumberCodeTypeChange() {
}

const std::int32_t phoneNumberCodeTypeChange::ID;

void phoneNumberCodeTypeChange::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneNumberCodeTypeChange");
    s.store_class_end();
  }
}

phoneNumberCodeTypeVerify::phoneNumberCodeTypeVerify() {
}

const std::int32_t phoneNumberCodeTypeVerify::ID;

void phoneNumberCodeTypeVerify::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneNumberCodeTypeVerify");
    s.store_class_end();
  }
}

phoneNumberCodeTypeConfirmOwnership::phoneNumberCodeTypeConfirmOwnership()
  : hash_()
{}

phoneNumberCodeTypeConfirmOwnership::phoneNumberCodeTypeConfirmOwnership(string const &hash_)
  : hash_(hash_)
{}

const std::int32_t phoneNumberCodeTypeConfirmOwnership::ID;

void phoneNumberCodeTypeConfirmOwnership::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneNumberCodeTypeConfirmOwnership");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

savedCredentials::savedCredentials()
  : id_()
  , title_()
{}

savedCredentials::savedCredentials(string const &id_, string const &title_)
  : id_(id_)
  , title_(title_)
{}

const std::int32_t savedCredentials::ID;

void savedCredentials::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedCredentials");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

sharedUser::sharedUser()
  : user_id_()
  , first_name_()
  , last_name_()
  , username_()
  , photo_()
{}

sharedUser::sharedUser(int53 user_id_, string const &first_name_, string const &last_name_, string const &username_, object_ptr<photo> &&photo_)
  : user_id_(user_id_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , username_(username_)
  , photo_(std::move(photo_))
{}

const std::int32_t sharedUser::ID;

void sharedUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sharedUser");
    s.store_field("user_id", user_id_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_field("username", username_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

storageStatistics::storageStatistics()
  : size_()
  , count_()
  , by_chat_()
{}

storageStatistics::storageStatistics(int53 size_, int32 count_, array<object_ptr<storageStatisticsByChat>> &&by_chat_)
  : size_(size_)
  , count_(count_)
  , by_chat_(std::move(by_chat_))
{}

const std::int32_t storageStatistics::ID;

void storageStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storageStatistics");
    s.store_field("size", size_);
    s.store_field("count", count_);
    { s.store_vector_begin("by_chat", by_chat_.size()); for (const auto &_value : by_chat_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

suggestedPostInfo::suggestedPostInfo()
  : price_()
  , send_date_()
  , state_()
  , can_be_approved_()
  , can_be_declined_()
{}

suggestedPostInfo::suggestedPostInfo(object_ptr<SuggestedPostPrice> &&price_, int32 send_date_, object_ptr<SuggestedPostState> &&state_, bool can_be_approved_, bool can_be_declined_)
  : price_(std::move(price_))
  , send_date_(send_date_)
  , state_(std::move(state_))
  , can_be_approved_(can_be_approved_)
  , can_be_declined_(can_be_declined_)
{}

const std::int32_t suggestedPostInfo::ID;

void suggestedPostInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedPostInfo");
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_field("send_date", send_date_);
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_field("can_be_approved", can_be_approved_);
    s.store_field("can_be_declined", can_be_declined_);
    s.store_class_end();
  }
}

suggestedPostPriceStar::suggestedPostPriceStar()
  : star_count_()
{}

suggestedPostPriceStar::suggestedPostPriceStar(int53 star_count_)
  : star_count_(star_count_)
{}

const std::int32_t suggestedPostPriceStar::ID;

void suggestedPostPriceStar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedPostPriceStar");
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

suggestedPostPriceTon::suggestedPostPriceTon()
  : toncoin_cent_count_()
{}

suggestedPostPriceTon::suggestedPostPriceTon(int53 toncoin_cent_count_)
  : toncoin_cent_count_(toncoin_cent_count_)
{}

const std::int32_t suggestedPostPriceTon::ID;

void suggestedPostPriceTon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedPostPriceTon");
    s.store_field("toncoin_cent_count", toncoin_cent_count_);
    s.store_class_end();
  }
}

textEntity::textEntity()
  : offset_()
  , length_()
  , type_()
{}

textEntity::textEntity(int32 offset_, int32 length_, object_ptr<TextEntityType> &&type_)
  : offset_(offset_)
  , length_(length_)
  , type_(std::move(type_))
{}

const std::int32_t textEntity::ID;

void textEntity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntity");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

tonTransactionTypeFragmentDeposit::tonTransactionTypeFragmentDeposit()
  : is_gift_()
  , sticker_()
{}

tonTransactionTypeFragmentDeposit::tonTransactionTypeFragmentDeposit(bool is_gift_, object_ptr<sticker> &&sticker_)
  : is_gift_(is_gift_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t tonTransactionTypeFragmentDeposit::ID;

void tonTransactionTypeFragmentDeposit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransactionTypeFragmentDeposit");
    s.store_field("is_gift", is_gift_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

tonTransactionTypeFragmentWithdrawal::tonTransactionTypeFragmentWithdrawal()
  : withdrawal_state_()
{}

tonTransactionTypeFragmentWithdrawal::tonTransactionTypeFragmentWithdrawal(object_ptr<RevenueWithdrawalState> &&withdrawal_state_)
  : withdrawal_state_(std::move(withdrawal_state_))
{}

const std::int32_t tonTransactionTypeFragmentWithdrawal::ID;

void tonTransactionTypeFragmentWithdrawal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransactionTypeFragmentWithdrawal");
    s.store_object_field("withdrawal_state", static_cast<const BaseObject *>(withdrawal_state_.get()));
    s.store_class_end();
  }
}

tonTransactionTypeSuggestedPostPayment::tonTransactionTypeSuggestedPostPayment()
  : chat_id_()
{}

tonTransactionTypeSuggestedPostPayment::tonTransactionTypeSuggestedPostPayment(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t tonTransactionTypeSuggestedPostPayment::ID;

void tonTransactionTypeSuggestedPostPayment::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransactionTypeSuggestedPostPayment");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

tonTransactionTypeGiftPurchaseOffer::tonTransactionTypeGiftPurchaseOffer()
  : gift_()
{}

tonTransactionTypeGiftPurchaseOffer::tonTransactionTypeGiftPurchaseOffer(object_ptr<upgradedGift> &&gift_)
  : gift_(std::move(gift_))
{}

const std::int32_t tonTransactionTypeGiftPurchaseOffer::ID;

void tonTransactionTypeGiftPurchaseOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransactionTypeGiftPurchaseOffer");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

tonTransactionTypeUpgradedGiftPurchase::tonTransactionTypeUpgradedGiftPurchase()
  : user_id_()
  , gift_()
{}

tonTransactionTypeUpgradedGiftPurchase::tonTransactionTypeUpgradedGiftPurchase(int53 user_id_, object_ptr<upgradedGift> &&gift_)
  : user_id_(user_id_)
  , gift_(std::move(gift_))
{}

const std::int32_t tonTransactionTypeUpgradedGiftPurchase::ID;

void tonTransactionTypeUpgradedGiftPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransactionTypeUpgradedGiftPurchase");
    s.store_field("user_id", user_id_);
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

tonTransactionTypeUpgradedGiftSale::tonTransactionTypeUpgradedGiftSale()
  : user_id_()
  , gift_()
  , commission_per_mille_()
  , commission_toncoin_amount_()
  , via_offer_()
{}

tonTransactionTypeUpgradedGiftSale::tonTransactionTypeUpgradedGiftSale(int53 user_id_, object_ptr<upgradedGift> &&gift_, int32 commission_per_mille_, int53 commission_toncoin_amount_, bool via_offer_)
  : user_id_(user_id_)
  , gift_(std::move(gift_))
  , commission_per_mille_(commission_per_mille_)
  , commission_toncoin_amount_(commission_toncoin_amount_)
  , via_offer_(via_offer_)
{}

const std::int32_t tonTransactionTypeUpgradedGiftSale::ID;

void tonTransactionTypeUpgradedGiftSale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransactionTypeUpgradedGiftSale");
    s.store_field("user_id", user_id_);
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_field("commission_per_mille", commission_per_mille_);
    s.store_field("commission_toncoin_amount", commission_toncoin_amount_);
    s.store_field("via_offer", via_offer_);
    s.store_class_end();
  }
}

tonTransactionTypeStakeDiceStake::tonTransactionTypeStakeDiceStake() {
}

const std::int32_t tonTransactionTypeStakeDiceStake::ID;

void tonTransactionTypeStakeDiceStake::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransactionTypeStakeDiceStake");
    s.store_class_end();
  }
}

tonTransactionTypeStakeDicePayout::tonTransactionTypeStakeDicePayout() {
}

const std::int32_t tonTransactionTypeStakeDicePayout::ID;

void tonTransactionTypeStakeDicePayout::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransactionTypeStakeDicePayout");
    s.store_class_end();
  }
}

tonTransactionTypeUnsupported::tonTransactionTypeUnsupported() {
}

const std::int32_t tonTransactionTypeUnsupported::ID;

void tonTransactionTypeUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransactionTypeUnsupported");
    s.store_class_end();
  }
}

updates::updates()
  : updates_()
{}

updates::updates(array<object_ptr<Update>> &&updates_)
  : updates_(std::move(updates_))
{}

const std::int32_t updates::ID;

void updates::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates");
    { s.store_vector_begin("updates", updates_.size()); for (const auto &_value : updates_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

upgradedGiftModelCount::upgradedGiftModelCount()
  : model_()
  , total_count_()
{}

upgradedGiftModelCount::upgradedGiftModelCount(object_ptr<upgradedGiftModel> &&model_, int32 total_count_)
  : model_(std::move(model_))
  , total_count_(total_count_)
{}

const std::int32_t upgradedGiftModelCount::ID;

void upgradedGiftModelCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftModelCount");
    s.store_object_field("model", static_cast<const BaseObject *>(model_.get()));
    s.store_field("total_count", total_count_);
    s.store_class_end();
  }
}

userPrivacySettingShowStatus::userPrivacySettingShowStatus() {
}

const std::int32_t userPrivacySettingShowStatus::ID;

void userPrivacySettingShowStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingShowStatus");
    s.store_class_end();
  }
}

userPrivacySettingShowProfilePhoto::userPrivacySettingShowProfilePhoto() {
}

const std::int32_t userPrivacySettingShowProfilePhoto::ID;

void userPrivacySettingShowProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingShowProfilePhoto");
    s.store_class_end();
  }
}

userPrivacySettingShowLinkInForwardedMessages::userPrivacySettingShowLinkInForwardedMessages() {
}

const std::int32_t userPrivacySettingShowLinkInForwardedMessages::ID;

void userPrivacySettingShowLinkInForwardedMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingShowLinkInForwardedMessages");
    s.store_class_end();
  }
}

userPrivacySettingShowPhoneNumber::userPrivacySettingShowPhoneNumber() {
}

const std::int32_t userPrivacySettingShowPhoneNumber::ID;

void userPrivacySettingShowPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingShowPhoneNumber");
    s.store_class_end();
  }
}

userPrivacySettingShowBio::userPrivacySettingShowBio() {
}

const std::int32_t userPrivacySettingShowBio::ID;

void userPrivacySettingShowBio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingShowBio");
    s.store_class_end();
  }
}

userPrivacySettingShowBirthdate::userPrivacySettingShowBirthdate() {
}

const std::int32_t userPrivacySettingShowBirthdate::ID;

void userPrivacySettingShowBirthdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingShowBirthdate");
    s.store_class_end();
  }
}

userPrivacySettingShowProfileAudio::userPrivacySettingShowProfileAudio() {
}

const std::int32_t userPrivacySettingShowProfileAudio::ID;

void userPrivacySettingShowProfileAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingShowProfileAudio");
    s.store_class_end();
  }
}

userPrivacySettingAllowChatInvites::userPrivacySettingAllowChatInvites() {
}

const std::int32_t userPrivacySettingAllowChatInvites::ID;

void userPrivacySettingAllowChatInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingAllowChatInvites");
    s.store_class_end();
  }
}

userPrivacySettingAllowCalls::userPrivacySettingAllowCalls() {
}

const std::int32_t userPrivacySettingAllowCalls::ID;

void userPrivacySettingAllowCalls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingAllowCalls");
    s.store_class_end();
  }
}

userPrivacySettingAllowPeerToPeerCalls::userPrivacySettingAllowPeerToPeerCalls() {
}

const std::int32_t userPrivacySettingAllowPeerToPeerCalls::ID;

void userPrivacySettingAllowPeerToPeerCalls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingAllowPeerToPeerCalls");
    s.store_class_end();
  }
}

userPrivacySettingAllowFindingByPhoneNumber::userPrivacySettingAllowFindingByPhoneNumber() {
}

const std::int32_t userPrivacySettingAllowFindingByPhoneNumber::ID;

void userPrivacySettingAllowFindingByPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingAllowFindingByPhoneNumber");
    s.store_class_end();
  }
}

userPrivacySettingAllowPrivateVoiceAndVideoNoteMessages::userPrivacySettingAllowPrivateVoiceAndVideoNoteMessages() {
}

const std::int32_t userPrivacySettingAllowPrivateVoiceAndVideoNoteMessages::ID;

void userPrivacySettingAllowPrivateVoiceAndVideoNoteMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingAllowPrivateVoiceAndVideoNoteMessages");
    s.store_class_end();
  }
}

userPrivacySettingAutosaveGifts::userPrivacySettingAutosaveGifts() {
}

const std::int32_t userPrivacySettingAutosaveGifts::ID;

void userPrivacySettingAutosaveGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingAutosaveGifts");
    s.store_class_end();
  }
}

userPrivacySettingAllowUnpaidMessages::userPrivacySettingAllowUnpaidMessages() {
}

const std::int32_t userPrivacySettingAllowUnpaidMessages::ID;

void userPrivacySettingAllowUnpaidMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingAllowUnpaidMessages");
    s.store_class_end();
  }
}

userPrivacySettingRuleAllowAll::userPrivacySettingRuleAllowAll() {
}

const std::int32_t userPrivacySettingRuleAllowAll::ID;

void userPrivacySettingRuleAllowAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleAllowAll");
    s.store_class_end();
  }
}

userPrivacySettingRuleAllowContacts::userPrivacySettingRuleAllowContacts() {
}

const std::int32_t userPrivacySettingRuleAllowContacts::ID;

void userPrivacySettingRuleAllowContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleAllowContacts");
    s.store_class_end();
  }
}

userPrivacySettingRuleAllowBots::userPrivacySettingRuleAllowBots() {
}

const std::int32_t userPrivacySettingRuleAllowBots::ID;

void userPrivacySettingRuleAllowBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleAllowBots");
    s.store_class_end();
  }
}

userPrivacySettingRuleAllowPremiumUsers::userPrivacySettingRuleAllowPremiumUsers() {
}

const std::int32_t userPrivacySettingRuleAllowPremiumUsers::ID;

void userPrivacySettingRuleAllowPremiumUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleAllowPremiumUsers");
    s.store_class_end();
  }
}

userPrivacySettingRuleAllowUsers::userPrivacySettingRuleAllowUsers()
  : user_ids_()
{}

userPrivacySettingRuleAllowUsers::userPrivacySettingRuleAllowUsers(array<int53> &&user_ids_)
  : user_ids_(std::move(user_ids_))
{}

const std::int32_t userPrivacySettingRuleAllowUsers::ID;

void userPrivacySettingRuleAllowUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleAllowUsers");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

userPrivacySettingRuleAllowChatMembers::userPrivacySettingRuleAllowChatMembers()
  : chat_ids_()
{}

userPrivacySettingRuleAllowChatMembers::userPrivacySettingRuleAllowChatMembers(array<int53> &&chat_ids_)
  : chat_ids_(std::move(chat_ids_))
{}

const std::int32_t userPrivacySettingRuleAllowChatMembers::ID;

void userPrivacySettingRuleAllowChatMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleAllowChatMembers");
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

userPrivacySettingRuleRestrictAll::userPrivacySettingRuleRestrictAll() {
}

const std::int32_t userPrivacySettingRuleRestrictAll::ID;

void userPrivacySettingRuleRestrictAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleRestrictAll");
    s.store_class_end();
  }
}

userPrivacySettingRuleRestrictContacts::userPrivacySettingRuleRestrictContacts() {
}

const std::int32_t userPrivacySettingRuleRestrictContacts::ID;

void userPrivacySettingRuleRestrictContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleRestrictContacts");
    s.store_class_end();
  }
}

userPrivacySettingRuleRestrictBots::userPrivacySettingRuleRestrictBots() {
}

const std::int32_t userPrivacySettingRuleRestrictBots::ID;

void userPrivacySettingRuleRestrictBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleRestrictBots");
    s.store_class_end();
  }
}

userPrivacySettingRuleRestrictUsers::userPrivacySettingRuleRestrictUsers()
  : user_ids_()
{}

userPrivacySettingRuleRestrictUsers::userPrivacySettingRuleRestrictUsers(array<int53> &&user_ids_)
  : user_ids_(std::move(user_ids_))
{}

const std::int32_t userPrivacySettingRuleRestrictUsers::ID;

void userPrivacySettingRuleRestrictUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleRestrictUsers");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

userPrivacySettingRuleRestrictChatMembers::userPrivacySettingRuleRestrictChatMembers()
  : chat_ids_()
{}

userPrivacySettingRuleRestrictChatMembers::userPrivacySettingRuleRestrictChatMembers(array<int53> &&chat_ids_)
  : chat_ids_(std::move(chat_ids_))
{}

const std::int32_t userPrivacySettingRuleRestrictChatMembers::ID;

void userPrivacySettingRuleRestrictChatMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleRestrictChatMembers");
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

userTypeRegular::userTypeRegular() {
}

const std::int32_t userTypeRegular::ID;

void userTypeRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userTypeRegular");
    s.store_class_end();
  }
}

userTypeDeleted::userTypeDeleted() {
}

const std::int32_t userTypeDeleted::ID;

void userTypeDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userTypeDeleted");
    s.store_class_end();
  }
}

userTypeBot::userTypeBot()
  : can_be_edited_()
  , can_join_groups_()
  , can_read_all_group_messages_()
  , has_main_web_app_()
  , has_topics_()
  , allows_users_to_create_topics_()
  , can_manage_bots_()
  , is_inline_()
  , inline_query_placeholder_()
  , need_location_()
  , can_connect_to_business_()
  , can_be_added_to_attachment_menu_()
  , active_user_count_()
{}

userTypeBot::userTypeBot(bool can_be_edited_, bool can_join_groups_, bool can_read_all_group_messages_, bool has_main_web_app_, bool has_topics_, bool allows_users_to_create_topics_, bool can_manage_bots_, bool is_inline_, string const &inline_query_placeholder_, bool need_location_, bool can_connect_to_business_, bool can_be_added_to_attachment_menu_, int32 active_user_count_)
  : can_be_edited_(can_be_edited_)
  , can_join_groups_(can_join_groups_)
  , can_read_all_group_messages_(can_read_all_group_messages_)
  , has_main_web_app_(has_main_web_app_)
  , has_topics_(has_topics_)
  , allows_users_to_create_topics_(allows_users_to_create_topics_)
  , can_manage_bots_(can_manage_bots_)
  , is_inline_(is_inline_)
  , inline_query_placeholder_(inline_query_placeholder_)
  , need_location_(need_location_)
  , can_connect_to_business_(can_connect_to_business_)
  , can_be_added_to_attachment_menu_(can_be_added_to_attachment_menu_)
  , active_user_count_(active_user_count_)
{}

const std::int32_t userTypeBot::ID;

void userTypeBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userTypeBot");
    s.store_field("can_be_edited", can_be_edited_);
    s.store_field("can_join_groups", can_join_groups_);
    s.store_field("can_read_all_group_messages", can_read_all_group_messages_);
    s.store_field("has_main_web_app", has_main_web_app_);
    s.store_field("has_topics", has_topics_);
    s.store_field("allows_users_to_create_topics", allows_users_to_create_topics_);
    s.store_field("can_manage_bots", can_manage_bots_);
    s.store_field("is_inline", is_inline_);
    s.store_field("inline_query_placeholder", inline_query_placeholder_);
    s.store_field("need_location", need_location_);
    s.store_field("can_connect_to_business", can_connect_to_business_);
    s.store_field("can_be_added_to_attachment_menu", can_be_added_to_attachment_menu_);
    s.store_field("active_user_count", active_user_count_);
    s.store_class_end();
  }
}

userTypeUnknown::userTypeUnknown() {
}

const std::int32_t userTypeUnknown::ID;

void userTypeUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userTypeUnknown");
    s.store_class_end();
  }
}

addPendingPaidMessageReaction::addPendingPaidMessageReaction()
  : chat_id_()
  , message_id_()
  , star_count_()
  , type_()
{}

addPendingPaidMessageReaction::addPendingPaidMessageReaction(int53 chat_id_, int53 message_id_, int53 star_count_, object_ptr<PaidReactionType> &&type_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , star_count_(star_count_)
  , type_(std::move(type_))
{}

const std::int32_t addPendingPaidMessageReaction::ID;

void addPendingPaidMessageReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addPendingPaidMessageReaction");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("star_count", star_count_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

allowUnpaidMessagesFromUser::allowUnpaidMessagesFromUser()
  : user_id_()
  , refund_payments_()
{}

allowUnpaidMessagesFromUser::allowUnpaidMessagesFromUser(int53 user_id_, bool refund_payments_)
  : user_id_(user_id_)
  , refund_payments_(refund_payments_)
{}

const std::int32_t allowUnpaidMessagesFromUser::ID;

void allowUnpaidMessagesFromUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "allowUnpaidMessagesFromUser");
    s.store_field("user_id", user_id_);
    s.store_field("refund_payments", refund_payments_);
    s.store_class_end();
  }
}

answerShippingQuery::answerShippingQuery()
  : shipping_query_id_()
  , shipping_options_()
  , error_message_()
{}

answerShippingQuery::answerShippingQuery(int64 shipping_query_id_, array<object_ptr<shippingOption>> &&shipping_options_, string const &error_message_)
  : shipping_query_id_(shipping_query_id_)
  , shipping_options_(std::move(shipping_options_))
  , error_message_(error_message_)
{}

const std::int32_t answerShippingQuery::ID;

void answerShippingQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerShippingQuery");
    s.store_field("shipping_query_id", shipping_query_id_);
    { s.store_vector_begin("shipping_options", shipping_options_.size()); for (const auto &_value : shipping_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("error_message", error_message_);
    s.store_class_end();
  }
}

cancelRecoveryEmailAddressVerification::cancelRecoveryEmailAddressVerification() {
}

const std::int32_t cancelRecoveryEmailAddressVerification::ID;

void cancelRecoveryEmailAddressVerification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "cancelRecoveryEmailAddressVerification");
    s.store_class_end();
  }
}

checkStickerSetName::checkStickerSetName()
  : name_()
{}

checkStickerSetName::checkStickerSetName(string const &name_)
  : name_(name_)
{}

const std::int32_t checkStickerSetName::ID;

void checkStickerSetName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkStickerSetName");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

closeWebApp::closeWebApp()
  : web_app_launch_id_()
{}

closeWebApp::closeWebApp(int64 web_app_launch_id_)
  : web_app_launch_id_(web_app_launch_id_)
{}

const std::int32_t closeWebApp::ID;

void closeWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "closeWebApp");
    s.store_field("web_app_launch_id", web_app_launch_id_);
    s.store_class_end();
  }
}

commitPendingPaidMessageReactions::commitPendingPaidMessageReactions()
  : chat_id_()
  , message_id_()
{}

commitPendingPaidMessageReactions::commitPendingPaidMessageReactions(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t commitPendingPaidMessageReactions::ID;

void commitPendingPaidMessageReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "commitPendingPaidMessageReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

createGiftCollection::createGiftCollection()
  : owner_id_()
  , name_()
  , received_gift_ids_()
{}

createGiftCollection::createGiftCollection(object_ptr<MessageSender> &&owner_id_, string const &name_, array<string> &&received_gift_ids_)
  : owner_id_(std::move(owner_id_))
  , name_(name_)
  , received_gift_ids_(std::move(received_gift_ids_))
{}

const std::int32_t createGiftCollection::ID;

void createGiftCollection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createGiftCollection");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("name", name_);
    { s.store_vector_begin("received_gift_ids", received_gift_ids_.size()); for (const auto &_value : received_gift_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

declineOauthRequest::declineOauthRequest()
  : url_()
{}

declineOauthRequest::declineOauthRequest(string const &url_)
  : url_(url_)
{}

const std::int32_t declineOauthRequest::ID;

void declineOauthRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "declineOauthRequest");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

deleteChatFolderInviteLink::deleteChatFolderInviteLink()
  : chat_folder_id_()
  , invite_link_()
{}

deleteChatFolderInviteLink::deleteChatFolderInviteLink(int32 chat_folder_id_, string const &invite_link_)
  : chat_folder_id_(chat_folder_id_)
  , invite_link_(invite_link_)
{}

const std::int32_t deleteChatFolderInviteLink::ID;

void deleteChatFolderInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChatFolderInviteLink");
    s.store_field("chat_folder_id", chat_folder_id_);
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

deleteDefaultBackground::deleteDefaultBackground()
  : for_dark_theme_()
{}

deleteDefaultBackground::deleteDefaultBackground(bool for_dark_theme_)
  : for_dark_theme_(for_dark_theme_)
{}

const std::int32_t deleteDefaultBackground::ID;

void deleteDefaultBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteDefaultBackground");
    s.store_field("for_dark_theme", for_dark_theme_);
    s.store_class_end();
  }
}

deleteFile::deleteFile()
  : file_id_()
{}

deleteFile::deleteFile(int32 file_id_)
  : file_id_(file_id_)
{}

const std::int32_t deleteFile::ID;

void deleteFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteFile");
    s.store_field("file_id", file_id_);
    s.store_class_end();
  }
}

deleteForumTopic::deleteForumTopic()
  : chat_id_()
  , forum_topic_id_()
{}

deleteForumTopic::deleteForumTopic(int53 chat_id_, int32 forum_topic_id_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
{}

const std::int32_t deleteForumTopic::ID;

void deleteForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteForumTopic");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_class_end();
  }
}

deleteLanguagePack::deleteLanguagePack()
  : language_pack_id_()
{}

deleteLanguagePack::deleteLanguagePack(string const &language_pack_id_)
  : language_pack_id_(language_pack_id_)
{}

const std::int32_t deleteLanguagePack::ID;

void deleteLanguagePack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteLanguagePack");
    s.store_field("language_pack_id", language_pack_id_);
    s.store_class_end();
  }
}

dropGiftOriginalDetails::dropGiftOriginalDetails()
  : received_gift_id_()
  , star_count_()
{}

dropGiftOriginalDetails::dropGiftOriginalDetails(string const &received_gift_id_, int53 star_count_)
  : received_gift_id_(received_gift_id_)
  , star_count_(star_count_)
{}

const std::int32_t dropGiftOriginalDetails::ID;

void dropGiftOriginalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dropGiftOriginalDetails");
    s.store_field("received_gift_id", received_gift_id_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

editBusinessMessageLiveLocation::editBusinessMessageLiveLocation()
  : business_connection_id_()
  , chat_id_()
  , message_id_()
  , reply_markup_()
  , location_()
  , live_period_()
  , heading_()
  , proximity_alert_radius_()
{}

editBusinessMessageLiveLocation::editBusinessMessageLiveLocation(string const &business_connection_id_, int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<location> &&location_, int32 live_period_, int32 heading_, int32 proximity_alert_radius_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , location_(std::move(location_))
  , live_period_(live_period_)
  , heading_(heading_)
  , proximity_alert_radius_(proximity_alert_radius_)
{}

const std::int32_t editBusinessMessageLiveLocation::ID;

void editBusinessMessageLiveLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editBusinessMessageLiveLocation");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("live_period", live_period_);
    s.store_field("heading", heading_);
    s.store_field("proximity_alert_radius", proximity_alert_radius_);
    s.store_class_end();
  }
}

editInlineMessageText::editInlineMessageText()
  : inline_message_id_()
  , reply_markup_()
  , input_message_content_()
{}

editInlineMessageText::editInlineMessageText(string const &inline_message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : inline_message_id_(inline_message_id_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t editInlineMessageText::ID;

void editInlineMessageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editInlineMessageText");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

editMessageCaption::editMessageCaption()
  : chat_id_()
  , message_id_()
  , reply_markup_()
  , caption_()
  , show_caption_above_media_()
{}

editMessageCaption::editMessageCaption(int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
{}

const std::int32_t editMessageCaption::ID;

void editMessageCaption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageCaption");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_class_end();
  }
}

editStory::editStory()
  : story_poster_chat_id_()
  , story_id_()
  , content_()
  , areas_()
  , caption_()
{}

editStory::editStory(int53 story_poster_chat_id_, int32 story_id_, object_ptr<InputStoryContent> &&content_, object_ptr<inputStoryAreas> &&areas_, object_ptr<formattedText> &&caption_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , content_(std::move(content_))
  , areas_(std::move(areas_))
  , caption_(std::move(caption_))
{}

const std::int32_t editStory::ID;

void editStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_object_field("areas", static_cast<const BaseObject *>(areas_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

finishFileGeneration::finishFileGeneration()
  : generation_id_()
  , error_()
{}

finishFileGeneration::finishFileGeneration(int64 generation_id_, object_ptr<error> &&error_)
  : generation_id_(generation_id_)
  , error_(std::move(error_))
{}

const std::int32_t finishFileGeneration::ID;

void finishFileGeneration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "finishFileGeneration");
    s.store_field("generation_id", generation_id_);
    s.store_object_field("error", static_cast<const BaseObject *>(error_.get()));
    s.store_class_end();
  }
}

getBotSimilarBotCount::getBotSimilarBotCount()
  : bot_user_id_()
  , return_local_()
{}

getBotSimilarBotCount::getBotSimilarBotCount(int53 bot_user_id_, bool return_local_)
  : bot_user_id_(bot_user_id_)
  , return_local_(return_local_)
{}

const std::int32_t getBotSimilarBotCount::ID;

void getBotSimilarBotCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBotSimilarBotCount");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("return_local", return_local_);
    s.store_class_end();
  }
}

getBusinessFeatures::getBusinessFeatures()
  : source_()
{}

getBusinessFeatures::getBusinessFeatures(object_ptr<BusinessFeature> &&source_)
  : source_(std::move(source_))
{}

const std::int32_t getBusinessFeatures::ID;

void getBusinessFeatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBusinessFeatures");
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_class_end();
  }
}

getChatBoostLink::getChatBoostLink()
  : chat_id_()
{}

getChatBoostLink::getChatBoostLink(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatBoostLink::ID;

void getChatBoostLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatBoostLink");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatStoryAlbums::getChatStoryAlbums()
  : chat_id_()
{}

getChatStoryAlbums::getChatStoryAlbums(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatStoryAlbums::ID;

void getChatStoryAlbums::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatStoryAlbums");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getCommands::getCommands()
  : scope_()
  , language_code_()
{}

getCommands::getCommands(object_ptr<BotCommandScope> &&scope_, string const &language_code_)
  : scope_(std::move(scope_))
  , language_code_(language_code_)
{}

const std::int32_t getCommands::ID;

void getCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCommands");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_field("language_code", language_code_);
    s.store_class_end();
  }
}

getDefaultChatEmojiStatuses::getDefaultChatEmojiStatuses() {
}

const std::int32_t getDefaultChatEmojiStatuses::ID;

void getDefaultChatEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDefaultChatEmojiStatuses");
    s.store_class_end();
  }
}

getExternalLink::getExternalLink()
  : link_()
  , allow_write_access_()
{}

getExternalLink::getExternalLink(string const &link_, bool allow_write_access_)
  : link_(link_)
  , allow_write_access_(allow_write_access_)
{}

const std::int32_t getExternalLink::ID;

void getExternalLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getExternalLink");
    s.store_field("link", link_);
    s.store_field("allow_write_access", allow_write_access_);
    s.store_class_end();
  }
}

getExternalLinkInfo::getExternalLinkInfo()
  : link_()
{}

getExternalLinkInfo::getExternalLinkInfo(string const &link_)
  : link_(link_)
{}

const std::int32_t getExternalLinkInfo::ID;

void getExternalLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getExternalLinkInfo");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

getFavoriteStickers::getFavoriteStickers() {
}

const std::int32_t getFavoriteStickers::ID;

void getFavoriteStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getFavoriteStickers");
    s.store_class_end();
  }
}

getGameHighScores::getGameHighScores()
  : chat_id_()
  , message_id_()
  , user_id_()
{}

getGameHighScores::getGameHighScores(int53 chat_id_, int53 message_id_, int53 user_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , user_id_(user_id_)
{}

const std::int32_t getGameHighScores::ID;

void getGameHighScores::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGameHighScores");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getGiveawayInfo::getGiveawayInfo()
  : chat_id_()
  , message_id_()
{}

getGiveawayInfo::getGiveawayInfo(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getGiveawayInfo::ID;

void getGiveawayInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGiveawayInfo");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getLiveStoryStreamer::getLiveStoryStreamer()
  : group_call_id_()
{}

getLiveStoryStreamer::getLiveStoryStreamer(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t getLiveStoryStreamer::ID;

void getLiveStoryStreamer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLiveStoryStreamer");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

getMessageEmbeddingCode::getMessageEmbeddingCode()
  : chat_id_()
  , message_id_()
  , for_album_()
{}

getMessageEmbeddingCode::getMessageEmbeddingCode(int53 chat_id_, int53 message_id_, bool for_album_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , for_album_(for_album_)
{}

const std::int32_t getMessageEmbeddingCode::ID;

void getMessageEmbeddingCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageEmbeddingCode");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("for_album", for_album_);
    s.store_class_end();
  }
}

getMessageViewers::getMessageViewers()
  : chat_id_()
  , message_id_()
{}

getMessageViewers::getMessageViewers(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getMessageViewers::ID;

void getMessageViewers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageViewers");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getOauthLinkInfo::getOauthLinkInfo()
  : url_()
  , in_app_origin_()
{}

getOauthLinkInfo::getOauthLinkInfo(string const &url_, string const &in_app_origin_)
  : url_(url_)
  , in_app_origin_(in_app_origin_)
{}

const std::int32_t getOauthLinkInfo::ID;

void getOauthLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getOauthLinkInfo");
    s.store_field("url", url_);
    s.store_field("in_app_origin", in_app_origin_);
    s.store_class_end();
  }
}

getReadDatePrivacySettings::getReadDatePrivacySettings() {
}

const std::int32_t getReadDatePrivacySettings::ID;

void getReadDatePrivacySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getReadDatePrivacySettings");
    s.store_class_end();
  }
}

getReceivedGifts::getReceivedGifts()
  : business_connection_id_()
  , owner_id_()
  , collection_id_()
  , exclude_unsaved_()
  , exclude_saved_()
  , exclude_unlimited_()
  , exclude_upgradable_()
  , exclude_non_upgradable_()
  , exclude_upgraded_()
  , exclude_without_colors_()
  , exclude_hosted_()
  , sort_by_price_()
  , offset_()
  , limit_()
{}

getReceivedGifts::getReceivedGifts(string const &business_connection_id_, object_ptr<MessageSender> &&owner_id_, int32 collection_id_, bool exclude_unsaved_, bool exclude_saved_, bool exclude_unlimited_, bool exclude_upgradable_, bool exclude_non_upgradable_, bool exclude_upgraded_, bool exclude_without_colors_, bool exclude_hosted_, bool sort_by_price_, string const &offset_, int32 limit_)
  : business_connection_id_(business_connection_id_)
  , owner_id_(std::move(owner_id_))
  , collection_id_(collection_id_)
  , exclude_unsaved_(exclude_unsaved_)
  , exclude_saved_(exclude_saved_)
  , exclude_unlimited_(exclude_unlimited_)
  , exclude_upgradable_(exclude_upgradable_)
  , exclude_non_upgradable_(exclude_non_upgradable_)
  , exclude_upgraded_(exclude_upgraded_)
  , exclude_without_colors_(exclude_without_colors_)
  , exclude_hosted_(exclude_hosted_)
  , sort_by_price_(sort_by_price_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getReceivedGifts::ID;

void getReceivedGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getReceivedGifts");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("collection_id", collection_id_);
    s.store_field("exclude_unsaved", exclude_unsaved_);
    s.store_field("exclude_saved", exclude_saved_);
    s.store_field("exclude_unlimited", exclude_unlimited_);
    s.store_field("exclude_upgradable", exclude_upgradable_);
    s.store_field("exclude_non_upgradable", exclude_non_upgradable_);
    s.store_field("exclude_upgraded", exclude_upgraded_);
    s.store_field("exclude_without_colors", exclude_without_colors_);
    s.store_field("exclude_hosted", exclude_hosted_);
    s.store_field("sort_by_price", sort_by_price_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getSavedNotificationSound::getSavedNotificationSound()
  : notification_sound_id_()
{}

getSavedNotificationSound::getSavedNotificationSound(int64 notification_sound_id_)
  : notification_sound_id_(notification_sound_id_)
{}

const std::int32_t getSavedNotificationSound::ID;

void getSavedNotificationSound::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSavedNotificationSound");
    s.store_field("notification_sound_id", notification_sound_id_);
    s.store_class_end();
  }
}

getStory::getStory()
  : story_poster_chat_id_()
  , story_id_()
  , only_local_()
{}

getStory::getStory(int53 story_poster_chat_id_, int32 story_id_, bool only_local_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , only_local_(only_local_)
{}

const std::int32_t getStory::ID;

void getStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_field("only_local", only_local_);
    s.store_class_end();
  }
}

getSupergroupFullInfo::getSupergroupFullInfo()
  : supergroup_id_()
{}

getSupergroupFullInfo::getSupergroupFullInfo(int53 supergroup_id_)
  : supergroup_id_(supergroup_id_)
{}

const std::int32_t getSupergroupFullInfo::ID;

void getSupergroupFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSupergroupFullInfo");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_class_end();
  }
}

getUserPrivacySettingRules::getUserPrivacySettingRules()
  : setting_()
{}

getUserPrivacySettingRules::getUserPrivacySettingRules(object_ptr<UserPrivacySetting> &&setting_)
  : setting_(std::move(setting_))
{}

const std::int32_t getUserPrivacySettingRules::ID;

void getUserPrivacySettingRules::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUserPrivacySettingRules");
    s.store_object_field("setting", static_cast<const BaseObject *>(setting_.get()));
    s.store_class_end();
  }
}

importMessages::importMessages()
  : chat_id_()
  , message_file_()
  , attached_files_()
{}

importMessages::importMessages(int53 chat_id_, object_ptr<InputFile> &&message_file_, array<object_ptr<InputFile>> &&attached_files_)
  : chat_id_(chat_id_)
  , message_file_(std::move(message_file_))
  , attached_files_(std::move(attached_files_))
{}

const std::int32_t importMessages::ID;

void importMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "importMessages");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("message_file", static_cast<const BaseObject *>(message_file_.get()));
    { s.store_vector_begin("attached_files", attached_files_.size()); for (const auto &_value : attached_files_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

leaveGroupCall::leaveGroupCall()
  : group_call_id_()
{}

leaveGroupCall::leaveGroupCall(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t leaveGroupCall::ID;

void leaveGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "leaveGroupCall");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

preliminaryUploadFile::preliminaryUploadFile()
  : file_()
  , file_type_()
  , priority_()
{}

preliminaryUploadFile::preliminaryUploadFile(object_ptr<InputFile> &&file_, object_ptr<FileType> &&file_type_, int32 priority_)
  : file_(std::move(file_))
  , file_type_(std::move(file_type_))
  , priority_(priority_)
{}

const std::int32_t preliminaryUploadFile::ID;

void preliminaryUploadFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "preliminaryUploadFile");
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_object_field("file_type", static_cast<const BaseObject *>(file_type_.get()));
    s.store_field("priority", priority_);
    s.store_class_end();
  }
}

rateSpeechRecognition::rateSpeechRecognition()
  : chat_id_()
  , message_id_()
  , is_good_()
{}

rateSpeechRecognition::rateSpeechRecognition(int53 chat_id_, int53 message_id_, bool is_good_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , is_good_(is_good_)
{}

const std::int32_t rateSpeechRecognition::ID;

void rateSpeechRecognition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "rateSpeechRecognition");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("is_good", is_good_);
    s.store_class_end();
  }
}

registerUser::registerUser()
  : first_name_()
  , last_name_()
  , disable_notification_()
{}

registerUser::registerUser(string const &first_name_, string const &last_name_, bool disable_notification_)
  : first_name_(first_name_)
  , last_name_(last_name_)
  , disable_notification_(disable_notification_)
{}

const std::int32_t registerUser::ID;

void registerUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "registerUser");
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_field("disable_notification", disable_notification_);
    s.store_class_end();
  }
}

removeAllFilesFromDownloads::removeAllFilesFromDownloads()
  : only_active_()
  , only_completed_()
  , delete_from_cache_()
{}

removeAllFilesFromDownloads::removeAllFilesFromDownloads(bool only_active_, bool only_completed_, bool delete_from_cache_)
  : only_active_(only_active_)
  , only_completed_(only_completed_)
  , delete_from_cache_(delete_from_cache_)
{}

const std::int32_t removeAllFilesFromDownloads::ID;

void removeAllFilesFromDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeAllFilesFromDownloads");
    s.store_field("only_active", only_active_);
    s.store_field("only_completed", only_completed_);
    s.store_field("delete_from_cache", delete_from_cache_);
    s.store_class_end();
  }
}

removeRecentHashtag::removeRecentHashtag()
  : hashtag_()
{}

removeRecentHashtag::removeRecentHashtag(string const &hashtag_)
  : hashtag_(hashtag_)
{}

const std::int32_t removeRecentHashtag::ID;

void removeRecentHashtag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeRecentHashtag");
    s.store_field("hashtag", hashtag_);
    s.store_class_end();
  }
}

reorderChatFolders::reorderChatFolders()
  : chat_folder_ids_()
  , main_chat_list_position_()
{}

reorderChatFolders::reorderChatFolders(array<int32> &&chat_folder_ids_, int32 main_chat_list_position_)
  : chat_folder_ids_(std::move(chat_folder_ids_))
  , main_chat_list_position_(main_chat_list_position_)
{}

const std::int32_t reorderChatFolders::ID;

void reorderChatFolders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderChatFolders");
    { s.store_vector_begin("chat_folder_ids", chat_folder_ids_.size()); for (const auto &_value : chat_folder_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("main_chat_list_position", main_chat_list_position_);
    s.store_class_end();
  }
}

reportChat::reportChat()
  : chat_id_()
  , option_id_()
  , message_ids_()
  , text_()
{}

reportChat::reportChat(int53 chat_id_, bytes const &option_id_, array<int53> &&message_ids_, string const &text_)
  : chat_id_(chat_id_)
  , option_id_(std::move(option_id_))
  , message_ids_(std::move(message_ids_))
  , text_(text_)
{}

const std::int32_t reportChat::ID;

void reportChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportChat");
    s.store_field("chat_id", chat_id_);
    s.store_bytes_field("option_id", option_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("text", text_);
    s.store_class_end();
  }
}

reportVideoMessageAdvertisement::reportVideoMessageAdvertisement()
  : advertisement_unique_id_()
  , option_id_()
{}

reportVideoMessageAdvertisement::reportVideoMessageAdvertisement(int53 advertisement_unique_id_, bytes const &option_id_)
  : advertisement_unique_id_(advertisement_unique_id_)
  , option_id_(std::move(option_id_))
{}

const std::int32_t reportVideoMessageAdvertisement::ID;

void reportVideoMessageAdvertisement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportVideoMessageAdvertisement");
    s.store_field("advertisement_unique_id", advertisement_unique_id_);
    s.store_bytes_field("option_id", option_id_);
    s.store_class_end();
  }
}

revokeChatInviteLink::revokeChatInviteLink()
  : chat_id_()
  , invite_link_()
{}

revokeChatInviteLink::revokeChatInviteLink(int53 chat_id_, string const &invite_link_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
{}

const std::int32_t revokeChatInviteLink::ID;

void revokeChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "revokeChatInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

searchHashtags::searchHashtags()
  : prefix_()
  , limit_()
{}

searchHashtags::searchHashtags(string const &prefix_, int32 limit_)
  : prefix_(prefix_)
  , limit_(limit_)
{}

const std::int32_t searchHashtags::ID;

void searchHashtags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchHashtags");
    s.store_field("prefix", prefix_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchOutgoingDocumentMessages::searchOutgoingDocumentMessages()
  : query_()
  , limit_()
{}

searchOutgoingDocumentMessages::searchOutgoingDocumentMessages(string const &query_, int32 limit_)
  : query_(query_)
  , limit_(limit_)
{}

const std::int32_t searchOutgoingDocumentMessages::ID;

void searchOutgoingDocumentMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchOutgoingDocumentMessages");
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchPublicMessagesByTag::searchPublicMessagesByTag()
  : tag_()
  , offset_()
  , limit_()
{}

searchPublicMessagesByTag::searchPublicMessagesByTag(string const &tag_, string const &offset_, int32 limit_)
  : tag_(tag_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t searchPublicMessagesByTag::ID;

void searchPublicMessagesByTag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchPublicMessagesByTag");
    s.store_field("tag", tag_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchSecretMessages::searchSecretMessages()
  : chat_id_()
  , query_()
  , offset_()
  , limit_()
  , filter_()
{}

searchSecretMessages::searchSecretMessages(int53 chat_id_, string const &query_, string const &offset_, int32 limit_, object_ptr<SearchMessagesFilter> &&filter_)
  : chat_id_(chat_id_)
  , query_(query_)
  , offset_(offset_)
  , limit_(limit_)
  , filter_(std::move(filter_))
{}

const std::int32_t searchSecretMessages::ID;

void searchSecretMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchSecretMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("query", query_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_class_end();
  }
}

sendAuthenticationFirebaseSms::sendAuthenticationFirebaseSms()
  : token_()
{}

sendAuthenticationFirebaseSms::sendAuthenticationFirebaseSms(string const &token_)
  : token_(token_)
{}

const std::int32_t sendAuthenticationFirebaseSms::ID;

void sendAuthenticationFirebaseSms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendAuthenticationFirebaseSms");
    s.store_field("token", token_);
    s.store_class_end();
  }
}

sendCallRating::sendCallRating()
  : call_id_()
  , rating_()
  , comment_()
  , problems_()
{}

sendCallRating::sendCallRating(object_ptr<InputCall> &&call_id_, int32 rating_, string const &comment_, array<object_ptr<CallProblem>> &&problems_)
  : call_id_(std::move(call_id_))
  , rating_(rating_)
  , comment_(comment_)
  , problems_(std::move(problems_))
{}

const std::int32_t sendCallRating::ID;

void sendCallRating::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendCallRating");
    s.store_object_field("call_id", static_cast<const BaseObject *>(call_id_.get()));
    s.store_field("rating", rating_);
    s.store_field("comment", comment_);
    { s.store_vector_begin("problems", problems_.size()); for (const auto &_value : problems_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

sendGiftPurchaseOffer::sendGiftPurchaseOffer()
  : owner_id_()
  , gift_name_()
  , price_()
  , duration_()
  , paid_message_star_count_()
{}

sendGiftPurchaseOffer::sendGiftPurchaseOffer(object_ptr<MessageSender> &&owner_id_, string const &gift_name_, object_ptr<GiftResalePrice> &&price_, int32 duration_, int53 paid_message_star_count_)
  : owner_id_(std::move(owner_id_))
  , gift_name_(gift_name_)
  , price_(std::move(price_))
  , duration_(duration_)
  , paid_message_star_count_(paid_message_star_count_)
{}

const std::int32_t sendGiftPurchaseOffer::ID;

void sendGiftPurchaseOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendGiftPurchaseOffer");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("gift_name", gift_name_);
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_field("duration", duration_);
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_class_end();
  }
}

sendMessageAlbum::sendMessageAlbum()
  : chat_id_()
  , topic_id_()
  , reply_to_()
  , options_()
  , input_message_contents_()
{}

sendMessageAlbum::sendMessageAlbum(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, object_ptr<InputMessageReplyTo> &&reply_to_, object_ptr<messageSendOptions> &&options_, array<object_ptr<InputMessageContent>> &&input_message_contents_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , reply_to_(std::move(reply_to_))
  , options_(std::move(options_))
  , input_message_contents_(std::move(input_message_contents_))
{}

const std::int32_t sendMessageAlbum::ID;

void sendMessageAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageAlbum");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_object_field("options", static_cast<const BaseObject *>(options_.get()));
    { s.store_vector_begin("input_message_contents", input_message_contents_.size()); for (const auto &_value : input_message_contents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

sendWebAppData::sendWebAppData()
  : bot_user_id_()
  , button_text_()
  , data_()
{}

sendWebAppData::sendWebAppData(int53 bot_user_id_, string const &button_text_, string const &data_)
  : bot_user_id_(bot_user_id_)
  , button_text_(button_text_)
  , data_(data_)
{}

const std::int32_t sendWebAppData::ID;

void sendWebAppData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendWebAppData");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("button_text", button_text_);
    s.store_field("data", data_);
    s.store_class_end();
  }
}

setAccountTtl::setAccountTtl()
  : ttl_()
{}

setAccountTtl::setAccountTtl(object_ptr<accountTtl> &&ttl_)
  : ttl_(std::move(ttl_))
{}

const std::int32_t setAccountTtl::ID;

void setAccountTtl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setAccountTtl");
    s.store_object_field("ttl", static_cast<const BaseObject *>(ttl_.get()));
    s.store_class_end();
  }
}

setBirthdate::setBirthdate()
  : birthdate_()
{}

setBirthdate::setBirthdate(object_ptr<birthdate> &&birthdate_)
  : birthdate_(std::move(birthdate_))
{}

const std::int32_t setBirthdate::ID;

void setBirthdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBirthdate");
    s.store_object_field("birthdate", static_cast<const BaseObject *>(birthdate_.get()));
    s.store_class_end();
  }
}

setChatDraftMessage::setChatDraftMessage()
  : chat_id_()
  , topic_id_()
  , draft_message_()
{}

setChatDraftMessage::setChatDraftMessage(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, object_ptr<draftMessage> &&draft_message_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , draft_message_(std::move(draft_message_))
{}

const std::int32_t setChatDraftMessage::ID;

void setChatDraftMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatDraftMessage");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("draft_message", static_cast<const BaseObject *>(draft_message_.get()));
    s.store_class_end();
  }
}

setChatMessageSender::setChatMessageSender()
  : chat_id_()
  , message_sender_id_()
{}

setChatMessageSender::setChatMessageSender(int53 chat_id_, object_ptr<MessageSender> &&message_sender_id_)
  : chat_id_(chat_id_)
  , message_sender_id_(std::move(message_sender_id_))
{}

const std::int32_t setChatMessageSender::ID;

void setChatMessageSender::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatMessageSender");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("message_sender_id", static_cast<const BaseObject *>(message_sender_id_.get()));
    s.store_class_end();
  }
}

setChatPermissions::setChatPermissions()
  : chat_id_()
  , permissions_()
{}

setChatPermissions::setChatPermissions(int53 chat_id_, object_ptr<chatPermissions> &&permissions_)
  : chat_id_(chat_id_)
  , permissions_(std::move(permissions_))
{}

const std::int32_t setChatPermissions::ID;

void setChatPermissions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatPermissions");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("permissions", static_cast<const BaseObject *>(permissions_.get()));
    s.store_class_end();
  }
}

setChatProfileAccentColor::setChatProfileAccentColor()
  : chat_id_()
  , profile_accent_color_id_()
  , profile_background_custom_emoji_id_()
{}

setChatProfileAccentColor::setChatProfileAccentColor(int53 chat_id_, int32 profile_accent_color_id_, int64 profile_background_custom_emoji_id_)
  : chat_id_(chat_id_)
  , profile_accent_color_id_(profile_accent_color_id_)
  , profile_background_custom_emoji_id_(profile_background_custom_emoji_id_)
{}

const std::int32_t setChatProfileAccentColor::ID;

void setChatProfileAccentColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatProfileAccentColor");
    s.store_field("chat_id", chat_id_);
    s.store_field("profile_accent_color_id", profile_accent_color_id_);
    s.store_field("profile_background_custom_emoji_id", profile_background_custom_emoji_id_);
    s.store_class_end();
  }
}

setCustomLanguagePack::setCustomLanguagePack()
  : info_()
  , strings_()
{}

setCustomLanguagePack::setCustomLanguagePack(object_ptr<languagePackInfo> &&info_, array<object_ptr<languagePackString>> &&strings_)
  : info_(std::move(info_))
  , strings_(std::move(strings_))
{}

const std::int32_t setCustomLanguagePack::ID;

void setCustomLanguagePack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setCustomLanguagePack");
    s.store_object_field("info", static_cast<const BaseObject *>(info_.get()));
    { s.store_vector_begin("strings", strings_.size()); for (const auto &_value : strings_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

setDefaultGroupAdministratorRights::setDefaultGroupAdministratorRights()
  : default_group_administrator_rights_()
{}

setDefaultGroupAdministratorRights::setDefaultGroupAdministratorRights(object_ptr<chatAdministratorRights> &&default_group_administrator_rights_)
  : default_group_administrator_rights_(std::move(default_group_administrator_rights_))
{}

const std::int32_t setDefaultGroupAdministratorRights::ID;

void setDefaultGroupAdministratorRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setDefaultGroupAdministratorRights");
    s.store_object_field("default_group_administrator_rights", static_cast<const BaseObject *>(default_group_administrator_rights_.get()));
    s.store_class_end();
  }
}

setInlineGameScore::setInlineGameScore()
  : inline_message_id_()
  , edit_message_()
  , user_id_()
  , score_()
  , force_()
{}

setInlineGameScore::setInlineGameScore(string const &inline_message_id_, bool edit_message_, int53 user_id_, int32 score_, bool force_)
  : inline_message_id_(inline_message_id_)
  , edit_message_(edit_message_)
  , user_id_(user_id_)
  , score_(score_)
  , force_(force_)
{}

const std::int32_t setInlineGameScore::ID;

void setInlineGameScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setInlineGameScore");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_field("edit_message", edit_message_);
    s.store_field("user_id", user_id_);
    s.store_field("score", score_);
    s.store_field("force", force_);
    s.store_class_end();
  }
}

setMessageSenderBlockList::setMessageSenderBlockList()
  : sender_id_()
  , block_list_()
{}

setMessageSenderBlockList::setMessageSenderBlockList(object_ptr<MessageSender> &&sender_id_, object_ptr<BlockList> &&block_list_)
  : sender_id_(std::move(sender_id_))
  , block_list_(std::move(block_list_))
{}

const std::int32_t setMessageSenderBlockList::ID;

void setMessageSenderBlockList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setMessageSenderBlockList");
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_object_field("block_list", static_cast<const BaseObject *>(block_list_.get()));
    s.store_class_end();
  }
}

setName::setName()
  : first_name_()
  , last_name_()
{}

setName::setName(string const &first_name_, string const &last_name_)
  : first_name_(first_name_)
  , last_name_(last_name_)
{}

const std::int32_t setName::ID;

void setName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setName");
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_class_end();
  }
}

setVideoChatTitle::setVideoChatTitle()
  : group_call_id_()
  , title_()
{}

setVideoChatTitle::setVideoChatTitle(int32 group_call_id_, string const &title_)
  : group_call_id_(group_call_id_)
  , title_(title_)
{}

const std::int32_t setVideoChatTitle::ID;

void setVideoChatTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setVideoChatTitle");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

shareUsersWithBot::shareUsersWithBot()
  : source_()
  , button_id_()
  , shared_user_ids_()
  , only_check_()
{}

shareUsersWithBot::shareUsersWithBot(object_ptr<KeyboardButtonSource> &&source_, int32 button_id_, array<int53> &&shared_user_ids_, bool only_check_)
  : source_(std::move(source_))
  , button_id_(button_id_)
  , shared_user_ids_(std::move(shared_user_ids_))
  , only_check_(only_check_)
{}

const std::int32_t shareUsersWithBot::ID;

void shareUsersWithBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "shareUsersWithBot");
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_field("button_id", button_id_);
    { s.store_vector_begin("shared_user_ids", shared_user_ids_.size()); for (const auto &_value : shared_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("only_check", only_check_);
    s.store_class_end();
  }
}

suggestUserProfilePhoto::suggestUserProfilePhoto()
  : user_id_()
  , photo_()
{}

suggestUserProfilePhoto::suggestUserProfilePhoto(int53 user_id_, object_ptr<InputChatPhoto> &&photo_)
  : user_id_(user_id_)
  , photo_(std::move(photo_))
{}

const std::int32_t suggestUserProfilePhoto::ID;

void suggestUserProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestUserProfilePhoto");
    s.store_field("user_id", user_id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

testCallBytes::testCallBytes()
  : x_()
{}

testCallBytes::testCallBytes(bytes const &x_)
  : x_(std::move(x_))
{}

const std::int32_t testCallBytes::ID;

void testCallBytes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallBytes");
    s.store_bytes_field("x", x_);
    s.store_class_end();
  }
}

testCallString::testCallString()
  : x_()
{}

testCallString::testCallString(string const &x_)
  : x_(x_)
{}

const std::int32_t testCallString::ID;

void testCallString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallString");
    s.store_field("x", x_);
    s.store_class_end();
  }
}

testCallVectorInt::testCallVectorInt()
  : x_()
{}

testCallVectorInt::testCallVectorInt(array<int32> &&x_)
  : x_(std::move(x_))
{}

const std::int32_t testCallVectorInt::ID;

void testCallVectorInt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallVectorInt");
    { s.store_vector_begin("x", x_.size()); for (const auto &_value : x_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

testCallVectorStringObject::testCallVectorStringObject()
  : x_()
{}

testCallVectorStringObject::testCallVectorStringObject(array<object_ptr<testString>> &&x_)
  : x_(std::move(x_))
{}

const std::int32_t testCallVectorStringObject::ID;

void testCallVectorStringObject::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallVectorStringObject");
    { s.store_vector_begin("x", x_.size()); for (const auto &_value : x_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

toggleBotCanManageEmojiStatus::toggleBotCanManageEmojiStatus()
  : bot_user_id_()
  , can_manage_emoji_status_()
{}

toggleBotCanManageEmojiStatus::toggleBotCanManageEmojiStatus(int53 bot_user_id_, bool can_manage_emoji_status_)
  : bot_user_id_(bot_user_id_)
  , can_manage_emoji_status_(can_manage_emoji_status_)
{}

const std::int32_t toggleBotCanManageEmojiStatus::ID;

void toggleBotCanManageEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleBotCanManageEmojiStatus");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("can_manage_emoji_status", can_manage_emoji_status_);
    s.store_class_end();
  }
}

toggleBotIsAddedToAttachmentMenu::toggleBotIsAddedToAttachmentMenu()
  : bot_user_id_()
  , is_added_()
  , allow_write_access_()
{}

toggleBotIsAddedToAttachmentMenu::toggleBotIsAddedToAttachmentMenu(int53 bot_user_id_, bool is_added_, bool allow_write_access_)
  : bot_user_id_(bot_user_id_)
  , is_added_(is_added_)
  , allow_write_access_(allow_write_access_)
{}

const std::int32_t toggleBotIsAddedToAttachmentMenu::ID;

void toggleBotIsAddedToAttachmentMenu::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleBotIsAddedToAttachmentMenu");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("is_added", is_added_);
    s.store_field("allow_write_access", allow_write_access_);
    s.store_class_end();
  }
}

toggleForumTopicIsClosed::toggleForumTopicIsClosed()
  : chat_id_()
  , forum_topic_id_()
  , is_closed_()
{}

toggleForumTopicIsClosed::toggleForumTopicIsClosed(int53 chat_id_, int32 forum_topic_id_, bool is_closed_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
  , is_closed_(is_closed_)
{}

const std::int32_t toggleForumTopicIsClosed::ID;

void toggleForumTopicIsClosed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleForumTopicIsClosed");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_field("is_closed", is_closed_);
    s.store_class_end();
  }
}

toggleSupergroupIsBroadcastGroup::toggleSupergroupIsBroadcastGroup()
  : supergroup_id_()
{}

toggleSupergroupIsBroadcastGroup::toggleSupergroupIsBroadcastGroup(int53 supergroup_id_)
  : supergroup_id_(supergroup_id_)
{}

const std::int32_t toggleSupergroupIsBroadcastGroup::ID;

void toggleSupergroupIsBroadcastGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupIsBroadcastGroup");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_class_end();
  }
}

transferChatOwnership::transferChatOwnership()
  : chat_id_()
  , user_id_()
  , password_()
{}

transferChatOwnership::transferChatOwnership(int53 chat_id_, int53 user_id_, string const &password_)
  : chat_id_(chat_id_)
  , user_id_(user_id_)
  , password_(password_)
{}

const std::int32_t transferChatOwnership::ID;

void transferChatOwnership::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "transferChatOwnership");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_field("password", password_);
    s.store_class_end();
  }
}

translateText::translateText()
  : text_()
  , to_language_code_()
  , tone_()
{}

translateText::translateText(object_ptr<formattedText> &&text_, string const &to_language_code_, string const &tone_)
  : text_(std::move(text_))
  , to_language_code_(to_language_code_)
  , tone_(tone_)
{}

const std::int32_t translateText::ID;

void translateText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "translateText");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("to_language_code", to_language_code_);
    s.store_field("tone", tone_);
    s.store_class_end();
  }
}

viewSponsoredChat::viewSponsoredChat()
  : sponsored_chat_unique_id_()
{}

viewSponsoredChat::viewSponsoredChat(int53 sponsored_chat_unique_id_)
  : sponsored_chat_unique_id_(sponsored_chat_unique_id_)
{}

const std::int32_t viewSponsoredChat::ID;

void viewSponsoredChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "viewSponsoredChat");
    s.store_field("sponsored_chat_unique_id", sponsored_chat_unique_id_);
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
