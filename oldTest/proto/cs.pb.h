// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cs.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_cs_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_cs_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3009000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3009000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_cs_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_cs_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_cs_2eproto;
class Hello;
class HelloDefaultTypeInternal;
extern HelloDefaultTypeInternal _Hello_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::Hello* Arena::CreateMaybeMessage<::Hello>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class Hello :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Hello) */ {
 public:
  Hello();
  virtual ~Hello();

  Hello(const Hello& from);
  Hello(Hello&& from) noexcept
    : Hello() {
    *this = ::std::move(from);
  }

  inline Hello& operator=(const Hello& from) {
    CopyFrom(from);
    return *this;
  }
  inline Hello& operator=(Hello&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Hello& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Hello* internal_default_instance() {
    return reinterpret_cast<const Hello*>(
               &_Hello_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Hello& a, Hello& b) {
    a.Swap(&b);
  }
  inline void Swap(Hello* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Hello* New() const final {
    return CreateMaybeMessage<Hello>(nullptr);
  }

  Hello* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Hello>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Hello& from);
  void MergeFrom(const Hello& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Hello* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Hello";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_cs_2eproto);
    return ::descriptor_table_cs_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kAccNameFieldNumber = 1,
    kPasswdFieldNumber = 2,
  };
  // bytes acc_name = 1;
  void clear_acc_name();
  const std::string& acc_name() const;
  void set_acc_name(const std::string& value);
  void set_acc_name(std::string&& value);
  void set_acc_name(const char* value);
  void set_acc_name(const void* value, size_t size);
  std::string* mutable_acc_name();
  std::string* release_acc_name();
  void set_allocated_acc_name(std::string* acc_name);

  // bytes passwd = 2;
  void clear_passwd();
  const std::string& passwd() const;
  void set_passwd(const std::string& value);
  void set_passwd(std::string&& value);
  void set_passwd(const char* value);
  void set_passwd(const void* value, size_t size);
  std::string* mutable_passwd();
  std::string* release_passwd();
  void set_allocated_passwd(std::string* passwd);

  // @@protoc_insertion_point(class_scope:Hello)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr acc_name_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr passwd_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_cs_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Hello

// bytes acc_name = 1;
inline void Hello::clear_acc_name() {
  acc_name_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& Hello::acc_name() const {
  // @@protoc_insertion_point(field_get:Hello.acc_name)
  return acc_name_.GetNoArena();
}
inline void Hello::set_acc_name(const std::string& value) {
  
  acc_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Hello.acc_name)
}
inline void Hello::set_acc_name(std::string&& value) {
  
  acc_name_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Hello.acc_name)
}
inline void Hello::set_acc_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  acc_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Hello.acc_name)
}
inline void Hello::set_acc_name(const void* value, size_t size) {
  
  acc_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Hello.acc_name)
}
inline std::string* Hello::mutable_acc_name() {
  
  // @@protoc_insertion_point(field_mutable:Hello.acc_name)
  return acc_name_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* Hello::release_acc_name() {
  // @@protoc_insertion_point(field_release:Hello.acc_name)
  
  return acc_name_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void Hello::set_allocated_acc_name(std::string* acc_name) {
  if (acc_name != nullptr) {
    
  } else {
    
  }
  acc_name_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), acc_name);
  // @@protoc_insertion_point(field_set_allocated:Hello.acc_name)
}

// bytes passwd = 2;
inline void Hello::clear_passwd() {
  passwd_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& Hello::passwd() const {
  // @@protoc_insertion_point(field_get:Hello.passwd)
  return passwd_.GetNoArena();
}
inline void Hello::set_passwd(const std::string& value) {
  
  passwd_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Hello.passwd)
}
inline void Hello::set_passwd(std::string&& value) {
  
  passwd_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Hello.passwd)
}
inline void Hello::set_passwd(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  passwd_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Hello.passwd)
}
inline void Hello::set_passwd(const void* value, size_t size) {
  
  passwd_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Hello.passwd)
}
inline std::string* Hello::mutable_passwd() {
  
  // @@protoc_insertion_point(field_mutable:Hello.passwd)
  return passwd_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* Hello::release_passwd() {
  // @@protoc_insertion_point(field_release:Hello.passwd)
  
  return passwd_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void Hello::set_allocated_passwd(std::string* passwd) {
  if (passwd != nullptr) {
    
  } else {
    
  }
  passwd_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), passwd);
  // @@protoc_insertion_point(field_set_allocated:Hello.passwd)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_cs_2eproto
