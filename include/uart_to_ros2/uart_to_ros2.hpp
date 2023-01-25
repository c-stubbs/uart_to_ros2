#ifndef UART_TO_ROS2_ROS_HPP
#define UART_TO_ROS2_ROS_HPP

#include <chrono>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

class UARTtoROS2 : public rclcpp::Node
{
public:
    UARTtoROS2();
    ~UARTtoROS2();

private:
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_;

    void pubCallback();

    int fd, len;
	char text[255];
	struct termios options;

};

#endif