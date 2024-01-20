// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from roborio_msgs:msg/RoborioTags.idl
// generated code does not contain a copyright notice

#ifndef ROBORIO_MSGS__MSG__DETAIL__ROBORIO_TAGS__TRAITS_HPP_
#define ROBORIO_MSGS__MSG__DETAIL__ROBORIO_TAGS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "roborio_msgs/msg/detail/roborio_tags__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace roborio_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RoborioTags & msg,
  std::ostream & out)
{
  out << "{";
  // member: tag
  {
    out << "tag: ";
    rosidl_generator_traits::value_to_yaml(msg.tag, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RoborioTags & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: tag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tag: ";
    rosidl_generator_traits::value_to_yaml(msg.tag, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RoborioTags & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace roborio_msgs

namespace rosidl_generator_traits
{

[[deprecated("use roborio_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const roborio_msgs::msg::RoborioTags & msg,
  std::ostream & out, size_t indentation = 0)
{
  roborio_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use roborio_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const roborio_msgs::msg::RoborioTags & msg)
{
  return roborio_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<roborio_msgs::msg::RoborioTags>()
{
  return "roborio_msgs::msg::RoborioTags";
}

template<>
inline const char * name<roborio_msgs::msg::RoborioTags>()
{
  return "roborio_msgs/msg/RoborioTags";
}

template<>
struct has_fixed_size<roborio_msgs::msg::RoborioTags>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<roborio_msgs::msg::RoborioTags>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<roborio_msgs::msg::RoborioTags>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBORIO_MSGS__MSG__DETAIL__ROBORIO_TAGS__TRAITS_HPP_
