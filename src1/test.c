/*
 * Written by @asofcs
 * Copyright 2024
 */


#include <stdio.h>

/*
 *Enum initialization 
 */
enum Company {GOOGLE, FACEBOOK, XEROX, YAHOO = 10, EBAY, MICROSOFT};

int main(void)
{
    enum Company comp1 = XEROX; // company 1
    enum Company comp2 = GOOGLE; // company 2
    enum Company comp3 = EBAY; // company 3
    
    
   /*
    * Print output: (int) values of company 1, company 2, and company 3.  
    */
    printf("Values (xerox, google, ebay):\n %d\n %d\n %d\n ", comp1, comp2, comp3);
    
    return 0;
}
