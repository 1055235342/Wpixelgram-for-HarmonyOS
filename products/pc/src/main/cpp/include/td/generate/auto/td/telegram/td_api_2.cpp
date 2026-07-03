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


accountInfo::accountInfo()
  : registration_month_()
  , registration_year_()
  , phone_number_country_code_()
  , last_name_change_date_()
  , last_photo_change_date_()
{}

accountInfo::accountInfo(int32 registration_month_, int32 registration_year_, string const &phone_number_country_code_, int32 last_name_change_date_, int32 last_photo_change_date_)
  : registration_month_(registration_month_)
  , registration_year_(registration_year_)
  , phone_number_country_code_(phone_number_country_code_)
  , last_name_change_date_(last_name_change_date_)
  , last_photo_change_date_(last_photo_change_date_)
{}

const std::int32_t accountInfo::ID;

void accountInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "accountInfo");
    s.store_field("registration_month", registration_month_);
    s.store_field("registration_year", registration_year_);
    s.store_field("phone_number_country_code", phone_number_country_code_);
    s.store_field("last_name_change_date", last_name_change_date_);
    s.store_field("last_photo_change_date", last_photo_change_date_);
    s.store_class_end();
  }
}

affiliateInfo::affiliateInfo()
  : commission_per_mille_()
  , affiliate_chat_id_()
  , star_amount_()
{}

affiliateInfo::affiliateInfo(int32 commission_per_mille_, int53 affiliate_chat_id_, object_ptr<starAmount> &&star_amount_)
  : commission_per_mille_(commission_per_mille_)
  , affiliate_chat_id_(affiliate_chat_id_)
  , star_amount_(std::move(star_amount_))
{}

const std::int32_t affiliateInfo::ID;

void affiliateInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "affiliateInfo");
    s.store_field("commission_per_mille", commission_per_mille_);
    s.store_field("affiliate_chat_id", affiliate_chat_id_);
    s.store_object_field("star_amount", static_cast<const BaseObject *>(star_amount_.get()));
    s.store_class_end();
  }
}

affiliateProgramInfo::affiliateProgramInfo()
  : parameters_()
  , end_date_()
  , daily_revenue_per_user_amount_()
{}

affiliateProgramInfo::affiliateProgramInfo(object_ptr<affiliateProgramParameters> &&parameters_, int32 end_date_, object_ptr<starAmount> &&daily_revenue_per_user_amount_)
  : parameters_(std::move(parameters_))
  , end_date_(end_date_)
  , daily_revenue_per_user_amount_(std::move(daily_revenue_per_user_amount_))
{}

const std::int32_t affiliateProgramInfo::ID;

void affiliateProgramInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "affiliateProgramInfo");
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_field("end_date", end_date_);
    s.store_object_field("daily_revenue_per_user_amount", static_cast<const BaseObject *>(daily_revenue_per_user_amount_.get()));
    s.store_class_end();
  }
}

affiliateProgramSortOrderProfitability::affiliateProgramSortOrderProfitability() {
}

const std::int32_t affiliateProgramSortOrderProfitability::ID;

void affiliateProgramSortOrderProfitability::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "affiliateProgramSortOrderProfitability");
    s.store_class_end();
  }
}

affiliateProgramSortOrderCreationDate::affiliateProgramSortOrderCreationDate() {
}

const std::int32_t affiliateProgramSortOrderCreationDate::ID;

void affiliateProgramSortOrderCreationDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "affiliateProgramSortOrderCreationDate");
    s.store_class_end();
  }
}

affiliateProgramSortOrderRevenue::affiliateProgramSortOrderRevenue() {
}

const std::int32_t affiliateProgramSortOrderRevenue::ID;

void affiliateProgramSortOrderRevenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "affiliateProgramSortOrderRevenue");
    s.store_class_end();
  }
}

ageVerificationParameters::ageVerificationParameters()
  : min_age_()
  , verification_bot_username_()
  , country_()
{}

ageVerificationParameters::ageVerificationParameters(int32 min_age_, string const &verification_bot_username_, string const &country_)
  : min_age_(min_age_)
  , verification_bot_username_(verification_bot_username_)
  , country_(country_)
{}

const std::int32_t ageVerificationParameters::ID;

void ageVerificationParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ageVerificationParameters");
    s.store_field("min_age", min_age_);
    s.store_field("verification_bot_username", verification_bot_username_);
    s.store_field("country", country_);
    s.store_class_end();
  }
}

animation::animation()
  : duration_()
  , width_()
  , height_()
  , file_name_()
  , mime_type_()
  , has_stickers_()
  , minithumbnail_()
  , thumbnail_()
  , animation_()
{}

animation::animation(int32 duration_, int32 width_, int32 height_, string const &file_name_, string const &mime_type_, bool has_stickers_, object_ptr<minithumbnail> &&minithumbnail_, object_ptr<thumbnail> &&thumbnail_, object_ptr<file> &&animation_)
  : duration_(duration_)
  , width_(width_)
  , height_(height_)
  , file_name_(file_name_)
  , mime_type_(mime_type_)
  , has_stickers_(has_stickers_)
  , minithumbnail_(std::move(minithumbnail_))
  , thumbnail_(std::move(thumbnail_))
  , animation_(std::move(animation_))
{}

const std::int32_t animation::ID;

void animation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "animation");
    s.store_field("duration", duration_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("file_name", file_name_);
    s.store_field("mime_type", mime_type_);
    s.store_field("has_stickers", has_stickers_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

attributeCraftPersistenceProbability::attributeCraftPersistenceProbability()
  : persistence_chance_per_mille_()
{}

attributeCraftPersistenceProbability::attributeCraftPersistenceProbability(array<int32> &&persistence_chance_per_mille_)
  : persistence_chance_per_mille_(std::move(persistence_chance_per_mille_))
{}

const std::int32_t attributeCraftPersistenceProbability::ID;

void attributeCraftPersistenceProbability::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attributeCraftPersistenceProbability");
    { s.store_vector_begin("persistence_chance_per_mille", persistence_chance_per_mille_.size()); for (const auto &_value : persistence_chance_per_mille_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

availableReaction::availableReaction()
  : type_()
  , needs_premium_()
{}

availableReaction::availableReaction(object_ptr<ReactionType> &&type_, bool needs_premium_)
  : type_(std::move(type_))
  , needs_premium_(needs_premium_)
{}

const std::int32_t availableReaction::ID;

void availableReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "availableReaction");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("needs_premium", needs_premium_);
    s.store_class_end();
  }
}

botCommandScopeDefault::botCommandScopeDefault() {
}

const std::int32_t botCommandScopeDefault::ID;

void botCommandScopeDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeDefault");
    s.store_class_end();
  }
}

botCommandScopeAllPrivateChats::botCommandScopeAllPrivateChats() {
}

const std::int32_t botCommandScopeAllPrivateChats::ID;

void botCommandScopeAllPrivateChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeAllPrivateChats");
    s.store_class_end();
  }
}

botCommandScopeAllGroupChats::botCommandScopeAllGroupChats() {
}

const std::int32_t botCommandScopeAllGroupChats::ID;

void botCommandScopeAllGroupChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeAllGroupChats");
    s.store_class_end();
  }
}

botCommandScopeAllChatAdministrators::botCommandScopeAllChatAdministrators() {
}

const std::int32_t botCommandScopeAllChatAdministrators::ID;

void botCommandScopeAllChatAdministrators::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeAllChatAdministrators");
    s.store_class_end();
  }
}

botCommandScopeChat::botCommandScopeChat()
  : chat_id_()
{}

botCommandScopeChat::botCommandScopeChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t botCommandScopeChat::ID;

void botCommandScopeChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

botCommandScopeChatAdministrators::botCommandScopeChatAdministrators()
  : chat_id_()
{}

botCommandScopeChatAdministrators::botCommandScopeChatAdministrators(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t botCommandScopeChatAdministrators::ID;

void botCommandScopeChatAdministrators::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeChatAdministrators");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

botCommandScopeChatMember::botCommandScopeChatMember()
  : chat_id_()
  , user_id_()
{}

botCommandScopeChatMember::botCommandScopeChatMember(int53 chat_id_, int53 user_id_)
  : chat_id_(chat_id_)
  , user_id_(user_id_)
{}

const std::int32_t botCommandScopeChatMember::ID;

void botCommandScopeChatMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeChatMember");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

botMediaPreviews::botMediaPreviews()
  : previews_()
{}

botMediaPreviews::botMediaPreviews(array<object_ptr<botMediaPreview>> &&previews_)
  : previews_(std::move(previews_))
{}

const std::int32_t botMediaPreviews::ID;

void botMediaPreviews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botMediaPreviews");
    { s.store_vector_begin("previews", previews_.size()); for (const auto &_value : previews_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

businessAwayMessageSettings::businessAwayMessageSettings()
  : shortcut_id_()
  , recipients_()
  , schedule_()
  , offline_only_()
{}

businessAwayMessageSettings::businessAwayMessageSettings(int32 shortcut_id_, object_ptr<businessRecipients> &&recipients_, object_ptr<BusinessAwayMessageSchedule> &&schedule_, bool offline_only_)
  : shortcut_id_(shortcut_id_)
  , recipients_(std::move(recipients_))
  , schedule_(std::move(schedule_))
  , offline_only_(offline_only_)
{}

const std::int32_t businessAwayMessageSettings::ID;

void businessAwayMessageSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessAwayMessageSettings");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_object_field("recipients", static_cast<const BaseObject *>(recipients_.get()));
    s.store_object_field("schedule", static_cast<const BaseObject *>(schedule_.get()));
    s.store_field("offline_only", offline_only_);
    s.store_class_end();
  }
}

businessMessage::businessMessage()
  : message_()
  , reply_to_message_()
{}

businessMessage::businessMessage(object_ptr<message> &&message_, object_ptr<message> &&reply_to_message_)
  : message_(std::move(message_))
  , reply_to_message_(std::move(reply_to_message_))
{}

const std::int32_t businessMessage::ID;

void businessMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_object_field("reply_to_message", static_cast<const BaseObject *>(reply_to_message_.get()));
    s.store_class_end();
  }
}

chatActiveStories::chatActiveStories()
  : chat_id_()
  , list_()
  , order_()
  , can_be_archived_()
  , max_read_story_id_()
  , stories_()
{}

chatActiveStories::chatActiveStories(int53 chat_id_, object_ptr<StoryList> &&list_, int53 order_, bool can_be_archived_, int32 max_read_story_id_, array<object_ptr<storyInfo>> &&stories_)
  : chat_id_(chat_id_)
  , list_(std::move(list_))
  , order_(order_)
  , can_be_archived_(can_be_archived_)
  , max_read_story_id_(max_read_story_id_)
  , stories_(std::move(stories_))
{}

const std::int32_t chatActiveStories::ID;

void chatActiveStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActiveStories");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("list", static_cast<const BaseObject *>(list_.get()));
    s.store_field("order", order_);
    s.store_field("can_be_archived", can_be_archived_);
    s.store_field("max_read_story_id", max_read_story_id_);
    { s.store_vector_begin("stories", stories_.size()); for (const auto &_value : stories_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatAdministrator::chatAdministrator()
  : user_id_()
  , custom_title_()
  , is_owner_()
  , can_be_edited_()
{}

chatAdministrator::chatAdministrator(int53 user_id_, string const &custom_title_, bool is_owner_, bool can_be_edited_)
  : user_id_(user_id_)
  , custom_title_(custom_title_)
  , is_owner_(is_owner_)
  , can_be_edited_(can_be_edited_)
{}

const std::int32_t chatAdministrator::ID;

void chatAdministrator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatAdministrator");
    s.store_field("user_id", user_id_);
    s.store_field("custom_title", custom_title_);
    s.store_field("is_owner", is_owner_);
    s.store_field("can_be_edited", can_be_edited_);
    s.store_class_end();
  }
}

chatBoostLink::chatBoostLink()
  : link_()
  , is_public_()
{}

chatBoostLink::chatBoostLink(string const &link_, bool is_public_)
  : link_(link_)
  , is_public_(is_public_)
{}

const std::int32_t chatBoostLink::ID;

void chatBoostLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoostLink");
    s.store_field("link", link_);
    s.store_field("is_public", is_public_);
    s.store_class_end();
  }
}

chatBoostSlots::chatBoostSlots()
  : slots_()
{}

chatBoostSlots::chatBoostSlots(array<object_ptr<chatBoostSlot>> &&slots_)
  : slots_(std::move(slots_))
{}

const std::int32_t chatBoostSlots::ID;

void chatBoostSlots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoostSlots");
    { s.store_vector_begin("slots", slots_.size()); for (const auto &_value : slots_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatFolderInfo::chatFolderInfo()
  : id_()
  , name_()
  , icon_()
  , color_id_()
  , is_shareable_()
  , has_my_invite_links_()
{}

chatFolderInfo::chatFolderInfo(int32 id_, object_ptr<chatFolderName> &&name_, object_ptr<chatFolderIcon> &&icon_, int32 color_id_, bool is_shareable_, bool has_my_invite_links_)
  : id_(id_)
  , name_(std::move(name_))
  , icon_(std::move(icon_))
  , color_id_(color_id_)
  , is_shareable_(is_shareable_)
  , has_my_invite_links_(has_my_invite_links_)
{}

const std::int32_t chatFolderInfo::ID;

void chatFolderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatFolderInfo");
    s.store_field("id", id_);
    s.store_object_field("name", static_cast<const BaseObject *>(name_.get()));
    s.store_object_field("icon", static_cast<const BaseObject *>(icon_.get()));
    s.store_field("color_id", color_id_);
    s.store_field("is_shareable", is_shareable_);
    s.store_field("has_my_invite_links", has_my_invite_links_);
    s.store_class_end();
  }
}

chatInviteLinkCount::chatInviteLinkCount()
  : user_id_()
  , invite_link_count_()
  , revoked_invite_link_count_()
{}

chatInviteLinkCount::chatInviteLinkCount(int53 user_id_, int32 invite_link_count_, int32 revoked_invite_link_count_)
  : user_id_(user_id_)
  , invite_link_count_(invite_link_count_)
  , revoked_invite_link_count_(revoked_invite_link_count_)
{}

const std::int32_t chatInviteLinkCount::ID;

void chatInviteLinkCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLinkCount");
    s.store_field("user_id", user_id_);
    s.store_field("invite_link_count", invite_link_count_);
    s.store_field("revoked_invite_link_count", revoked_invite_link_count_);
    s.store_class_end();
  }
}

chatJoinRequest::chatJoinRequest()
  : user_id_()
  , date_()
  , bio_()
{}

chatJoinRequest::chatJoinRequest(int53 user_id_, int32 date_, string const &bio_)
  : user_id_(user_id_)
  , date_(date_)
  , bio_(bio_)
{}

const std::int32_t chatJoinRequest::ID;

void chatJoinRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatJoinRequest");
    s.store_field("user_id", user_id_);
    s.store_field("date", date_);
    s.store_field("bio", bio_);
    s.store_class_end();
  }
}

chatJoinRequests::chatJoinRequests()
  : total_count_()
  , requests_()
{}

chatJoinRequests::chatJoinRequests(int32 total_count_, array<object_ptr<chatJoinRequest>> &&requests_)
  : total_count_(total_count_)
  , requests_(std::move(requests_))
{}

const std::int32_t chatJoinRequests::ID;

void chatJoinRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatJoinRequests");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("requests", requests_.size()); for (const auto &_value : requests_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatMembers::chatMembers()
  : total_count_()
  , members_()
{}

chatMembers::chatMembers(int32 total_count_, array<object_ptr<chatMember>> &&members_)
  : total_count_(total_count_)
  , members_(std::move(members_))
{}

const std::int32_t chatMembers::ID;

void chatMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembers");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("members", members_.size()); for (const auto &_value : members_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatTypePrivate::chatTypePrivate()
  : user_id_()
{}

chatTypePrivate::chatTypePrivate(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t chatTypePrivate::ID;

void chatTypePrivate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatTypePrivate");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

chatTypeBasicGroup::chatTypeBasicGroup()
  : basic_group_id_()
{}

chatTypeBasicGroup::chatTypeBasicGroup(int53 basic_group_id_)
  : basic_group_id_(basic_group_id_)
{}

const std::int32_t chatTypeBasicGroup::ID;

void chatTypeBasicGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatTypeBasicGroup");
    s.store_field("basic_group_id", basic_group_id_);
    s.store_class_end();
  }
}

chatTypeSupergroup::chatTypeSupergroup()
  : supergroup_id_()
  , is_channel_()
{}

chatTypeSupergroup::chatTypeSupergroup(int53 supergroup_id_, bool is_channel_)
  : supergroup_id_(supergroup_id_)
  , is_channel_(is_channel_)
{}

const std::int32_t chatTypeSupergroup::ID;

void chatTypeSupergroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatTypeSupergroup");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("is_channel", is_channel_);
    s.store_class_end();
  }
}

chatTypeSecret::chatTypeSecret()
  : secret_chat_id_()
  , user_id_()
{}

chatTypeSecret::chatTypeSecret(int32 secret_chat_id_, int53 user_id_)
  : secret_chat_id_(secret_chat_id_)
  , user_id_(user_id_)
{}

const std::int32_t chatTypeSecret::ID;

void chatTypeSecret::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatTypeSecret");
    s.store_field("secret_chat_id", secret_chat_id_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

data::data()
  : data_()
{}

data::data(bytes const &data_)
  : data_(std::move(data_))
{}

const std::int32_t data::ID;

void data::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "data");
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

date::date()
  : day_()
  , month_()
  , year_()
{}

date::date(int32 day_, int32 month_, int32 year_)
  : day_(day_)
  , month_(month_)
  , year_(year_)
{}

const std::int32_t date::ID;

void date::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "date");
    s.store_field("day", day_);
    s.store_field("month", month_);
    s.store_field("year", year_);
    s.store_class_end();
  }
}

dateRange::dateRange()
  : start_date_()
  , end_date_()
{}

dateRange::dateRange(int32 start_date_, int32 end_date_)
  : start_date_(start_date_)
  , end_date_(end_date_)
{}

const std::int32_t dateRange::ID;

void dateRange::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dateRange");
    s.store_field("start_date", start_date_);
    s.store_field("end_date", end_date_);
    s.store_class_end();
  }
}

emojiCategoryTypeDefault::emojiCategoryTypeDefault() {
}

const std::int32_t emojiCategoryTypeDefault::ID;

void emojiCategoryTypeDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiCategoryTypeDefault");
    s.store_class_end();
  }
}

emojiCategoryTypeRegularStickers::emojiCategoryTypeRegularStickers() {
}

const std::int32_t emojiCategoryTypeRegularStickers::ID;

void emojiCategoryTypeRegularStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiCategoryTypeRegularStickers");
    s.store_class_end();
  }
}

emojiCategoryTypeEmojiStatus::emojiCategoryTypeEmojiStatus() {
}

const std::int32_t emojiCategoryTypeEmojiStatus::ID;

void emojiCategoryTypeEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiCategoryTypeEmojiStatus");
    s.store_class_end();
  }
}

emojiCategoryTypeChatPhoto::emojiCategoryTypeChatPhoto() {
}

const std::int32_t emojiCategoryTypeChatPhoto::ID;

void emojiCategoryTypeChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiCategoryTypeChatPhoto");
    s.store_class_end();
  }
}

encryptedCredentials::encryptedCredentials()
  : data_()
  , hash_()
  , secret_()
{}

encryptedCredentials::encryptedCredentials(bytes const &data_, bytes const &hash_, bytes const &secret_)
  : data_(std::move(data_))
  , hash_(std::move(hash_))
  , secret_(std::move(secret_))
{}

const std::int32_t encryptedCredentials::ID;

void encryptedCredentials::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedCredentials");
    s.store_bytes_field("data", data_);
    s.store_bytes_field("hash", hash_);
    s.store_bytes_field("secret", secret_);
    s.store_class_end();
  }
}

failedToAddMembers::failedToAddMembers()
  : failed_to_add_members_()
{}

failedToAddMembers::failedToAddMembers(array<object_ptr<failedToAddMember>> &&failed_to_add_members_)
  : failed_to_add_members_(std::move(failed_to_add_members_))
{}

const std::int32_t failedToAddMembers::ID;

void failedToAddMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "failedToAddMembers");
    { s.store_vector_begin("failed_to_add_members", failed_to_add_members_.size()); for (const auto &_value : failed_to_add_members_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

fileTypeNone::fileTypeNone() {
}

const std::int32_t fileTypeNone::ID;

void fileTypeNone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeNone");
    s.store_class_end();
  }
}

fileTypeAnimation::fileTypeAnimation() {
}

const std::int32_t fileTypeAnimation::ID;

void fileTypeAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeAnimation");
    s.store_class_end();
  }
}

fileTypeAudio::fileTypeAudio() {
}

const std::int32_t fileTypeAudio::ID;

void fileTypeAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeAudio");
    s.store_class_end();
  }
}

fileTypeDocument::fileTypeDocument() {
}

const std::int32_t fileTypeDocument::ID;

void fileTypeDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeDocument");
    s.store_class_end();
  }
}

fileTypeLivePhotoVideo::fileTypeLivePhotoVideo() {
}

const std::int32_t fileTypeLivePhotoVideo::ID;

void fileTypeLivePhotoVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeLivePhotoVideo");
    s.store_class_end();
  }
}

fileTypeNotificationSound::fileTypeNotificationSound() {
}

const std::int32_t fileTypeNotificationSound::ID;

void fileTypeNotificationSound::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeNotificationSound");
    s.store_class_end();
  }
}

fileTypePhoto::fileTypePhoto() {
}

const std::int32_t fileTypePhoto::ID;

void fileTypePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypePhoto");
    s.store_class_end();
  }
}

fileTypePhotoStory::fileTypePhotoStory() {
}

const std::int32_t fileTypePhotoStory::ID;

void fileTypePhotoStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypePhotoStory");
    s.store_class_end();
  }
}

fileTypeProfilePhoto::fileTypeProfilePhoto() {
}

const std::int32_t fileTypeProfilePhoto::ID;

void fileTypeProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeProfilePhoto");
    s.store_class_end();
  }
}

fileTypeSecret::fileTypeSecret() {
}

const std::int32_t fileTypeSecret::ID;

void fileTypeSecret::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSecret");
    s.store_class_end();
  }
}

fileTypeSecretThumbnail::fileTypeSecretThumbnail() {
}

const std::int32_t fileTypeSecretThumbnail::ID;

void fileTypeSecretThumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSecretThumbnail");
    s.store_class_end();
  }
}

fileTypeSecure::fileTypeSecure() {
}

const std::int32_t fileTypeSecure::ID;

void fileTypeSecure::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSecure");
    s.store_class_end();
  }
}

fileTypeSelfDestructingLivePhotoVideo::fileTypeSelfDestructingLivePhotoVideo() {
}

const std::int32_t fileTypeSelfDestructingLivePhotoVideo::ID;

void fileTypeSelfDestructingLivePhotoVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSelfDestructingLivePhotoVideo");
    s.store_class_end();
  }
}

fileTypeSelfDestructingPhoto::fileTypeSelfDestructingPhoto() {
}

const std::int32_t fileTypeSelfDestructingPhoto::ID;

void fileTypeSelfDestructingPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSelfDestructingPhoto");
    s.store_class_end();
  }
}

fileTypeSelfDestructingVideo::fileTypeSelfDestructingVideo() {
}

const std::int32_t fileTypeSelfDestructingVideo::ID;

void fileTypeSelfDestructingVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSelfDestructingVideo");
    s.store_class_end();
  }
}

fileTypeSelfDestructingVideoNote::fileTypeSelfDestructingVideoNote() {
}

const std::int32_t fileTypeSelfDestructingVideoNote::ID;

void fileTypeSelfDestructingVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSelfDestructingVideoNote");
    s.store_class_end();
  }
}

fileTypeSelfDestructingVoiceNote::fileTypeSelfDestructingVoiceNote() {
}

const std::int32_t fileTypeSelfDestructingVoiceNote::ID;

void fileTypeSelfDestructingVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSelfDestructingVoiceNote");
    s.store_class_end();
  }
}

fileTypeSticker::fileTypeSticker() {
}

const std::int32_t fileTypeSticker::ID;

void fileTypeSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSticker");
    s.store_class_end();
  }
}

fileTypeThumbnail::fileTypeThumbnail() {
}

const std::int32_t fileTypeThumbnail::ID;

void fileTypeThumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeThumbnail");
    s.store_class_end();
  }
}

fileTypeUnknown::fileTypeUnknown() {
}

const std::int32_t fileTypeUnknown::ID;

void fileTypeUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeUnknown");
    s.store_class_end();
  }
}

fileTypeVideo::fileTypeVideo() {
}

const std::int32_t fileTypeVideo::ID;

void fileTypeVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeVideo");
    s.store_class_end();
  }
}

fileTypeVideoNote::fileTypeVideoNote() {
}

const std::int32_t fileTypeVideoNote::ID;

void fileTypeVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeVideoNote");
    s.store_class_end();
  }
}

fileTypeVideoStory::fileTypeVideoStory() {
}

const std::int32_t fileTypeVideoStory::ID;

void fileTypeVideoStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeVideoStory");
    s.store_class_end();
  }
}

fileTypeVoiceNote::fileTypeVoiceNote() {
}

const std::int32_t fileTypeVoiceNote::ID;

void fileTypeVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeVoiceNote");
    s.store_class_end();
  }
}

fileTypeWallpaper::fileTypeWallpaper() {
}

const std::int32_t fileTypeWallpaper::ID;

void fileTypeWallpaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeWallpaper");
    s.store_class_end();
  }
}

firebaseDeviceVerificationParametersSafetyNet::firebaseDeviceVerificationParametersSafetyNet()
  : nonce_()
{}

firebaseDeviceVerificationParametersSafetyNet::firebaseDeviceVerificationParametersSafetyNet(bytes const &nonce_)
  : nonce_(std::move(nonce_))
{}

const std::int32_t firebaseDeviceVerificationParametersSafetyNet::ID;

void firebaseDeviceVerificationParametersSafetyNet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "firebaseDeviceVerificationParametersSafetyNet");
    s.store_bytes_field("nonce", nonce_);
    s.store_class_end();
  }
}

firebaseDeviceVerificationParametersPlayIntegrity::firebaseDeviceVerificationParametersPlayIntegrity()
  : nonce_()
  , cloud_project_number_()
{}

firebaseDeviceVerificationParametersPlayIntegrity::firebaseDeviceVerificationParametersPlayIntegrity(string const &nonce_, int64 cloud_project_number_)
  : nonce_(nonce_)
  , cloud_project_number_(cloud_project_number_)
{}

const std::int32_t firebaseDeviceVerificationParametersPlayIntegrity::ID;

void firebaseDeviceVerificationParametersPlayIntegrity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "firebaseDeviceVerificationParametersPlayIntegrity");
    s.store_field("nonce", nonce_);
    s.store_field("cloud_project_number", cloud_project_number_);
    s.store_class_end();
  }
}

foundChatMessages::foundChatMessages()
  : total_count_()
  , messages_()
  , next_from_message_id_()
{}

foundChatMessages::foundChatMessages(int32 total_count_, array<object_ptr<message>> &&messages_, int53 next_from_message_id_)
  : total_count_(total_count_)
  , messages_(std::move(messages_))
  , next_from_message_id_(next_from_message_id_)
{}

const std::int32_t foundChatMessages::ID;

void foundChatMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundChatMessages");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_from_message_id", next_from_message_id_);
    s.store_class_end();
  }
}

game::game()
  : id_()
  , short_name_()
  , title_()
  , text_()
  , description_()
  , photo_()
  , animation_()
{}

game::game(int64 id_, string const &short_name_, string const &title_, object_ptr<formattedText> &&text_, string const &description_, object_ptr<photo> &&photo_, object_ptr<animation> &&animation_)
  : id_(id_)
  , short_name_(short_name_)
  , title_(title_)
  , text_(std::move(text_))
  , description_(description_)
  , photo_(std::move(photo_))
  , animation_(std::move(animation_))
{}

const std::int32_t game::ID;

void game::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "game");
    s.store_field("id", id_);
    s.store_field("short_name", short_name_);
    s.store_field("title", title_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("description", description_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

giftPurchaseOfferStatePending::giftPurchaseOfferStatePending() {
}

const std::int32_t giftPurchaseOfferStatePending::ID;

void giftPurchaseOfferStatePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftPurchaseOfferStatePending");
    s.store_class_end();
  }
}

giftPurchaseOfferStateAccepted::giftPurchaseOfferStateAccepted() {
}

const std::int32_t giftPurchaseOfferStateAccepted::ID;

void giftPurchaseOfferStateAccepted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftPurchaseOfferStateAccepted");
    s.store_class_end();
  }
}

giftPurchaseOfferStateRejected::giftPurchaseOfferStateRejected() {
}

const std::int32_t giftPurchaseOfferStateRejected::ID;

void giftPurchaseOfferStateRejected::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftPurchaseOfferStateRejected");
    s.store_class_end();
  }
}

giveawayInfoOngoing::giveawayInfoOngoing()
  : creation_date_()
  , status_()
  , is_ended_()
{}

giveawayInfoOngoing::giveawayInfoOngoing(int32 creation_date_, object_ptr<GiveawayParticipantStatus> &&status_, bool is_ended_)
  : creation_date_(creation_date_)
  , status_(std::move(status_))
  , is_ended_(is_ended_)
{}

const std::int32_t giveawayInfoOngoing::ID;

void giveawayInfoOngoing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giveawayInfoOngoing");
    s.store_field("creation_date", creation_date_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_field("is_ended", is_ended_);
    s.store_class_end();
  }
}

giveawayInfoCompleted::giveawayInfoCompleted()
  : creation_date_()
  , actual_winners_selection_date_()
  , was_refunded_()
  , is_winner_()
  , winner_count_()
  , activation_count_()
  , gift_code_()
  , won_star_count_()
{}

giveawayInfoCompleted::giveawayInfoCompleted(int32 creation_date_, int32 actual_winners_selection_date_, bool was_refunded_, bool is_winner_, int32 winner_count_, int32 activation_count_, string const &gift_code_, int53 won_star_count_)
  : creation_date_(creation_date_)
  , actual_winners_selection_date_(actual_winners_selection_date_)
  , was_refunded_(was_refunded_)
  , is_winner_(is_winner_)
  , winner_count_(winner_count_)
  , activation_count_(activation_count_)
  , gift_code_(gift_code_)
  , won_star_count_(won_star_count_)
{}

const std::int32_t giveawayInfoCompleted::ID;

void giveawayInfoCompleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giveawayInfoCompleted");
    s.store_field("creation_date", creation_date_);
    s.store_field("actual_winners_selection_date", actual_winners_selection_date_);
    s.store_field("was_refunded", was_refunded_);
    s.store_field("is_winner", is_winner_);
    s.store_field("winner_count", winner_count_);
    s.store_field("activation_count", activation_count_);
    s.store_field("gift_code", gift_code_);
    s.store_field("won_star_count", won_star_count_);
    s.store_class_end();
  }
}

giveawayPrizePremium::giveawayPrizePremium()
  : month_count_()
{}

giveawayPrizePremium::giveawayPrizePremium(int32 month_count_)
  : month_count_(month_count_)
{}

const std::int32_t giveawayPrizePremium::ID;

void giveawayPrizePremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giveawayPrizePremium");
    s.store_field("month_count", month_count_);
    s.store_class_end();
  }
}

giveawayPrizeStars::giveawayPrizeStars()
  : star_count_()
{}

giveawayPrizeStars::giveawayPrizeStars(int53 star_count_)
  : star_count_(star_count_)
{}

const std::int32_t giveawayPrizeStars::ID;

void giveawayPrizeStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giveawayPrizeStars");
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

groupCallJoinParameters::groupCallJoinParameters()
  : audio_source_id_()
  , payload_()
  , is_muted_()
  , is_my_video_enabled_()
{}

groupCallJoinParameters::groupCallJoinParameters(int32 audio_source_id_, string const &payload_, bool is_muted_, bool is_my_video_enabled_)
  : audio_source_id_(audio_source_id_)
  , payload_(payload_)
  , is_muted_(is_muted_)
  , is_my_video_enabled_(is_my_video_enabled_)
{}

const std::int32_t groupCallJoinParameters::ID;

void groupCallJoinParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallJoinParameters");
    s.store_field("audio_source_id", audio_source_id_);
    s.store_field("payload", payload_);
    s.store_field("is_muted", is_muted_);
    s.store_field("is_my_video_enabled", is_my_video_enabled_);
    s.store_class_end();
  }
}

groupCallParticipants::groupCallParticipants()
  : total_count_()
  , participant_ids_()
{}

groupCallParticipants::groupCallParticipants(int32 total_count_, array<object_ptr<MessageSender>> &&participant_ids_)
  : total_count_(total_count_)
  , participant_ids_(std::move(participant_ids_))
{}

const std::int32_t groupCallParticipants::ID;

void groupCallParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallParticipants");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("participant_ids", participant_ids_.size()); for (const auto &_value : participant_ids_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

inlineQueryResultArticle::inlineQueryResultArticle()
  : id_()
  , url_()
  , title_()
  , description_()
  , thumbnail_()
{}

inlineQueryResultArticle::inlineQueryResultArticle(string const &id_, string const &url_, string const &title_, string const &description_, object_ptr<thumbnail> &&thumbnail_)
  : id_(id_)
  , url_(url_)
  , title_(title_)
  , description_(description_)
  , thumbnail_(std::move(thumbnail_))
{}

const std::int32_t inlineQueryResultArticle::ID;

void inlineQueryResultArticle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultArticle");
    s.store_field("id", id_);
    s.store_field("url", url_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_class_end();
  }
}

inlineQueryResultContact::inlineQueryResultContact()
  : id_()
  , contact_()
  , thumbnail_()
{}

inlineQueryResultContact::inlineQueryResultContact(string const &id_, object_ptr<contact> &&contact_, object_ptr<thumbnail> &&thumbnail_)
  : id_(id_)
  , contact_(std::move(contact_))
  , thumbnail_(std::move(thumbnail_))
{}

const std::int32_t inlineQueryResultContact::ID;

void inlineQueryResultContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultContact");
    s.store_field("id", id_);
    s.store_object_field("contact", static_cast<const BaseObject *>(contact_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_class_end();
  }
}

inlineQueryResultLocation::inlineQueryResultLocation()
  : id_()
  , location_()
  , title_()
  , thumbnail_()
{}

inlineQueryResultLocation::inlineQueryResultLocation(string const &id_, object_ptr<location> &&location_, string const &title_, object_ptr<thumbnail> &&thumbnail_)
  : id_(id_)
  , location_(std::move(location_))
  , title_(title_)
  , thumbnail_(std::move(thumbnail_))
{}

const std::int32_t inlineQueryResultLocation::ID;

void inlineQueryResultLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultLocation");
    s.store_field("id", id_);
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("title", title_);
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_class_end();
  }
}

inlineQueryResultVenue::inlineQueryResultVenue()
  : id_()
  , venue_()
  , thumbnail_()
{}

inlineQueryResultVenue::inlineQueryResultVenue(string const &id_, object_ptr<venue> &&venue_, object_ptr<thumbnail> &&thumbnail_)
  : id_(id_)
  , venue_(std::move(venue_))
  , thumbnail_(std::move(thumbnail_))
{}

const std::int32_t inlineQueryResultVenue::ID;

void inlineQueryResultVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultVenue");
    s.store_field("id", id_);
    s.store_object_field("venue", static_cast<const BaseObject *>(venue_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_class_end();
  }
}

inlineQueryResultGame::inlineQueryResultGame()
  : id_()
  , game_()
{}

inlineQueryResultGame::inlineQueryResultGame(string const &id_, object_ptr<game> &&game_)
  : id_(id_)
  , game_(std::move(game_))
{}

const std::int32_t inlineQueryResultGame::ID;

void inlineQueryResultGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultGame");
    s.store_field("id", id_);
    s.store_object_field("game", static_cast<const BaseObject *>(game_.get()));
    s.store_class_end();
  }
}

inlineQueryResultAnimation::inlineQueryResultAnimation()
  : id_()
  , animation_()
  , title_()
{}

inlineQueryResultAnimation::inlineQueryResultAnimation(string const &id_, object_ptr<animation> &&animation_, string const &title_)
  : id_(id_)
  , animation_(std::move(animation_))
  , title_(title_)
{}

const std::int32_t inlineQueryResultAnimation::ID;

void inlineQueryResultAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultAnimation");
    s.store_field("id", id_);
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_field("title", title_);
    s.store_class_end();
  }
}

inlineQueryResultAudio::inlineQueryResultAudio()
  : id_()
  , audio_()
{}

inlineQueryResultAudio::inlineQueryResultAudio(string const &id_, object_ptr<audio> &&audio_)
  : id_(id_)
  , audio_(std::move(audio_))
{}

const std::int32_t inlineQueryResultAudio::ID;

void inlineQueryResultAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultAudio");
    s.store_field("id", id_);
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_class_end();
  }
}

inlineQueryResultDocument::inlineQueryResultDocument()
  : id_()
  , document_()
  , title_()
  , description_()
{}

inlineQueryResultDocument::inlineQueryResultDocument(string const &id_, object_ptr<document> &&document_, string const &title_, string const &description_)
  : id_(id_)
  , document_(std::move(document_))
  , title_(title_)
  , description_(description_)
{}

const std::int32_t inlineQueryResultDocument::ID;

void inlineQueryResultDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultDocument");
    s.store_field("id", id_);
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

inlineQueryResultPhoto::inlineQueryResultPhoto()
  : id_()
  , photo_()
  , title_()
  , description_()
{}

inlineQueryResultPhoto::inlineQueryResultPhoto(string const &id_, object_ptr<photo> &&photo_, string const &title_, string const &description_)
  : id_(id_)
  , photo_(std::move(photo_))
  , title_(title_)
  , description_(description_)
{}

const std::int32_t inlineQueryResultPhoto::ID;

void inlineQueryResultPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultPhoto");
    s.store_field("id", id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

inlineQueryResultSticker::inlineQueryResultSticker()
  : id_()
  , sticker_()
{}

inlineQueryResultSticker::inlineQueryResultSticker(string const &id_, object_ptr<sticker> &&sticker_)
  : id_(id_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t inlineQueryResultSticker::ID;

void inlineQueryResultSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultSticker");
    s.store_field("id", id_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

inlineQueryResultVideo::inlineQueryResultVideo()
  : id_()
  , video_()
  , title_()
  , description_()
{}

inlineQueryResultVideo::inlineQueryResultVideo(string const &id_, object_ptr<video> &&video_, string const &title_, string const &description_)
  : id_(id_)
  , video_(std::move(video_))
  , title_(title_)
  , description_(description_)
{}

const std::int32_t inlineQueryResultVideo::ID;

void inlineQueryResultVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultVideo");
    s.store_field("id", id_);
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

inlineQueryResultVoiceNote::inlineQueryResultVoiceNote()
  : id_()
  , voice_note_()
  , title_()
{}

inlineQueryResultVoiceNote::inlineQueryResultVoiceNote(string const &id_, object_ptr<voiceNote> &&voice_note_, string const &title_)
  : id_(id_)
  , voice_note_(std::move(voice_note_))
  , title_(title_)
{}

const std::int32_t inlineQueryResultVoiceNote::ID;

void inlineQueryResultVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultVoiceNote");
    s.store_field("id", id_);
    s.store_object_field("voice_note", static_cast<const BaseObject *>(voice_note_.get()));
    s.store_field("title", title_);
    s.store_class_end();
  }
}

inputChatPhotoPrevious::inputChatPhotoPrevious()
  : chat_photo_id_()
{}

inputChatPhotoPrevious::inputChatPhotoPrevious(int64 chat_photo_id_)
  : chat_photo_id_(chat_photo_id_)
{}

const std::int32_t inputChatPhotoPrevious::ID;

void inputChatPhotoPrevious::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatPhotoPrevious");
    s.store_field("chat_photo_id", chat_photo_id_);
    s.store_class_end();
  }
}

inputChatPhotoStatic::inputChatPhotoStatic()
  : photo_()
{}

inputChatPhotoStatic::inputChatPhotoStatic(object_ptr<InputFile> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t inputChatPhotoStatic::ID;

void inputChatPhotoStatic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatPhotoStatic");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

inputChatPhotoAnimation::inputChatPhotoAnimation()
  : animation_()
  , main_frame_timestamp_()
{}

inputChatPhotoAnimation::inputChatPhotoAnimation(object_ptr<InputFile> &&animation_, double main_frame_timestamp_)
  : animation_(std::move(animation_))
  , main_frame_timestamp_(main_frame_timestamp_)
{}

const std::int32_t inputChatPhotoAnimation::ID;

void inputChatPhotoAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatPhotoAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_field("main_frame_timestamp", main_frame_timestamp_);
    s.store_class_end();
  }
}

inputChatPhotoSticker::inputChatPhotoSticker()
  : sticker_()
{}

inputChatPhotoSticker::inputChatPhotoSticker(object_ptr<chatPhotoSticker> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t inputChatPhotoSticker::ID;

void inputChatPhotoSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatPhotoSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

inputPersonalDocument::inputPersonalDocument()
  : files_()
  , translation_()
{}

inputPersonalDocument::inputPersonalDocument(array<object_ptr<InputFile>> &&files_, array<object_ptr<InputFile>> &&translation_)
  : files_(std::move(files_))
  , translation_(std::move(translation_))
{}

const std::int32_t inputPersonalDocument::ID;

void inputPersonalDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPersonalDocument");
    { s.store_vector_begin("files", files_.size()); for (const auto &_value : files_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("translation", translation_.size()); for (const auto &_value : translation_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

inviteLinkChatTypeBasicGroup::inviteLinkChatTypeBasicGroup() {
}

const std::int32_t inviteLinkChatTypeBasicGroup::ID;

void inviteLinkChatTypeBasicGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inviteLinkChatTypeBasicGroup");
    s.store_class_end();
  }
}

inviteLinkChatTypeSupergroup::inviteLinkChatTypeSupergroup() {
}

const std::int32_t inviteLinkChatTypeSupergroup::ID;

void inviteLinkChatTypeSupergroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inviteLinkChatTypeSupergroup");
    s.store_class_end();
  }
}

inviteLinkChatTypeChannel::inviteLinkChatTypeChannel() {
}

const std::int32_t inviteLinkChatTypeChannel::ID;

void inviteLinkChatTypeChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inviteLinkChatTypeChannel");
    s.store_class_end();
  }
}

languagePackStringValueOrdinary::languagePackStringValueOrdinary()
  : value_()
{}

languagePackStringValueOrdinary::languagePackStringValueOrdinary(string const &value_)
  : value_(value_)
{}

const std::int32_t languagePackStringValueOrdinary::ID;

void languagePackStringValueOrdinary::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "languagePackStringValueOrdinary");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

languagePackStringValuePluralized::languagePackStringValuePluralized()
  : zero_value_()
  , one_value_()
  , two_value_()
  , few_value_()
  , many_value_()
  , other_value_()
{}

languagePackStringValuePluralized::languagePackStringValuePluralized(string const &zero_value_, string const &one_value_, string const &two_value_, string const &few_value_, string const &many_value_, string const &other_value_)
  : zero_value_(zero_value_)
  , one_value_(one_value_)
  , two_value_(two_value_)
  , few_value_(few_value_)
  , many_value_(many_value_)
  , other_value_(other_value_)
{}

const std::int32_t languagePackStringValuePluralized::ID;

void languagePackStringValuePluralized::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "languagePackStringValuePluralized");
    s.store_field("zero_value", zero_value_);
    s.store_field("one_value", one_value_);
    s.store_field("two_value", two_value_);
    s.store_field("few_value", few_value_);
    s.store_field("many_value", many_value_);
    s.store_field("other_value", other_value_);
    s.store_class_end();
  }
}

languagePackStringValueDeleted::languagePackStringValueDeleted() {
}

const std::int32_t languagePackStringValueDeleted::ID;

void languagePackStringValueDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "languagePackStringValueDeleted");
    s.store_class_end();
  }
}

logStreamDefault::logStreamDefault() {
}

const std::int32_t logStreamDefault::ID;

void logStreamDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "logStreamDefault");
    s.store_class_end();
  }
}

logStreamFile::logStreamFile()
  : path_()
  , max_file_size_()
  , redirect_stderr_()
{}

logStreamFile::logStreamFile(string const &path_, int53 max_file_size_, bool redirect_stderr_)
  : path_(path_)
  , max_file_size_(max_file_size_)
  , redirect_stderr_(redirect_stderr_)
{}

const std::int32_t logStreamFile::ID;

void logStreamFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "logStreamFile");
    s.store_field("path", path_);
    s.store_field("max_file_size", max_file_size_);
    s.store_field("redirect_stderr", redirect_stderr_);
    s.store_class_end();
  }
}

logStreamEmpty::logStreamEmpty() {
}

const std::int32_t logStreamEmpty::ID;

void logStreamEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "logStreamEmpty");
    s.store_class_end();
  }
}

networkStatistics::networkStatistics()
  : since_date_()
  , entries_()
{}

networkStatistics::networkStatistics(int32 since_date_, array<object_ptr<NetworkStatisticsEntry>> &&entries_)
  : since_date_(since_date_)
  , entries_(std::move(entries_))
{}

const std::int32_t networkStatistics::ID;

void networkStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkStatistics");
    s.store_field("since_date", since_date_);
    { s.store_vector_begin("entries", entries_.size()); for (const auto &_value : entries_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

notificationSounds::notificationSounds()
  : notification_sounds_()
{}

notificationSounds::notificationSounds(array<object_ptr<notificationSound>> &&notification_sounds_)
  : notification_sounds_(std::move(notification_sounds_))
{}

const std::int32_t notificationSounds::ID;

void notificationSounds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSounds");
    { s.store_vector_begin("notification_sounds", notification_sounds_.size()); for (const auto &_value : notification_sounds_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

notificationTypeNewMessage::notificationTypeNewMessage()
  : message_()
  , show_preview_()
{}

notificationTypeNewMessage::notificationTypeNewMessage(object_ptr<message> &&message_, bool show_preview_)
  : message_(std::move(message_))
  , show_preview_(show_preview_)
{}

const std::int32_t notificationTypeNewMessage::ID;

void notificationTypeNewMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationTypeNewMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("show_preview", show_preview_);
    s.store_class_end();
  }
}

notificationTypeNewSecretChat::notificationTypeNewSecretChat() {
}

const std::int32_t notificationTypeNewSecretChat::ID;

void notificationTypeNewSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationTypeNewSecretChat");
    s.store_class_end();
  }
}

notificationTypeNewCall::notificationTypeNewCall()
  : call_id_()
{}

notificationTypeNewCall::notificationTypeNewCall(int32 call_id_)
  : call_id_(call_id_)
{}

const std::int32_t notificationTypeNewCall::ID;

void notificationTypeNewCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationTypeNewCall");
    s.store_field("call_id", call_id_);
    s.store_class_end();
  }
}

notificationTypeNewPushMessage::notificationTypeNewPushMessage()
  : message_id_()
  , sender_id_()
  , sender_name_()
  , is_outgoing_()
  , content_()
{}

notificationTypeNewPushMessage::notificationTypeNewPushMessage(int53 message_id_, object_ptr<MessageSender> &&sender_id_, string const &sender_name_, bool is_outgoing_, object_ptr<PushMessageContent> &&content_)
  : message_id_(message_id_)
  , sender_id_(std::move(sender_id_))
  , sender_name_(sender_name_)
  , is_outgoing_(is_outgoing_)
  , content_(std::move(content_))
{}

const std::int32_t notificationTypeNewPushMessage::ID;

void notificationTypeNewPushMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationTypeNewPushMessage");
    s.store_field("message_id", message_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("sender_name", sender_name_);
    s.store_field("is_outgoing", is_outgoing_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_class_end();
  }
}

pageBlockHorizontalAlignmentLeft::pageBlockHorizontalAlignmentLeft() {
}

const std::int32_t pageBlockHorizontalAlignmentLeft::ID;

void pageBlockHorizontalAlignmentLeft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockHorizontalAlignmentLeft");
    s.store_class_end();
  }
}

pageBlockHorizontalAlignmentCenter::pageBlockHorizontalAlignmentCenter() {
}

const std::int32_t pageBlockHorizontalAlignmentCenter::ID;

void pageBlockHorizontalAlignmentCenter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockHorizontalAlignmentCenter");
    s.store_class_end();
  }
}

pageBlockHorizontalAlignmentRight::pageBlockHorizontalAlignmentRight() {
}

const std::int32_t pageBlockHorizontalAlignmentRight::ID;

void pageBlockHorizontalAlignmentRight::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockHorizontalAlignmentRight");
    s.store_class_end();
  }
}

paymentResult::paymentResult()
  : success_()
  , verification_url_()
{}

paymentResult::paymentResult(bool success_, string const &verification_url_)
  : success_(success_)
  , verification_url_(verification_url_)
{}

const std::int32_t paymentResult::ID;

void paymentResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentResult");
    s.store_field("success", success_);
    s.store_field("verification_url", verification_url_);
    s.store_class_end();
  }
}

pollOptionProperties::pollOptionProperties()
  : can_be_deleted_()
  , can_be_replied_()
  , can_be_replied_in_another_chat_()
  , can_get_link_()
{}

pollOptionProperties::pollOptionProperties(bool can_be_deleted_, bool can_be_replied_, bool can_be_replied_in_another_chat_, bool can_get_link_)
  : can_be_deleted_(can_be_deleted_)
  , can_be_replied_(can_be_replied_)
  , can_be_replied_in_another_chat_(can_be_replied_in_another_chat_)
  , can_get_link_(can_get_link_)
{}

const std::int32_t pollOptionProperties::ID;

void pollOptionProperties::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollOptionProperties");
    s.store_field("can_be_deleted", can_be_deleted_);
    s.store_field("can_be_replied", can_be_replied_);
    s.store_field("can_be_replied_in_another_chat", can_be_replied_in_another_chat_);
    s.store_field("can_get_link", can_get_link_);
    s.store_class_end();
  }
}

premiumGiftPaymentOptions::premiumGiftPaymentOptions()
  : options_()
{}

premiumGiftPaymentOptions::premiumGiftPaymentOptions(array<object_ptr<premiumGiftPaymentOption>> &&options_)
  : options_(std::move(options_))
{}

const std::int32_t premiumGiftPaymentOptions::ID;

void premiumGiftPaymentOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumGiftPaymentOptions");
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

premiumState::premiumState()
  : state_()
  , payment_options_()
  , animations_()
  , business_animations_()
{}

premiumState::premiumState(object_ptr<formattedText> &&state_, array<object_ptr<premiumStatePaymentOption>> &&payment_options_, array<object_ptr<premiumFeaturePromotionAnimation>> &&animations_, array<object_ptr<businessFeaturePromotionAnimation>> &&business_animations_)
  : state_(std::move(state_))
  , payment_options_(std::move(payment_options_))
  , animations_(std::move(animations_))
  , business_animations_(std::move(business_animations_))
{}

const std::int32_t premiumState::ID;

void premiumState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumState");
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    { s.store_vector_begin("payment_options", payment_options_.size()); for (const auto &_value : payment_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("animations", animations_.size()); for (const auto &_value : animations_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("business_animations", business_animations_.size()); for (const auto &_value : business_animations_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

publicChatTypeHasUsername::publicChatTypeHasUsername() {
}

const std::int32_t publicChatTypeHasUsername::ID;

void publicChatTypeHasUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "publicChatTypeHasUsername");
    s.store_class_end();
  }
}

publicChatTypeIsLocationBased::publicChatTypeIsLocationBased() {
}

const std::int32_t publicChatTypeIsLocationBased::ID;

void publicChatTypeIsLocationBased::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "publicChatTypeIsLocationBased");
    s.store_class_end();
  }
}

reportStoryResultOk::reportStoryResultOk() {
}

const std::int32_t reportStoryResultOk::ID;

void reportStoryResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportStoryResultOk");
    s.store_class_end();
  }
}

reportStoryResultOptionRequired::reportStoryResultOptionRequired()
  : title_()
  , options_()
{}

reportStoryResultOptionRequired::reportStoryResultOptionRequired(string const &title_, array<object_ptr<reportOption>> &&options_)
  : title_(title_)
  , options_(std::move(options_))
{}

const std::int32_t reportStoryResultOptionRequired::ID;

void reportStoryResultOptionRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportStoryResultOptionRequired");
    s.store_field("title", title_);
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

reportStoryResultTextRequired::reportStoryResultTextRequired()
  : option_id_()
  , is_optional_()
{}

reportStoryResultTextRequired::reportStoryResultTextRequired(bytes const &option_id_, bool is_optional_)
  : option_id_(std::move(option_id_))
  , is_optional_(is_optional_)
{}

const std::int32_t reportStoryResultTextRequired::ID;

void reportStoryResultTextRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportStoryResultTextRequired");
    s.store_bytes_field("option_id", option_id_);
    s.store_field("is_optional", is_optional_);
    s.store_class_end();
  }
}

scopeNotificationSettings::scopeNotificationSettings()
  : mute_for_()
  , sound_id_()
  , show_preview_()
  , use_default_mute_stories_()
  , mute_stories_()
  , story_sound_id_()
  , show_story_poster_()
  , disable_pinned_message_notifications_()
  , disable_mention_notifications_()
{}

scopeNotificationSettings::scopeNotificationSettings(int32 mute_for_, int64 sound_id_, bool show_preview_, bool use_default_mute_stories_, bool mute_stories_, int64 story_sound_id_, bool show_story_poster_, bool disable_pinned_message_notifications_, bool disable_mention_notifications_)
  : mute_for_(mute_for_)
  , sound_id_(sound_id_)
  , show_preview_(show_preview_)
  , use_default_mute_stories_(use_default_mute_stories_)
  , mute_stories_(mute_stories_)
  , story_sound_id_(story_sound_id_)
  , show_story_poster_(show_story_poster_)
  , disable_pinned_message_notifications_(disable_pinned_message_notifications_)
  , disable_mention_notifications_(disable_mention_notifications_)
{}

const std::int32_t scopeNotificationSettings::ID;

void scopeNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "scopeNotificationSettings");
    s.store_field("mute_for", mute_for_);
    s.store_field("sound_id", sound_id_);
    s.store_field("show_preview", show_preview_);
    s.store_field("use_default_mute_stories", use_default_mute_stories_);
    s.store_field("mute_stories", mute_stories_);
    s.store_field("story_sound_id", story_sound_id_);
    s.store_field("show_story_poster", show_story_poster_);
    s.store_field("disable_pinned_message_notifications", disable_pinned_message_notifications_);
    s.store_field("disable_mention_notifications", disable_mention_notifications_);
    s.store_class_end();
  }
}

searchMessagesChatTypeFilterPrivate::searchMessagesChatTypeFilterPrivate() {
}

const std::int32_t searchMessagesChatTypeFilterPrivate::ID;

void searchMessagesChatTypeFilterPrivate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesChatTypeFilterPrivate");
    s.store_class_end();
  }
}

searchMessagesChatTypeFilterGroup::searchMessagesChatTypeFilterGroup() {
}

const std::int32_t searchMessagesChatTypeFilterGroup::ID;

void searchMessagesChatTypeFilterGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesChatTypeFilterGroup");
    s.store_class_end();
  }
}

searchMessagesChatTypeFilterChannel::searchMessagesChatTypeFilterChannel() {
}

const std::int32_t searchMessagesChatTypeFilterChannel::ID;

void searchMessagesChatTypeFilterChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesChatTypeFilterChannel");
    s.store_class_end();
  }
}

searchMessagesFilterEmpty::searchMessagesFilterEmpty() {
}

const std::int32_t searchMessagesFilterEmpty::ID;

void searchMessagesFilterEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterEmpty");
    s.store_class_end();
  }
}

searchMessagesFilterAnimation::searchMessagesFilterAnimation() {
}

const std::int32_t searchMessagesFilterAnimation::ID;

void searchMessagesFilterAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterAnimation");
    s.store_class_end();
  }
}

searchMessagesFilterAudio::searchMessagesFilterAudio() {
}

const std::int32_t searchMessagesFilterAudio::ID;

void searchMessagesFilterAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterAudio");
    s.store_class_end();
  }
}

searchMessagesFilterDocument::searchMessagesFilterDocument() {
}

const std::int32_t searchMessagesFilterDocument::ID;

void searchMessagesFilterDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterDocument");
    s.store_class_end();
  }
}

searchMessagesFilterPhoto::searchMessagesFilterPhoto() {
}

const std::int32_t searchMessagesFilterPhoto::ID;

void searchMessagesFilterPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterPhoto");
    s.store_class_end();
  }
}

searchMessagesFilterPoll::searchMessagesFilterPoll() {
}

const std::int32_t searchMessagesFilterPoll::ID;

void searchMessagesFilterPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterPoll");
    s.store_class_end();
  }
}

searchMessagesFilterVideo::searchMessagesFilterVideo() {
}

const std::int32_t searchMessagesFilterVideo::ID;

void searchMessagesFilterVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterVideo");
    s.store_class_end();
  }
}

searchMessagesFilterVoiceNote::searchMessagesFilterVoiceNote() {
}

const std::int32_t searchMessagesFilterVoiceNote::ID;

void searchMessagesFilterVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterVoiceNote");
    s.store_class_end();
  }
}

searchMessagesFilterPhotoAndVideo::searchMessagesFilterPhotoAndVideo() {
}

const std::int32_t searchMessagesFilterPhotoAndVideo::ID;

void searchMessagesFilterPhotoAndVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterPhotoAndVideo");
    s.store_class_end();
  }
}

searchMessagesFilterUrl::searchMessagesFilterUrl() {
}

const std::int32_t searchMessagesFilterUrl::ID;

void searchMessagesFilterUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterUrl");
    s.store_class_end();
  }
}

searchMessagesFilterChatPhoto::searchMessagesFilterChatPhoto() {
}

const std::int32_t searchMessagesFilterChatPhoto::ID;

void searchMessagesFilterChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterChatPhoto");
    s.store_class_end();
  }
}

searchMessagesFilterVideoNote::searchMessagesFilterVideoNote() {
}

const std::int32_t searchMessagesFilterVideoNote::ID;

void searchMessagesFilterVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterVideoNote");
    s.store_class_end();
  }
}

searchMessagesFilterVoiceAndVideoNote::searchMessagesFilterVoiceAndVideoNote() {
}

const std::int32_t searchMessagesFilterVoiceAndVideoNote::ID;

void searchMessagesFilterVoiceAndVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterVoiceAndVideoNote");
    s.store_class_end();
  }
}

searchMessagesFilterMention::searchMessagesFilterMention() {
}

const std::int32_t searchMessagesFilterMention::ID;

void searchMessagesFilterMention::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterMention");
    s.store_class_end();
  }
}

searchMessagesFilterUnreadMention::searchMessagesFilterUnreadMention() {
}

const std::int32_t searchMessagesFilterUnreadMention::ID;

void searchMessagesFilterUnreadMention::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterUnreadMention");
    s.store_class_end();
  }
}

searchMessagesFilterUnreadReaction::searchMessagesFilterUnreadReaction() {
}

const std::int32_t searchMessagesFilterUnreadReaction::ID;

void searchMessagesFilterUnreadReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterUnreadReaction");
    s.store_class_end();
  }
}

searchMessagesFilterUnreadPollVote::searchMessagesFilterUnreadPollVote() {
}

const std::int32_t searchMessagesFilterUnreadPollVote::ID;

void searchMessagesFilterUnreadPollVote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterUnreadPollVote");
    s.store_class_end();
  }
}

searchMessagesFilterFailedToSend::searchMessagesFilterFailedToSend() {
}

const std::int32_t searchMessagesFilterFailedToSend::ID;

void searchMessagesFilterFailedToSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterFailedToSend");
    s.store_class_end();
  }
}

searchMessagesFilterPinned::searchMessagesFilterPinned() {
}

const std::int32_t searchMessagesFilterPinned::ID;

void searchMessagesFilterPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterPinned");
    s.store_class_end();
  }
}

seconds::seconds()
  : seconds_()
{}

seconds::seconds(double seconds_)
  : seconds_(seconds_)
{}

const std::int32_t seconds::ID;

void seconds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "seconds");
    s.store_field("seconds", seconds_);
    s.store_class_end();
  }
}

settingsSectionAppearance::settingsSectionAppearance()
  : subsection_()
{}

settingsSectionAppearance::settingsSectionAppearance(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionAppearance::ID;

void settingsSectionAppearance::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionAppearance");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionAskQuestion::settingsSectionAskQuestion() {
}

const std::int32_t settingsSectionAskQuestion::ID;

void settingsSectionAskQuestion::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionAskQuestion");
    s.store_class_end();
  }
}

settingsSectionBusiness::settingsSectionBusiness()
  : subsection_()
{}

settingsSectionBusiness::settingsSectionBusiness(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionBusiness::ID;

void settingsSectionBusiness::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionBusiness");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionChatFolders::settingsSectionChatFolders()
  : subsection_()
{}

settingsSectionChatFolders::settingsSectionChatFolders(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionChatFolders::ID;

void settingsSectionChatFolders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionChatFolders");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionDataAndStorage::settingsSectionDataAndStorage()
  : subsection_()
{}

settingsSectionDataAndStorage::settingsSectionDataAndStorage(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionDataAndStorage::ID;

void settingsSectionDataAndStorage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionDataAndStorage");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionDevices::settingsSectionDevices()
  : subsection_()
{}

settingsSectionDevices::settingsSectionDevices(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionDevices::ID;

void settingsSectionDevices::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionDevices");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionEditProfile::settingsSectionEditProfile()
  : subsection_()
{}

settingsSectionEditProfile::settingsSectionEditProfile(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionEditProfile::ID;

void settingsSectionEditProfile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionEditProfile");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionFaq::settingsSectionFaq() {
}

const std::int32_t settingsSectionFaq::ID;

void settingsSectionFaq::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionFaq");
    s.store_class_end();
  }
}

settingsSectionFeatures::settingsSectionFeatures() {
}

const std::int32_t settingsSectionFeatures::ID;

void settingsSectionFeatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionFeatures");
    s.store_class_end();
  }
}

settingsSectionInAppBrowser::settingsSectionInAppBrowser()
  : subsection_()
{}

settingsSectionInAppBrowser::settingsSectionInAppBrowser(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionInAppBrowser::ID;

void settingsSectionInAppBrowser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionInAppBrowser");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionLanguage::settingsSectionLanguage()
  : subsection_()
{}

settingsSectionLanguage::settingsSectionLanguage(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionLanguage::ID;

void settingsSectionLanguage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionLanguage");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionMyStars::settingsSectionMyStars()
  : subsection_()
{}

settingsSectionMyStars::settingsSectionMyStars(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionMyStars::ID;

void settingsSectionMyStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionMyStars");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionMyToncoins::settingsSectionMyToncoins() {
}

const std::int32_t settingsSectionMyToncoins::ID;

void settingsSectionMyToncoins::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionMyToncoins");
    s.store_class_end();
  }
}

settingsSectionNotifications::settingsSectionNotifications()
  : subsection_()
{}

settingsSectionNotifications::settingsSectionNotifications(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionNotifications::ID;

void settingsSectionNotifications::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionNotifications");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionPowerSaving::settingsSectionPowerSaving()
  : subsection_()
{}

settingsSectionPowerSaving::settingsSectionPowerSaving(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionPowerSaving::ID;

void settingsSectionPowerSaving::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionPowerSaving");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionPremium::settingsSectionPremium() {
}

const std::int32_t settingsSectionPremium::ID;

void settingsSectionPremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionPremium");
    s.store_class_end();
  }
}

settingsSectionPrivacyAndSecurity::settingsSectionPrivacyAndSecurity()
  : subsection_()
{}

settingsSectionPrivacyAndSecurity::settingsSectionPrivacyAndSecurity(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionPrivacyAndSecurity::ID;

void settingsSectionPrivacyAndSecurity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionPrivacyAndSecurity");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionPrivacyPolicy::settingsSectionPrivacyPolicy() {
}

const std::int32_t settingsSectionPrivacyPolicy::ID;

void settingsSectionPrivacyPolicy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionPrivacyPolicy");
    s.store_class_end();
  }
}

settingsSectionQrCode::settingsSectionQrCode()
  : subsection_()
{}

settingsSectionQrCode::settingsSectionQrCode(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionQrCode::ID;

void settingsSectionQrCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionQrCode");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

settingsSectionSearch::settingsSectionSearch() {
}

const std::int32_t settingsSectionSearch::ID;

void settingsSectionSearch::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionSearch");
    s.store_class_end();
  }
}

settingsSectionSendGift::settingsSectionSendGift()
  : subsection_()
{}

settingsSectionSendGift::settingsSectionSendGift(string const &subsection_)
  : subsection_(subsection_)
{}

const std::int32_t settingsSectionSendGift::ID;

void settingsSectionSendGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "settingsSectionSendGift");
    s.store_field("subsection", subsection_);
    s.store_class_end();
  }
}

sharedChat::sharedChat()
  : chat_id_()
  , title_()
  , username_()
  , photo_()
{}

sharedChat::sharedChat(int53 chat_id_, string const &title_, string const &username_, object_ptr<photo> &&photo_)
  : chat_id_(chat_id_)
  , title_(title_)
  , username_(username_)
  , photo_(std::move(photo_))
{}

const std::int32_t sharedChat::ID;

void sharedChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sharedChat");
    s.store_field("chat_id", chat_id_);
    s.store_field("title", title_);
    s.store_field("username", username_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

sponsoredChat::sponsoredChat()
  : unique_id_()
  , chat_id_()
  , sponsor_info_()
  , additional_info_()
{}

sponsoredChat::sponsoredChat(int53 unique_id_, int53 chat_id_, string const &sponsor_info_, string const &additional_info_)
  : unique_id_(unique_id_)
  , chat_id_(chat_id_)
  , sponsor_info_(sponsor_info_)
  , additional_info_(additional_info_)
{}

const std::int32_t sponsoredChat::ID;

void sponsoredChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sponsoredChat");
    s.store_field("unique_id", unique_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("sponsor_info", sponsor_info_);
    s.store_field("additional_info", additional_info_);
    s.store_class_end();
  }
}

stakeDiceState::stakeDiceState()
  : state_hash_()
  , stake_toncoin_amount_()
  , suggested_stake_toncoin_amounts_()
  , current_streak_()
  , prize_per_mille_()
  , streak_prize_per_mille_()
{}

stakeDiceState::stakeDiceState(string const &state_hash_, int53 stake_toncoin_amount_, array<int53> &&suggested_stake_toncoin_amounts_, int32 current_streak_, array<int32> &&prize_per_mille_, int32 streak_prize_per_mille_)
  : state_hash_(state_hash_)
  , stake_toncoin_amount_(stake_toncoin_amount_)
  , suggested_stake_toncoin_amounts_(std::move(suggested_stake_toncoin_amounts_))
  , current_streak_(current_streak_)
  , prize_per_mille_(std::move(prize_per_mille_))
  , streak_prize_per_mille_(streak_prize_per_mille_)
{}

const std::int32_t stakeDiceState::ID;

void stakeDiceState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stakeDiceState");
    s.store_field("state_hash", state_hash_);
    s.store_field("stake_toncoin_amount", stake_toncoin_amount_);
    { s.store_vector_begin("suggested_stake_toncoin_amounts", suggested_stake_toncoin_amounts_.size()); for (const auto &_value : suggested_stake_toncoin_amounts_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("current_streak", current_streak_);
    { s.store_vector_begin("prize_per_mille", prize_per_mille_.size()); for (const auto &_value : prize_per_mille_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("streak_prize_per_mille", streak_prize_per_mille_);
    s.store_class_end();
  }
}

starGiveawayPaymentOptions::starGiveawayPaymentOptions()
  : options_()
{}

starGiveawayPaymentOptions::starGiveawayPaymentOptions(array<object_ptr<starGiveawayPaymentOption>> &&options_)
  : options_(std::move(options_))
{}

const std::int32_t starGiveawayPaymentOptions::ID;

void starGiveawayPaymentOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiveawayPaymentOptions");
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

starPaymentOption::starPaymentOption()
  : currency_()
  , amount_()
  , star_count_()
  , store_product_id_()
  , is_additional_()
{}

starPaymentOption::starPaymentOption(string const &currency_, int53 amount_, int53 star_count_, string const &store_product_id_, bool is_additional_)
  : currency_(currency_)
  , amount_(amount_)
  , star_count_(star_count_)
  , store_product_id_(store_product_id_)
  , is_additional_(is_additional_)
{}

const std::int32_t starPaymentOption::ID;

void starPaymentOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starPaymentOption");
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("star_count", star_count_);
    s.store_field("store_product_id", store_product_id_);
    s.store_field("is_additional", is_additional_);
    s.store_class_end();
  }
}

starSubscription::starSubscription()
  : id_()
  , chat_id_()
  , expiration_date_()
  , is_canceled_()
  , is_expiring_()
  , pricing_()
  , type_()
{}

starSubscription::starSubscription(string const &id_, int53 chat_id_, int32 expiration_date_, bool is_canceled_, bool is_expiring_, object_ptr<starSubscriptionPricing> &&pricing_, object_ptr<StarSubscriptionType> &&type_)
  : id_(id_)
  , chat_id_(chat_id_)
  , expiration_date_(expiration_date_)
  , is_canceled_(is_canceled_)
  , is_expiring_(is_expiring_)
  , pricing_(std::move(pricing_))
  , type_(std::move(type_))
{}

const std::int32_t starSubscription::ID;

void starSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starSubscription");
    s.store_field("id", id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("expiration_date", expiration_date_);
    s.store_field("is_canceled", is_canceled_);
    s.store_field("is_expiring", is_expiring_);
    s.store_object_field("pricing", static_cast<const BaseObject *>(pricing_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

starSubscriptions::starSubscriptions()
  : star_amount_()
  , subscriptions_()
  , required_star_count_()
  , next_offset_()
{}

starSubscriptions::starSubscriptions(object_ptr<starAmount> &&star_amount_, array<object_ptr<starSubscription>> &&subscriptions_, int53 required_star_count_, string const &next_offset_)
  : star_amount_(std::move(star_amount_))
  , subscriptions_(std::move(subscriptions_))
  , required_star_count_(required_star_count_)
  , next_offset_(next_offset_)
{}

const std::int32_t starSubscriptions::ID;

void starSubscriptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starSubscriptions");
    s.store_object_field("star_amount", static_cast<const BaseObject *>(star_amount_.get()));
    { s.store_vector_begin("subscriptions", subscriptions_.size()); for (const auto &_value : subscriptions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("required_star_count", required_star_count_);
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

storyFullId::storyFullId()
  : poster_chat_id_()
  , story_id_()
{}

storyFullId::storyFullId(int53 poster_chat_id_, int32 story_id_)
  : poster_chat_id_(poster_chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t storyFullId::ID;

void storyFullId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyFullId");
    s.store_field("poster_chat_id", poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

storyInteractionInfo::storyInteractionInfo()
  : view_count_()
  , forward_count_()
  , reaction_count_()
  , recent_viewer_user_ids_()
{}

storyInteractionInfo::storyInteractionInfo(int32 view_count_, int32 forward_count_, int32 reaction_count_, array<int53> &&recent_viewer_user_ids_)
  : view_count_(view_count_)
  , forward_count_(forward_count_)
  , reaction_count_(reaction_count_)
  , recent_viewer_user_ids_(std::move(recent_viewer_user_ids_))
{}

const std::int32_t storyInteractionInfo::ID;

void storyInteractionInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyInteractionInfo");
    s.store_field("view_count", view_count_);
    s.store_field("forward_count", forward_count_);
    s.store_field("reaction_count", reaction_count_);
    { s.store_vector_begin("recent_viewer_user_ids", recent_viewer_user_ids_.size()); for (const auto &_value : recent_viewer_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

storyOriginPublicStory::storyOriginPublicStory()
  : chat_id_()
  , story_id_()
{}

storyOriginPublicStory::storyOriginPublicStory(int53 chat_id_, int32 story_id_)
  : chat_id_(chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t storyOriginPublicStory::ID;

void storyOriginPublicStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyOriginPublicStory");
    s.store_field("chat_id", chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

storyOriginHiddenUser::storyOriginHiddenUser()
  : poster_name_()
{}

storyOriginHiddenUser::storyOriginHiddenUser(string const &poster_name_)
  : poster_name_(poster_name_)
{}

const std::int32_t storyOriginHiddenUser::ID;

void storyOriginHiddenUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyOriginHiddenUser");
    s.store_field("poster_name", poster_name_);
    s.store_class_end();
  }
}

storyVideo::storyVideo()
  : duration_()
  , width_()
  , height_()
  , has_stickers_()
  , is_animation_()
  , minithumbnail_()
  , thumbnail_()
  , preload_prefix_size_()
  , cover_frame_timestamp_()
  , video_()
{}

storyVideo::storyVideo(double duration_, int32 width_, int32 height_, bool has_stickers_, bool is_animation_, object_ptr<minithumbnail> &&minithumbnail_, object_ptr<thumbnail> &&thumbnail_, int32 preload_prefix_size_, double cover_frame_timestamp_, object_ptr<file> &&video_)
  : duration_(duration_)
  , width_(width_)
  , height_(height_)
  , has_stickers_(has_stickers_)
  , is_animation_(is_animation_)
  , minithumbnail_(std::move(minithumbnail_))
  , thumbnail_(std::move(thumbnail_))
  , preload_prefix_size_(preload_prefix_size_)
  , cover_frame_timestamp_(cover_frame_timestamp_)
  , video_(std::move(video_))
{}

const std::int32_t storyVideo::ID;

void storyVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyVideo");
    s.store_field("duration", duration_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("has_stickers", has_stickers_);
    s.store_field("is_animation", is_animation_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_field("preload_prefix_size", preload_prefix_size_);
    s.store_field("cover_frame_timestamp", cover_frame_timestamp_);
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_class_end();
  }
}

suggestedActionEnableArchiveAndMuteNewChats::suggestedActionEnableArchiveAndMuteNewChats() {
}

const std::int32_t suggestedActionEnableArchiveAndMuteNewChats::ID;

void suggestedActionEnableArchiveAndMuteNewChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionEnableArchiveAndMuteNewChats");
    s.store_class_end();
  }
}

suggestedActionCheckPassword::suggestedActionCheckPassword() {
}

const std::int32_t suggestedActionCheckPassword::ID;

void suggestedActionCheckPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionCheckPassword");
    s.store_class_end();
  }
}

suggestedActionCheckPhoneNumber::suggestedActionCheckPhoneNumber() {
}

const std::int32_t suggestedActionCheckPhoneNumber::ID;

void suggestedActionCheckPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionCheckPhoneNumber");
    s.store_class_end();
  }
}

suggestedActionViewChecksHint::suggestedActionViewChecksHint() {
}

const std::int32_t suggestedActionViewChecksHint::ID;

void suggestedActionViewChecksHint::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionViewChecksHint");
    s.store_class_end();
  }
}

suggestedActionConvertToBroadcastGroup::suggestedActionConvertToBroadcastGroup()
  : supergroup_id_()
{}

suggestedActionConvertToBroadcastGroup::suggestedActionConvertToBroadcastGroup(int53 supergroup_id_)
  : supergroup_id_(supergroup_id_)
{}

const std::int32_t suggestedActionConvertToBroadcastGroup::ID;

void suggestedActionConvertToBroadcastGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionConvertToBroadcastGroup");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_class_end();
  }
}

suggestedActionSetPassword::suggestedActionSetPassword()
  : authorization_delay_()
{}

suggestedActionSetPassword::suggestedActionSetPassword(int32 authorization_delay_)
  : authorization_delay_(authorization_delay_)
{}

const std::int32_t suggestedActionSetPassword::ID;

void suggestedActionSetPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionSetPassword");
    s.store_field("authorization_delay", authorization_delay_);
    s.store_class_end();
  }
}

suggestedActionUpgradePremium::suggestedActionUpgradePremium() {
}

const std::int32_t suggestedActionUpgradePremium::ID;

void suggestedActionUpgradePremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionUpgradePremium");
    s.store_class_end();
  }
}

suggestedActionRestorePremium::suggestedActionRestorePremium() {
}

const std::int32_t suggestedActionRestorePremium::ID;

void suggestedActionRestorePremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionRestorePremium");
    s.store_class_end();
  }
}

suggestedActionSubscribeToAnnualPremium::suggestedActionSubscribeToAnnualPremium() {
}

const std::int32_t suggestedActionSubscribeToAnnualPremium::ID;

void suggestedActionSubscribeToAnnualPremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionSubscribeToAnnualPremium");
    s.store_class_end();
  }
}

suggestedActionGiftPremiumForChristmas::suggestedActionGiftPremiumForChristmas() {
}

const std::int32_t suggestedActionGiftPremiumForChristmas::ID;

void suggestedActionGiftPremiumForChristmas::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionGiftPremiumForChristmas");
    s.store_class_end();
  }
}

suggestedActionSetBirthdate::suggestedActionSetBirthdate() {
}

const std::int32_t suggestedActionSetBirthdate::ID;

void suggestedActionSetBirthdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionSetBirthdate");
    s.store_class_end();
  }
}

suggestedActionSetProfilePhoto::suggestedActionSetProfilePhoto() {
}

const std::int32_t suggestedActionSetProfilePhoto::ID;

void suggestedActionSetProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionSetProfilePhoto");
    s.store_class_end();
  }
}

suggestedActionExtendPremium::suggestedActionExtendPremium()
  : manage_premium_subscription_url_()
{}

suggestedActionExtendPremium::suggestedActionExtendPremium(string const &manage_premium_subscription_url_)
  : manage_premium_subscription_url_(manage_premium_subscription_url_)
{}

const std::int32_t suggestedActionExtendPremium::ID;

void suggestedActionExtendPremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionExtendPremium");
    s.store_field("manage_premium_subscription_url", manage_premium_subscription_url_);
    s.store_class_end();
  }
}

suggestedActionExtendStarSubscriptions::suggestedActionExtendStarSubscriptions() {
}

const std::int32_t suggestedActionExtendStarSubscriptions::ID;

void suggestedActionExtendStarSubscriptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionExtendStarSubscriptions");
    s.store_class_end();
  }
}

suggestedActionCustom::suggestedActionCustom()
  : name_()
  , title_()
  , description_()
  , url_()
{}

suggestedActionCustom::suggestedActionCustom(string const &name_, object_ptr<formattedText> &&title_, object_ptr<formattedText> &&description_, string const &url_)
  : name_(name_)
  , title_(std::move(title_))
  , description_(std::move(description_))
  , url_(url_)
{}

const std::int32_t suggestedActionCustom::ID;

void suggestedActionCustom::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionCustom");
    s.store_field("name", name_);
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    s.store_object_field("description", static_cast<const BaseObject *>(description_.get()));
    s.store_field("url", url_);
    s.store_class_end();
  }
}

suggestedActionSetLoginEmailAddress::suggestedActionSetLoginEmailAddress()
  : can_be_hidden_()
{}

suggestedActionSetLoginEmailAddress::suggestedActionSetLoginEmailAddress(bool can_be_hidden_)
  : can_be_hidden_(can_be_hidden_)
{}

const std::int32_t suggestedActionSetLoginEmailAddress::ID;

void suggestedActionSetLoginEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionSetLoginEmailAddress");
    s.store_field("can_be_hidden", can_be_hidden_);
    s.store_class_end();
  }
}

suggestedActionAddLoginPasskey::suggestedActionAddLoginPasskey() {
}

const std::int32_t suggestedActionAddLoginPasskey::ID;

void suggestedActionAddLoginPasskey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionAddLoginPasskey");
    s.store_class_end();
  }
}

targetChatCurrent::targetChatCurrent() {
}

const std::int32_t targetChatCurrent::ID;

void targetChatCurrent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "targetChatCurrent");
    s.store_class_end();
  }
}

targetChatChosen::targetChatChosen()
  : types_()
{}

targetChatChosen::targetChatChosen(object_ptr<targetChatTypes> &&types_)
  : types_(std::move(types_))
{}

const std::int32_t targetChatChosen::ID;

void targetChatChosen::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "targetChatChosen");
    s.store_object_field("types", static_cast<const BaseObject *>(types_.get()));
    s.store_class_end();
  }
}

targetChatInternalLink::targetChatInternalLink()
  : link_()
{}

targetChatInternalLink::targetChatInternalLink(object_ptr<InternalLinkType> &&link_)
  : link_(std::move(link_))
{}

const std::int32_t targetChatInternalLink::ID;

void targetChatInternalLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "targetChatInternalLink");
    s.store_object_field("link", static_cast<const BaseObject *>(link_.get()));
    s.store_class_end();
  }
}

tonRevenueStatistics::tonRevenueStatistics()
  : revenue_by_day_graph_()
  , status_()
  , usd_rate_()
{}

tonRevenueStatistics::tonRevenueStatistics(object_ptr<StatisticalGraph> &&revenue_by_day_graph_, object_ptr<tonRevenueStatus> &&status_, double usd_rate_)
  : revenue_by_day_graph_(std::move(revenue_by_day_graph_))
  , status_(std::move(status_))
  , usd_rate_(usd_rate_)
{}

const std::int32_t tonRevenueStatistics::ID;

void tonRevenueStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonRevenueStatistics");
    s.store_object_field("revenue_by_day_graph", static_cast<const BaseObject *>(revenue_by_day_graph_.get()));
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_field("usd_rate", usd_rate_);
    s.store_class_end();
  }
}

upgradedGiftOriginalDetails::upgradedGiftOriginalDetails()
  : sender_id_()
  , receiver_id_()
  , text_()
  , date_()
{}

upgradedGiftOriginalDetails::upgradedGiftOriginalDetails(object_ptr<MessageSender> &&sender_id_, object_ptr<MessageSender> &&receiver_id_, object_ptr<formattedText> &&text_, int32 date_)
  : sender_id_(std::move(sender_id_))
  , receiver_id_(std::move(receiver_id_))
  , text_(std::move(text_))
  , date_(date_)
{}

const std::int32_t upgradedGiftOriginalDetails::ID;

void upgradedGiftOriginalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftOriginalDetails");
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_object_field("receiver_id", static_cast<const BaseObject *>(receiver_id_.get()));
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("date", date_);
    s.store_class_end();
  }
}

user::user()
  : id_()
  , first_name_()
  , last_name_()
  , usernames_()
  , phone_number_()
  , status_()
  , profile_photo_()
  , accent_color_id_()
  , background_custom_emoji_id_()
  , upgraded_gift_colors_()
  , profile_accent_color_id_()
  , profile_background_custom_emoji_id_()
  , emoji_status_()
  , is_contact_()
  , is_mutual_contact_()
  , is_close_friend_()
  , verification_status_()
  , is_premium_()
  , is_support_()
  , restriction_info_()
  , active_story_state_()
  , restricts_new_chats_()
  , paid_message_star_count_()
  , have_access_()
  , type_()
  , language_code_()
  , added_to_attachment_menu_()
{}

user::user(int53 id_, string const &first_name_, string const &last_name_, object_ptr<usernames> &&usernames_, string const &phone_number_, object_ptr<UserStatus> &&status_, object_ptr<profilePhoto> &&profile_photo_, int32 accent_color_id_, int64 background_custom_emoji_id_, object_ptr<upgradedGiftColors> &&upgraded_gift_colors_, int32 profile_accent_color_id_, int64 profile_background_custom_emoji_id_, object_ptr<emojiStatus> &&emoji_status_, bool is_contact_, bool is_mutual_contact_, bool is_close_friend_, object_ptr<verificationStatus> &&verification_status_, bool is_premium_, bool is_support_, object_ptr<restrictionInfo> &&restriction_info_, object_ptr<ActiveStoryState> &&active_story_state_, bool restricts_new_chats_, int53 paid_message_star_count_, bool have_access_, object_ptr<UserType> &&type_, string const &language_code_, bool added_to_attachment_menu_)
  : id_(id_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , usernames_(std::move(usernames_))
  , phone_number_(phone_number_)
  , status_(std::move(status_))
  , profile_photo_(std::move(profile_photo_))
  , accent_color_id_(accent_color_id_)
  , background_custom_emoji_id_(background_custom_emoji_id_)
  , upgraded_gift_colors_(std::move(upgraded_gift_colors_))
  , profile_accent_color_id_(profile_accent_color_id_)
  , profile_background_custom_emoji_id_(profile_background_custom_emoji_id_)
  , emoji_status_(std::move(emoji_status_))
  , is_contact_(is_contact_)
  , is_mutual_contact_(is_mutual_contact_)
  , is_close_friend_(is_close_friend_)
  , verification_status_(std::move(verification_status_))
  , is_premium_(is_premium_)
  , is_support_(is_support_)
  , restriction_info_(std::move(restriction_info_))
  , active_story_state_(std::move(active_story_state_))
  , restricts_new_chats_(restricts_new_chats_)
  , paid_message_star_count_(paid_message_star_count_)
  , have_access_(have_access_)
  , type_(std::move(type_))
  , language_code_(language_code_)
  , added_to_attachment_menu_(added_to_attachment_menu_)
{}

const std::int32_t user::ID;

void user::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "user");
    s.store_field("id", id_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_object_field("usernames", static_cast<const BaseObject *>(usernames_.get()));
    s.store_field("phone_number", phone_number_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_object_field("profile_photo", static_cast<const BaseObject *>(profile_photo_.get()));
    s.store_field("accent_color_id", accent_color_id_);
    s.store_field("background_custom_emoji_id", background_custom_emoji_id_);
    s.store_object_field("upgraded_gift_colors", static_cast<const BaseObject *>(upgraded_gift_colors_.get()));
    s.store_field("profile_accent_color_id", profile_accent_color_id_);
    s.store_field("profile_background_custom_emoji_id", profile_background_custom_emoji_id_);
    s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get()));
    s.store_field("is_contact", is_contact_);
    s.store_field("is_mutual_contact", is_mutual_contact_);
    s.store_field("is_close_friend", is_close_friend_);
    s.store_object_field("verification_status", static_cast<const BaseObject *>(verification_status_.get()));
    s.store_field("is_premium", is_premium_);
    s.store_field("is_support", is_support_);
    s.store_object_field("restriction_info", static_cast<const BaseObject *>(restriction_info_.get()));
    s.store_object_field("active_story_state", static_cast<const BaseObject *>(active_story_state_.get()));
    s.store_field("restricts_new_chats", restricts_new_chats_);
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_field("have_access", have_access_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("language_code", language_code_);
    s.store_field("added_to_attachment_menu", added_to_attachment_menu_);
    s.store_class_end();
  }
}

users::users()
  : total_count_()
  , user_ids_()
{}

users::users(int32 total_count_, array<int53> &&user_ids_)
  : total_count_(total_count_)
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t users::ID;

void users::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

webPageInstantView::webPageInstantView()
  : page_blocks_()
  , view_count_()
  , version_()
  , is_rtl_()
  , is_full_()
  , feedback_link_()
{}

webPageInstantView::webPageInstantView(array<object_ptr<PageBlock>> &&page_blocks_, int32 view_count_, int32 version_, bool is_rtl_, bool is_full_, object_ptr<InternalLinkType> &&feedback_link_)
  : page_blocks_(std::move(page_blocks_))
  , view_count_(view_count_)
  , version_(version_)
  , is_rtl_(is_rtl_)
  , is_full_(is_full_)
  , feedback_link_(std::move(feedback_link_))
{}

const std::int32_t webPageInstantView::ID;

void webPageInstantView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPageInstantView");
    { s.store_vector_begin("page_blocks", page_blocks_.size()); for (const auto &_value : page_blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("view_count", view_count_);
    s.store_field("version", version_);
    s.store_field("is_rtl", is_rtl_);
    s.store_field("is_full", is_full_);
    s.store_object_field("feedback_link", static_cast<const BaseObject *>(feedback_link_.get()));
    s.store_class_end();
  }
}

addFavoriteSticker::addFavoriteSticker()
  : sticker_()
{}

addFavoriteSticker::addFavoriteSticker(object_ptr<InputFile> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t addFavoriteSticker::ID;

void addFavoriteSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addFavoriteSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

addRecentlyFoundChat::addRecentlyFoundChat()
  : chat_id_()
{}

addRecentlyFoundChat::addRecentlyFoundChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t addRecentlyFoundChat::ID;

void addRecentlyFoundChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addRecentlyFoundChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

addStoryAlbumStories::addStoryAlbumStories()
  : chat_id_()
  , story_album_id_()
  , story_ids_()
{}

addStoryAlbumStories::addStoryAlbumStories(int53 chat_id_, int32 story_album_id_, array<int32> &&story_ids_)
  : chat_id_(chat_id_)
  , story_album_id_(story_album_id_)
  , story_ids_(std::move(story_ids_))
{}

const std::int32_t addStoryAlbumStories::ID;

void addStoryAlbumStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addStoryAlbumStories");
    s.store_field("chat_id", chat_id_);
    s.store_field("story_album_id", story_album_id_);
    { s.store_vector_begin("story_ids", story_ids_.size()); for (const auto &_value : story_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

answerWebAppQuery::answerWebAppQuery()
  : web_app_query_id_()
  , result_()
{}

answerWebAppQuery::answerWebAppQuery(string const &web_app_query_id_, object_ptr<InputInlineQueryResult> &&result_)
  : web_app_query_id_(web_app_query_id_)
  , result_(std::move(result_))
{}

const std::int32_t answerWebAppQuery::ID;

void answerWebAppQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerWebAppQuery");
    s.store_field("web_app_query_id", web_app_query_id_);
    s.store_object_field("result", static_cast<const BaseObject *>(result_.get()));
    s.store_class_end();
  }
}

banChatMember::banChatMember()
  : chat_id_()
  , member_id_()
  , banned_until_date_()
  , revoke_messages_()
{}

banChatMember::banChatMember(int53 chat_id_, object_ptr<MessageSender> &&member_id_, int32 banned_until_date_, bool revoke_messages_)
  : chat_id_(chat_id_)
  , member_id_(std::move(member_id_))
  , banned_until_date_(banned_until_date_)
  , revoke_messages_(revoke_messages_)
{}

const std::int32_t banChatMember::ID;

void banChatMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "banChatMember");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("member_id", static_cast<const BaseObject *>(member_id_.get()));
    s.store_field("banned_until_date", banned_until_date_);
    s.store_field("revoke_messages", revoke_messages_);
    s.store_class_end();
  }
}

canBotSendMessages::canBotSendMessages()
  : bot_user_id_()
{}

canBotSendMessages::canBotSendMessages(int53 bot_user_id_)
  : bot_user_id_(bot_user_id_)
{}

const std::int32_t canBotSendMessages::ID;

void canBotSendMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canBotSendMessages");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

changeStickerSet::changeStickerSet()
  : set_id_()
  , is_installed_()
  , is_archived_()
{}

changeStickerSet::changeStickerSet(int64 set_id_, bool is_installed_, bool is_archived_)
  : set_id_(set_id_)
  , is_installed_(is_installed_)
  , is_archived_(is_archived_)
{}

const std::int32_t changeStickerSet::ID;

void changeStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "changeStickerSet");
    s.store_field("set_id", set_id_);
    s.store_field("is_installed", is_installed_);
    s.store_field("is_archived", is_archived_);
    s.store_class_end();
  }
}

checkChatFolderInviteLink::checkChatFolderInviteLink()
  : invite_link_()
{}

checkChatFolderInviteLink::checkChatFolderInviteLink(string const &invite_link_)
  : invite_link_(invite_link_)
{}

const std::int32_t checkChatFolderInviteLink::ID;

void checkChatFolderInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatFolderInviteLink");
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

checkEmailAddressVerificationCode::checkEmailAddressVerificationCode()
  : code_()
{}

checkEmailAddressVerificationCode::checkEmailAddressVerificationCode(string const &code_)
  : code_(code_)
{}

const std::int32_t checkEmailAddressVerificationCode::ID;

void checkEmailAddressVerificationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkEmailAddressVerificationCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

checkQuickReplyShortcutName::checkQuickReplyShortcutName()
  : name_()
{}

checkQuickReplyShortcutName::checkQuickReplyShortcutName(string const &name_)
  : name_(name_)
{}

const std::int32_t checkQuickReplyShortcutName::ID;

void checkQuickReplyShortcutName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkQuickReplyShortcutName");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

createChatInviteLink::createChatInviteLink()
  : chat_id_()
  , name_()
  , expiration_date_()
  , member_limit_()
  , creates_join_request_()
{}

createChatInviteLink::createChatInviteLink(int53 chat_id_, string const &name_, int32 expiration_date_, int32 member_limit_, bool creates_join_request_)
  : chat_id_(chat_id_)
  , name_(name_)
  , expiration_date_(expiration_date_)
  , member_limit_(member_limit_)
  , creates_join_request_(creates_join_request_)
{}

const std::int32_t createChatInviteLink::ID;

void createChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createChatInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("name", name_);
    s.store_field("expiration_date", expiration_date_);
    s.store_field("member_limit", member_limit_);
    s.store_field("creates_join_request", creates_join_request_);
    s.store_class_end();
  }
}

createPrivateChat::createPrivateChat()
  : user_id_()
  , force_()
{}

createPrivateChat::createPrivateChat(int53 user_id_, bool force_)
  : user_id_(user_id_)
  , force_(force_)
{}

const std::int32_t createPrivateChat::ID;

void createPrivateChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createPrivateChat");
    s.store_field("user_id", user_id_);
    s.store_field("force", force_);
    s.store_class_end();
  }
}

deleteBusinessChatLink::deleteBusinessChatLink()
  : link_()
{}

deleteBusinessChatLink::deleteBusinessChatLink(string const &link_)
  : link_(link_)
{}

const std::int32_t deleteBusinessChatLink::ID;

void deleteBusinessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteBusinessChatLink");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

deleteGroupCallMessages::deleteGroupCallMessages()
  : group_call_id_()
  , message_ids_()
  , report_spam_()
{}

deleteGroupCallMessages::deleteGroupCallMessages(int32 group_call_id_, array<int32> &&message_ids_, bool report_spam_)
  : group_call_id_(group_call_id_)
  , message_ids_(std::move(message_ids_))
  , report_spam_(report_spam_)
{}

const std::int32_t deleteGroupCallMessages::ID;

void deleteGroupCallMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteGroupCallMessages");
    s.store_field("group_call_id", group_call_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("report_spam", report_spam_);
    s.store_class_end();
  }
}

deletePassportElement::deletePassportElement()
  : type_()
{}

deletePassportElement::deletePassportElement(object_ptr<PassportElementType> &&type_)
  : type_(std::move(type_))
{}

const std::int32_t deletePassportElement::ID;

void deletePassportElement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deletePassportElement");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

deletePollOption::deletePollOption()
  : chat_id_()
  , message_id_()
  , option_id_()
{}

deletePollOption::deletePollOption(int53 chat_id_, int53 message_id_, string const &option_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , option_id_(option_id_)
{}

const std::int32_t deletePollOption::ID;

void deletePollOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deletePollOption");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("option_id", option_id_);
    s.store_class_end();
  }
}

deleteQuickReplyShortcutMessages::deleteQuickReplyShortcutMessages()
  : shortcut_id_()
  , message_ids_()
{}

deleteQuickReplyShortcutMessages::deleteQuickReplyShortcutMessages(int32 shortcut_id_, array<int53> &&message_ids_)
  : shortcut_id_(shortcut_id_)
  , message_ids_(std::move(message_ids_))
{}

const std::int32_t deleteQuickReplyShortcutMessages::ID;

void deleteQuickReplyShortcutMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteQuickReplyShortcutMessages");
    s.store_field("shortcut_id", shortcut_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

editCustomLanguagePackInfo::editCustomLanguagePackInfo()
  : info_()
{}

editCustomLanguagePackInfo::editCustomLanguagePackInfo(object_ptr<languagePackInfo> &&info_)
  : info_(std::move(info_))
{}

const std::int32_t editCustomLanguagePackInfo::ID;

void editCustomLanguagePackInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editCustomLanguagePackInfo");
    s.store_object_field("info", static_cast<const BaseObject *>(info_.get()));
    s.store_class_end();
  }
}

editInlineMessageCaption::editInlineMessageCaption()
  : inline_message_id_()
  , reply_markup_()
  , caption_()
  , show_caption_above_media_()
{}

editInlineMessageCaption::editInlineMessageCaption(string const &inline_message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_)
  : inline_message_id_(inline_message_id_)
  , reply_markup_(std::move(reply_markup_))
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
{}

const std::int32_t editInlineMessageCaption::ID;

void editInlineMessageCaption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editInlineMessageCaption");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_class_end();
  }
}

editInlineMessageLiveLocation::editInlineMessageLiveLocation()
  : inline_message_id_()
  , reply_markup_()
  , location_()
  , live_period_()
  , heading_()
  , proximity_alert_radius_()
{}

editInlineMessageLiveLocation::editInlineMessageLiveLocation(string const &inline_message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<location> &&location_, int32 live_period_, int32 heading_, int32 proximity_alert_radius_)
  : inline_message_id_(inline_message_id_)
  , reply_markup_(std::move(reply_markup_))
  , location_(std::move(location_))
  , live_period_(live_period_)
  , heading_(heading_)
  , proximity_alert_radius_(proximity_alert_radius_)
{}

const std::int32_t editInlineMessageLiveLocation::ID;

void editInlineMessageLiveLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editInlineMessageLiveLocation");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("live_period", live_period_);
    s.store_field("heading", heading_);
    s.store_field("proximity_alert_radius", proximity_alert_radius_);
    s.store_class_end();
  }
}

endGroupCallScreenSharing::endGroupCallScreenSharing()
  : group_call_id_()
{}

endGroupCallScreenSharing::endGroupCallScreenSharing(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t endGroupCallScreenSharing::ID;

void endGroupCallScreenSharing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "endGroupCallScreenSharing");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

forwardMessages::forwardMessages()
  : chat_id_()
  , topic_id_()
  , from_chat_id_()
  , message_ids_()
  , options_()
  , send_copy_()
  , remove_caption_()
{}

forwardMessages::forwardMessages(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, int53 from_chat_id_, array<int53> &&message_ids_, object_ptr<messageSendOptions> &&options_, bool send_copy_, bool remove_caption_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , from_chat_id_(from_chat_id_)
  , message_ids_(std::move(message_ids_))
  , options_(std::move(options_))
  , send_copy_(send_copy_)
  , remove_caption_(remove_caption_)
{}

const std::int32_t forwardMessages::ID;

void forwardMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "forwardMessages");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_field("from_chat_id", from_chat_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_object_field("options", static_cast<const BaseObject *>(options_.get()));
    s.store_field("send_copy", send_copy_);
    s.store_field("remove_caption", remove_caption_);
    s.store_class_end();
  }
}

getAttachedStickerSets::getAttachedStickerSets()
  : file_id_()
{}

getAttachedStickerSets::getAttachedStickerSets(int32 file_id_)
  : file_id_(file_id_)
{}

const std::int32_t getAttachedStickerSets::ID;

void getAttachedStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAttachedStickerSets");
    s.store_field("file_id", file_id_);
    s.store_class_end();
  }
}

getAvailableGifts::getAvailableGifts() {
}

const std::int32_t getAvailableGifts::ID;

void getAvailableGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAvailableGifts");
    s.store_class_end();
  }
}

getBotInfoDescription::getBotInfoDescription()
  : bot_user_id_()
  , language_code_()
{}

getBotInfoDescription::getBotInfoDescription(int53 bot_user_id_, string const &language_code_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
{}

const std::int32_t getBotInfoDescription::ID;

void getBotInfoDescription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBotInfoDescription");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    s.store_class_end();
  }
}

getBusinessChatLinkInfo::getBusinessChatLinkInfo()
  : link_name_()
{}

getBusinessChatLinkInfo::getBusinessChatLinkInfo(string const &link_name_)
  : link_name_(link_name_)
{}

const std::int32_t getBusinessChatLinkInfo::ID;

void getBusinessChatLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBusinessChatLinkInfo");
    s.store_field("link_name", link_name_);
    s.store_class_end();
  }
}

getChatAvailablePaidMessageReactionSenders::getChatAvailablePaidMessageReactionSenders()
  : chat_id_()
{}

getChatAvailablePaidMessageReactionSenders::getChatAvailablePaidMessageReactionSenders(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatAvailablePaidMessageReactionSenders::ID;

void getChatAvailablePaidMessageReactionSenders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatAvailablePaidMessageReactionSenders");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatBoostFeatures::getChatBoostFeatures()
  : is_channel_()
{}

getChatBoostFeatures::getChatBoostFeatures(bool is_channel_)
  : is_channel_(is_channel_)
{}

const std::int32_t getChatBoostFeatures::ID;

void getChatBoostFeatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatBoostFeatures");
    s.store_field("is_channel", is_channel_);
    s.store_class_end();
  }
}

getChatBoostLevelFeatures::getChatBoostLevelFeatures()
  : is_channel_()
  , level_()
{}

getChatBoostLevelFeatures::getChatBoostLevelFeatures(bool is_channel_, int32 level_)
  : is_channel_(is_channel_)
  , level_(level_)
{}

const std::int32_t getChatBoostLevelFeatures::ID;

void getChatBoostLevelFeatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatBoostLevelFeatures");
    s.store_field("is_channel", is_channel_);
    s.store_field("level", level_);
    s.store_class_end();
  }
}

getChatHistory::getChatHistory()
  : chat_id_()
  , from_message_id_()
  , offset_()
  , limit_()
  , only_local_()
{}

getChatHistory::getChatHistory(int53 chat_id_, int53 from_message_id_, int32 offset_, int32 limit_, bool only_local_)
  : chat_id_(chat_id_)
  , from_message_id_(from_message_id_)
  , offset_(offset_)
  , limit_(limit_)
  , only_local_(only_local_)
{}

const std::int32_t getChatHistory::ID;

void getChatHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatHistory");
    s.store_field("chat_id", chat_id_);
    s.store_field("from_message_id", from_message_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("only_local", only_local_);
    s.store_class_end();
  }
}

getChatJoinRequests::getChatJoinRequests()
  : chat_id_()
  , invite_link_()
  , query_()
  , offset_request_()
  , limit_()
{}

getChatJoinRequests::getChatJoinRequests(int53 chat_id_, string const &invite_link_, string const &query_, object_ptr<chatJoinRequest> &&offset_request_, int32 limit_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
  , query_(query_)
  , offset_request_(std::move(offset_request_))
  , limit_(limit_)
{}

const std::int32_t getChatJoinRequests::ID;

void getChatJoinRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatJoinRequests");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_field("query", query_);
    s.store_object_field("offset_request", static_cast<const BaseObject *>(offset_request_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getChatMember::getChatMember()
  : chat_id_()
  , member_id_()
{}

getChatMember::getChatMember(int53 chat_id_, object_ptr<MessageSender> &&member_id_)
  : chat_id_(chat_id_)
  , member_id_(std::move(member_id_))
{}

const std::int32_t getChatMember::ID;

void getChatMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatMember");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("member_id", static_cast<const BaseObject *>(member_id_.get()));
    s.store_class_end();
  }
}

getChatMessagePosition::getChatMessagePosition()
  : chat_id_()
  , topic_id_()
  , filter_()
  , message_id_()
{}

getChatMessagePosition::getChatMessagePosition(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, object_ptr<SearchMessagesFilter> &&filter_, int53 message_id_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , filter_(std::move(filter_))
  , message_id_(message_id_)
{}

const std::int32_t getChatMessagePosition::ID;

void getChatMessagePosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatMessagePosition");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getChatRevenueStatistics::getChatRevenueStatistics()
  : chat_id_()
  , is_dark_()
{}

getChatRevenueStatistics::getChatRevenueStatistics(int53 chat_id_, bool is_dark_)
  : chat_id_(chat_id_)
  , is_dark_(is_dark_)
{}

const std::int32_t getChatRevenueStatistics::ID;

void getChatRevenueStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatRevenueStatistics");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_dark", is_dark_);
    s.store_class_end();
  }
}

getChatRevenueTransactions::getChatRevenueTransactions()
  : chat_id_()
  , offset_()
  , limit_()
{}

getChatRevenueTransactions::getChatRevenueTransactions(int53 chat_id_, string const &offset_, int32 limit_)
  : chat_id_(chat_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getChatRevenueTransactions::ID;

void getChatRevenueTransactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatRevenueTransactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getChatScheduledMessages::getChatScheduledMessages()
  : chat_id_()
{}

getChatScheduledMessages::getChatScheduledMessages(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatScheduledMessages::ID;

void getChatScheduledMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatScheduledMessages");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getConnectedWebsites::getConnectedWebsites() {
}

const std::int32_t getConnectedWebsites::ID;

void getConnectedWebsites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getConnectedWebsites");
    s.store_class_end();
  }
}

getCurrentWeather::getCurrentWeather()
  : location_()
{}

getCurrentWeather::getCurrentWeather(object_ptr<location> &&location_)
  : location_(std::move(location_))
{}

const std::int32_t getCurrentWeather::ID;

void getCurrentWeather::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCurrentWeather");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_class_end();
  }
}

getDeepLinkInfo::getDeepLinkInfo()
  : link_()
{}

getDeepLinkInfo::getDeepLinkInfo(string const &link_)
  : link_(link_)
{}

const std::int32_t getDeepLinkInfo::ID;

void getDeepLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDeepLinkInfo");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

getEmojiCategories::getEmojiCategories()
  : type_()
{}

getEmojiCategories::getEmojiCategories(object_ptr<EmojiCategoryType> &&type_)
  : type_(std::move(type_))
{}

const std::int32_t getEmojiCategories::ID;

void getEmojiCategories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getEmojiCategories");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

getEmojiReaction::getEmojiReaction()
  : emoji_()
{}

getEmojiReaction::getEmojiReaction(string const &emoji_)
  : emoji_(emoji_)
{}

const std::int32_t getEmojiReaction::ID;

void getEmojiReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getEmojiReaction");
    s.store_field("emoji", emoji_);
    s.store_class_end();
  }
}

getForumTopicLink::getForumTopicLink()
  : chat_id_()
  , forum_topic_id_()
{}

getForumTopicLink::getForumTopicLink(int53 chat_id_, int32 forum_topic_id_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
{}

const std::int32_t getForumTopicLink::ID;

void getForumTopicLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getForumTopicLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_class_end();
  }
}

getGiftCollections::getGiftCollections()
  : owner_id_()
{}

getGiftCollections::getGiftCollections(object_ptr<MessageSender> &&owner_id_)
  : owner_id_(std::move(owner_id_))
{}

const std::int32_t getGiftCollections::ID;

void getGiftCollections::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGiftCollections");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_class_end();
  }
}

getGroupCallStreamSegment::getGroupCallStreamSegment()
  : group_call_id_()
  , time_offset_()
  , scale_()
  , channel_id_()
  , video_quality_()
{}

getGroupCallStreamSegment::getGroupCallStreamSegment(int32 group_call_id_, int53 time_offset_, int32 scale_, int32 channel_id_, object_ptr<GroupCallVideoQuality> &&video_quality_)
  : group_call_id_(group_call_id_)
  , time_offset_(time_offset_)
  , scale_(scale_)
  , channel_id_(channel_id_)
  , video_quality_(std::move(video_quality_))
{}

const std::int32_t getGroupCallStreamSegment::ID;

void getGroupCallStreamSegment::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGroupCallStreamSegment");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("time_offset", time_offset_);
    s.store_field("scale", scale_);
    s.store_field("channel_id", channel_id_);
    s.store_object_field("video_quality", static_cast<const BaseObject *>(video_quality_.get()));
    s.store_class_end();
  }
}

getLanguagePackInfo::getLanguagePackInfo()
  : language_pack_id_()
{}

getLanguagePackInfo::getLanguagePackInfo(string const &language_pack_id_)
  : language_pack_id_(language_pack_id_)
{}

const std::int32_t getLanguagePackInfo::ID;

void getLanguagePackInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLanguagePackInfo");
    s.store_field("language_pack_id", language_pack_id_);
    s.store_class_end();
  }
}

getLiveStoryTopDonors::getLiveStoryTopDonors()
  : group_call_id_()
{}

getLiveStoryTopDonors::getLiveStoryTopDonors(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t getLiveStoryTopDonors::ID;

void getLiveStoryTopDonors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLiveStoryTopDonors");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

getLogStream::getLogStream() {
}

const std::int32_t getLogStream::ID;

void getLogStream::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLogStream");
    s.store_class_end();
  }
}

getLogTags::getLogTags() {
}

const std::int32_t getLogTags::ID;

void getLogTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLogTags");
    s.store_class_end();
  }
}

getLoginUrlInfo::getLoginUrlInfo()
  : chat_id_()
  , message_id_()
  , button_id_()
{}

getLoginUrlInfo::getLoginUrlInfo(int53 chat_id_, int53 message_id_, int53 button_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , button_id_(button_id_)
{}

const std::int32_t getLoginUrlInfo::ID;

void getLoginUrlInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLoginUrlInfo");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("button_id", button_id_);
    s.store_class_end();
  }
}

getMessagePublicForwards::getMessagePublicForwards()
  : chat_id_()
  , message_id_()
  , offset_()
  , limit_()
{}

getMessagePublicForwards::getMessagePublicForwards(int53 chat_id_, int53 message_id_, string const &offset_, int32 limit_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getMessagePublicForwards::ID;

void getMessagePublicForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessagePublicForwards");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getMessageThreadHistory::getMessageThreadHistory()
  : chat_id_()
  , message_id_()
  , from_message_id_()
  , offset_()
  , limit_()
{}

getMessageThreadHistory::getMessageThreadHistory(int53 chat_id_, int53 message_id_, int53 from_message_id_, int32 offset_, int32 limit_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , from_message_id_(from_message_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getMessageThreadHistory::ID;

void getMessageThreadHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageThreadHistory");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("from_message_id", from_message_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getPassportElement::getPassportElement()
  : type_()
  , password_()
{}

getPassportElement::getPassportElement(object_ptr<PassportElementType> &&type_, string const &password_)
  : type_(std::move(type_))
  , password_(password_)
{}

const std::int32_t getPassportElement::ID;

void getPassportElement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPassportElement");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("password", password_);
    s.store_class_end();
  }
}

getPaymentReceipt::getPaymentReceipt()
  : chat_id_()
  , message_id_()
{}

getPaymentReceipt::getPaymentReceipt(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getPaymentReceipt::ID;

void getPaymentReceipt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPaymentReceipt");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getPremiumFeatures::getPremiumFeatures()
  : source_()
{}

getPremiumFeatures::getPremiumFeatures(object_ptr<PremiumSource> &&source_)
  : source_(std::move(source_))
{}

const std::int32_t getPremiumFeatures::ID;

void getPremiumFeatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPremiumFeatures");
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_class_end();
  }
}

getRecentlyOpenedChats::getRecentlyOpenedChats()
  : limit_()
{}

getRecentlyOpenedChats::getRecentlyOpenedChats(int32 limit_)
  : limit_(limit_)
{}

const std::int32_t getRecentlyOpenedChats::ID;

void getRecentlyOpenedChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecentlyOpenedChats");
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getSavedMessagesTags::getSavedMessagesTags()
  : saved_messages_topic_id_()
{}

getSavedMessagesTags::getSavedMessagesTags(int53 saved_messages_topic_id_)
  : saved_messages_topic_id_(saved_messages_topic_id_)
{}

const std::int32_t getSavedMessagesTags::ID;

void getSavedMessagesTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSavedMessagesTags");
    s.store_field("saved_messages_topic_id", saved_messages_topic_id_);
    s.store_class_end();
  }
}

getStarAdAccountUrl::getStarAdAccountUrl()
  : owner_id_()
{}

getStarAdAccountUrl::getStarAdAccountUrl(object_ptr<MessageSender> &&owner_id_)
  : owner_id_(std::move(owner_id_))
{}

const std::int32_t getStarAdAccountUrl::ID;

void getStarAdAccountUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStarAdAccountUrl");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_class_end();
  }
}

getStarTransactions::getStarTransactions()
  : owner_id_()
  , subscription_id_()
  , direction_()
  , offset_()
  , limit_()
{}

getStarTransactions::getStarTransactions(object_ptr<MessageSender> &&owner_id_, string const &subscription_id_, object_ptr<TransactionDirection> &&direction_, string const &offset_, int32 limit_)
  : owner_id_(std::move(owner_id_))
  , subscription_id_(subscription_id_)
  , direction_(std::move(direction_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getStarTransactions::ID;

void getStarTransactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStarTransactions");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("subscription_id", subscription_id_);
    s.store_object_field("direction", static_cast<const BaseObject *>(direction_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getStarWithdrawalUrl::getStarWithdrawalUrl()
  : owner_id_()
  , star_count_()
  , password_()
{}

getStarWithdrawalUrl::getStarWithdrawalUrl(object_ptr<MessageSender> &&owner_id_, int53 star_count_, string const &password_)
  : owner_id_(std::move(owner_id_))
  , star_count_(star_count_)
  , password_(password_)
{}

const std::int32_t getStarWithdrawalUrl::ID;

void getStarWithdrawalUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStarWithdrawalUrl");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("star_count", star_count_);
    s.store_field("password", password_);
    s.store_class_end();
  }
}

getStickerEmojis::getStickerEmojis()
  : sticker_()
{}

getStickerEmojis::getStickerEmojis(object_ptr<InputFile> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t getStickerEmojis::ID;

void getStickerEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStickerEmojis");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

getStickerSet::getStickerSet()
  : set_id_()
{}

getStickerSet::getStickerSet(int64 set_id_)
  : set_id_(set_id_)
{}

const std::int32_t getStickerSet::ID;

void getStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStickerSet");
    s.store_field("set_id", set_id_);
    s.store_class_end();
  }
}

getUpgradedGift::getUpgradedGift()
  : name_()
{}

getUpgradedGift::getUpgradedGift(string const &name_)
  : name_(name_)
{}

const std::int32_t getUpgradedGift::ID;

void getUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUpgradedGift");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

getUpgradedGiftVariants::getUpgradedGiftVariants()
  : regular_gift_id_()
  , return_upgrade_models_()
  , return_craft_models_()
{}

getUpgradedGiftVariants::getUpgradedGiftVariants(int64 regular_gift_id_, bool return_upgrade_models_, bool return_craft_models_)
  : regular_gift_id_(regular_gift_id_)
  , return_upgrade_models_(return_upgrade_models_)
  , return_craft_models_(return_craft_models_)
{}

const std::int32_t getUpgradedGiftVariants::ID;

void getUpgradedGiftVariants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUpgradedGiftVariants");
    s.store_field("regular_gift_id", regular_gift_id_);
    s.store_field("return_upgrade_models", return_upgrade_models_);
    s.store_field("return_craft_models", return_craft_models_);
    s.store_class_end();
  }
}

inviteVideoChatParticipants::inviteVideoChatParticipants()
  : group_call_id_()
  , user_ids_()
{}

inviteVideoChatParticipants::inviteVideoChatParticipants(int32 group_call_id_, array<int53> &&user_ids_)
  : group_call_id_(group_call_id_)
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t inviteVideoChatParticipants::ID;

void inviteVideoChatParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inviteVideoChatParticipants");
    s.store_field("group_call_id", group_call_id_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

listenToAudio::listenToAudio()
  : audio_file_id_()
  , duration_()
{}

listenToAudio::listenToAudio(int32 audio_file_id_, int32 duration_)
  : audio_file_id_(audio_file_id_)
  , duration_(duration_)
{}

const std::int32_t listenToAudio::ID;

void listenToAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "listenToAudio");
    s.store_field("audio_file_id", audio_file_id_);
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

optimizeStorage::optimizeStorage()
  : size_()
  , ttl_()
  , count_()
  , immunity_delay_()
  , file_types_()
  , chat_ids_()
  , exclude_chat_ids_()
  , return_deleted_file_statistics_()
  , chat_limit_()
{}

optimizeStorage::optimizeStorage(int53 size_, int32 ttl_, int32 count_, int32 immunity_delay_, array<object_ptr<FileType>> &&file_types_, array<int53> &&chat_ids_, array<int53> &&exclude_chat_ids_, bool return_deleted_file_statistics_, int32 chat_limit_)
  : size_(size_)
  , ttl_(ttl_)
  , count_(count_)
  , immunity_delay_(immunity_delay_)
  , file_types_(std::move(file_types_))
  , chat_ids_(std::move(chat_ids_))
  , exclude_chat_ids_(std::move(exclude_chat_ids_))
  , return_deleted_file_statistics_(return_deleted_file_statistics_)
  , chat_limit_(chat_limit_)
{}

const std::int32_t optimizeStorage::ID;

void optimizeStorage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "optimizeStorage");
    s.store_field("size", size_);
    s.store_field("ttl", ttl_);
    s.store_field("count", count_);
    s.store_field("immunity_delay", immunity_delay_);
    { s.store_vector_begin("file_types", file_types_.size()); for (const auto &_value : file_types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("exclude_chat_ids", exclude_chat_ids_.size()); for (const auto &_value : exclude_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("return_deleted_file_statistics", return_deleted_file_statistics_);
    s.store_field("chat_limit", chat_limit_);
    s.store_class_end();
  }
}

pingProxy::pingProxy()
  : proxy_()
{}

pingProxy::pingProxy(object_ptr<proxy> &&proxy_)
  : proxy_(std::move(proxy_))
{}

const std::int32_t pingProxy::ID;

void pingProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pingProxy");
    s.store_object_field("proxy", static_cast<const BaseObject *>(proxy_.get()));
    s.store_class_end();
  }
}

postStory::postStory()
  : chat_id_()
  , content_()
  , areas_()
  , caption_()
  , privacy_settings_()
  , album_ids_()
  , active_period_()
  , from_story_full_id_()
  , is_posted_to_chat_page_()
  , protect_content_()
{}

postStory::postStory(int53 chat_id_, object_ptr<InputStoryContent> &&content_, object_ptr<inputStoryAreas> &&areas_, object_ptr<formattedText> &&caption_, object_ptr<StoryPrivacySettings> &&privacy_settings_, array<int32> &&album_ids_, int32 active_period_, object_ptr<storyFullId> &&from_story_full_id_, bool is_posted_to_chat_page_, bool protect_content_)
  : chat_id_(chat_id_)
  , content_(std::move(content_))
  , areas_(std::move(areas_))
  , caption_(std::move(caption_))
  , privacy_settings_(std::move(privacy_settings_))
  , album_ids_(std::move(album_ids_))
  , active_period_(active_period_)
  , from_story_full_id_(std::move(from_story_full_id_))
  , is_posted_to_chat_page_(is_posted_to_chat_page_)
  , protect_content_(protect_content_)
{}

const std::int32_t postStory::ID;

void postStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "postStory");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_object_field("areas", static_cast<const BaseObject *>(areas_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_object_field("privacy_settings", static_cast<const BaseObject *>(privacy_settings_.get()));
    { s.store_vector_begin("album_ids", album_ids_.size()); for (const auto &_value : album_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("active_period", active_period_);
    s.store_object_field("from_story_full_id", static_cast<const BaseObject *>(from_story_full_id_.get()));
    s.store_field("is_posted_to_chat_page", is_posted_to_chat_page_);
    s.store_field("protect_content", protect_content_);
    s.store_class_end();
  }
}

processChatJoinRequest::processChatJoinRequest()
  : chat_id_()
  , user_id_()
  , approve_()
{}

processChatJoinRequest::processChatJoinRequest(int53 chat_id_, int53 user_id_, bool approve_)
  : chat_id_(chat_id_)
  , user_id_(user_id_)
  , approve_(approve_)
{}

const std::int32_t processChatJoinRequest::ID;

void processChatJoinRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "processChatJoinRequest");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_field("approve", approve_);
    s.store_class_end();
  }
}

readAllForumTopicReactions::readAllForumTopicReactions()
  : chat_id_()
  , forum_topic_id_()
{}

readAllForumTopicReactions::readAllForumTopicReactions(int53 chat_id_, int32 forum_topic_id_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
{}

const std::int32_t readAllForumTopicReactions::ID;

void readAllForumTopicReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readAllForumTopicReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_class_end();
  }
}

readChatList::readChatList()
  : chat_list_()
{}

readChatList::readChatList(object_ptr<ChatList> &&chat_list_)
  : chat_list_(std::move(chat_list_))
{}

const std::int32_t readChatList::ID;

void readChatList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readChatList");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_class_end();
  }
}

recognizeSpeech::recognizeSpeech()
  : chat_id_()
  , message_id_()
{}

recognizeSpeech::recognizeSpeech(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t recognizeSpeech::ID;

void recognizeSpeech::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recognizeSpeech");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

removeFileFromDownloads::removeFileFromDownloads()
  : file_id_()
  , delete_from_cache_()
{}

removeFileFromDownloads::removeFileFromDownloads(int32 file_id_, bool delete_from_cache_)
  : file_id_(file_id_)
  , delete_from_cache_(delete_from_cache_)
{}

const std::int32_t removeFileFromDownloads::ID;

void removeFileFromDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeFileFromDownloads");
    s.store_field("file_id", file_id_);
    s.store_field("delete_from_cache", delete_from_cache_);
    s.store_class_end();
  }
}

removeProfileAudio::removeProfileAudio()
  : file_id_()
{}

removeProfileAudio::removeProfileAudio(int32 file_id_)
  : file_id_(file_id_)
{}

const std::int32_t removeProfileAudio::ID;

void removeProfileAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeProfileAudio");
    s.store_field("file_id", file_id_);
    s.store_class_end();
  }
}

removeProxy::removeProxy()
  : proxy_id_()
{}

removeProxy::removeProxy(int32 proxy_id_)
  : proxy_id_(proxy_id_)
{}

const std::int32_t removeProxy::ID;

void removeProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeProxy");
    s.store_field("proxy_id", proxy_id_);
    s.store_class_end();
  }
}

reorderSupergroupActiveUsernames::reorderSupergroupActiveUsernames()
  : supergroup_id_()
  , usernames_()
{}

reorderSupergroupActiveUsernames::reorderSupergroupActiveUsernames(int53 supergroup_id_, array<string> &&usernames_)
  : supergroup_id_(supergroup_id_)
  , usernames_(std::move(usernames_))
{}

const std::int32_t reorderSupergroupActiveUsernames::ID;

void reorderSupergroupActiveUsernames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderSupergroupActiveUsernames");
    s.store_field("supergroup_id", supergroup_id_);
    { s.store_vector_begin("usernames", usernames_.size()); for (const auto &_value : usernames_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

replacePrimaryChatInviteLink::replacePrimaryChatInviteLink()
  : chat_id_()
{}

replacePrimaryChatInviteLink::replacePrimaryChatInviteLink(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t replacePrimaryChatInviteLink::ID;

void replacePrimaryChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replacePrimaryChatInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

replaceVideoChatRtmpUrl::replaceVideoChatRtmpUrl()
  : chat_id_()
{}

replaceVideoChatRtmpUrl::replaceVideoChatRtmpUrl(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t replaceVideoChatRtmpUrl::ID;

void replaceVideoChatRtmpUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replaceVideoChatRtmpUrl");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

reportSupergroupSpam::reportSupergroupSpam()
  : supergroup_id_()
  , message_ids_()
{}

reportSupergroupSpam::reportSupergroupSpam(int53 supergroup_id_, array<int53> &&message_ids_)
  : supergroup_id_(supergroup_id_)
  , message_ids_(std::move(message_ids_))
{}

const std::int32_t reportSupergroupSpam::ID;

void reportSupergroupSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportSupergroupSpam");
    s.store_field("supergroup_id", supergroup_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

searchInstalledStickerSets::searchInstalledStickerSets()
  : sticker_type_()
  , query_()
  , limit_()
{}

searchInstalledStickerSets::searchInstalledStickerSets(object_ptr<StickerType> &&sticker_type_, string const &query_, int32 limit_)
  : sticker_type_(std::move(sticker_type_))
  , query_(query_)
  , limit_(limit_)
{}

const std::int32_t searchInstalledStickerSets::ID;

void searchInstalledStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchInstalledStickerSets");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchPublicChats::searchPublicChats()
  : query_()
{}

searchPublicChats::searchPublicChats(string const &query_)
  : query_(query_)
{}

const std::int32_t searchPublicChats::ID;

void searchPublicChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchPublicChats");
    s.store_field("query", query_);
    s.store_class_end();
  }
}

sendEmailAddressVerificationCode::sendEmailAddressVerificationCode()
  : email_address_()
{}

sendEmailAddressVerificationCode::sendEmailAddressVerificationCode(string const &email_address_)
  : email_address_(email_address_)
{}

const std::int32_t sendEmailAddressVerificationCode::ID;

void sendEmailAddressVerificationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendEmailAddressVerificationCode");
    s.store_field("email_address", email_address_);
    s.store_class_end();
  }
}

sendGroupCallMessage::sendGroupCallMessage()
  : group_call_id_()
  , text_()
  , paid_message_star_count_()
{}

sendGroupCallMessage::sendGroupCallMessage(int32 group_call_id_, object_ptr<formattedText> &&text_, int53 paid_message_star_count_)
  : group_call_id_(group_call_id_)
  , text_(std::move(text_))
  , paid_message_star_count_(paid_message_star_count_)
{}

const std::int32_t sendGroupCallMessage::ID;

void sendGroupCallMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendGroupCallMessage");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_class_end();
  }
}

sendPassportAuthorizationForm::sendPassportAuthorizationForm()
  : authorization_form_id_()
  , types_()
{}

sendPassportAuthorizationForm::sendPassportAuthorizationForm(int32 authorization_form_id_, array<object_ptr<PassportElementType>> &&types_)
  : authorization_form_id_(authorization_form_id_)
  , types_(std::move(types_))
{}

const std::int32_t sendPassportAuthorizationForm::ID;

void sendPassportAuthorizationForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendPassportAuthorizationForm");
    s.store_field("authorization_form_id", authorization_form_id_);
    { s.store_vector_begin("types", types_.size()); for (const auto &_value : types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

sendPhoneNumberCode::sendPhoneNumberCode()
  : phone_number_()
  , settings_()
  , type_()
{}

sendPhoneNumberCode::sendPhoneNumberCode(string const &phone_number_, object_ptr<phoneNumberAuthenticationSettings> &&settings_, object_ptr<PhoneNumberCodeType> &&type_)
  : phone_number_(phone_number_)
  , settings_(std::move(settings_))
  , type_(std::move(type_))
{}

const std::int32_t sendPhoneNumberCode::ID;

void sendPhoneNumberCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendPhoneNumberCode");
    s.store_field("phone_number", phone_number_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

setAuthenticationEmailAddress::setAuthenticationEmailAddress()
  : email_address_()
{}

setAuthenticationEmailAddress::setAuthenticationEmailAddress(string const &email_address_)
  : email_address_(email_address_)
{}

const std::int32_t setAuthenticationEmailAddress::ID;

void setAuthenticationEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setAuthenticationEmailAddress");
    s.store_field("email_address", email_address_);
    s.store_class_end();
  }
}

setBotProfilePhoto::setBotProfilePhoto()
  : bot_user_id_()
  , photo_()
{}

setBotProfilePhoto::setBotProfilePhoto(int53 bot_user_id_, object_ptr<InputChatPhoto> &&photo_)
  : bot_user_id_(bot_user_id_)
  , photo_(std::move(photo_))
{}

const std::int32_t setBotProfilePhoto::ID;

void setBotProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBotProfilePhoto");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

setBusinessStartPage::setBusinessStartPage()
  : start_page_()
{}

setBusinessStartPage::setBusinessStartPage(object_ptr<inputBusinessStartPage> &&start_page_)
  : start_page_(std::move(start_page_))
{}

const std::int32_t setBusinessStartPage::ID;

void setBusinessStartPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessStartPage");
    s.store_object_field("start_page", static_cast<const BaseObject *>(start_page_.get()));
    s.store_class_end();
  }
}

setChatPhoto::setChatPhoto()
  : chat_id_()
  , photo_()
{}

setChatPhoto::setChatPhoto(int53 chat_id_, object_ptr<InputChatPhoto> &&photo_)
  : chat_id_(chat_id_)
  , photo_(std::move(photo_))
{}

const std::int32_t setChatPhoto::ID;

void setChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatPhoto");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

setGiftCollectionName::setGiftCollectionName()
  : owner_id_()
  , collection_id_()
  , name_()
{}

setGiftCollectionName::setGiftCollectionName(object_ptr<MessageSender> &&owner_id_, int32 collection_id_, string const &name_)
  : owner_id_(std::move(owner_id_))
  , collection_id_(collection_id_)
  , name_(name_)
{}

const std::int32_t setGiftCollectionName::ID;

void setGiftCollectionName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setGiftCollectionName");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("collection_id", collection_id_);
    s.store_field("name", name_);
    s.store_class_end();
  }
}

setGroupCallParticipantVolumeLevel::setGroupCallParticipantVolumeLevel()
  : group_call_id_()
  , participant_id_()
  , volume_level_()
{}

setGroupCallParticipantVolumeLevel::setGroupCallParticipantVolumeLevel(int32 group_call_id_, object_ptr<MessageSender> &&participant_id_, int32 volume_level_)
  : group_call_id_(group_call_id_)
  , participant_id_(std::move(participant_id_))
  , volume_level_(volume_level_)
{}

const std::int32_t setGroupCallParticipantVolumeLevel::ID;

void setGroupCallParticipantVolumeLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setGroupCallParticipantVolumeLevel");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("volume_level", volume_level_);
    s.store_class_end();
  }
}

setInactiveSessionTtl::setInactiveSessionTtl()
  : inactive_session_ttl_days_()
{}

setInactiveSessionTtl::setInactiveSessionTtl(int32 inactive_session_ttl_days_)
  : inactive_session_ttl_days_(inactive_session_ttl_days_)
{}

const std::int32_t setInactiveSessionTtl::ID;

void setInactiveSessionTtl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setInactiveSessionTtl");
    s.store_field("inactive_session_ttl_days", inactive_session_ttl_days_);
    s.store_class_end();
  }
}

setLogTagVerbosityLevel::setLogTagVerbosityLevel()
  : tag_()
  , new_verbosity_level_()
{}

setLogTagVerbosityLevel::setLogTagVerbosityLevel(string const &tag_, int32 new_verbosity_level_)
  : tag_(tag_)
  , new_verbosity_level_(new_verbosity_level_)
{}

const std::int32_t setLogTagVerbosityLevel::ID;

void setLogTagVerbosityLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setLogTagVerbosityLevel");
    s.store_field("tag", tag_);
    s.store_field("new_verbosity_level", new_verbosity_level_);
    s.store_class_end();
  }
}

setProfilePhoto::setProfilePhoto()
  : photo_()
  , is_public_()
{}

setProfilePhoto::setProfilePhoto(object_ptr<InputChatPhoto> &&photo_, bool is_public_)
  : photo_(std::move(photo_))
  , is_public_(is_public_)
{}

const std::int32_t setProfilePhoto::ID;

void setProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setProfilePhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("is_public", is_public_);
    s.store_class_end();
  }
}

testNetwork::testNetwork() {
}

const std::int32_t testNetwork::ID;

void testNetwork::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testNetwork");
    s.store_class_end();
  }
}

toggleAllDownloadsArePaused::toggleAllDownloadsArePaused()
  : are_paused_()
{}

toggleAllDownloadsArePaused::toggleAllDownloadsArePaused(bool are_paused_)
  : are_paused_(are_paused_)
{}

const std::int32_t toggleAllDownloadsArePaused::ID;

void toggleAllDownloadsArePaused::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleAllDownloadsArePaused");
    s.store_field("are_paused", are_paused_);
    s.store_class_end();
  }
}

toggleBotUsernameIsActive::toggleBotUsernameIsActive()
  : bot_user_id_()
  , username_()
  , is_active_()
{}

toggleBotUsernameIsActive::toggleBotUsernameIsActive(int53 bot_user_id_, string const &username_, bool is_active_)
  : bot_user_id_(bot_user_id_)
  , username_(username_)
  , is_active_(is_active_)
{}

const std::int32_t toggleBotUsernameIsActive::ID;

void toggleBotUsernameIsActive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleBotUsernameIsActive");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("username", username_);
    s.store_field("is_active", is_active_);
    s.store_class_end();
  }
}

toggleGeneralForumTopicIsHidden::toggleGeneralForumTopicIsHidden()
  : chat_id_()
  , is_hidden_()
{}

toggleGeneralForumTopicIsHidden::toggleGeneralForumTopicIsHidden(int53 chat_id_, bool is_hidden_)
  : chat_id_(chat_id_)
  , is_hidden_(is_hidden_)
{}

const std::int32_t toggleGeneralForumTopicIsHidden::ID;

void toggleGeneralForumTopicIsHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGeneralForumTopicIsHidden");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_hidden", is_hidden_);
    s.store_class_end();
  }
}

toggleGroupCallAreMessagesAllowed::toggleGroupCallAreMessagesAllowed()
  : group_call_id_()
  , are_messages_allowed_()
{}

toggleGroupCallAreMessagesAllowed::toggleGroupCallAreMessagesAllowed(int32 group_call_id_, bool are_messages_allowed_)
  : group_call_id_(group_call_id_)
  , are_messages_allowed_(are_messages_allowed_)
{}

const std::int32_t toggleGroupCallAreMessagesAllowed::ID;

void toggleGroupCallAreMessagesAllowed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGroupCallAreMessagesAllowed");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("are_messages_allowed", are_messages_allowed_);
    s.store_class_end();
  }
}

toggleSupergroupCanHaveSponsoredMessages::toggleSupergroupCanHaveSponsoredMessages()
  : supergroup_id_()
  , can_have_sponsored_messages_()
{}

toggleSupergroupCanHaveSponsoredMessages::toggleSupergroupCanHaveSponsoredMessages(int53 supergroup_id_, bool can_have_sponsored_messages_)
  : supergroup_id_(supergroup_id_)
  , can_have_sponsored_messages_(can_have_sponsored_messages_)
{}

const std::int32_t toggleSupergroupCanHaveSponsoredMessages::ID;

void toggleSupergroupCanHaveSponsoredMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupCanHaveSponsoredMessages");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("can_have_sponsored_messages", can_have_sponsored_messages_);
    s.store_class_end();
  }
}

toggleVideoChatEnabledStartNotification::toggleVideoChatEnabledStartNotification()
  : group_call_id_()
  , enabled_start_notification_()
{}

toggleVideoChatEnabledStartNotification::toggleVideoChatEnabledStartNotification(int32 group_call_id_, bool enabled_start_notification_)
  : group_call_id_(group_call_id_)
  , enabled_start_notification_(enabled_start_notification_)
{}

const std::int32_t toggleVideoChatEnabledStartNotification::ID;

void toggleVideoChatEnabledStartNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleVideoChatEnabledStartNotification");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("enabled_start_notification", enabled_start_notification_);
    s.store_class_end();
  }
}

unpinAllChatMessages::unpinAllChatMessages()
  : chat_id_()
{}

unpinAllChatMessages::unpinAllChatMessages(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t unpinAllChatMessages::ID;

void unpinAllChatMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "unpinAllChatMessages");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
