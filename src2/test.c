/*
 * Written by @asofcs
 * Copyright 2024
 */
 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXSIZE 100
#define MAXSTR 25
#define ERRORINT -1

void clrscr(); // clear screen
int getstr(char strN[]); // validation of the input string
int getnstr(int nStr, char strNN[MAXSTR][MAXSIZE]); // get n strings
void reversestr(char strN[]); // reversed string
void bubblesort(int nStr, char strNN[MAXSTR][MAXSIZE]); //bubblesort of strings

int main(void)
{
    
    char original[MAXSTR][MAXSIZE];
    int totalStr = 0;
    
    /*Ask to user the total number of strings required*/
    printf(" \n\t\tPlease enter the total number of strings:");
    scanf("%d", &totalStr);
    
    /*To avoid conflict with fgets*/
    getc(stdin);
    
    if (getnstr(totalStr, original) == 0)
    {
        /*revert string*/
        bubblesort(totalStr, original);
    }
    return 0;
}

/*
 *Clear Screen 
 */
void clrscr()
{
    system("clear"); // UNIX: "clear"; POSIX: "cls"
}

/*
 * Validation of the input string
 * 0: Valid. -1: Otherwise
 */
int getstr(char strN[])
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
 * Get n strings
 * 0: Valid. -1: Otherwise
 */
int getnstr(int nStr, char strNN[MAXSTR][MAXSIZE])
{
    clrscr();

    int checkVal = 0;
    
    char temp[MAXSIZE/2];
    
    if (nStr <= 0)
    {
        return ERRORINT;
    }
    for (int i = 0; i < nStr; i++)
    {
        printf("Please enter the %d string (MAX SIZE: %d):\n", i+1 , (MAXSIZE/2)-1);
        
        if (getstr(temp) == 0)
        {
            strncpy(strNN[i], temp, MAXSIZE);
        
            /*revert string*/
            reversestr(strNN[i]);
        }
        else
        {
            checkVal = ERRORINT;
        }
    }
    return checkVal;   
}

/*
 * Reversed string
 */
void reversestr(char strN[])
{
    char temp[MAXSIZE/2];
    int j = 0;
    
    if ((strlen(strN) >0) && (strN[0] != '\0'))
    {
        for(int i = strlen(strN)-1; i >=0; i--)
        {
            temp[j] = strN[i];
            j = j+1;
        }
        
        if (temp[j] != '\0')
        {
            temp[j] = '\0';
        }
        printf("\t\tString reversed: %s\n", temp);
    }
}

/*
 * Bubblesort of strings
 */
void bubblesort(int nStr, char strNN[MAXSTR][MAXSIZE])
{
    char temp[MAXSIZE/2];

    for(int i = 1; i < nStr+1; i++)
    {
        for(int j = 0; j< = nStr-i; j++)
        {
            if(strcmp(strNN[j], strNN[j+1]) > 0)
            {
                strncpy(temp, strNN[j], MAXSIZE/2);
                strncpy(strNN[j], strNN[j+1], MAXSIZE/2);
                strncpy(strNN[j+1], temp, MAXSIZE/2);
            }
        }
        
    }
    
    printf("\n\t\tStrings after sorting:\n");

    for (int i = 0; i < nStr+1; i++)
    {
        printf("%s\n", strNN[i]);

    }
}
