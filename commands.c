#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "Arduino/tests.h"

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
    } else if (strcmp(command, "test") == 0) {
        LEDTest();
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
    //To do: corrections
    printf("All commands:\n");
    printf("echo [text] - write a text\nexit - turn off Swallow\nhelp - show all commands\n");
    printf("test - LED 7 blinks test\n");
}
