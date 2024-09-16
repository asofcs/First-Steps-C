/*
 * Written by @asofcs
 * Copyright 2024
 */
 

#include "student.h"
#include <stdio.h>


int main(void)
{
    student *new = NULL;
    new = student_new();
    
    if(new != NULL)
    {
        printf("\n\tMEMORY ALLOCATED!\n");
    }
    
    printf(" \nTesting of units insertion\n ");
    student_insert(new, "PROG2", 7, 15, -1);
    student_insert(new, "AMAT", 6, 12, -1);
    student_insert(new, "AMAT2", 3, 11, -1);
    student_insert(new, "ELEM", 5, 0, -1);
    student_print(new);
    printf(" \nTesting unit removal\n ");
    student_remove(new, "ELEM");
    student_print(new);
    printf(" \nTesting alphabetical order\n ");
    student_order(new);
    student_print(new);
    printf(" \nFinal size: %d\n ", student_size(new));
    student_delete(new);

	return 0;
}
