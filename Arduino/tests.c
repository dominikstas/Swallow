#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include "tests.h"

// Function to test LED functionality
void LEDTest(int times) {

    // Open the serial port associated with Arduino (Assuming it's /dev/ttyACM0)
    // To do: make it avaliable to change the port
    int fd = open("/dev/ttyACM0", O_RDWR | O_NOCTTY);

    // Check if opening the serial port was successful
    if (fd == -1) {
        perror("Error opening the serial port");
        return;
    }

    // Configure the serial port settings
    struct termios options;
    tcgetattr(fd, &options);
    cfsetispeed(&options, B9600);
    cfsetospeed(&options, B9600);
    tcsetattr(fd, TCSANOW, &options);

    // Blink the PB5 diode  on Arduino 7 times
    for (int i = 0; i < times; i++) {
        write(fd, "Blink", 5);
        sleep(1);
    }

    // Close the serial port
    close(fd);

    // Print a success message
    printf("Test successful\n");
    return;
}
