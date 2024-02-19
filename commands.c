#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

void execute(char *command) {
    if (strncmp(command, "echo ", 5) == 0) {
        // to do: fix usage error
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
    } else {
        printf("Unknown command: %s\n", command);
    }
}

void echo(char *text) {
    // Wypisz tekst
    printf("%s\n", text);
}

void exitS() {
    printf("Thanks for using\n");
    exit(0);
}

void help() {
    printf("All commands:\n");
    printf("echo [text] - write a text\nexit - turn off Swallow\nhelp - show all commands\n");
}
