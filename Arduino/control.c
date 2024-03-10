#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>

#include "control.h"



// to do
void checkArduinoMemory() {
    
}

void clearArduinoMemory(){
    const char *arduinoCodePath = "../Arduino/obc-sets/clear";
    chdir(arduinoCodePath);

    char command[256];
    snprintf(command, sizeof(command), "make -f Makefile.clear");
    system(command);

    const char *reset = "../../../build";
    chdir(reset);

}