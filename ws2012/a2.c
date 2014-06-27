#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// replace only first hit
char* replace(char* str, char* tar, char* repl) {
    int i = -1;
    bool equal = false;
    

    // find tar occurence
    for(i=0; i<strlen(str); ++i) {
        equal = false;
        for(int c=0; c<strlen(tar) && (c+i)<strlen(str); ++c) {
            if(str[i+c] != tar[c]) {
                equal = false;
                break;
            }
            else if (c == strlen(tar)-1) 
                equal = true;
        }
        if (equal) break;
    }

    if (!equal) return NULL;
    
    int len = strlen(str) - strlen(tar) + strlen(repl) + 1; 
    char* res = malloc(sizeof(char)*len);
    
    // compose new string with repl
    int j=0;
    //for (j=0; j<len;) {
    while(j<len) {
        if (j<i)  {
           res[j] = str[j];
           ++j;
        }
        else if (j>i) {
            res[j] = str[j + strlen(tar) - strlen(repl)];
            ++j;
        }
        else 
           for(int p=0; p<strlen(repl); ++p) 
                res[j++] = repl[p];
    }
    
    res[j] = '\0';
    return res;
}


// helper funktion ( equals strncmp with n == strlen(tar) );; this could be used in replace too
bool _match(char* str, char* tar) {
    bool hit = false;
    for(int i=0; i<strlen(str) && i<strlen(tar); ++i) {
        if(str[i] != tar[i]) break;
        if(i == strlen(tar) -1) hit = true;
    }
    return hit;
}

// replace all hits in str
char* replace_all(char* str, char* tar, char* repl) {
    int cnt = 0;
    
    // get amount of pattern hits
    for(int i=0; i<strlen(str);) {
       if(_match((str+i), tar)) {
           ++cnt;
           i += strlen(tar); // if string is abaaa don't recognize 'aa' 'aa' only 'aa' ;;
       }
       else ++i;
    }
    
    if(!cnt) return NULL; // no hit

    int len = strlen(str) + (strlen(repl) - strlen(tar)) * cnt + 1; // ie if repl 3 , tar 2 for each hit str gets 1 bigger ;; repl 2 tar 3 for each hit str gets 1 smaller
    char* res = calloc(len, sizeof(char));
    
    int i = 0;
    int j = 0;
    while(i<strlen(str) && j<len) {
        if (_match((str+i), tar)) {
            for(int t=0; t<strlen(repl) && j<len; ++t) 
               res[j++] = repl[t];
            i += strlen(tar);
        }
        else {
            res[j++] = str[i++];
        }
    }
    return res;
}

int main(void) {
    printf("%s\n", replace_all("abcdefbc", "bc", "xxxx"));
    printf("%s\n", replace_all("abcdefbcd", "bcd", "xx"));
    printf("%s\n", replace_all("abcdefbc", "bc", "xx"));
    return 0;
}
