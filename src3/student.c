/*****************************************************************/
/*       LIBRARY STUDENT  | Vector based | asofcs | 2024         */
/*****************************************************************/


#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ERRORPTR NULL
#define ERRORINT -1
#define ERRORFLT 0

student *student_new()
{
    /*initialization*/
    student *stdnew = ERRORPTR;
    
    /*memory allocation*/
    stdnew = (student*)malloc(sizeof(student));
    
    if(stdnew == ERRORPTR)
    {
        return ERRORPTR;
    }
    
    /*initialization of the student's parameters*/
    stdnew->units = ERRORPTR;
    stdnew->average = 0;
    stdnew->capacity = 0;
    stdnew->size = 0;  

    return stdnew;
}

void student_delete(student *stdnew)
{
    if(stdnew != ERRORPTR)
    {
        /*free every unit's name*/

        for(int i = 0; i < stdnew->size; i++)
        {
            free(stdnew->units[i].name);
        }
        
        /*free units*/
        free(stdnew->units);
        
        /*free student*/
        free(stdnew);
        stdnew = ERRORPTR;
        
        printf("\n\tMEMORY FREED WITH SUCCESS!\n");
    }
}

float student_average(student *stdnew)
{
    int subtotal = 0, sumEcts = 0;

    if((stdnew == ERRORPTR) || (stdnew->size < 1))
    {
        return ERRORFLT;
    }
        
    for (int i = 0; i < stdnew->size; i++)
    {
        if (stdnew->units[i].grade > 0)
        {
            sumEcts = sumEcts + stdnew->units[i].ects;
            subtotal = subtotal + (stdnew->units[i].ects*stdnew->units[i].grade);
        }
    }
    
    return subtotal/(float)sumEcts;
    
}

void student_print(student *stdnew)
{
    if(stdnew->units != ERRORPTR)
    {
        for(int i = 0; i < stdnew->size; i++)
        {
            printf(" \n\t\t Unit %d: \n", i+1);
            printf(" \n\t\t\t Name: %s\n", stdnew->units[i].name);
            printf(" \n\t\t\t ECTS: %d\n", stdnew->units[i].ects);
            printf(" \n\t\t\t Grade: %.2f\n", stdnew->units[i].grade);
        }
        
        printf(" \n\tAverage: %.2f\n", stdnew->average);
    }
    else
    {
        printf("EMPTY STUDENT\n");
    }
}

int student_remove(student *stdnew, const char *name)
{
    int pos = ERRORINT;
    
    if((stdnew == ERRORPTR) || (stdnew->size < 1))
    {
        return ERRORINT;
    }
    
    /*find unit's position*/

    for(int i = 0; i < stdnew->size; i++)
    {
        if (strcmp(stdnew->units[i].name, name) == 0)
        {
            pos = i;
            break;
        }
    }
    

    if (pos > ERRORINT)
    {
        /*free unit's name*/
        free(stdnew->units[pos].name);
        
        /*copy of all units to the new positions*/
        for(int i = pos+1; i< stdnew->size; i++)
        {
            stdnew->units[i-1] = stdnew->units[i];
        }
        
        /*decrement of the total size*/
        stdnew->size = stdnew->size - 1;
        return 0;
    }
    else
    {
        return ERRORINT;
    }
      
}


int student_insert(student *stdnew, const char *name, int ects, float grade, int pos)
{
    
    if((stdnew == ERRORPTR) || (pos < ERRORINT) || (pos > stdnew->size))
    {
        return ERRORINT;
    }
    
    // increases capacity if it is not enough.
    if (stdnew->size == stdnew->capacity)
    {
        if(stdnew->capacity == 0)
        {
            stdnew->capacity = 1;
        }
        else
        {
            stdnew->capacity = stdnew->capacity*2;
        }
        
        stdnew->units = (unit*)realloc(stdnew->units, stdnew->capacity * sizeof(unit));
        
        if (stdnew->units == ERRORPTR)
        {
            return ERRORINT;
        }
    }
    
    // insert at the end
    if(pos == ERRORINT)
    {
        pos = stdnew->size;
    }
    
    /*copy of all units to the new positions*/

    for(int i = stdnew->size-1; i >= pos; i--)
    {
        stdnew->units[i+1] = stdnew->units[i];
    }
    
    /*assigns ects and grade to new unit*/
    stdnew->units[pos].ects = ects;
    stdnew->units[pos].grade = grade;
    
    /*memory allocation for the name of the new unit*/
    stdnew->units[pos].name = (char*)calloc(strlen(name)+1, sizeof(char));
    
    if((stdnew->units[pos].name == ERRORPTR) || (stdnew->units[pos].ects <= 0) || (stdnew->units[pos].grade < 0))
    {
        return ERRORINT;
    }
    
    /*assigns name to new unit*/
    strcpy(stdnew->units[pos].name, name);
    
    /*updates total size*/
    stdnew->size = stdnew->size + 1;
    
    /*updates total average*/
    stdnew->average = student_average(stdnew);
    
    return pos;
}


int student_size(student *stdnew)
{
    if(stdnew == ERRORPTR)
    {
        return ERRORINT;
    }
    return stdnew->size;
    
}


int student_order(student *stdnew)
{
    
    unit temp;
    
    if(stdnew == ERRORPTR)
    {
        return ERRORINT;
    }
     
    /*search by bubble sort*/
    for (int i = 1; i < stdnew->size; i++)
    {
        if(strcmp(stdnew->units[i].name, stdnew->units[i-1].name) < 0)
        {
            temp = stdnew->units[i];
            stdnew->units[i] = stdnew->units[i-1];
            stdnew->units[i-1] = temp;
        }
    }
    
    return 0;
}
