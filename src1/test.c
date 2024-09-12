/*
 * Written by @asofcs
 * Copyright 2024
 */


#include <stdio.h>

int main(void)
{
    int number1 = 5; // int variable
    int *ptr = NULL; // int pointer
    ptr = &number1;
    number1 = 20;
    
    if (ptr != NULL)
    {
        printf("Variable's value: %d\n", number1);
        printf("Variable's address: %p\n",  &number1);
        printf("Address pointed by the pointer: %p\n", ptr);
        printf("Value pointed by the pointer: %d\n", *ptr);
        printf("Pointer's address: %p\n", &ptr);        
    }
	return 0;
}
