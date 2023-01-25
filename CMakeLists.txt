cmake_minimum_required(VERSION 3.5)
project(uart_to_ros2)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(include
  ~/Projects/ros2/foxy_ws/src/uart_to_ros2/include/
)


# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_library(uart_to_ros2 src/uart_to_ros2.cpp)
ament_target_dependencies(uart_to_ros2 rclcpp std_msgs)

add_executable(uart_to_ros2_node src/uart_to_ros2_node.cpp)
target_link_libraries(uart_to_ros2_node uart_to_ros2)
ament_target_dependencies(uart_to_ros2_node rclcpp)

install(TARGETS
  uart_to_ros2
  uart_to_ros2_node
  DESTINATION lib/${PROJECT_NAME}
)


ament_package()
