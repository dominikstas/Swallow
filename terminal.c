#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

#define MAX_INPUT_LENGTH 1000 

void init(){
    system("clear");
    printf("Welcome to Swallow!\n");
}

char* getInput(){
    char *input = NULL;
    size_t bufferSize = 0;

    getline(&input, &bufferSize, stdin);
    input[strcspn(input, "\n")] = '\0';

    return input;
}


int main() {
    char *command;
    init();
    while(1){
        printf(">");
        command = getInput();

        if(strlen(command) != 0){
            execute(command);

            free(command);
        }
    }
    return 0;
}