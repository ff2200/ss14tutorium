#include <unistd.h> //size_t
#include <string.h>
#include "readline.h"

#define BUF_SIZE 1024

static char readBuffer[BUF_SIZE];

char* readline_prompt(char* prompt) {
    puts(prompt);
    
    for(size_t i = 0; i < BUF_SIZE; ++i)
        readBuffer[i] = '\0';

    fgets(readBuffer, BUF_SIZE, stdin);
    readBuffer[strlen(readBuffer) - 1] = '\0';
    return readBuffer;
}

