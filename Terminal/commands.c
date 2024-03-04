#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "../Arduino/tests.h"

void execute(char *command) {
    if (strncmp(command, "echo ", 4) == 0) {
        char *text = command + 5; 
        if (strlen(text) > 0) {
            echo(text);
        } else {
            printf("Usage: echo [text]\n");
        }
    } else if (strcmp(command, "exit") == 0) {
        exitS();
    } else if (strcmp(command, "help") == 0) {
        help();
    } else if (strncmp(command, "led ", 3) == 0) {
        char *timesStr = command + 4;
        int times = atoi(timesStr);

        // Check if a valid integer was provided
        if (times > 0) {
            LEDTest(times);
        } else {
            printf("Usage: led [times]\n");
        }
    } else if ((strcmp(command, "memory") == 0)) {
        checkArduinoMemory();
    } else if (strcmp(command, "run") == 0) {
        runArduinoCode();
    } else if (strcmp(command, "clear") == 0) {
        clearArduinoMemory();
    } else {
        printf("Unknown command: %s\n", command);
    }
}

void echo(char *text) {
    printf("%s\n", text);
}

void exitS() {
    printf("Thanks for using\n");
    exit(0);
}

void help() {
    printf("--------------------------------------\n");
    printf("All commands:\n");
    printf("help - show all commands\n");
    printf("echo [text] - write a text\n");
    printf("led [times] - LED blink test. \n");
    //printf("memory - estimate available memory on Arduino (approximate)\n");
    //to do: fix ^
    printf("run - run diodes code. \n"); //to be changed
    printf("exit - turn off Swallow\n");
    printf("--------------------------------------\n");
}

void runArduinoCode() {
    //to do: correct readme after fixing this function
    //to do: take the set as an argument
    //to do: fix all the bugs this code generate
    const char *arduinoCodePath = "../Arduino/obc-sets/diodes/diodes.ino";

    char command[256];
    snprintf(command, sizeof(command), "arduino-cli compile --fqbn arduino:avr:uno %s", arduinoCodePath);
    system(command);

    snprintf(command, sizeof(command), "arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno");
    system(command);
}
