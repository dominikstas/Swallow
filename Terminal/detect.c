#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include "detect.h"

#define ARDUINO_VENDOR_ID   0x2341
#define ARDUINO_PRODUCT_ID  0x0043

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <errno.h>

int detectMicrocontroller() {
    // Arch Linux config
    
    // To do: add support for entering your port

    //if you use other port, change this code manually
    int fd = open("/dev/ttyACM0", O_RDWR | O_NOCTTY);
    
    if (fd == -1) {
        perror("Error opening serial port");
        
        // Check if the error is due to permission denied
        if (errno == EACCES) {
            printf("\nPermission denied. You may need to run the program with elevated privileges.\n");
            printf("Try using 'sudo chmod a+rw /dev/[port]' or 'sudo usermod -a -G uucp $user' \nbefore your command.\n");
        }
        
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

