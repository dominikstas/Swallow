#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

void execute(char *command) {
    if (strcmp(command, "echo") == 0){
        echo();
    }
    else if (strcmp(command, "exit") == 0){
        exitS();
    }
    if (strcmp(command, "help") == 0){
        help();
    } else {
        printf("Unknown command: %s\n", command);
    }
}

void echo(){
    //to do: correct
    printf("echo\n");
}

void exitS(){
    printf("Thanks for using\n");
    exit(0);
}

void help(){
    printf("All commands:\n");
    printf("echo - write a text\nexit - turn off Swallow\nhelp - show all commands\n");
}
