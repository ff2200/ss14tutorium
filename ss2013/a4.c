#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void split(char** words, char* str) {

    int str_i;
    bool intoken = false;
    int token_start = 0;
    int word_i = 0;

    for(str_i=0; str_i < strlen(str); ++str_i) {
        if(isalpha(str[str_i]) != 0)  {
            if(!intoken) {
                token_start = str_i;
            }
            intoken = true;
            
        }
        else {
            if(token_start != -1) {
                intoken = false;
                words[word_i] = strndup((str + token_start),(str_i - token_start));
                word_i++;
                token_start = -1;
            }
        }
    }
    words[word_i] = NULL;
}



