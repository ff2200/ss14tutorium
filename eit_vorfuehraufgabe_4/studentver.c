#include <unistd.h> // size_t
#include <stdint.h> // YintX_t
#include <stdlib.h> // strtol, NULL, ... 
#include <stdbool.h> // boolean type
#include <errno.h> // errno variable and errornames
#include <string.h> // strlen
#include <ctype.h> // isdigit

#include "linkedlist.h"
#include "student.h"
#include "readline.h"

#define HASH_MOD 20

size_t hash(uint16_t mtr);

Stud* readStudent(void);

void readManyStudents(SLLStud** dict);

void printStudents(SLLStud** dict);

void freePtrs(SLLStud** dict);

int main(void) {
    
    SLLStud* hashDict[HASH_MOD] =  { NULL };
    readManyStudents(hashDict);
    printStudents(hashDict);
    freePtrs(hashDict);
    return EXIT_SUCCESS;

}


size_t hash(uint16_t mtr) {
    return mtr % HASH_MOD;
}


//#define _strtol

#ifdef _strtol
Stud* readStudent(void) {
   char* tmp = NULL;
   Stud* res = NULL;
   long  mat_nr = 0;
   char* end_p; // needed for strtol

   do {
       errno = 0;
       tmp = readline_prompt("Matrikel#:");
       mat_nr = strtol(tmp, &end_p , 0);
   }while(errno == EINVAL || errno == ERANGE || strlen(end_p) != 0);

   if(mat_nr == 0) return NULL;

   tmp = readline_prompt("Name:");
   res = createStud(mat_nr, strdup(tmp));

   return res;
}
#else
Stud* readStudent(void) {
   char* tmp = NULL;
   Stud* res = NULL;
   uint16_t mat_nr = 0;
   
   bool error = false;
   do {
       error = false;
       tmp = readline_prompt("Matrikel#:");
       for(size_t i = 0; i < strlen(tmp); ++i) {
           if (!isdigit(tmp[i])) {
               error = true;
               break;
           }
       }
   }while(error);
   
   mat_nr = atoi(tmp);
  
   if(mat_nr == 0) return NULL;
  
   tmp = readline_prompt("Name:");
   res = createStud(mat_nr, strdup(tmp));

   return res;
}
#endif


void readManyStudents(SLLStud** dict) {
    if(!dict) 
        return;

    Stud* tmp = NULL;

    do {
        tmp = readStudent();
                
        if(tmp == NULL) 
            break;
        
        size_t hash_value = hash(tmp->mat_nr);
        
        if(dict[hash_value] == NULL) 
            dict[hash_value] = calloc(1, sizeof(SLLStud*));
            if(dict[hash_value] == NULL) return;

        SLLStud* run = dict[hash_value];

        while(run->next != NULL)
            run = run->next;

        run->next = calloc(1, sizeof(SLLStud*));
        if(run->next == NULL)
            return;
        (run->next)->student = tmp;
    
    }while(true);
    return;
}

void printStudents(SLLStud** dict) {
    if(!dict) return;

    for(size_t i = 0; i < HASH_MOD; ++i) {
        if(!dict[i]) continue;
        printf("Hashvalue: %ld\n", (long)i);
        
        SLLStud* list = dict[i];
        while(list) {
            Stud* stu = list->student;
            if(stu != NULL) {
                printf("\tMatNr: %d\tName: %s\n", stu->mat_nr, stu->name);
            }
            list = list->next;
        }

        puts("----------------------------------------------------");
    }
}

void freePtrs(SLLStud** dict) {

    if(!dict) return;

    for(size_t i = 0; i < HASH_MOD; ++i) {
        if(!dict[i]) continue;
        SLLStud* list = dict[i];
        while(list) {
            Stud* stu = list->student;
            if(stu) 
                free(stu->name);
            free(stu);
            SLLStud* freeSLL = list;
            list = list->next;
            free(freeSLL);
        }
    } 
}
