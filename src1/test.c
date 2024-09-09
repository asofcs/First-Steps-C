/*
 * Written by @asofcs
 * Copyright 2024
 */


#include <stdio.h>

#define MAXPRIME 100
#define MINPRIME 1

int main(void)
{
    
    int primeNumber[MAXPRIME]; // array for prime numbers
    int counter = 0; // position on the array
    
    for (int i = MINPRIME; i<= MAXPRIME; i++)
    {
        /*Exceptions: 0 and 1*/
        if ((i==0) || (i==1))
        {
           continue; 
        }
        
        /*Prime: All numbers that are not divisible by 2 and 3 and 5 and 7 (and including 2, 3, 5, and 7) */
        else if (((i % 2 != 0) && (i % 3 != 0) && (i % 5 != 0) && (i % 7!= 0)) || ((i== 2) || (i== 3) || (i == 5) || (i == 7)))
        {
           primeNumber[counter] = i;
           printf("Prime No.%d)  - %d\n",  counter+1, primeNumber[counter]);
           counter = counter + 1;
        }
    }
	
    return 0;
}
