// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from roborio_msgs:msg/RoborioTags.idl
// generated code does not contain a copyright notice

#ifndef ROBORIO_MSGS__MSG__DETAIL__ROBORIO_TAGS__STRUCT_HPP_
#define ROBORIO_MSGS__MSG__DETAIL__ROBORIO_TAGS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__roborio_msgs__msg__RoborioTags __attribute__((deprecated))
#else
# define DEPRECATED__roborio_msgs__msg__RoborioTags __declspec(deprecated)
#endif

namespace roborio_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RoborioTags_
{
  using Type = RoborioTags_<ContainerAllocator>;

  explicit RoborioTags_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tag = 0;
      this->x = 0.0;
      this->y = 0.0;
    }
  }

  explicit RoborioTags_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tag = 0;
      this->x = 0.0;
      this->y = 0.0;
    }
  }

  // field types and members
  using _tag_type =
    uint8_t;
  _tag_type tag;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;

  // setters for named parameter idiom
  Type & set__tag(
    const uint8_t & _arg)
  {
    this->tag = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    roborio_msgs::msg::RoborioTags_<ContainerAllocator> *;
  using ConstRawPtr =
    const roborio_msgs::msg::RoborioTags_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<roborio_msgs::msg::RoborioTags_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<roborio_msgs::msg::RoborioTags_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      roborio_msgs::msg::RoborioTags_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<roborio_msgs::msg::RoborioTags_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      roborio_msgs::msg::RoborioTags_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<roborio_msgs::msg::RoborioTags_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<roborio_msgs::msg::RoborioTags_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<roborio_msgs::msg::RoborioTags_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__roborio_msgs__msg__RoborioTags
    std::shared_ptr<roborio_msgs::msg::RoborioTags_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__roborio_msgs__msg__RoborioTags
    std::shared_ptr<roborio_msgs::msg::RoborioTags_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RoborioTags_ & other) const
  {
    if (this->tag != other.tag) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const RoborioTags_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RoborioTags_

// alias to use template instance with default allocator
using RoborioTags =
  roborio_msgs::msg::RoborioTags_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace roborio_msgs

#endif  // ROBORIO_MSGS__MSG__DETAIL__ROBORIO_TAGS__STRUCT_HPP_
