#ifndef SINGLELINKEDLIST_H_INCLUDED
#define SINGLELINKEDLIST_H_INCLUDED

// NOTE: students have to implement this interface in singlelinkedlist.c 
// all functions return the head of the list

typedef struct String_LL {
    struct String_LL* next;
    char* data;
} String_LL;


/* populateList: read strings form stdin into linked list */
String_LL* populateList(String_LL* head); 
/* createNewElem: creates a new String_LL element */ 
String_LL* createNewElem(char* payload);
/* append: adds a String_LL to the tail of a list */
String_LL* append(String_LL* head,String_LL* elem);
/* insertFront: push String_LL element into the front of the list, prevents truncation of elem */
String_LL* insertFront(String_LL* head, String_LL* elem);
/* freeList: deallocates a list and elements payload */
String_LL* freeList(String_LL* head);

#endif // SINGLELINKEDLIST_H_INCLUDED
