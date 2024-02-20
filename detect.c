#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include "detect.h"

#define ARDUINO_VENDOR_ID   0x2341
#define ARDUINO_PRODUCT_ID  0x0043

int detectMicrocontroller() {
    //arch linux config
    
    //to do: for acces denied - sudo usermod -a -G uucp <username>
    
    //to do: add support for entering your port
    int fd = open("/dev/ttyACM0", O_RDWR | O_NOCTTY);
    
    if (fd == -1) {
        perror("Error opening serial port");
        return 1; 
    }

    struct termios options;
    tcgetattr(fd, &options);
    cfsetispeed(&options, B9600);
    cfsetospeed(&options, B9600);
    tcsetattr(fd, TCSANOW, &options);

    close(fd);

    return 0; 
}
