/*
 * Written by @asofcs
 * Copyright 2024
 */

#include <stdio.h>

#define MAXSIZE 100

int getstr(char *strN); // validation of the input string
int stringlen(const char *ptr); //count the total number of chars


int main(void)
{
    int result = -1, counter = 0; // outputs
    char str1[MAXSIZE/2]; //input


    printf("Please enter the first string (MAX SIZE: %d):\n", (MAXSIZE/2)-1);
    result = getstr(str1); 
    
    if (result == 0)
    {
        counter = stringlen((const char *)str1);
        printf("\n\t\tString : %s \n\t\tTotal number of chars: %d \n", str1, counter); 
    }
    
    return 0;
}


/*
 * Validation of the input string
 * 0: Valid. -1: Otherwise
 */
int getstr(char *strN)
{
    if(fgets(strN, MAXSIZE/2, stdin) != NULL)
    {
        return 0;
    }
    else
    {
        printf("\t\tInvalid string!\n");
        return -1;
    }
}

/*
 * Count the total number of chars
 */
int stringlen(const char *string)
{
    /*initialize to the first address of the string-> first char*/
    const char *lastAddress = string;

    while((*lastAddress != '\n') &&  (*lastAddress != '\0'))
    {
        /*increment the pointed address */
        lastAddress++;
    }    
    /*return the difference of addresses*/    
    return lastAddress - string;
}
