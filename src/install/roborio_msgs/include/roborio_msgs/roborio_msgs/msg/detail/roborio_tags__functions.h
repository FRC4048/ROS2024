// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from roborio_msgs:msg/RoborioTags.idl
// generated code does not contain a copyright notice

#ifndef ROBORIO_MSGS__MSG__DETAIL__ROBORIO_TAGS__FUNCTIONS_H_
#define ROBORIO_MSGS__MSG__DETAIL__ROBORIO_TAGS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "roborio_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "roborio_msgs/msg/detail/roborio_tags__struct.h"

/// Initialize msg/RoborioTags message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * roborio_msgs__msg__RoborioTags
 * )) before or use
 * roborio_msgs__msg__RoborioTags__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_roborio_msgs
bool
roborio_msgs__msg__RoborioTags__init(roborio_msgs__msg__RoborioTags * msg);

/// Finalize msg/RoborioTags message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_roborio_msgs
void
roborio_msgs__msg__RoborioTags__fini(roborio_msgs__msg__RoborioTags * msg);

/// Create msg/RoborioTags message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * roborio_msgs__msg__RoborioTags__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_roborio_msgs
roborio_msgs__msg__RoborioTags *
roborio_msgs__msg__RoborioTags__create();

/// Destroy msg/RoborioTags message.
/**
 * It calls
 * roborio_msgs__msg__RoborioTags__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_roborio_msgs
void
roborio_msgs__msg__RoborioTags__destroy(roborio_msgs__msg__RoborioTags * msg);

/// Check for msg/RoborioTags message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_roborio_msgs
bool
roborio_msgs__msg__RoborioTags__are_equal(const roborio_msgs__msg__RoborioTags * lhs, const roborio_msgs__msg__RoborioTags * rhs);

/// Copy a msg/RoborioTags message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_roborio_msgs
bool
roborio_msgs__msg__RoborioTags__copy(
  const roborio_msgs__msg__RoborioTags * input,
  roborio_msgs__msg__RoborioTags * output);

/// Initialize array of msg/RoborioTags messages.
/**
 * It allocates the memory for the number of elements and calls
 * roborio_msgs__msg__RoborioTags__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_roborio_msgs
bool
roborio_msgs__msg__RoborioTags__Sequence__init(roborio_msgs__msg__RoborioTags__Sequence * array, size_t size);

/// Finalize array of msg/RoborioTags messages.
/**
 * It calls
 * roborio_msgs__msg__RoborioTags__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_roborio_msgs
void
roborio_msgs__msg__RoborioTags__Sequence__fini(roborio_msgs__msg__RoborioTags__Sequence * array);

/// Create array of msg/RoborioTags messages.
/**
 * It allocates the memory for the array and calls
 * roborio_msgs__msg__RoborioTags__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_roborio_msgs
roborio_msgs__msg__RoborioTags__Sequence *
roborio_msgs__msg__RoborioTags__Sequence__create(size_t size);

/// Destroy array of msg/RoborioTags messages.
/**
 * It calls
 * roborio_msgs__msg__RoborioTags__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_roborio_msgs
void
roborio_msgs__msg__RoborioTags__Sequence__destroy(roborio_msgs__msg__RoborioTags__Sequence * array);

/// Check for msg/RoborioTags message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_roborio_msgs
bool
roborio_msgs__msg__RoborioTags__Sequence__are_equal(const roborio_msgs__msg__RoborioTags__Sequence * lhs, const roborio_msgs__msg__RoborioTags__Sequence * rhs);

/// Copy an array of msg/RoborioTags messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_roborio_msgs
bool
roborio_msgs__msg__RoborioTags__Sequence__copy(
  const roborio_msgs__msg__RoborioTags__Sequence * input,
  roborio_msgs__msg__RoborioTags__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ROBORIO_MSGS__MSG__DETAIL__ROBORIO_TAGS__FUNCTIONS_H_
