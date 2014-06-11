#include <stdlib.h>
#include "student.h"

Stud* createStud(uint16_t mat_nr, char* name) {
    Stud* res = NULL;
    // malloc(1*sizof(Stud)) == malloc(sizeof(Stud))
    if ((res = calloc(1, sizeof(Stud))) == NULL) 
            return NULL;
    
    res->mat_nr = mat_nr;
    res->name = name;
    /*
     * (*res).mat_nr = mat_nr;
     */
    
    return res;
}

