/*
 * Written by @asofcs
 * Copyright 2024
 */
 
 
#include <stdio.h>
#include <stdlib.h>


void getstr(char *strN, int MAXSIZE); // get the input string


int main(int argc, char **argv)
{
	
    unsigned int maxSize = 0; // input1: maximum size of string 
    char *text = NULL; // input2: pointer to the string
    
    /*User enter the value of maxSize*/
    printf("\nPlease enter the limit of the text:\n");
    scanf("%u", &maxSize);
    
    /*Memory allocation*/
    if (maxSize > 0)
    {
        text = (char*)calloc(maxSize, sizeof(char));
    }
    
    if(text == NULL)
    {
        printf("\n\tMEMORY NOT ALLOCATED!\n");
        exit(1);
    }
    else
    {
        printf("\n\tMEMORY ALLOCATED WITH SUCCESS!\n");
       
        /*Get the string to be pointed*/
        getstr(text, maxSize);
        printf("\n\t\tString : %s  \n", text); 
        
        if (text == NULL)
        {
            exit(1);
        }
        
        /*Free memory*/
        free(text);
        text = NULL;
        printf("\n\tMEMORY FREED WITH SUCCESS!\n");
    }
	
    return 0;
}


/*
 * Get of the input string
 * Update strN. IF not valid: NULL.
 */
void getstr(char *strN, int MAXSIZE)
{
    /*Get the string enter by the user */
    printf("\nPlease enter the string (MAX SIZE: %d):\n", (MAXSIZE));
    
    getchar();       

    fgets(strN, MAXSIZE, stdin);
}
