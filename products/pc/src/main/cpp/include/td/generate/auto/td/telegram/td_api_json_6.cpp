#include "td/telegram/td_api_json.h"

#include "td/telegram/td_api.h"
#include "td/telegram/td_api.hpp"

#include "td/tl/tl_json.h"

#include "td/utils/base64.h"
#include "td/utils/common.h"
#include "td/utils/FlatHashMap.h"
#include "td/utils/Slice.h"

namespace td {
namespace td_api {
Result<int32> tl_constructor_from_string(td_api::BackgroundType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"backgroundTypeWallpaper", 1972128891},
    {"backgroundTypePattern", 1290213117},
    {"backgroundTypeFill", 993008684},
    {"backgroundTypeChatTheme", 1299879762}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::ChatAvailableReactions *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"chatAvailableReactionsAll", 694160279},
    {"chatAvailableReactionsSome", 152513153}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::EmailAddressAuthentication *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"emailAddressAuthenticationCode", -993257022},
    {"emailAddressAuthenticationAppleId", 633948265},
    {"emailAddressAuthenticationGoogleId", -19142846}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::InlineKeyboardButtonType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"inlineKeyboardButtonTypeUrl", 1130741420},
    {"inlineKeyboardButtonTypeLoginUrl", -1203413081},
    {"inlineKeyboardButtonTypeWebApp", -1767471672},
    {"inlineKeyboardButtonTypeCallback", -1127515139},
    {"inlineKeyboardButtonTypeCallbackWithPassword", 908018248},
    {"inlineKeyboardButtonTypeCallbackGame", -383429528},
    {"inlineKeyboardButtonTypeSwitchInline", 544906485},
    {"inlineKeyboardButtonTypeBuy", 1360739440},
    {"inlineKeyboardButtonTypeUser", 1836574114},
    {"inlineKeyboardButtonTypeCopyText", 68883206}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::InputInlineQueryResult *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"inputInlineQueryResultAnimation", -1489808874},
    {"inputInlineQueryResultArticle", 1983218620},
    {"inputInlineQueryResultAudio", 1260139988},
    {"inputInlineQueryResultContact", 1846064594},
    {"inputInlineQueryResultDocument", 578801869},
    {"inputInlineQueryResultGame", 966074327},
    {"inputInlineQueryResultLocation", -1887650218},
    {"inputInlineQueryResultPhoto", -1123338721},
    {"inputInlineQueryResultSticker", 274007129},
    {"inputInlineQueryResultVenue", 541704509},
    {"inputInlineQueryResultVideo", 1724073191},
    {"inputInlineQueryResultVoiceNote", -1790072503}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::InputStoryContent *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"inputStoryContentPhoto", -309196727},
    {"inputStoryContentVideo", 3809243}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::MessageSelfDestructType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"messageSelfDestructTypeTimer", 1351440333},
    {"messageSelfDestructTypeImmediately", -1036218363}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::PassportElementType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"passportElementTypePersonalDetails", -1032136365},
    {"passportElementTypePassport", -436360376},
    {"passportElementTypeDriverLicense", 1827298379},
    {"passportElementTypeIdentityCard", -502356132},
    {"passportElementTypeInternalPassport", -793781959},
    {"passportElementTypeAddress", 496327874},
    {"passportElementTypeUtilityBill", 627084906},
    {"passportElementTypeBankStatement", 574095667},
    {"passportElementTypeRentalAgreement", -2060583280},
    {"passportElementTypePassportRegistration", -159478209},
    {"passportElementTypeTemporaryRegistration", 1092498527},
    {"passportElementTypePhoneNumber", -995361172},
    {"passportElementTypeEmailAddress", -79321405}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::ReactionNotificationSource *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"reactionNotificationSourceNone", 366374940},
    {"reactionNotificationSourceContacts", 555501621},
    {"reactionNotificationSourceAll", 1241689234}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::StickerType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"stickerTypeRegular", 56345973},
    {"stickerTypeMask", -1765394796},
    {"stickerTypeCustomEmoji", -120752249}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::TargetChat *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"targetChatCurrent", -416689904},
    {"targetChatChosen", -1392978522},
    {"targetChatInternalLink", -579301408}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::WebAppOpenMode *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"webAppOpenModeCompact", 1711603675},
    {"webAppOpenModeFullSize", 189320513},
    {"webAppOpenModeFullScreen", 1871315357}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Status from_json(td_api::affiliateTypeBot &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  return Status::OK();
}

Status from_json(td_api::backgroundFillGradient &to, JsonObject &from) {
  TRY_STATUS(from_json(to.top_color_, from.extract_field("top_color")));
  TRY_STATUS(from_json(to.bottom_color_, from.extract_field("bottom_color")));
  TRY_STATUS(from_json(to.rotation_angle_, from.extract_field("rotation_angle")));
  return Status::OK();
}

Status from_json(td_api::botCommand &to, JsonObject &from) {
  TRY_STATUS(from_json(to.command_, from.extract_field("command")));
  TRY_STATUS(from_json(to.description_, from.extract_field("description")));
  return Status::OK();
}

Status from_json(td_api::businessAwayMessageScheduleAlways &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::businessFeatureGreetingMessage &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::businessLocation &to, JsonObject &from) {
  TRY_STATUS(from_json(to.location_, from.extract_field("location")));
  TRY_STATUS(from_json(to.address_, from.extract_field("address")));
  return Status::OK();
}

Status from_json(td_api::callProblemNoise &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::callbackQueryPayloadData &to, JsonObject &from) {
  TRY_STATUS(from_json_bytes(to.data_, from.extract_field("data")));
  return Status::OK();
}

Status from_json(td_api::chatActionUploadingDocument &to, JsonObject &from) {
  TRY_STATUS(from_json(to.progress_, from.extract_field("progress")));
  return Status::OK();
}

Status from_json(td_api::chatAdministratorRights &to, JsonObject &from) {
  TRY_STATUS(from_json(to.can_manage_chat_, from.extract_field("can_manage_chat")));
  TRY_STATUS(from_json(to.can_change_info_, from.extract_field("can_change_info")));
  TRY_STATUS(from_json(to.can_post_messages_, from.extract_field("can_post_messages")));
  TRY_STATUS(from_json(to.can_edit_messages_, from.extract_field("can_edit_messages")));
  TRY_STATUS(from_json(to.can_delete_messages_, from.extract_field("can_delete_messages")));
  TRY_STATUS(from_json(to.can_invite_users_, from.extract_field("can_invite_users")));
  TRY_STATUS(from_json(to.can_restrict_members_, from.extract_field("can_restrict_members")));
  TRY_STATUS(from_json(to.can_pin_messages_, from.extract_field("can_pin_messages")));
  TRY_STATUS(from_json(to.can_manage_topics_, from.extract_field("can_manage_topics")));
  TRY_STATUS(from_json(to.can_promote_members_, from.extract_field("can_promote_members")));
  TRY_STATUS(from_json(to.can_manage_video_chats_, from.extract_field("can_manage_video_chats")));
  TRY_STATUS(from_json(to.can_post_stories_, from.extract_field("can_post_stories")));
  TRY_STATUS(from_json(to.can_edit_stories_, from.extract_field("can_edit_stories")));
  TRY_STATUS(from_json(to.can_delete_stories_, from.extract_field("can_delete_stories")));
  TRY_STATUS(from_json(to.can_manage_direct_messages_, from.extract_field("can_manage_direct_messages")));
  TRY_STATUS(from_json(to.can_manage_tags_, from.extract_field("can_manage_tags")));
  TRY_STATUS(from_json(to.is_anonymous_, from.extract_field("is_anonymous")));
  return Status::OK();
}

Status from_json(td_api::chatListMain &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::chatMemberStatusBanned &to, JsonObject &from) {
  TRY_STATUS(from_json(to.banned_until_date_, from.extract_field("banned_until_date")));
  return Status::OK();
}

Status from_json(td_api::chatPermissions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.can_send_basic_messages_, from.extract_field("can_send_basic_messages")));
  TRY_STATUS(from_json(to.can_send_audios_, from.extract_field("can_send_audios")));
  TRY_STATUS(from_json(to.can_send_documents_, from.extract_field("can_send_documents")));
  TRY_STATUS(from_json(to.can_send_photos_, from.extract_field("can_send_photos")));
  TRY_STATUS(from_json(to.can_send_videos_, from.extract_field("can_send_videos")));
  TRY_STATUS(from_json(to.can_send_video_notes_, from.extract_field("can_send_video_notes")));
  TRY_STATUS(from_json(to.can_send_voice_notes_, from.extract_field("can_send_voice_notes")));
  TRY_STATUS(from_json(to.can_send_polls_, from.extract_field("can_send_polls")));
  TRY_STATUS(from_json(to.can_send_other_messages_, from.extract_field("can_send_other_messages")));
  TRY_STATUS(from_json(to.can_add_link_previews_, from.extract_field("can_add_link_previews")));
  TRY_STATUS(from_json(to.can_edit_tag_, from.extract_field("can_edit_tag")));
  TRY_STATUS(from_json(to.can_change_info_, from.extract_field("can_change_info")));
  TRY_STATUS(from_json(to.can_invite_users_, from.extract_field("can_invite_users")));
  TRY_STATUS(from_json(to.can_pin_messages_, from.extract_field("can_pin_messages")));
  TRY_STATUS(from_json(to.can_create_topics_, from.extract_field("can_create_topics")));
  return Status::OK();
}

Status from_json(td_api::dateTimeFormattingTypeAbsolute &to, JsonObject &from) {
  TRY_STATUS(from_json(to.time_precision_, from.extract_field("time_precision")));
  TRY_STATUS(from_json(to.date_precision_, from.extract_field("date_precision")));
  TRY_STATUS(from_json(to.show_day_of_week_, from.extract_field("show_day_of_week")));
  return Status::OK();
}

Status from_json(td_api::deviceTokenMicrosoftPushVoIP &to, JsonObject &from) {
  TRY_STATUS(from_json(to.channel_uri_, from.extract_field("channel_uri")));
  return Status::OK();
}

Status from_json(td_api::emailAddressAuthenticationAppleId &to, JsonObject &from) {
  TRY_STATUS(from_json(to.token_, from.extract_field("token")));
  return Status::OK();
}

Status from_json(td_api::error &to, JsonObject &from) {
  TRY_STATUS(from_json(to.code_, from.extract_field("code")));
  TRY_STATUS(from_json(to.message_, from.extract_field("message")));
  return Status::OK();
}

Status from_json(td_api::fileTypeProfilePhoto &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::fileTypeSticker &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::firebaseAuthenticationSettingsIos &to, JsonObject &from) {
  TRY_STATUS(from_json(to.device_token_, from.extract_field("device_token")));
  TRY_STATUS(from_json(to.is_app_sandbox_, from.extract_field("is_app_sandbox")));
  return Status::OK();
}

Status from_json(td_api::giveawayParameters &to, JsonObject &from) {
  TRY_STATUS(from_json(to.boosted_chat_id_, from.extract_field("boosted_chat_id")));
  TRY_STATUS(from_json(to.additional_chat_ids_, from.extract_field("additional_chat_ids")));
  TRY_STATUS(from_json(to.winners_selection_date_, from.extract_field("winners_selection_date")));
  TRY_STATUS(from_json(to.only_new_members_, from.extract_field("only_new_members")));
  TRY_STATUS(from_json(to.has_public_winners_, from.extract_field("has_public_winners")));
  TRY_STATUS(from_json(to.country_codes_, from.extract_field("country_codes")));
  TRY_STATUS(from_json(to.prize_description_, from.extract_field("prize_description")));
  return Status::OK();
}

Status from_json(td_api::inlineKeyboardButtonTypeUrl &to, JsonObject &from) {
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  return Status::OK();
}

Status from_json(td_api::inlineKeyboardButtonTypeCopyText &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  return Status::OK();
}

Status from_json(td_api::inputCallDiscarded &to, JsonObject &from) {
  TRY_STATUS(from_json(to.call_id_, from.extract_field("call_id")));
  return Status::OK();
}

Status from_json(td_api::inputChecklistTask &to, JsonObject &from) {
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  return Status::OK();
}

Status from_json(td_api::inputGroupCallLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.link_, from.extract_field("link")));
  return Status::OK();
}

Status from_json(td_api::inputInlineQueryResultLocation &to, JsonObject &from) {
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  TRY_STATUS(from_json(to.location_, from.extract_field("location")));
  TRY_STATUS(from_json(to.live_period_, from.extract_field("live_period")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  TRY_STATUS(from_json(to.thumbnail_url_, from.extract_field("thumbnail_url")));
  TRY_STATUS(from_json(to.thumbnail_width_, from.extract_field("thumbnail_width")));
  TRY_STATUS(from_json(to.thumbnail_height_, from.extract_field("thumbnail_height")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::inputMessageText &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.link_preview_options_, from.extract_field("link_preview_options")));
  TRY_STATUS(from_json(to.clear_draft_, from.extract_field("clear_draft")));
  return Status::OK();
}

Status from_json(td_api::inputMessageVoiceNote &to, JsonObject &from) {
  TRY_STATUS(from_json(to.voice_note_, from.extract_field("voice_note")));
  TRY_STATUS(from_json(to.duration_, from.extract_field("duration")));
  TRY_STATUS(from_json_bytes(to.waveform_, from.extract_field("waveform")));
  TRY_STATUS(from_json(to.caption_, from.extract_field("caption")));
  TRY_STATUS(from_json(to.self_destruct_type_, from.extract_field("self_destruct_type")));
  return Status::OK();
}

Status from_json(td_api::inputMessageStory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_poster_chat_id_, from.extract_field("story_poster_chat_id")));
  TRY_STATUS(from_json(to.story_id_, from.extract_field("story_id")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementPersonalDetails &to, JsonObject &from) {
  TRY_STATUS(from_json(to.personal_details_, from.extract_field("personal_details")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementPassportRegistration &to, JsonObject &from) {
  TRY_STATUS(from_json(to.passport_registration_, from.extract_field("passport_registration")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementErrorSourceSelfie &to, JsonObject &from) {
  TRY_STATUS(from_json_bytes(to.file_hash_, from.extract_field("file_hash")));
  return Status::OK();
}

Status from_json(td_api::inputSticker &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_, from.extract_field("sticker")));
  TRY_STATUS(from_json(to.format_, from.extract_field("format")));
  TRY_STATUS(from_json(to.emojis_, from.extract_field("emojis")));
  TRY_STATUS(from_json(to.mask_position_, from.extract_field("mask_position")));
  TRY_STATUS(from_json(to.keywords_, from.extract_field("keywords")));
  return Status::OK();
}

Status from_json(td_api::inputStoryAreaTypeUpgradedGift &to, JsonObject &from) {
  TRY_STATUS(from_json(to.gift_name_, from.extract_field("gift_name")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeBackground &to, JsonObject &from) {
  TRY_STATUS(from_json(to.background_name_, from.extract_field("background_name")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeChatInvite &to, JsonObject &from) {
  TRY_STATUS(from_json(to.invite_link_, from.extract_field("invite_link")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeInvoice &to, JsonObject &from) {
  TRY_STATUS(from_json(to.invoice_name_, from.extract_field("invoice_name")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeNewPrivateChat &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::internalLinkTypePublicChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_username_, from.extract_field("chat_username")));
  TRY_STATUS(from_json(to.draft_text_, from.extract_field("draft_text")));
  TRY_STATUS(from_json(to.open_profile_, from.extract_field("open_profile")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeStory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_poster_username_, from.extract_field("story_poster_username")));
  TRY_STATUS(from_json(to.story_id_, from.extract_field("story_id")));
  return Status::OK();
}

Status from_json(td_api::invoice &to, JsonObject &from) {
  TRY_STATUS(from_json(to.currency_, from.extract_field("currency")));
  TRY_STATUS(from_json(to.price_parts_, from.extract_field("price_parts")));
  TRY_STATUS(from_json(to.subscription_period_, from.extract_field("subscription_period")));
  TRY_STATUS(from_json(to.max_tip_amount_, from.extract_field("max_tip_amount")));
  TRY_STATUS(from_json(to.suggested_tip_amounts_, from.extract_field("suggested_tip_amounts")));
  TRY_STATUS(from_json(to.recurring_payment_terms_of_service_url_, from.extract_field("recurring_payment_terms_of_service_url")));
  TRY_STATUS(from_json(to.terms_of_service_url_, from.extract_field("terms_of_service_url")));
  TRY_STATUS(from_json(to.is_test_, from.extract_field("is_test")));
  TRY_STATUS(from_json(to.need_name_, from.extract_field("need_name")));
  TRY_STATUS(from_json(to.need_phone_number_, from.extract_field("need_phone_number")));
  TRY_STATUS(from_json(to.need_email_address_, from.extract_field("need_email_address")));
  TRY_STATUS(from_json(to.need_shipping_address_, from.extract_field("need_shipping_address")));
  TRY_STATUS(from_json(to.send_phone_number_to_provider_, from.extract_field("send_phone_number_to_provider")));
  TRY_STATUS(from_json(to.send_email_address_to_provider_, from.extract_field("send_email_address_to_provider")));
  TRY_STATUS(from_json(to.is_flexible_, from.extract_field("is_flexible")));
  return Status::OK();
}

Status from_json(td_api::keyboardButtonSourceMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::keyboardButtonTypeWebApp &to, JsonObject &from) {
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  return Status::OK();
}

Status from_json(td_api::locationAddress &to, JsonObject &from) {
  TRY_STATUS(from_json(to.country_code_, from.extract_field("country_code")));
  TRY_STATUS(from_json(to.state_, from.extract_field("state")));
  TRY_STATUS(from_json(to.city_, from.extract_field("city")));
  TRY_STATUS(from_json(to.street_, from.extract_field("street")));
  return Status::OK();
}

Status from_json(td_api::messageAutoDeleteTime &to, JsonObject &from) {
  TRY_STATUS(from_json(to.time_, from.extract_field("time")));
  return Status::OK();
}

Status from_json(td_api::messageSenderChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::messageSourceNotification &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::networkTypeNone &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::optionValueBoolean &to, JsonObject &from) {
  TRY_STATUS(from_json(to.value_, from.extract_field("value")));
  return Status::OK();
}

Status from_json(td_api::passportElementTypePassport &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::passportElementTypeTemporaryRegistration &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureIncreasedUploadFileSize &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureEmojiStatus &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureSavedMessagesTags &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumLimitTypeSupergroupCount &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumLimitTypeCaptionLength &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumLimitTypeSimilarChatCount &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumStoryFeatureStealthMode &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::profileTabFiles &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::publicChatTypeHasUsername &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::readDatePrivacySettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.show_read_date_, from.extract_field("show_read_date")));
  return Status::OK();
}

Status from_json(td_api::reportReasonCopyright &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::scopeNotificationSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.mute_for_, from.extract_field("mute_for")));
  TRY_STATUS(from_json(to.sound_id_, from.extract_field("sound_id")));
  TRY_STATUS(from_json(to.show_preview_, from.extract_field("show_preview")));
  TRY_STATUS(from_json(to.use_default_mute_stories_, from.extract_field("use_default_mute_stories")));
  TRY_STATUS(from_json(to.mute_stories_, from.extract_field("mute_stories")));
  TRY_STATUS(from_json(to.story_sound_id_, from.extract_field("story_sound_id")));
  TRY_STATUS(from_json(to.show_story_poster_, from.extract_field("show_story_poster")));
  TRY_STATUS(from_json(to.disable_pinned_message_notifications_, from.extract_field("disable_pinned_message_notifications")));
  TRY_STATUS(from_json(to.disable_mention_notifications_, from.extract_field("disable_mention_notifications")));
  return Status::OK();
}

Status from_json(td_api::searchMessagesFilterPoll &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchMessagesFilterUnreadMention &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::settingsSectionDataAndStorage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.subsection_, from.extract_field("subsection")));
  return Status::OK();
}

Status from_json(td_api::settingsSectionNotifications &to, JsonObject &from) {
  TRY_STATUS(from_json(to.subsection_, from.extract_field("subsection")));
  return Status::OK();
}

Status from_json(td_api::starSubscriptionPricing &to, JsonObject &from) {
  TRY_STATUS(from_json(to.period_, from.extract_field("period")));
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  return Status::OK();
}

Status from_json(td_api::storePaymentPurposePremiumGiftCodes &to, JsonObject &from) {
  TRY_STATUS(from_json(to.boosted_chat_id_, from.extract_field("boosted_chat_id")));
  TRY_STATUS(from_json(to.currency_, from.extract_field("currency")));
  TRY_STATUS(from_json(to.amount_, from.extract_field("amount")));
  TRY_STATUS(from_json(to.user_ids_, from.extract_field("user_ids")));
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  return Status::OK();
}

Status from_json(td_api::storyContentTypeVideo &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::storyPrivacySettingsSelectedUsers &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_ids_, from.extract_field("user_ids")));
  return Status::OK();
}

Status from_json(td_api::suggestedActionSubscribeToAnnualPremium &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::suggestedPostPriceStar &to, JsonObject &from) {
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  return Status::OK();
}

Status from_json(td_api::supergroupMembersFilterBots &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::telegramPaymentPurposeGiftedStars &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.currency_, from.extract_field("currency")));
  TRY_STATUS(from_json(to.amount_, from.extract_field("amount")));
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  return Status::OK();
}

Status from_json(td_api::textEntityTypeBotCommand &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::textEntityTypeSpoiler &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::textEntityTypeMediaTimestamp &to, JsonObject &from) {
  TRY_STATUS(from_json(to.media_timestamp_, from.extract_field("media_timestamp")));
  return Status::OK();
}

Status from_json(td_api::topChatCategoryInlineBots &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::upgradedGiftBackdropColors &to, JsonObject &from) {
  TRY_STATUS(from_json(to.center_color_, from.extract_field("center_color")));
  TRY_STATUS(from_json(to.edge_color_, from.extract_field("edge_color")));
  TRY_STATUS(from_json(to.symbol_color_, from.extract_field("symbol_color")));
  TRY_STATUS(from_json(to.text_color_, from.extract_field("text_color")));
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingAllowCalls &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingRuleAllowPremiumUsers &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::venue &to, JsonObject &from) {
  TRY_STATUS(from_json(to.location_, from.extract_field("location")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  TRY_STATUS(from_json(to.address_, from.extract_field("address")));
  TRY_STATUS(from_json(to.provider_, from.extract_field("provider")));
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  return Status::OK();
}

Status from_json(td_api::addBotMediaPreview &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.language_code_, from.extract_field("language_code")));
  TRY_STATUS(from_json(to.content_, from.extract_field("content")));
  return Status::OK();
}

Status from_json(td_api::addFileToDownloads &to, JsonObject &from) {
  TRY_STATUS(from_json(to.file_id_, from.extract_field("file_id")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.priority_, from.extract_field("priority")));
  return Status::OK();
}

Status from_json(td_api::addPendingPaidMessageReaction &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  return Status::OK();
}

Status from_json(td_api::addSavedAnimation &to, JsonObject &from) {
  TRY_STATUS(from_json(to.animation_, from.extract_field("animation")));
  return Status::OK();
}

Status from_json(td_api::answerPreCheckoutQuery &to, JsonObject &from) {
  TRY_STATUS(from_json(to.pre_checkout_query_id_, from.extract_field("pre_checkout_query_id")));
  TRY_STATUS(from_json(to.error_message_, from.extract_field("error_message")));
  return Status::OK();
}

Status from_json(td_api::boostChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.slot_ids_, from.extract_field("slot_ids")));
  return Status::OK();
}

Status from_json(td_api::cancelPasswordReset &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::checkAuthenticationPassword &to, JsonObject &from) {
  TRY_STATUS(from_json(to.password_, from.extract_field("password")));
  return Status::OK();
}

Status from_json(td_api::checkLoginEmailAddressCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.code_, from.extract_field("code")));
  return Status::OK();
}

Status from_json(td_api::cleanFileName &to, JsonObject &from) {
  TRY_STATUS(from_json(to.file_name_, from.extract_field("file_name")));
  return Status::OK();
}

Status from_json(td_api::clickAnimatedEmojiMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::closeWebApp &to, JsonObject &from) {
  TRY_STATUS(from_json(to.web_app_launch_id_, from.extract_field("web_app_launch_id")));
  return Status::OK();
}

Status from_json(td_api::createBot &to, JsonObject &from) {
  TRY_STATUS(from_json(to.manager_bot_user_id_, from.extract_field("manager_bot_user_id")));
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.username_, from.extract_field("username")));
  TRY_STATUS(from_json(to.via_link_, from.extract_field("via_link")));
  return Status::OK();
}

Status from_json(td_api::createGroupCall &to, JsonObject &from) {
  TRY_STATUS(from_json(to.join_parameters_, from.extract_field("join_parameters")));
  return Status::OK();
}

Status from_json(td_api::createSupergroupChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  TRY_STATUS(from_json(to.force_, from.extract_field("force")));
  return Status::OK();
}

Status from_json(td_api::deleteAllRevokedChatInviteLinks &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.creator_user_id_, from.extract_field("creator_user_id")));
  return Status::OK();
}

Status from_json(td_api::deleteChatFolderInviteLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_folder_id_, from.extract_field("chat_folder_id")));
  TRY_STATUS(from_json(to.invite_link_, from.extract_field("invite_link")));
  return Status::OK();
}

Status from_json(td_api::deleteFile &to, JsonObject &from) {
  TRY_STATUS(from_json(to.file_id_, from.extract_field("file_id")));
  return Status::OK();
}

Status from_json(td_api::deleteProfilePhoto &to, JsonObject &from) {
  TRY_STATUS(from_json(to.profile_photo_id_, from.extract_field("profile_photo_id")));
  return Status::OK();
}

Status from_json(td_api::deleteStory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_poster_chat_id_, from.extract_field("story_poster_chat_id")));
  TRY_STATUS(from_json(to.story_id_, from.extract_field("story_id")));
  return Status::OK();
}

Status from_json(td_api::downloadFile &to, JsonObject &from) {
  TRY_STATUS(from_json(to.file_id_, from.extract_field("file_id")));
  TRY_STATUS(from_json(to.priority_, from.extract_field("priority")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  TRY_STATUS(from_json(to.synchronous_, from.extract_field("synchronous")));
  return Status::OK();
}

Status from_json(td_api::editBusinessMessageText &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::editInlineMessageLiveLocation &to, JsonObject &from) {
  TRY_STATUS(from_json(to.inline_message_id_, from.extract_field("inline_message_id")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.location_, from.extract_field("location")));
  TRY_STATUS(from_json(to.live_period_, from.extract_field("live_period")));
  TRY_STATUS(from_json(to.heading_, from.extract_field("heading")));
  TRY_STATUS(from_json(to.proximity_alert_radius_, from.extract_field("proximity_alert_radius")));
  return Status::OK();
}

Status from_json(td_api::editMessageSchedulingState &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.scheduling_state_, from.extract_field("scheduling_state")));
  return Status::OK();
}

Status from_json(td_api::encryptGroupCallData &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.data_channel_, from.extract_field("data_channel")));
  TRY_STATUS(from_json_bytes(to.data_, from.extract_field("data")));
  TRY_STATUS(from_json(to.unencrypted_prefix_size_, from.extract_field("unencrypted_prefix_size")));
  return Status::OK();
}

Status from_json(td_api::getAllPassportElements &to, JsonObject &from) {
  TRY_STATUS(from_json(to.password_, from.extract_field("password")));
  return Status::OK();
}

Status from_json(td_api::getAuthenticationPasskeyParameters &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getBasicGroupFullInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.basic_group_id_, from.extract_field("basic_group_id")));
  return Status::OK();
}

Status from_json(td_api::getBotToken &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.revoke_, from.extract_field("revoke")));
  return Status::OK();
}

Status from_json(td_api::getChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::getChatBoostLinkInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  return Status::OK();
}

Status from_json(td_api::getChatFolderNewChats &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_folder_id_, from.extract_field("chat_folder_id")));
  return Status::OK();
}

Status from_json(td_api::getChatMessageByDate &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.date_, from.extract_field("date")));
  return Status::OK();
}

Status from_json(td_api::getChatRevenueTransactions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getChatStoryInteractions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_poster_chat_id_, from.extract_field("story_poster_chat_id")));
  TRY_STATUS(from_json(to.story_id_, from.extract_field("story_id")));
  TRY_STATUS(from_json(to.reaction_type_, from.extract_field("reaction_type")));
  TRY_STATUS(from_json(to.prefer_forwards_, from.extract_field("prefer_forwards")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getConnectedWebsites &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getCustomEmojiStickers &to, JsonObject &from) {
  TRY_STATUS(from_json(to.custom_emoji_ids_, from.extract_field("custom_emoji_ids")));
  return Status::OK();
}

Status from_json(td_api::getDirectMessagesChatTopic &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  return Status::OK();
}

Status from_json(td_api::getExternalLinkInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.link_, from.extract_field("link")));
  return Status::OK();
}

Status from_json(td_api::getForumTopicLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.forum_topic_id_, from.extract_field("forum_topic_id")));
  return Status::OK();
}

Status from_json(td_api::getGiveawayInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::getInactiveSupergroupChats &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getKeywordEmojis &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.input_language_codes_, from.extract_field("input_language_codes")));
  return Status::OK();
}

Status from_json(td_api::getLocalizationTargetInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.only_local_, from.extract_field("only_local")));
  return Status::OK();
}

Status from_json(td_api::getMapThumbnailFile &to, JsonObject &from) {
  TRY_STATUS(from_json(to.location_, from.extract_field("location")));
  TRY_STATUS(from_json(to.zoom_, from.extract_field("zoom")));
  TRY_STATUS(from_json(to.width_, from.extract_field("width")));
  TRY_STATUS(from_json(to.height_, from.extract_field("height")));
  TRY_STATUS(from_json(to.scale_, from.extract_field("scale")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::getMessageEmbeddingCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.for_album_, from.extract_field("for_album")));
  return Status::OK();
}

Status from_json(td_api::getMessageStatistics &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.is_dark_, from.extract_field("is_dark")));
  return Status::OK();
}

Status from_json(td_api::getOwnedBots &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getPaymentReceipt &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::getPremiumInfoSticker &to, JsonObject &from) {
  TRY_STATUS(from_json(to.month_count_, from.extract_field("month_count")));
  return Status::OK();
}

Status from_json(td_api::getPushReceiverId &to, JsonObject &from) {
  TRY_STATUS(from_json(to.payload_, from.extract_field("payload")));
  return Status::OK();
}

Status from_json(td_api::getRecommendedChatFolders &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getSavedNotificationSound &to, JsonObject &from) {
  TRY_STATUS(from_json(to.notification_sound_id_, from.extract_field("notification_sound_id")));
  return Status::OK();
}

Status from_json(td_api::getStarGiftPaymentOptions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  return Status::OK();
}

Status from_json(td_api::getStickerOutline &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_file_id_, from.extract_field("sticker_file_id")));
  TRY_STATUS(from_json(to.for_animated_emoji_, from.extract_field("for_animated_emoji")));
  TRY_STATUS(from_json(to.for_clicked_animated_emoji_message_, from.extract_field("for_clicked_animated_emoji_message")));
  return Status::OK();
}

Status from_json(td_api::getStoryAvailableReactions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.row_size_, from.extract_field("row_size")));
  return Status::OK();
}

Status from_json(td_api::getSupergroup &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  return Status::OK();
}

Status from_json(td_api::getThemedEmojiStatuses &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getUpgradedGiftValueInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  return Status::OK();
}

Status from_json(td_api::getUserProfileAudios &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getWebAppUrl &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  TRY_STATUS(from_json(to.parameters_, from.extract_field("parameters")));
  return Status::OK();
}

Status from_json(td_api::inviteVideoChatParticipants &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.user_ids_, from.extract_field("user_ids")));
  return Status::OK();
}

Status from_json(td_api::leaveChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::loadSavedMessagesTopics &to, JsonObject &from) {
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::openStory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_poster_chat_id_, from.extract_field("story_poster_chat_id")));
  TRY_STATUS(from_json(to.story_id_, from.extract_field("story_id")));
  return Status::OK();
}

Status from_json(td_api::preliminaryUploadFile &to, JsonObject &from) {
  TRY_STATUS(from_json(to.file_, from.extract_field("file")));
  TRY_STATUS(from_json(to.file_type_, from.extract_field("file_type")));
  TRY_STATUS(from_json(to.priority_, from.extract_field("priority")));
  return Status::OK();
}

Status from_json(td_api::readAllChatPollVotes &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::readdQuickReplyShortcutMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.shortcut_name_, from.extract_field("shortcut_name")));
  TRY_STATUS(from_json(to.message_ids_, from.extract_field("message_ids")));
  return Status::OK();
}

Status from_json(td_api::removeChatActionBar &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::removeNotification &to, JsonObject &from) {
  TRY_STATUS(from_json(to.notification_group_id_, from.extract_field("notification_group_id")));
  TRY_STATUS(from_json(to.notification_id_, from.extract_field("notification_id")));
  return Status::OK();
}

Status from_json(td_api::removeSavedAnimation &to, JsonObject &from) {
  TRY_STATUS(from_json(to.animation_, from.extract_field("animation")));
  return Status::OK();
}

Status from_json(td_api::reorderChatFolders &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_folder_ids_, from.extract_field("chat_folder_ids")));
  TRY_STATUS(from_json(to.main_chat_list_position_, from.extract_field("main_chat_list_position")));
  return Status::OK();
}

Status from_json(td_api::replacePrimaryChatInviteLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::reportSponsoredChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sponsored_chat_unique_id_, from.extract_field("sponsored_chat_unique_id")));
  TRY_STATUS(from_json_bytes(to.option_id_, from.extract_field("option_id")));
  return Status::OK();
}

Status from_json(td_api::resendEmailAddressVerificationCode &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::resetPassword &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchCallMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  TRY_STATUS(from_json(to.only_missed_, from.extract_field("only_missed")));
  return Status::OK();
}

Status from_json(td_api::searchFileDownloads &to, JsonObject &from) {
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.only_active_, from.extract_field("only_active")));
  TRY_STATUS(from_json(to.only_completed_, from.extract_field("only_completed")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::searchPublicPosts &to, JsonObject &from) {
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  return Status::OK();
}

Status from_json(td_api::searchStickerSets &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_type_, from.extract_field("sticker_type")));
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  return Status::OK();
}

Status from_json(td_api::sendBusinessMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.reply_to_, from.extract_field("reply_to")));
  TRY_STATUS(from_json(to.disable_notification_, from.extract_field("disable_notification")));
  TRY_STATUS(from_json(to.protect_content_, from.extract_field("protect_content")));
  TRY_STATUS(from_json(to.effect_id_, from.extract_field("effect_id")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::sendGift &to, JsonObject &from) {
  TRY_STATUS(from_json(to.gift_id_, from.extract_field("gift_id")));
  TRY_STATUS(from_json(to.owner_id_, from.extract_field("owner_id")));
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.is_private_, from.extract_field("is_private")));
  TRY_STATUS(from_json(to.pay_for_upgrade_, from.extract_field("pay_for_upgrade")));
  return Status::OK();
}

Status from_json(td_api::sendPhoneNumberCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.phone_number_, from.extract_field("phone_number")));
  TRY_STATUS(from_json(to.settings_, from.extract_field("settings")));
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  return Status::OK();
}

Status from_json(td_api::setAlarm &to, JsonObject &from) {
  TRY_STATUS(from_json(to.seconds_, from.extract_field("seconds")));
  return Status::OK();
}

Status from_json(td_api::setBirthdate &to, JsonObject &from) {
  TRY_STATUS(from_json(to.birthdate_, from.extract_field("birthdate")));
  return Status::OK();
}

Status from_json(td_api::setBusinessAccountProfilePhoto &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.photo_, from.extract_field("photo")));
  TRY_STATUS(from_json(to.is_public_, from.extract_field("is_public")));
  return Status::OK();
}

Status from_json(td_api::setChatAccentColor &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.accent_color_id_, from.extract_field("accent_color_id")));
  TRY_STATUS(from_json(to.background_custom_emoji_id_, from.extract_field("background_custom_emoji_id")));
  return Status::OK();
}

Status from_json(td_api::setChatDraftMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  TRY_STATUS(from_json(to.draft_message_, from.extract_field("draft_message")));
  return Status::OK();
}

Status from_json(td_api::setChatPermissions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.permissions_, from.extract_field("permissions")));
  return Status::OK();
}

Status from_json(td_api::setCustomEmojiStickerSetThumbnail &to, JsonObject &from) {
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.custom_emoji_id_, from.extract_field("custom_emoji_id")));
  return Status::OK();
}

Status from_json(td_api::setDirectMessagesChatTopicIsMarkedAsUnread &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  TRY_STATUS(from_json(to.is_marked_as_unread_, from.extract_field("is_marked_as_unread")));
  return Status::OK();
}

Status from_json(td_api::setGroupCallParticipantIsSpeaking &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.audio_source_, from.extract_field("audio_source")));
  TRY_STATUS(from_json(to.is_speaking_, from.extract_field("is_speaking")));
  return Status::OK();
}

Status from_json(td_api::setMainProfileTab &to, JsonObject &from) {
  TRY_STATUS(from_json(to.main_profile_tab_, from.extract_field("main_profile_tab")));
  return Status::OK();
}

Status from_json(td_api::setOption &to, JsonObject &from) {
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.value_, from.extract_field("value")));
  return Status::OK();
}

Status from_json(td_api::setPinnedSavedMessagesTopics &to, JsonObject &from) {
  TRY_STATUS(from_json(to.saved_messages_topic_ids_, from.extract_field("saved_messages_topic_ids")));
  return Status::OK();
}

Status from_json(td_api::setSavedMessagesTagLabel &to, JsonObject &from) {
  TRY_STATUS(from_json(to.tag_, from.extract_field("tag")));
  TRY_STATUS(from_json(to.label_, from.extract_field("label")));
  return Status::OK();
}

Status from_json(td_api::setStoryPrivacySettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_id_, from.extract_field("story_id")));
  TRY_STATUS(from_json(to.privacy_settings_, from.extract_field("privacy_settings")));
  return Status::OK();
}

Status from_json(td_api::setUserEmojiStatus &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.emoji_status_, from.extract_field("emoji_status")));
  return Status::OK();
}

Status from_json(td_api::sharePhoneNumber &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  return Status::OK();
}

Status from_json(td_api::suggestUserProfilePhoto &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.photo_, from.extract_field("photo")));
  return Status::OK();
}

Status from_json(td_api::testCallVectorIntObject &to, JsonObject &from) {
  TRY_STATUS(from_json(to.x_, from.extract_field("x")));
  return Status::OK();
}

Status from_json(td_api::toggleAllDownloadsArePaused &to, JsonObject &from) {
  TRY_STATUS(from_json(to.are_paused_, from.extract_field("are_paused")));
  return Status::OK();
}

Status from_json(td_api::toggleChatIsMarkedAsUnread &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.is_marked_as_unread_, from.extract_field("is_marked_as_unread")));
  return Status::OK();
}

Status from_json(td_api::toggleGiftIsSaved &to, JsonObject &from) {
  TRY_STATUS(from_json(to.received_gift_id_, from.extract_field("received_gift_id")));
  TRY_STATUS(from_json(to.is_saved_, from.extract_field("is_saved")));
  return Status::OK();
}

Status from_json(td_api::toggleSessionCanAcceptCalls &to, JsonObject &from) {
  TRY_STATUS(from_json(to.session_id_, from.extract_field("session_id")));
  TRY_STATUS(from_json(to.can_accept_calls_, from.extract_field("can_accept_calls")));
  return Status::OK();
}

Status from_json(td_api::toggleSupergroupIsForum &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  TRY_STATUS(from_json(to.is_forum_, from.extract_field("is_forum")));
  TRY_STATUS(from_json(to.has_forum_tabs_, from.extract_field("has_forum_tabs")));
  return Status::OK();
}

Status from_json(td_api::transferChatOwnership &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.password_, from.extract_field("password")));
  return Status::OK();
}

Status from_json(td_api::upgradeGift &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.received_gift_id_, from.extract_field("received_gift_id")));
  TRY_STATUS(from_json(to.keep_original_details_, from.extract_field("keep_original_details")));
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  return Status::OK();
}

void to_json(JsonValueScope &jv, const td_api::accentColor &object) {
  auto jo = jv.enter_object();
  jo("@type", "accentColor");
  jo("id", object.id_);
  jo("built_in_accent_color_id", object.built_in_accent_color_id_);
  jo("light_theme_colors", ToJson(object.light_theme_colors_));
  jo("dark_theme_colors", ToJson(object.dark_theme_colors_));
  jo("min_channel_chat_boost_level", object.min_channel_chat_boost_level_);
}

void to_json(JsonValueScope &jv, const td_api::address &object) {
  auto jo = jv.enter_object();
  jo("@type", "address");
  jo("country_code", object.country_code_);
  jo("state", object.state_);
  jo("city", object.city_);
  jo("street_line1", object.street_line1_);
  jo("street_line2", object.street_line2_);
  jo("postal_code", object.postal_code_);
}

void to_json(JsonValueScope &jv, const td_api::animation &object) {
  auto jo = jv.enter_object();
  jo("@type", "animation");
  jo("duration", object.duration_);
  jo("width", object.width_);
  jo("height", object.height_);
  jo("file_name", object.file_name_);
  jo("mime_type", object.mime_type_);
  jo("has_stickers", JsonBool{object.has_stickers_});
  if (object.minithumbnail_) {
    jo("minithumbnail", ToJson(*object.minithumbnail_));
  }
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
  if (object.animation_) {
    jo("animation", ToJson(*object.animation_));
  }
}

void to_json(JsonValueScope &jv, const td_api::audio &object) {
  auto jo = jv.enter_object();
  jo("@type", "audio");
  jo("duration", object.duration_);
  jo("title", object.title_);
  jo("performer", object.performer_);
  jo("file_name", object.file_name_);
  jo("mime_type", object.mime_type_);
  if (object.album_cover_minithumbnail_) {
    jo("album_cover_minithumbnail", ToJson(*object.album_cover_minithumbnail_));
  }
  if (object.album_cover_thumbnail_) {
    jo("album_cover_thumbnail", ToJson(*object.album_cover_thumbnail_));
  }
  jo("external_album_covers", ToJson(object.external_album_covers_));
  if (object.audio_) {
    jo("audio", ToJson(*object.audio_));
  }
}

void to_json(JsonValueScope &jv, const td_api::AutosaveSettingsScope &object) {
  td_api::downcast_call(const_cast<td_api::AutosaveSettingsScope &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::autosaveSettingsScopePrivateChats &object) {
  auto jo = jv.enter_object();
  jo("@type", "autosaveSettingsScopePrivateChats");
}

void to_json(JsonValueScope &jv, const td_api::autosaveSettingsScopeGroupChats &object) {
  auto jo = jv.enter_object();
  jo("@type", "autosaveSettingsScopeGroupChats");
}

void to_json(JsonValueScope &jv, const td_api::autosaveSettingsScopeChannelChats &object) {
  auto jo = jv.enter_object();
  jo("@type", "autosaveSettingsScopeChannelChats");
}

void to_json(JsonValueScope &jv, const td_api::autosaveSettingsScopeChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "autosaveSettingsScopeChat");
  jo("chat_id", object.chat_id_);
}

void to_json(JsonValueScope &jv, const td_api::bankCardActionOpenUrl &object) {
  auto jo = jv.enter_object();
  jo("@type", "bankCardActionOpenUrl");
  jo("text", object.text_);
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::botMediaPreview &object) {
  auto jo = jv.enter_object();
  jo("@type", "botMediaPreview");
  jo("date", object.date_);
  if (object.content_) {
    jo("content", ToJson(*object.content_));
  }
}

void to_json(JsonValueScope &jv, const td_api::businessAwayMessageSettings &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessAwayMessageSettings");
  jo("shortcut_id", object.shortcut_id_);
  if (object.recipients_) {
    jo("recipients", ToJson(*object.recipients_));
  }
  if (object.schedule_) {
    jo("schedule", ToJson(*object.schedule_));
  }
  jo("offline_only", JsonBool{object.offline_only_});
}

void to_json(JsonValueScope &jv, const td_api::businessFeaturePromotionAnimation &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessFeaturePromotionAnimation");
  if (object.feature_) {
    jo("feature", ToJson(*object.feature_));
  }
  if (object.animation_) {
    jo("animation", ToJson(*object.animation_));
  }
}

void to_json(JsonValueScope &jv, const td_api::businessRecipients &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessRecipients");
  jo("chat_ids", ToJson(object.chat_ids_));
  jo("excluded_chat_ids", ToJson(object.excluded_chat_ids_));
  jo("select_existing_chats", JsonBool{object.select_existing_chats_});
  jo("select_new_chats", JsonBool{object.select_new_chats_});
  jo("select_contacts", JsonBool{object.select_contacts_});
  jo("select_non_contacts", JsonBool{object.select_non_contacts_});
  jo("exclude_selected", JsonBool{object.exclude_selected_});
}

void to_json(JsonValueScope &jv, const td_api::CallState &object) {
  td_api::downcast_call(const_cast<td_api::CallState &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::callStatePending &object) {
  auto jo = jv.enter_object();
  jo("@type", "callStatePending");
  jo("is_created", JsonBool{object.is_created_});
  jo("is_received", JsonBool{object.is_received_});
}

void to_json(JsonValueScope &jv, const td_api::callStateExchangingKeys &object) {
  auto jo = jv.enter_object();
  jo("@type", "callStateExchangingKeys");
}

void to_json(JsonValueScope &jv, const td_api::callStateReady &object) {
  auto jo = jv.enter_object();
  jo("@type", "callStateReady");
  if (object.protocol_) {
    jo("protocol", ToJson(*object.protocol_));
  }
  jo("servers", ToJson(object.servers_));
  jo("config", object.config_);
  jo("encryption_key", base64_encode(object.encryption_key_));
  jo("emojis", ToJson(object.emojis_));
  jo("allow_p2p", JsonBool{object.allow_p2p_});
  jo("is_group_call_supported", JsonBool{object.is_group_call_supported_});
  jo("custom_parameters", object.custom_parameters_);
}

void to_json(JsonValueScope &jv, const td_api::callStateHangingUp &object) {
  auto jo = jv.enter_object();
  jo("@type", "callStateHangingUp");
}

void to_json(JsonValueScope &jv, const td_api::callStateDiscarded &object) {
  auto jo = jv.enter_object();
  jo("@type", "callStateDiscarded");
  if (object.reason_) {
    jo("reason", ToJson(*object.reason_));
  }
  jo("need_rating", JsonBool{object.need_rating_});
  jo("need_debug_information", JsonBool{object.need_debug_information_});
  jo("need_log", JsonBool{object.need_log_});
}

void to_json(JsonValueScope &jv, const td_api::callStateError &object) {
  auto jo = jv.enter_object();
  jo("@type", "callStateError");
  if (object.error_) {
    jo("error", ToJson(*object.error_));
  }
}

void to_json(JsonValueScope &jv, const td_api::ChatActionBar &object) {
  td_api::downcast_call(const_cast<td_api::ChatActionBar &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::chatActionBarReportSpam &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionBarReportSpam");
  jo("can_unarchive", JsonBool{object.can_unarchive_});
}

void to_json(JsonValueScope &jv, const td_api::chatActionBarInviteMembers &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionBarInviteMembers");
}

void to_json(JsonValueScope &jv, const td_api::chatActionBarReportAddBlock &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionBarReportAddBlock");
  jo("can_unarchive", JsonBool{object.can_unarchive_});
  if (object.account_info_) {
    jo("account_info", ToJson(*object.account_info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatActionBarAddContact &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionBarAddContact");
}

void to_json(JsonValueScope &jv, const td_api::chatActionBarSharePhoneNumber &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionBarSharePhoneNumber");
}

void to_json(JsonValueScope &jv, const td_api::chatActionBarJoinRequest &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionBarJoinRequest");
  jo("title", object.title_);
  jo("is_channel", JsonBool{object.is_channel_});
  jo("request_date", object.request_date_);
}

void to_json(JsonValueScope &jv, const td_api::chatBoostLevelFeatures &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatBoostLevelFeatures");
  jo("level", object.level_);
  jo("story_per_day_count", object.story_per_day_count_);
  jo("custom_emoji_reaction_count", object.custom_emoji_reaction_count_);
  jo("title_color_count", object.title_color_count_);
  jo("profile_accent_color_count", object.profile_accent_color_count_);
  jo("can_set_profile_background_custom_emoji", JsonBool{object.can_set_profile_background_custom_emoji_});
  jo("accent_color_count", object.accent_color_count_);
  jo("can_set_background_custom_emoji", JsonBool{object.can_set_background_custom_emoji_});
  jo("can_set_emoji_status", JsonBool{object.can_set_emoji_status_});
  jo("chat_theme_background_count", object.chat_theme_background_count_);
  jo("can_set_custom_background", JsonBool{object.can_set_custom_background_});
  jo("can_set_custom_emoji_sticker_set", JsonBool{object.can_set_custom_emoji_sticker_set_});
  jo("can_enable_automatic_translation", JsonBool{object.can_enable_automatic_translation_});
  jo("can_recognize_speech", JsonBool{object.can_recognize_speech_});
  jo("can_disable_sponsored_messages", JsonBool{object.can_disable_sponsored_messages_});
}

void to_json(JsonValueScope &jv, const td_api::chatEvents &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEvents");
  jo("events", ToJson(object.events_));
}

void to_json(JsonValueScope &jv, const td_api::chatInviteLinkCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatInviteLinkCount");
  jo("user_id", object.user_id_);
  jo("invite_link_count", object.invite_link_count_);
  jo("revoked_invite_link_count", object.revoked_invite_link_count_);
}

void to_json(JsonValueScope &jv, const td_api::chatJoinRequestsInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatJoinRequestsInfo");
  jo("total_count", object.total_count_);
  jo("user_ids", ToJson(object.user_ids_));
}

void to_json(JsonValueScope &jv, const td_api::chatNotificationSettings &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatNotificationSettings");
  jo("use_default_mute_for", JsonBool{object.use_default_mute_for_});
  jo("mute_for", object.mute_for_);
  jo("use_default_sound", JsonBool{object.use_default_sound_});
  jo("sound_id", ToJson(JsonInt64{object.sound_id_}));
  jo("use_default_show_preview", JsonBool{object.use_default_show_preview_});
  jo("show_preview", JsonBool{object.show_preview_});
  jo("use_default_mute_stories", JsonBool{object.use_default_mute_stories_});
  jo("mute_stories", JsonBool{object.mute_stories_});
  jo("use_default_story_sound", JsonBool{object.use_default_story_sound_});
  jo("story_sound_id", ToJson(JsonInt64{object.story_sound_id_}));
  jo("use_default_show_story_poster", JsonBool{object.use_default_show_story_poster_});
  jo("show_story_poster", JsonBool{object.show_story_poster_});
  jo("use_default_disable_pinned_message_notifications", JsonBool{object.use_default_disable_pinned_message_notifications_});
  jo("disable_pinned_message_notifications", JsonBool{object.disable_pinned_message_notifications_});
  jo("use_default_disable_mention_notifications", JsonBool{object.use_default_disable_mention_notifications_});
  jo("disable_mention_notifications", JsonBool{object.disable_mention_notifications_});
}

void to_json(JsonValueScope &jv, const td_api::chatRevenueStatistics &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatRevenueStatistics");
  if (object.revenue_by_hour_graph_) {
    jo("revenue_by_hour_graph", ToJson(*object.revenue_by_hour_graph_));
  }
  if (object.revenue_graph_) {
    jo("revenue_graph", ToJson(*object.revenue_graph_));
  }
  if (object.revenue_amount_) {
    jo("revenue_amount", ToJson(*object.revenue_amount_));
  }
  jo("usd_rate", object.usd_rate_);
}

void to_json(JsonValueScope &jv, const td_api::chatStatisticsMessageSenderInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatStatisticsMessageSenderInfo");
  jo("user_id", object.user_id_);
  jo("sent_message_count", object.sent_message_count_);
  jo("average_character_count", object.average_character_count_);
}

void to_json(JsonValueScope &jv, const td_api::closeBirthdayUser &object) {
  auto jo = jv.enter_object();
  jo("@type", "closeBirthdayUser");
  jo("user_id", object.user_id_);
  if (object.birthdate_) {
    jo("birthdate", ToJson(*object.birthdate_));
  }
}

void to_json(JsonValueScope &jv, const td_api::count &object) {
  auto jo = jv.enter_object();
  jo("@type", "count");
  jo("count", object.count_);
}

void to_json(JsonValueScope &jv, const td_api::date &object) {
  auto jo = jv.enter_object();
  jo("@type", "date");
  jo("day", object.day_);
  jo("month", object.month_);
  jo("year", object.year_);
}

void to_json(JsonValueScope &jv, const td_api::diffText &object) {
  auto jo = jv.enter_object();
  jo("@type", "diffText");
  jo("text", object.text_);
  jo("entities", ToJson(object.entities_));
}

void to_json(JsonValueScope &jv, const td_api::EmojiCategorySource &object) {
  td_api::downcast_call(const_cast<td_api::EmojiCategorySource &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::emojiCategorySourceSearch &object) {
  auto jo = jv.enter_object();
  jo("@type", "emojiCategorySourceSearch");
  jo("emojis", ToJson(object.emojis_));
}

void to_json(JsonValueScope &jv, const td_api::emojiCategorySourcePremium &object) {
  auto jo = jv.enter_object();
  jo("@type", "emojiCategorySourcePremium");
}

void to_json(JsonValueScope &jv, const td_api::emojis &object) {
  auto jo = jv.enter_object();
  jo("@type", "emojis");
  jo("emojis", ToJson(object.emojis_));
}

void to_json(JsonValueScope &jv, const td_api::fileDownloadedPrefixSize &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileDownloadedPrefixSize");
  jo("size", object.size_);
}

void to_json(JsonValueScope &jv, const td_api::forwardSource &object) {
  auto jo = jv.enter_object();
  jo("@type", "forwardSource");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
  if (object.sender_id_) {
    jo("sender_id", ToJson(*object.sender_id_));
  }
  jo("sender_name", object.sender_name_);
  jo("date", object.date_);
  jo("is_outgoing", JsonBool{object.is_outgoing_});
}

void to_json(JsonValueScope &jv, const td_api::foundPublicPosts &object) {
  auto jo = jv.enter_object();
  jo("@type", "foundPublicPosts");
  jo("messages", ToJson(object.messages_));
  jo("next_offset", object.next_offset_);
  if (object.search_limits_) {
    jo("search_limits", ToJson(*object.search_limits_));
  }
  jo("are_limits_exceeded", JsonBool{object.are_limits_exceeded_});
}

void to_json(JsonValueScope &jv, const td_api::giftAuctionAcquiredGift &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftAuctionAcquiredGift");
  if (object.receiver_id_) {
    jo("receiver_id", ToJson(*object.receiver_id_));
  }
  jo("date", object.date_);
  jo("star_count", object.star_count_);
  jo("auction_round_number", object.auction_round_number_);
  jo("auction_round_position", object.auction_round_position_);
  jo("unique_gift_number", object.unique_gift_number_);
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("is_private", JsonBool{object.is_private_});
}

void to_json(JsonValueScope &jv, const td_api::giftPurchaseLimits &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftPurchaseLimits");
  jo("total_count", object.total_count_);
  jo("remaining_count", object.remaining_count_);
}

void to_json(JsonValueScope &jv, const td_api::giftsForCrafting &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftsForCrafting");
  jo("total_count", object.total_count_);
  jo("gifts", ToJson(object.gifts_));
  jo("attribute_persistence_probabilities", ToJson(object.attribute_persistence_probabilities_));
  jo("next_offset", object.next_offset_);
}

void to_json(JsonValueScope &jv, const td_api::groupCallMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "groupCallMessage");
  jo("message_id", object.message_id_);
  if (object.sender_id_) {
    jo("sender_id", ToJson(*object.sender_id_));
  }
  jo("date", object.date_);
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("paid_message_star_count", object.paid_message_star_count_);
  jo("is_from_owner", JsonBool{object.is_from_owner_});
  jo("can_be_deleted", JsonBool{object.can_be_deleted_});
}

void to_json(JsonValueScope &jv, const td_api::hashtags &object) {
  auto jo = jv.enter_object();
  jo("@type", "hashtags");
  jo("hashtags", ToJson(object.hashtags_));
}

void to_json(JsonValueScope &jv, const td_api::InlineQueryResultsButtonType &object) {
  td_api::downcast_call(const_cast<td_api::InlineQueryResultsButtonType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::inlineQueryResultsButtonTypeStartBot &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineQueryResultsButtonTypeStartBot");
  jo("parameter", object.parameter_);
}

void to_json(JsonValueScope &jv, const td_api::inlineQueryResultsButtonTypeWebApp &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineQueryResultsButtonTypeWebApp");
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::InputPollType &object) {
  td_api::downcast_call(const_cast<td_api::InputPollType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::inputPollTypeRegular &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputPollTypeRegular");
  jo("allow_adding_options", JsonBool{object.allow_adding_options_});
}

void to_json(JsonValueScope &jv, const td_api::inputPollTypeQuiz &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputPollTypeQuiz");
  jo("correct_option_ids", ToJson(object.correct_option_ids_));
  if (object.explanation_) {
    jo("explanation", ToJson(*object.explanation_));
  }
}

void to_json(JsonValueScope &jv, const td_api::JsonValue &object) {
  td_api::downcast_call(const_cast<td_api::JsonValue &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::jsonValueNull &object) {
  auto jo = jv.enter_object();
  jo("@type", "jsonValueNull");
}

void to_json(JsonValueScope &jv, const td_api::jsonValueBoolean &object) {
  auto jo = jv.enter_object();
  jo("@type", "jsonValueBoolean");
  jo("value", JsonBool{object.value_});
}

void to_json(JsonValueScope &jv, const td_api::jsonValueNumber &object) {
  auto jo = jv.enter_object();
  jo("@type", "jsonValueNumber");
  jo("value", object.value_);
}

void to_json(JsonValueScope &jv, const td_api::jsonValueString &object) {
  auto jo = jv.enter_object();
  jo("@type", "jsonValueString");
  jo("value", object.value_);
}

void to_json(JsonValueScope &jv, const td_api::jsonValueArray &object) {
  auto jo = jv.enter_object();
  jo("@type", "jsonValueArray");
  jo("values", ToJson(object.values_));
}

void to_json(JsonValueScope &jv, const td_api::jsonValueObject &object) {
  auto jo = jv.enter_object();
  jo("@type", "jsonValueObject");
  jo("members", ToJson(object.members_));
}

void to_json(JsonValueScope &jv, const td_api::LinkPreviewAlbumMedia &object) {
  td_api::downcast_call(const_cast<td_api::LinkPreviewAlbumMedia &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewAlbumMediaPhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewAlbumMediaPhoto");
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewAlbumMediaVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewAlbumMediaVideo");
  if (object.video_) {
    jo("video", ToJson(*object.video_));
  }
}

void to_json(JsonValueScope &jv, const td_api::logTags &object) {
  auto jo = jv.enter_object();
  jo("@type", "logTags");
  jo("tags", ToJson(object.tags_));
}

void to_json(JsonValueScope &jv, const td_api::messageCalendarDay &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageCalendarDay");
  jo("total_count", object.total_count_);
  if (object.message_) {
    jo("message", ToJson(*object.message_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageLink &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageLink");
  jo("link", object.link_);
  jo("is_public", JsonBool{object.is_public_});
}

void to_json(JsonValueScope &jv, const td_api::messageReplyInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageReplyInfo");
  jo("reply_count", object.reply_count_);
  jo("recent_replier_ids", ToJson(object.recent_replier_ids_));
  jo("last_read_inbox_message_id", object.last_read_inbox_message_id_);
  jo("last_read_outbox_message_id", object.last_read_outbox_message_id_);
  jo("last_message_id", object.last_message_id_);
}

void to_json(JsonValueScope &jv, const td_api::MessageTopic &object) {
  td_api::downcast_call(const_cast<td_api::MessageTopic &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::messageTopicThread &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageTopicThread");
  jo("message_thread_id", object.message_thread_id_);
}

void to_json(JsonValueScope &jv, const td_api::messageTopicForum &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageTopicForum");
  jo("forum_topic_id", object.forum_topic_id_);
}

void to_json(JsonValueScope &jv, const td_api::messageTopicDirectMessages &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageTopicDirectMessages");
  jo("direct_messages_chat_topic_id", object.direct_messages_chat_topic_id_);
}

void to_json(JsonValueScope &jv, const td_api::messageTopicSavedMessages &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageTopicSavedMessages");
  jo("saved_messages_topic_id", object.saved_messages_topic_id_);
}

void to_json(JsonValueScope &jv, const td_api::notification &object) {
  auto jo = jv.enter_object();
  jo("@type", "notification");
  jo("id", object.id_);
  jo("date", object.date_);
  jo("is_silent", JsonBool{object.is_silent_});
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::OptionValue &object) {
  td_api::downcast_call(const_cast<td_api::OptionValue &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::optionValueBoolean &object) {
  auto jo = jv.enter_object();
  jo("@type", "optionValueBoolean");
  jo("value", JsonBool{object.value_});
}

void to_json(JsonValueScope &jv, const td_api::optionValueEmpty &object) {
  auto jo = jv.enter_object();
  jo("@type", "optionValueEmpty");
}

void to_json(JsonValueScope &jv, const td_api::optionValueInteger &object) {
  auto jo = jv.enter_object();
  jo("@type", "optionValueInteger");
  jo("value", ToJson(JsonInt64{object.value_}));
}

void to_json(JsonValueScope &jv, const td_api::optionValueString &object) {
  auto jo = jv.enter_object();
  jo("@type", "optionValueString");
  jo("value", object.value_);
}

void to_json(JsonValueScope &jv, const td_api::PageBlockVerticalAlignment &object) {
  td_api::downcast_call(const_cast<td_api::PageBlockVerticalAlignment &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::pageBlockVerticalAlignmentTop &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockVerticalAlignmentTop");
}

void to_json(JsonValueScope &jv, const td_api::pageBlockVerticalAlignmentMiddle &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockVerticalAlignmentMiddle");
}

void to_json(JsonValueScope &jv, const td_api::pageBlockVerticalAlignmentBottom &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockVerticalAlignmentBottom");
}

void to_json(JsonValueScope &jv, const td_api::PassportElementErrorSource &object) {
  td_api::downcast_call(const_cast<td_api::PassportElementErrorSource &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::passportElementErrorSourceUnspecified &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementErrorSourceUnspecified");
}

void to_json(JsonValueScope &jv, const td_api::passportElementErrorSourceDataField &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementErrorSourceDataField");
  jo("field_name", object.field_name_);
}

void to_json(JsonValueScope &jv, const td_api::passportElementErrorSourceFrontSide &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementErrorSourceFrontSide");
}

void to_json(JsonValueScope &jv, const td_api::passportElementErrorSourceReverseSide &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementErrorSourceReverseSide");
}

void to_json(JsonValueScope &jv, const td_api::passportElementErrorSourceSelfie &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementErrorSourceSelfie");
}

void to_json(JsonValueScope &jv, const td_api::passportElementErrorSourceTranslationFile &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementErrorSourceTranslationFile");
  jo("file_index", object.file_index_);
}

void to_json(JsonValueScope &jv, const td_api::passportElementErrorSourceTranslationFiles &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementErrorSourceTranslationFiles");
}

void to_json(JsonValueScope &jv, const td_api::passportElementErrorSourceFile &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementErrorSourceFile");
  jo("file_index", object.file_index_);
}

void to_json(JsonValueScope &jv, const td_api::passportElementErrorSourceFiles &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementErrorSourceFiles");
}

void to_json(JsonValueScope &jv, const td_api::paymentOption &object) {
  auto jo = jv.enter_object();
  jo("@type", "paymentOption");
  jo("title", object.title_);
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::photoSize &object) {
  auto jo = jv.enter_object();
  jo("@type", "photoSize");
  jo("type", object.type_);
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  jo("width", object.width_);
  jo("height", object.height_);
  jo("progressive_sizes", ToJson(object.progressive_sizes_));
}

void to_json(JsonValueScope &jv, const td_api::premiumFeaturePromotionAnimation &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeaturePromotionAnimation");
  if (object.feature_) {
    jo("feature", ToJson(*object.feature_));
  }
  if (object.animation_) {
    jo("animation", ToJson(*object.animation_));
  }
}

void to_json(JsonValueScope &jv, const td_api::premiumPaymentOption &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumPaymentOption");
  jo("currency", object.currency_);
  jo("amount", object.amount_);
  jo("discount_percentage", object.discount_percentage_);
  jo("month_count", object.month_count_);
  jo("store_product_id", object.store_product_id_);
  if (object.payment_link_) {
    jo("payment_link", ToJson(*object.payment_link_));
  }
}

void to_json(JsonValueScope &jv, const td_api::profilePhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "profilePhoto");
  jo("id", ToJson(JsonInt64{object.id_}));
  if (object.small_) {
    jo("small", ToJson(*object.small_));
  }
  if (object.big_) {
    jo("big", ToJson(*object.big_));
  }
  if (object.minithumbnail_) {
    jo("minithumbnail", ToJson(*object.minithumbnail_));
  }
  jo("has_animation", JsonBool{object.has_animation_});
  jo("is_personal", JsonBool{object.is_personal_});
}

void to_json(JsonValueScope &jv, const td_api::quickReplyMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "quickReplyMessage");
  jo("id", object.id_);
  if (object.sending_state_) {
    jo("sending_state", ToJson(*object.sending_state_));
  }
  jo("can_be_edited", JsonBool{object.can_be_edited_});
  jo("reply_to_message_id", object.reply_to_message_id_);
  jo("via_bot_user_id", object.via_bot_user_id_);
  jo("media_album_id", ToJson(JsonInt64{object.media_album_id_}));
  if (object.content_) {
    jo("content", ToJson(*object.content_));
  }
  if (object.reply_markup_) {
    jo("reply_markup", ToJson(*object.reply_markup_));
  }
}

void to_json(JsonValueScope &jv, const td_api::receivedGifts &object) {
  auto jo = jv.enter_object();
  jo("@type", "receivedGifts");
  jo("total_count", object.total_count_);
  jo("gifts", ToJson(object.gifts_));
  jo("are_notifications_enabled", JsonBool{object.are_notifications_enabled_});
  jo("next_offset", object.next_offset_);
}

void to_json(JsonValueScope &jv, const td_api::ReportStoryResult &object) {
  td_api::downcast_call(const_cast<td_api::ReportStoryResult &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::reportStoryResultOk &object) {
  auto jo = jv.enter_object();
  jo("@type", "reportStoryResultOk");
}

void to_json(JsonValueScope &jv, const td_api::reportStoryResultOptionRequired &object) {
  auto jo = jv.enter_object();
  jo("@type", "reportStoryResultOptionRequired");
  jo("title", object.title_);
  jo("options", ToJson(object.options_));
}

void to_json(JsonValueScope &jv, const td_api::reportStoryResultTextRequired &object) {
  auto jo = jv.enter_object();
  jo("@type", "reportStoryResultTextRequired");
  jo("option_id", base64_encode(object.option_id_));
  jo("is_optional", JsonBool{object.is_optional_});
}

void to_json(JsonValueScope &jv, const td_api::savedMessagesTopic &object) {
  auto jo = jv.enter_object();
  jo("@type", "savedMessagesTopic");
  jo("id", object.id_);
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  jo("is_pinned", JsonBool{object.is_pinned_});
  jo("order", ToJson(JsonInt64{object.order_}));
  if (object.last_message_) {
    jo("last_message", ToJson(*object.last_message_));
  }
  if (object.draft_message_) {
    jo("draft_message", ToJson(*object.draft_message_));
  }
}

void to_json(JsonValueScope &jv, const td_api::session &object) {
  auto jo = jv.enter_object();
  jo("@type", "session");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("is_current", JsonBool{object.is_current_});
  jo("is_password_pending", JsonBool{object.is_password_pending_});
  jo("is_unconfirmed", JsonBool{object.is_unconfirmed_});
  jo("can_accept_secret_chats", JsonBool{object.can_accept_secret_chats_});
  jo("can_accept_calls", JsonBool{object.can_accept_calls_});
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  jo("api_id", object.api_id_);
  jo("application_name", object.application_name_);
  jo("application_version", object.application_version_);
  jo("is_official_application", JsonBool{object.is_official_application_});
  jo("device_model", object.device_model_);
  jo("platform", object.platform_);
  jo("system_version", object.system_version_);
  jo("log_in_date", object.log_in_date_);
  jo("last_active_date", object.last_active_date_);
  jo("ip_address", object.ip_address_);
  jo("location", object.location_);
}

void to_json(JsonValueScope &jv, const td_api::sponsoredChats &object) {
  auto jo = jv.enter_object();
  jo("@type", "sponsoredChats");
  jo("chats", ToJson(object.chats_));
}

void to_json(JsonValueScope &jv, const td_api::starPaymentOption &object) {
  auto jo = jv.enter_object();
  jo("@type", "starPaymentOption");
  jo("currency", object.currency_);
  jo("amount", object.amount_);
  jo("star_count", object.star_count_);
  jo("store_product_id", object.store_product_id_);
  jo("is_additional", JsonBool{object.is_additional_});
}

void to_json(JsonValueScope &jv, const td_api::StarTransactionType &object) {
  td_api::downcast_call(const_cast<td_api::StarTransactionType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypePremiumBotDeposit &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypePremiumBotDeposit");
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeAppStoreDeposit &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeAppStoreDeposit");
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeGooglePlayDeposit &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeGooglePlayDeposit");
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeFragmentDeposit &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeFragmentDeposit");
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeUserDeposit &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeUserDeposit");
  jo("user_id", object.user_id_);
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeGiveawayDeposit &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeGiveawayDeposit");
  jo("chat_id", object.chat_id_);
  jo("giveaway_message_id", object.giveaway_message_id_);
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeFragmentWithdrawal &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeFragmentWithdrawal");
  if (object.withdrawal_state_) {
    jo("withdrawal_state", ToJson(*object.withdrawal_state_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeTelegramAdsWithdrawal &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeTelegramAdsWithdrawal");
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeTelegramApiUsage &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeTelegramApiUsage");
  jo("request_count", object.request_count_);
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeBotPaidMediaPurchase &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeBotPaidMediaPurchase");
  jo("user_id", object.user_id_);
  jo("media", ToJson(object.media_));
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeBotPaidMediaSale &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeBotPaidMediaSale");
  jo("user_id", object.user_id_);
  jo("media", ToJson(object.media_));
  jo("payload", object.payload_);
  if (object.affiliate_) {
    jo("affiliate", ToJson(*object.affiliate_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeChannelPaidMediaPurchase &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeChannelPaidMediaPurchase");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
  jo("media", ToJson(object.media_));
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeChannelPaidMediaSale &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeChannelPaidMediaSale");
  jo("user_id", object.user_id_);
  jo("message_id", object.message_id_);
  jo("media", ToJson(object.media_));
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeBotInvoicePurchase &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeBotInvoicePurchase");
  jo("user_id", object.user_id_);
  if (object.product_info_) {
    jo("product_info", ToJson(*object.product_info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeBotInvoiceSale &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeBotInvoiceSale");
  jo("user_id", object.user_id_);
  if (object.product_info_) {
    jo("product_info", ToJson(*object.product_info_));
  }
  jo("invoice_payload", base64_encode(object.invoice_payload_));
  if (object.affiliate_) {
    jo("affiliate", ToJson(*object.affiliate_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeBotSubscriptionPurchase &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeBotSubscriptionPurchase");
  jo("user_id", object.user_id_);
  jo("subscription_period", object.subscription_period_);
  if (object.product_info_) {
    jo("product_info", ToJson(*object.product_info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeBotSubscriptionSale &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeBotSubscriptionSale");
  jo("user_id", object.user_id_);
  jo("subscription_period", object.subscription_period_);
  if (object.product_info_) {
    jo("product_info", ToJson(*object.product_info_));
  }
  jo("invoice_payload", base64_encode(object.invoice_payload_));
  if (object.affiliate_) {
    jo("affiliate", ToJson(*object.affiliate_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeChannelSubscriptionPurchase &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeChannelSubscriptionPurchase");
  jo("chat_id", object.chat_id_);
  jo("subscription_period", object.subscription_period_);
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeChannelSubscriptionSale &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeChannelSubscriptionSale");
  jo("user_id", object.user_id_);
  jo("subscription_period", object.subscription_period_);
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeGiftAuctionBid &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeGiftAuctionBid");
  if (object.owner_id_) {
    jo("owner_id", ToJson(*object.owner_id_));
  }
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeGiftPurchase &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeGiftPurchase");
  if (object.owner_id_) {
    jo("owner_id", ToJson(*object.owner_id_));
  }
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeGiftPurchaseOffer &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeGiftPurchaseOffer");
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeGiftTransfer &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeGiftTransfer");
  if (object.owner_id_) {
    jo("owner_id", ToJson(*object.owner_id_));
  }
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeGiftOriginalDetailsDrop &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeGiftOriginalDetailsDrop");
  if (object.owner_id_) {
    jo("owner_id", ToJson(*object.owner_id_));
  }
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeGiftSale &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeGiftSale");
  jo("user_id", object.user_id_);
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeGiftUpgrade &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeGiftUpgrade");
  jo("user_id", object.user_id_);
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeGiftUpgradePurchase &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeGiftUpgradePurchase");
  if (object.owner_id_) {
    jo("owner_id", ToJson(*object.owner_id_));
  }
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeUpgradedGiftPurchase &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeUpgradedGiftPurchase");
  jo("user_id", object.user_id_);
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeUpgradedGiftSale &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeUpgradedGiftSale");
  jo("user_id", object.user_id_);
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
  jo("commission_per_mille", object.commission_per_mille_);
  if (object.commission_star_amount_) {
    jo("commission_star_amount", ToJson(*object.commission_star_amount_));
  }
  jo("via_offer", JsonBool{object.via_offer_});
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeChannelPaidReactionSend &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeChannelPaidReactionSend");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeChannelPaidReactionReceive &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeChannelPaidReactionReceive");
  jo("user_id", object.user_id_);
  jo("message_id", object.message_id_);
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeAffiliateProgramCommission &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeAffiliateProgramCommission");
  jo("chat_id", object.chat_id_);
  jo("commission_per_mille", object.commission_per_mille_);
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypePaidMessageSend &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypePaidMessageSend");
  jo("chat_id", object.chat_id_);
  jo("message_count", object.message_count_);
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypePaidMessageReceive &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypePaidMessageReceive");
  if (object.sender_id_) {
    jo("sender_id", ToJson(*object.sender_id_));
  }
  jo("message_count", object.message_count_);
  jo("commission_per_mille", object.commission_per_mille_);
  if (object.commission_star_amount_) {
    jo("commission_star_amount", ToJson(*object.commission_star_amount_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypePaidGroupCallMessageSend &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypePaidGroupCallMessageSend");
  jo("chat_id", object.chat_id_);
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypePaidGroupCallMessageReceive &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypePaidGroupCallMessageReceive");
  if (object.sender_id_) {
    jo("sender_id", ToJson(*object.sender_id_));
  }
  jo("commission_per_mille", object.commission_per_mille_);
  if (object.commission_star_amount_) {
    jo("commission_star_amount", ToJson(*object.commission_star_amount_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypePaidGroupCallReactionSend &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypePaidGroupCallReactionSend");
  jo("chat_id", object.chat_id_);
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypePaidGroupCallReactionReceive &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypePaidGroupCallReactionReceive");
  if (object.sender_id_) {
    jo("sender_id", ToJson(*object.sender_id_));
  }
  jo("commission_per_mille", object.commission_per_mille_);
  if (object.commission_star_amount_) {
    jo("commission_star_amount", ToJson(*object.commission_star_amount_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeSuggestedPostPaymentSend &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeSuggestedPostPaymentSend");
  jo("chat_id", object.chat_id_);
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeSuggestedPostPaymentReceive &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeSuggestedPostPaymentReceive");
  jo("user_id", object.user_id_);
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypePremiumPurchase &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypePremiumPurchase");
  jo("user_id", object.user_id_);
  jo("month_count", object.month_count_);
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeBusinessBotTransferSend &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeBusinessBotTransferSend");
  jo("user_id", object.user_id_);
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeBusinessBotTransferReceive &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeBusinessBotTransferReceive");
  jo("user_id", object.user_id_);
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypePublicPostSearch &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypePublicPostSearch");
}

void to_json(JsonValueScope &jv, const td_api::starTransactionTypeUnsupported &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactionTypeUnsupported");
}

void to_json(JsonValueScope &jv, const td_api::stickerSetInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "stickerSetInfo");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("title", object.title_);
  jo("name", object.name_);
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
  if (object.thumbnail_outline_) {
    jo("thumbnail_outline", ToJson(*object.thumbnail_outline_));
  }
  jo("is_owned", JsonBool{object.is_owned_});
  jo("is_installed", JsonBool{object.is_installed_});
  jo("is_archived", JsonBool{object.is_archived_});
  jo("is_official", JsonBool{object.is_official_});
  if (object.sticker_type_) {
    jo("sticker_type", ToJson(*object.sticker_type_));
  }
  jo("needs_repainting", JsonBool{object.needs_repainting_});
  jo("is_allowed_as_chat_emoji_status", JsonBool{object.is_allowed_as_chat_emoji_status_});
  jo("is_viewed", JsonBool{object.is_viewed_});
  jo("size", object.size_);
  jo("covers", ToJson(object.covers_));
}

void to_json(JsonValueScope &jv, const td_api::story &object) {
  auto jo = jv.enter_object();
  jo("@type", "story");
  jo("id", object.id_);
  jo("poster_chat_id", object.poster_chat_id_);
  if (object.poster_id_) {
    jo("poster_id", ToJson(*object.poster_id_));
  }
  jo("date", object.date_);
  jo("is_being_posted", JsonBool{object.is_being_posted_});
  jo("is_being_edited", JsonBool{object.is_being_edited_});
  jo("is_edited", JsonBool{object.is_edited_});
  jo("is_posted_to_chat_page", JsonBool{object.is_posted_to_chat_page_});
  jo("is_visible_only_for_self", JsonBool{object.is_visible_only_for_self_});
  jo("can_be_added_to_album", JsonBool{object.can_be_added_to_album_});
  jo("can_be_deleted", JsonBool{object.can_be_deleted_});
  jo("can_be_edited", JsonBool{object.can_be_edited_});
  jo("can_be_forwarded", JsonBool{object.can_be_forwarded_});
  jo("can_be_replied", JsonBool{object.can_be_replied_});
  jo("can_set_privacy_settings", JsonBool{object.can_set_privacy_settings_});
  jo("can_toggle_is_posted_to_chat_page", JsonBool{object.can_toggle_is_posted_to_chat_page_});
  jo("can_get_statistics", JsonBool{object.can_get_statistics_});
  jo("can_get_interactions", JsonBool{object.can_get_interactions_});
  jo("has_expired_viewers", JsonBool{object.has_expired_viewers_});
  if (object.repost_info_) {
    jo("repost_info", ToJson(*object.repost_info_));
  }
  if (object.interaction_info_) {
    jo("interaction_info", ToJson(*object.interaction_info_));
  }
  if (object.chosen_reaction_type_) {
    jo("chosen_reaction_type", ToJson(*object.chosen_reaction_type_));
  }
  if (object.privacy_settings_) {
    jo("privacy_settings", ToJson(*object.privacy_settings_));
  }
  if (object.content_) {
    jo("content", ToJson(*object.content_));
  }
  jo("areas", ToJson(object.areas_));
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
  jo("album_ids", ToJson(object.album_ids_));
}

void to_json(JsonValueScope &jv, const td_api::storyInteraction &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyInteraction");
  if (object.actor_id_) {
    jo("actor_id", ToJson(*object.actor_id_));
  }
  jo("interaction_date", object.interaction_date_);
  if (object.block_list_) {
    jo("block_list", ToJson(*object.block_list_));
  }
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::storyVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyVideo");
  jo("duration", object.duration_);
  jo("width", object.width_);
  jo("height", object.height_);
  jo("has_stickers", JsonBool{object.has_stickers_});
  jo("is_animation", JsonBool{object.is_animation_});
  if (object.minithumbnail_) {
    jo("minithumbnail", ToJson(*object.minithumbnail_));
  }
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
  jo("preload_prefix_size", object.preload_prefix_size_);
  jo("cover_frame_timestamp", object.cover_frame_timestamp_);
  if (object.video_) {
    jo("video", ToJson(*object.video_));
  }
}

void to_json(JsonValueScope &jv, const td_api::TMeUrlType &object) {
  td_api::downcast_call(const_cast<td_api::TMeUrlType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::tMeUrlTypeUser &object) {
  auto jo = jv.enter_object();
  jo("@type", "tMeUrlTypeUser");
  jo("user_id", object.user_id_);
}

void to_json(JsonValueScope &jv, const td_api::tMeUrlTypeSupergroup &object) {
  auto jo = jv.enter_object();
  jo("@type", "tMeUrlTypeSupergroup");
  jo("supergroup_id", object.supergroup_id_);
}

void to_json(JsonValueScope &jv, const td_api::tMeUrlTypeChatInvite &object) {
  auto jo = jv.enter_object();
  jo("@type", "tMeUrlTypeChatInvite");
  if (object.info_) {
    jo("info", ToJson(*object.info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::tMeUrlTypeStickerSet &object) {
  auto jo = jv.enter_object();
  jo("@type", "tMeUrlTypeStickerSet");
  jo("sticker_set_id", ToJson(JsonInt64{object.sticker_set_id_}));
}

void to_json(JsonValueScope &jv, const td_api::testVectorInt &object) {
  auto jo = jv.enter_object();
  jo("@type", "testVectorInt");
  jo("value", ToJson(object.value_));
}

void to_json(JsonValueScope &jv, const td_api::textQuote &object) {
  auto jo = jv.enter_object();
  jo("@type", "textQuote");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("position", object.position_);
  jo("is_manual", JsonBool{object.is_manual_});
}

void to_json(JsonValueScope &jv, const td_api::TonTransactionType &object) {
  td_api::downcast_call(const_cast<td_api::TonTransactionType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::tonTransactionTypeFragmentDeposit &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonTransactionTypeFragmentDeposit");
  jo("is_gift", JsonBool{object.is_gift_});
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
}

void to_json(JsonValueScope &jv, const td_api::tonTransactionTypeFragmentWithdrawal &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonTransactionTypeFragmentWithdrawal");
  if (object.withdrawal_state_) {
    jo("withdrawal_state", ToJson(*object.withdrawal_state_));
  }
}

void to_json(JsonValueScope &jv, const td_api::tonTransactionTypeSuggestedPostPayment &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonTransactionTypeSuggestedPostPayment");
  jo("chat_id", object.chat_id_);
}

void to_json(JsonValueScope &jv, const td_api::tonTransactionTypeGiftPurchaseOffer &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonTransactionTypeGiftPurchaseOffer");
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
}

void to_json(JsonValueScope &jv, const td_api::tonTransactionTypeUpgradedGiftPurchase &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonTransactionTypeUpgradedGiftPurchase");
  jo("user_id", object.user_id_);
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
}

void to_json(JsonValueScope &jv, const td_api::tonTransactionTypeUpgradedGiftSale &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonTransactionTypeUpgradedGiftSale");
  jo("user_id", object.user_id_);
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
  jo("commission_per_mille", object.commission_per_mille_);
  jo("commission_toncoin_amount", object.commission_toncoin_amount_);
  jo("via_offer", JsonBool{object.via_offer_});
}

void to_json(JsonValueScope &jv, const td_api::tonTransactionTypeStakeDiceStake &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonTransactionTypeStakeDiceStake");
}

void to_json(JsonValueScope &jv, const td_api::tonTransactionTypeStakeDicePayout &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonTransactionTypeStakeDicePayout");
}

void to_json(JsonValueScope &jv, const td_api::tonTransactionTypeUnsupported &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonTransactionTypeUnsupported");
}

void to_json(JsonValueScope &jv, const td_api::UpgradedGiftAttributeRarity &object) {
  td_api::downcast_call(const_cast<td_api::UpgradedGiftAttributeRarity &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftAttributeRarityPerMille &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftAttributeRarityPerMille");
  jo("per_mille", object.per_mille_);
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftAttributeRarityUncommon &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftAttributeRarityUncommon");
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftAttributeRarityRare &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftAttributeRarityRare");
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftAttributeRarityEpic &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftAttributeRarityEpic");
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftAttributeRarityLegendary &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftAttributeRarityLegendary");
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftSymbol &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftSymbol");
  jo("name", object.name_);
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
  if (object.rarity_) {
    jo("rarity", ToJson(*object.rarity_));
  }
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingRules &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingRules");
  jo("rules", ToJson(object.rules_));
}

void to_json(JsonValueScope &jv, const td_api::venue &object) {
  auto jo = jv.enter_object();
  jo("@type", "venue");
  if (object.location_) {
    jo("location", ToJson(*object.location_));
  }
  jo("title", object.title_);
  jo("address", object.address_);
  jo("provider", object.provider_);
  jo("id", object.id_);
  jo("type", object.type_);
}

void to_json(JsonValueScope &jv, const td_api::webApp &object) {
  auto jo = jv.enter_object();
  jo("@type", "webApp");
  jo("short_name", object.short_name_);
  jo("title", object.title_);
  jo("description", object.description_);
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  if (object.animation_) {
    jo("animation", ToJson(*object.animation_));
  }
}

}  // namespace td_api
}  // namespace td
