#include "uart_to_ros2/uart_to_ros2.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<UARTtoROS2>());
    rclcpp::shutdown();
    return 0;
}