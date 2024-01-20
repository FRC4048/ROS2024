// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from roborio_msgs:msg/RoborioTags.idl
// generated code does not contain a copyright notice
#include "roborio_msgs/msg/detail/roborio_tags__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
roborio_msgs__msg__RoborioTags__init(roborio_msgs__msg__RoborioTags * msg)
{
  if (!msg) {
    return false;
  }
  // tag
  // x
  // y
  return true;
}

void
roborio_msgs__msg__RoborioTags__fini(roborio_msgs__msg__RoborioTags * msg)
{
  if (!msg) {
    return;
  }
  // tag
  // x
  // y
}

bool
roborio_msgs__msg__RoborioTags__are_equal(const roborio_msgs__msg__RoborioTags * lhs, const roborio_msgs__msg__RoborioTags * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // tag
  if (lhs->tag != rhs->tag) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  return true;
}

bool
roborio_msgs__msg__RoborioTags__copy(
  const roborio_msgs__msg__RoborioTags * input,
  roborio_msgs__msg__RoborioTags * output)
{
  if (!input || !output) {
    return false;
  }
  // tag
  output->tag = input->tag;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  return true;
}

roborio_msgs__msg__RoborioTags *
roborio_msgs__msg__RoborioTags__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roborio_msgs__msg__RoborioTags * msg = (roborio_msgs__msg__RoborioTags *)allocator.allocate(sizeof(roborio_msgs__msg__RoborioTags), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(roborio_msgs__msg__RoborioTags));
  bool success = roborio_msgs__msg__RoborioTags__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
roborio_msgs__msg__RoborioTags__destroy(roborio_msgs__msg__RoborioTags * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    roborio_msgs__msg__RoborioTags__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
roborio_msgs__msg__RoborioTags__Sequence__init(roborio_msgs__msg__RoborioTags__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roborio_msgs__msg__RoborioTags * data = NULL;

  if (size) {
    data = (roborio_msgs__msg__RoborioTags *)allocator.zero_allocate(size, sizeof(roborio_msgs__msg__RoborioTags), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = roborio_msgs__msg__RoborioTags__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        roborio_msgs__msg__RoborioTags__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
roborio_msgs__msg__RoborioTags__Sequence__fini(roborio_msgs__msg__RoborioTags__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      roborio_msgs__msg__RoborioTags__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

roborio_msgs__msg__RoborioTags__Sequence *
roborio_msgs__msg__RoborioTags__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roborio_msgs__msg__RoborioTags__Sequence * array = (roborio_msgs__msg__RoborioTags__Sequence *)allocator.allocate(sizeof(roborio_msgs__msg__RoborioTags__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = roborio_msgs__msg__RoborioTags__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
roborio_msgs__msg__RoborioTags__Sequence__destroy(roborio_msgs__msg__RoborioTags__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    roborio_msgs__msg__RoborioTags__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
roborio_msgs__msg__RoborioTags__Sequence__are_equal(const roborio_msgs__msg__RoborioTags__Sequence * lhs, const roborio_msgs__msg__RoborioTags__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!roborio_msgs__msg__RoborioTags__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
roborio_msgs__msg__RoborioTags__Sequence__copy(
  const roborio_msgs__msg__RoborioTags__Sequence * input,
  roborio_msgs__msg__RoborioTags__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(roborio_msgs__msg__RoborioTags);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    roborio_msgs__msg__RoborioTags * data =
      (roborio_msgs__msg__RoborioTags *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!roborio_msgs__msg__RoborioTags__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          roborio_msgs__msg__RoborioTags__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!roborio_msgs__msg__RoborioTags__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
