// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ServerData.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_ServerData_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_ServerData_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4023000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4023004 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_ServerData_2eproto

PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_ServerData_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable
    descriptor_table_ServerData_2eproto;
namespace com {
namespace example {
class Client;
struct ClientDefaultTypeInternal;
extern ClientDefaultTypeInternal _Client_default_instance_;
}  // namespace example
}  // namespace com
PROTOBUF_NAMESPACE_OPEN
template <>
::com::example::Client* Arena::CreateMaybeMessage<::com::example::Client>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

namespace com {
namespace example {

// ===================================================================


// -------------------------------------------------------------------

class Client final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:com.example.Client) */ {
 public:
  inline Client() : Client(nullptr) {}
  ~Client() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR Client(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Client(const Client& from);
  Client(Client&& from) noexcept
    : Client() {
    *this = ::std::move(from);
  }

  inline Client& operator=(const Client& from) {
    CopyFrom(from);
    return *this;
  }
  inline Client& operator=(Client&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Client& default_instance() {
    return *internal_default_instance();
  }
  static inline const Client* internal_default_instance() {
    return reinterpret_cast<const Client*>(
               &_Client_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Client& a, Client& b) {
    a.Swap(&b);
  }
  inline void Swap(Client* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Client* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Client* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Client>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Client& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Client& from) {
    Client::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Client* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "com.example.Client";
  }
  protected:
  explicit Client(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kIdFieldNumber = 1,
    kNameFieldNumber = 2,
    kEmailFieldNumber = 4,
    kAccountBalanceFieldNumber = 3,
  };
  // string id = 1;
  void clear_id() ;
  const std::string& id() const;




  template <typename Arg_ = const std::string&, typename... Args_>
  void set_id(Arg_&& arg, Args_... args);
  std::string* mutable_id();
  PROTOBUF_NODISCARD std::string* release_id();
  void set_allocated_id(std::string* ptr);

  private:
  const std::string& _internal_id() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_id(
      const std::string& value);
  std::string* _internal_mutable_id();

  public:
  // string name = 2;
  void clear_name() ;
  const std::string& name() const;




  template <typename Arg_ = const std::string&, typename... Args_>
  void set_name(Arg_&& arg, Args_... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* ptr);

  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(
      const std::string& value);
  std::string* _internal_mutable_name();

  public:
  // string email = 4;
  void clear_email() ;
  const std::string& email() const;




  template <typename Arg_ = const std::string&, typename... Args_>
  void set_email(Arg_&& arg, Args_... args);
  std::string* mutable_email();
  PROTOBUF_NODISCARD std::string* release_email();
  void set_allocated_email(std::string* ptr);

  private:
  const std::string& _internal_email() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_email(
      const std::string& value);
  std::string* _internal_mutable_email();

  public:
  // int32 account_balance = 3;
  void clear_account_balance() ;
  ::int32_t account_balance() const;
  void set_account_balance(::int32_t value);

  private:
  ::int32_t _internal_account_balance() const;
  void _internal_set_account_balance(::int32_t value);

  public:
  // @@protoc_insertion_point(class_scope:com.example.Client)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr id_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr email_;
    ::int32_t account_balance_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_ServerData_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Client

// string id = 1;
inline void Client::clear_id() {
  _impl_.id_.ClearToEmpty();
}
inline const std::string& Client::id() const {
  // @@protoc_insertion_point(field_get:com.example.Client.id)
  return _internal_id();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Client::set_id(Arg_&& arg,
                                                     Args_... args) {
  ;
  _impl_.id_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:com.example.Client.id)
}
inline std::string* Client::mutable_id() {
  std::string* _s = _internal_mutable_id();
  // @@protoc_insertion_point(field_mutable:com.example.Client.id)
  return _s;
}
inline const std::string& Client::_internal_id() const {
  return _impl_.id_.Get();
}
inline void Client::_internal_set_id(const std::string& value) {
  ;


  _impl_.id_.Set(value, GetArenaForAllocation());
}
inline std::string* Client::_internal_mutable_id() {
  ;
  return _impl_.id_.Mutable( GetArenaForAllocation());
}
inline std::string* Client::release_id() {
  // @@protoc_insertion_point(field_release:com.example.Client.id)
  return _impl_.id_.Release();
}
inline void Client::set_allocated_id(std::string* value) {
  _impl_.id_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.id_.IsDefault()) {
          _impl_.id_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:com.example.Client.id)
}

// string name = 2;
inline void Client::clear_name() {
  _impl_.name_.ClearToEmpty();
}
inline const std::string& Client::name() const {
  // @@protoc_insertion_point(field_get:com.example.Client.name)
  return _internal_name();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Client::set_name(Arg_&& arg,
                                                     Args_... args) {
  ;
  _impl_.name_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:com.example.Client.name)
}
inline std::string* Client::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:com.example.Client.name)
  return _s;
}
inline const std::string& Client::_internal_name() const {
  return _impl_.name_.Get();
}
inline void Client::_internal_set_name(const std::string& value) {
  ;


  _impl_.name_.Set(value, GetArenaForAllocation());
}
inline std::string* Client::_internal_mutable_name() {
  ;
  return _impl_.name_.Mutable( GetArenaForAllocation());
}
inline std::string* Client::release_name() {
  // @@protoc_insertion_point(field_release:com.example.Client.name)
  return _impl_.name_.Release();
}
inline void Client::set_allocated_name(std::string* value) {
  _impl_.name_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.name_.IsDefault()) {
          _impl_.name_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:com.example.Client.name)
}

// int32 account_balance = 3;
inline void Client::clear_account_balance() {
  _impl_.account_balance_ = 0;
}
inline ::int32_t Client::account_balance() const {
  // @@protoc_insertion_point(field_get:com.example.Client.account_balance)
  return _internal_account_balance();
}
inline void Client::set_account_balance(::int32_t value) {
  _internal_set_account_balance(value);
  // @@protoc_insertion_point(field_set:com.example.Client.account_balance)
}
inline ::int32_t Client::_internal_account_balance() const {
  return _impl_.account_balance_;
}
inline void Client::_internal_set_account_balance(::int32_t value) {
  ;
  _impl_.account_balance_ = value;
}

// string email = 4;
inline void Client::clear_email() {
  _impl_.email_.ClearToEmpty();
}
inline const std::string& Client::email() const {
  // @@protoc_insertion_point(field_get:com.example.Client.email)
  return _internal_email();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Client::set_email(Arg_&& arg,
                                                     Args_... args) {
  ;
  _impl_.email_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:com.example.Client.email)
}
inline std::string* Client::mutable_email() {
  std::string* _s = _internal_mutable_email();
  // @@protoc_insertion_point(field_mutable:com.example.Client.email)
  return _s;
}
inline const std::string& Client::_internal_email() const {
  return _impl_.email_.Get();
}
inline void Client::_internal_set_email(const std::string& value) {
  ;


  _impl_.email_.Set(value, GetArenaForAllocation());
}
inline std::string* Client::_internal_mutable_email() {
  ;
  return _impl_.email_.Mutable( GetArenaForAllocation());
}
inline std::string* Client::release_email() {
  // @@protoc_insertion_point(field_release:com.example.Client.email)
  return _impl_.email_.Release();
}
inline void Client::set_allocated_email(std::string* value) {
  _impl_.email_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.email_.IsDefault()) {
          _impl_.email_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:com.example.Client.email)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace example
}  // namespace com


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_ServerData_2eproto_2epb_2eh
