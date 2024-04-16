cmake_minimum_required(VERSION 3.8)
project(redshift_cpp_odometry)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

find_package(rclcpp REQUIRED)

add_executable(lifesigns src/lifesigns.cpp)
ament_target_dependencies(lifesigns rclcpp std_msgs)
install(TARGETS
  lifesigns
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
