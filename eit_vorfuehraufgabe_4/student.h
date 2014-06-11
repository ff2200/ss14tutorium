#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdint.h> // YintX_t 

typedef struct Stud {
    uint16_t mat_nr;
    char* name;
    // und was sonst noch
} Stud;

Stud* createStud(uint16_t mat_nr, char* name);

#endif // STUDENT_H_INCLUDED
