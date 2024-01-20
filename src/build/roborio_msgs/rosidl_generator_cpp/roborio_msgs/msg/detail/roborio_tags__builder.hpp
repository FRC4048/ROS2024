// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from roborio_msgs:msg/RoborioTags.idl
// generated code does not contain a copyright notice

#ifndef ROBORIO_MSGS__MSG__DETAIL__ROBORIO_TAGS__BUILDER_HPP_
#define ROBORIO_MSGS__MSG__DETAIL__ROBORIO_TAGS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "roborio_msgs/msg/detail/roborio_tags__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace roborio_msgs
{

namespace msg
{

namespace builder
{

class Init_RoborioTags_y
{
public:
  explicit Init_RoborioTags_y(::roborio_msgs::msg::RoborioTags & msg)
  : msg_(msg)
  {}
  ::roborio_msgs::msg::RoborioTags y(::roborio_msgs::msg::RoborioTags::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roborio_msgs::msg::RoborioTags msg_;
};

class Init_RoborioTags_x
{
public:
  explicit Init_RoborioTags_x(::roborio_msgs::msg::RoborioTags & msg)
  : msg_(msg)
  {}
  Init_RoborioTags_y x(::roborio_msgs::msg::RoborioTags::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_RoborioTags_y(msg_);
  }

private:
  ::roborio_msgs::msg::RoborioTags msg_;
};

class Init_RoborioTags_tag
{
public:
  Init_RoborioTags_tag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RoborioTags_x tag(::roborio_msgs::msg::RoborioTags::_tag_type arg)
  {
    msg_.tag = std::move(arg);
    return Init_RoborioTags_x(msg_);
  }

private:
  ::roborio_msgs::msg::RoborioTags msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::roborio_msgs::msg::RoborioTags>()
{
  return roborio_msgs::msg::builder::Init_RoborioTags_tag();
}

}  // namespace roborio_msgs

#endif  // ROBORIO_MSGS__MSG__DETAIL__ROBORIO_TAGS__BUILDER_HPP_
