#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>

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

void checkArduinoMemory() {
    //this code aint working 
    //to do: create another solution

    // Create a dynamic array to estimate available memory
    int* dummyArray = malloc(1000 * sizeof(int));

    if (dummyArray == NULL) {
        perror("Error allocating memory");
        return;
    }

    // Calculate the amount of available memory
    size_t availableMemory = 1000 * sizeof(int);

    // Free dynamically allocated memory
    free(dummyArray);

    // Display information about available memory
    printf("Estimated Available Memory: %zu bytes\n", availableMemory);
}

//to do: separate this type of commands
void clearArduinoMemory(){
    const char *arduinoCodePath = "../Arduino/obc-sets/clear";
    chdir(arduinoCodePath);

    char command[256];
    snprintf(command, sizeof(command), "make -f Makefile.clear");
    system(command);

    const char *reset = "../../../build";
    chdir(reset);

}