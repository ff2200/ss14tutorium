#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "student.h"

typedef struct SLLStud {
    struct SLLStud* next;
    Stud* student;
} SLLStud;

#endif // LINKEDLIST_H_INCLUDED
