#include "uart_to_ros2/uart_to_ros2.hpp"

using namespace std::chrono_literals;

UARTtoROS2::UARTtoROS2()
    : Node("uart_to_ros2_node")
{
    fd = open("/dev/serial0", O_RDWR | O_NDELAY | O_NOCTTY);
    if (fd < 0)
    {
        perror("Error opening serial port");
    }
    
    /* Set up serial port */
	options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
	options.c_iflag = IGNPAR;
	options.c_oflag = 0;
	options.c_lflag = 0;

	/* Apply the settings */
	tcflush(fd, TCIFLUSH);
	tcsetattr(fd, TCSANOW, &options);

	/* Write to serial port */
	strcpy(text, "Hello from my RPi\n\r");
	len = strlen(text);
	len = write(fd, text, len);
	printf("Wrote %d bytes over UART\n", len);

    pub_ = this->create_publisher<std_msgs::msg::Float64>("/uart_to_ros2/data", 10);
    timer_ = this->create_wall_timer(500ms, std::bind(&UARTtoROS2::pubCallback, this));
}

UARTtoROS2::~UARTtoROS2()
{
    close(fd);
}

void UARTtoROS2::pubCallback()
{
	/* Read from serial port */
	memset(text, 0, 255);
	len = read(fd, text, 255);
	printf("Received %d bytes\n", len);
	printf("Received string: %s\n", text);
}
