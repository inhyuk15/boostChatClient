// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: chat.proto

#include "chat.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace chat {
PROTOBUF_CONSTEXPR ChatMessage::ChatMessage(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.user_name_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.file_extension_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.timestamp_)*/0u
  , /*decltype(_impl_.data_type_)*/0
  , /*decltype(_impl_.system_code_)*/0
  , /*decltype(_impl_.content_)*/{}
  , /*decltype(_impl_._cached_size_)*/{}
  , /*decltype(_impl_._oneof_case_)*/{}} {}
struct ChatMessageDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ChatMessageDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ChatMessageDefaultTypeInternal() {}
  union {
    ChatMessage _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ChatMessageDefaultTypeInternal _ChatMessage_default_instance_;
}  // namespace chat
static ::_pb::Metadata file_level_metadata_chat_2eproto[1];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_chat_2eproto[2];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_chat_2eproto = nullptr;

const uint32_t TableStruct_chat_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::chat::ChatMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  PROTOBUF_FIELD_OFFSET(::chat::ChatMessage, _impl_._oneof_case_[0]),
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::chat::ChatMessage, _impl_.user_name_),
  PROTOBUF_FIELD_OFFSET(::chat::ChatMessage, _impl_.timestamp_),
  PROTOBUF_FIELD_OFFSET(::chat::ChatMessage, _impl_.data_type_),
  ::_pbi::kInvalidFieldOffsetTag,
  ::_pbi::kInvalidFieldOffsetTag,
  PROTOBUF_FIELD_OFFSET(::chat::ChatMessage, _impl_.system_code_),
  PROTOBUF_FIELD_OFFSET(::chat::ChatMessage, _impl_.file_extension_),
  PROTOBUF_FIELD_OFFSET(::chat::ChatMessage, _impl_.content_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::chat::ChatMessage)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::chat::_ChatMessage_default_instance_._instance,
};

const char descriptor_table_protodef_chat_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\nchat.proto\022\004chat\"\316\001\n\013ChatMessage\022\021\n\tus"
  "er_name\030\001 \001(\t\022\021\n\ttimestamp\030\002 \001(\r\022!\n\tdata"
  "_type\030\003 \001(\0162\016.chat.DataType\022\026\n\014message_t"
  "ext\030\004 \001(\tH\000\022\024\n\nimage_data\030\005 \001(\014H\000\022%\n\013sys"
  "tem_code\030\006 \001(\0162\020.chat.SystemCode\022\026\n\016file"
  "_extension\030\007 \001(\tB\t\n\007content*+\n\010DataType\022"
  "\010\n\004TEXT\020\000\022\t\n\005IMAGE\020\001\022\n\n\006SYSTEM\020\002*#\n\nSyst"
  "emCode\022\010\n\004NONE\020\000\022\013\n\007TIMEOUT\020\001b\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_chat_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_chat_2eproto = {
    false, false, 317, descriptor_table_protodef_chat_2eproto,
    "chat.proto",
    &descriptor_table_chat_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_chat_2eproto::offsets,
    file_level_metadata_chat_2eproto, file_level_enum_descriptors_chat_2eproto,
    file_level_service_descriptors_chat_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_chat_2eproto_getter() {
  return &descriptor_table_chat_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_chat_2eproto(&descriptor_table_chat_2eproto);
namespace chat {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* DataType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_chat_2eproto);
  return file_level_enum_descriptors_chat_2eproto[0];
}
bool DataType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* SystemCode_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_chat_2eproto);
  return file_level_enum_descriptors_chat_2eproto[1];
}
bool SystemCode_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}


// ===================================================================

class ChatMessage::_Internal {
 public:
};

ChatMessage::ChatMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:chat.ChatMessage)
}
ChatMessage::ChatMessage(const ChatMessage& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  ChatMessage* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.user_name_){}
    , decltype(_impl_.file_extension_){}
    , decltype(_impl_.timestamp_){}
    , decltype(_impl_.data_type_){}
    , decltype(_impl_.system_code_){}
    , decltype(_impl_.content_){}
    , /*decltype(_impl_._cached_size_)*/{}
    , /*decltype(_impl_._oneof_case_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.user_name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.user_name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_user_name().empty()) {
    _this->_impl_.user_name_.Set(from._internal_user_name(), 
      _this->GetArenaForAllocation());
  }
  _impl_.file_extension_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.file_extension_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_file_extension().empty()) {
    _this->_impl_.file_extension_.Set(from._internal_file_extension(), 
      _this->GetArenaForAllocation());
  }
  ::memcpy(&_impl_.timestamp_, &from._impl_.timestamp_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.system_code_) -
    reinterpret_cast<char*>(&_impl_.timestamp_)) + sizeof(_impl_.system_code_));
  clear_has_content();
  switch (from.content_case()) {
    case kMessageText: {
      _this->_internal_set_message_text(from._internal_message_text());
      break;
    }
    case kImageData: {
      _this->_internal_set_image_data(from._internal_image_data());
      break;
    }
    case CONTENT_NOT_SET: {
      break;
    }
  }
  // @@protoc_insertion_point(copy_constructor:chat.ChatMessage)
}

inline void ChatMessage::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.user_name_){}
    , decltype(_impl_.file_extension_){}
    , decltype(_impl_.timestamp_){0u}
    , decltype(_impl_.data_type_){0}
    , decltype(_impl_.system_code_){0}
    , decltype(_impl_.content_){}
    , /*decltype(_impl_._cached_size_)*/{}
    , /*decltype(_impl_._oneof_case_)*/{}
  };
  _impl_.user_name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.user_name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.file_extension_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.file_extension_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  clear_has_content();
}

ChatMessage::~ChatMessage() {
  // @@protoc_insertion_point(destructor:chat.ChatMessage)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ChatMessage::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.user_name_.Destroy();
  _impl_.file_extension_.Destroy();
  if (has_content()) {
    clear_content();
  }
}

void ChatMessage::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void ChatMessage::clear_content() {
// @@protoc_insertion_point(one_of_clear_start:chat.ChatMessage)
  switch (content_case()) {
    case kMessageText: {
      _impl_.content_.message_text_.Destroy();
      break;
    }
    case kImageData: {
      _impl_.content_.image_data_.Destroy();
      break;
    }
    case CONTENT_NOT_SET: {
      break;
    }
  }
  _impl_._oneof_case_[0] = CONTENT_NOT_SET;
}


void ChatMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:chat.ChatMessage)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.user_name_.ClearToEmpty();
  _impl_.file_extension_.ClearToEmpty();
  ::memset(&_impl_.timestamp_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.system_code_) -
      reinterpret_cast<char*>(&_impl_.timestamp_)) + sizeof(_impl_.system_code_));
  clear_content();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ChatMessage::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string user_name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_user_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "chat.ChatMessage.user_name"));
        } else
          goto handle_unusual;
        continue;
      // uint32 timestamp = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _impl_.timestamp_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .chat.DataType data_type = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_data_type(static_cast<::chat::DataType>(val));
        } else
          goto handle_unusual;
        continue;
      // string message_text = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          auto str = _internal_mutable_message_text();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "chat.ChatMessage.message_text"));
        } else
          goto handle_unusual;
        continue;
      // bytes image_data = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 42)) {
          auto str = _internal_mutable_image_data();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .chat.SystemCode system_code = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 48)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_system_code(static_cast<::chat::SystemCode>(val));
        } else
          goto handle_unusual;
        continue;
      // string file_extension = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 58)) {
          auto str = _internal_mutable_file_extension();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "chat.ChatMessage.file_extension"));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* ChatMessage::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:chat.ChatMessage)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string user_name = 1;
  if (!this->_internal_user_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_user_name().data(), static_cast<int>(this->_internal_user_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "chat.ChatMessage.user_name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_user_name(), target);
  }

  // uint32 timestamp = 2;
  if (this->_internal_timestamp() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(2, this->_internal_timestamp(), target);
  }

  // .chat.DataType data_type = 3;
  if (this->_internal_data_type() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      3, this->_internal_data_type(), target);
  }

  // string message_text = 4;
  if (_internal_has_message_text()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_message_text().data(), static_cast<int>(this->_internal_message_text().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "chat.ChatMessage.message_text");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_message_text(), target);
  }

  // bytes image_data = 5;
  if (_internal_has_image_data()) {
    target = stream->WriteBytesMaybeAliased(
        5, this->_internal_image_data(), target);
  }

  // .chat.SystemCode system_code = 6;
  if (this->_internal_system_code() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      6, this->_internal_system_code(), target);
  }

  // string file_extension = 7;
  if (!this->_internal_file_extension().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_file_extension().data(), static_cast<int>(this->_internal_file_extension().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "chat.ChatMessage.file_extension");
    target = stream->WriteStringMaybeAliased(
        7, this->_internal_file_extension(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:chat.ChatMessage)
  return target;
}

size_t ChatMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:chat.ChatMessage)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string user_name = 1;
  if (!this->_internal_user_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_user_name());
  }

  // string file_extension = 7;
  if (!this->_internal_file_extension().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_file_extension());
  }

  // uint32 timestamp = 2;
  if (this->_internal_timestamp() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_timestamp());
  }

  // .chat.DataType data_type = 3;
  if (this->_internal_data_type() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_data_type());
  }

  // .chat.SystemCode system_code = 6;
  if (this->_internal_system_code() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_system_code());
  }

  switch (content_case()) {
    // string message_text = 4;
    case kMessageText: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_message_text());
      break;
    }
    // bytes image_data = 5;
    case kImageData: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
          this->_internal_image_data());
      break;
    }
    case CONTENT_NOT_SET: {
      break;
    }
  }
  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ChatMessage::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    ChatMessage::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ChatMessage::GetClassData() const { return &_class_data_; }


void ChatMessage::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<ChatMessage*>(&to_msg);
  auto& from = static_cast<const ChatMessage&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:chat.ChatMessage)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_user_name().empty()) {
    _this->_internal_set_user_name(from._internal_user_name());
  }
  if (!from._internal_file_extension().empty()) {
    _this->_internal_set_file_extension(from._internal_file_extension());
  }
  if (from._internal_timestamp() != 0) {
    _this->_internal_set_timestamp(from._internal_timestamp());
  }
  if (from._internal_data_type() != 0) {
    _this->_internal_set_data_type(from._internal_data_type());
  }
  if (from._internal_system_code() != 0) {
    _this->_internal_set_system_code(from._internal_system_code());
  }
  switch (from.content_case()) {
    case kMessageText: {
      _this->_internal_set_message_text(from._internal_message_text());
      break;
    }
    case kImageData: {
      _this->_internal_set_image_data(from._internal_image_data());
      break;
    }
    case CONTENT_NOT_SET: {
      break;
    }
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ChatMessage::CopyFrom(const ChatMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:chat.ChatMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChatMessage::IsInitialized() const {
  return true;
}

void ChatMessage::InternalSwap(ChatMessage* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.user_name_, lhs_arena,
      &other->_impl_.user_name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.file_extension_, lhs_arena,
      &other->_impl_.file_extension_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(ChatMessage, _impl_.system_code_)
      + sizeof(ChatMessage::_impl_.system_code_)
      - PROTOBUF_FIELD_OFFSET(ChatMessage, _impl_.timestamp_)>(
          reinterpret_cast<char*>(&_impl_.timestamp_),
          reinterpret_cast<char*>(&other->_impl_.timestamp_));
  swap(_impl_.content_, other->_impl_.content_);
  swap(_impl_._oneof_case_[0], other->_impl_._oneof_case_[0]);
}

::PROTOBUF_NAMESPACE_ID::Metadata ChatMessage::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_chat_2eproto_getter, &descriptor_table_chat_2eproto_once,
      file_level_metadata_chat_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace chat
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::chat::ChatMessage*
Arena::CreateMaybeMessage< ::chat::ChatMessage >(Arena* arena) {
  return Arena::CreateMessageInternal< ::chat::ChatMessage >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
