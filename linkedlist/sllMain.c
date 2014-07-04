/* This is a single linked list example
 * 
 * Students have to implement the interface 
 * provided by singlelinkedlist.h
 */

#define _GNU_SOURCE

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "singlelinkedlist.h"

#define WELCOME_MSG "Please enter text to store in linked list " \
                    "commit a record with <ENTER>.\n" \
                    "Trigger EOF (C^d) to see records.\n"

int main(int argc, const char* argv[]) {
    String_LL* head = NULL;

    puts(WELCOME_MSG);

    head = populateList(head);

    String_LL* ptr = head;
    while(ptr != NULL) {
        printf("output: %s\n", ptr->data);
        ptr = ptr->next;
    }

    freeList(head);
    return EXIT_SUCCESS;
}

