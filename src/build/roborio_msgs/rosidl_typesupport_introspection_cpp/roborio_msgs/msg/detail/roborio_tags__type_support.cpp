// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from roborio_msgs:msg/RoborioTags.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "roborio_msgs/msg/detail/roborio_tags__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace roborio_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void RoborioTags_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) roborio_msgs::msg::RoborioTags(_init);
}

void RoborioTags_fini_function(void * message_memory)
{
  auto typed_message = static_cast<roborio_msgs::msg::RoborioTags *>(message_memory);
  typed_message->~RoborioTags();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RoborioTags_message_member_array[3] = {
  {
    "tag",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roborio_msgs::msg::RoborioTags, tag),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roborio_msgs::msg::RoborioTags, x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roborio_msgs::msg::RoborioTags, y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RoborioTags_message_members = {
  "roborio_msgs::msg",  // message namespace
  "RoborioTags",  // message name
  3,  // number of fields
  sizeof(roborio_msgs::msg::RoborioTags),
  RoborioTags_message_member_array,  // message members
  RoborioTags_init_function,  // function to initialize message memory (memory has to be allocated)
  RoborioTags_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RoborioTags_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RoborioTags_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace roborio_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<roborio_msgs::msg::RoborioTags>()
{
  return &::roborio_msgs::msg::rosidl_typesupport_introspection_cpp::RoborioTags_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, roborio_msgs, msg, RoborioTags)() {
  return &::roborio_msgs::msg::rosidl_typesupport_introspection_cpp::RoborioTags_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
