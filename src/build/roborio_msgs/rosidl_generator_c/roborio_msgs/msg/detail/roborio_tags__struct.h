// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from roborio_msgs:msg/RoborioTags.idl
// generated code does not contain a copyright notice

#ifndef ROBORIO_MSGS__MSG__DETAIL__ROBORIO_TAGS__STRUCT_H_
#define ROBORIO_MSGS__MSG__DETAIL__ROBORIO_TAGS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/RoborioTags in the package roborio_msgs.
typedef struct roborio_msgs__msg__RoborioTags
{
  uint8_t tag;
  double x;
  double y;
} roborio_msgs__msg__RoborioTags;

// Struct for a sequence of roborio_msgs__msg__RoborioTags.
typedef struct roborio_msgs__msg__RoborioTags__Sequence
{
  roborio_msgs__msg__RoborioTags * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roborio_msgs__msg__RoborioTags__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBORIO_MSGS__MSG__DETAIL__ROBORIO_TAGS__STRUCT_H_
