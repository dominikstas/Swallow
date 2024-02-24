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
    }
    else {
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
    printf("memory - estimate available memory on Arduino (approximate)\n");
    printf("exit - turn off Swallow\n");
    printf("--------------------------------------\n");
}