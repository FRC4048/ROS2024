// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from roborio_msgs:msg/RoborioTags.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "roborio_msgs/msg/detail/roborio_tags__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace roborio_msgs
{

namespace msg
{

namespace rosidl_typesupport_cpp
{

typedef struct _RoborioTags_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _RoborioTags_type_support_ids_t;

static const _RoborioTags_type_support_ids_t _RoborioTags_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _RoborioTags_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _RoborioTags_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _RoborioTags_type_support_symbol_names_t _RoborioTags_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, roborio_msgs, msg, RoborioTags)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, roborio_msgs, msg, RoborioTags)),
  }
};

typedef struct _RoborioTags_type_support_data_t
{
  void * data[2];
} _RoborioTags_type_support_data_t;

static _RoborioTags_type_support_data_t _RoborioTags_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _RoborioTags_message_typesupport_map = {
  2,
  "roborio_msgs",
  &_RoborioTags_message_typesupport_ids.typesupport_identifier[0],
  &_RoborioTags_message_typesupport_symbol_names.symbol_name[0],
  &_RoborioTags_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t RoborioTags_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_RoborioTags_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace msg

}  // namespace roborio_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<roborio_msgs::msg::RoborioTags>()
{
  return &::roborio_msgs::msg::rosidl_typesupport_cpp::RoborioTags_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, roborio_msgs, msg, RoborioTags)() {
  return get_message_type_support_handle<roborio_msgs::msg::RoborioTags>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp
