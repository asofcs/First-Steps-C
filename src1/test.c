/*
 * Written by @asofcs
 * Copyright 2024
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAXSIZE 200

char strR[MAXSIZE];
char str1[MAXSIZE/2];
char str2[MAXSIZE/2];

int getstr(char strN[]); // validation of the input string
int countchar(const char strN[]); // count the number of characters in a string (length)
void concatstr(char strRes[], const char strN1[], const char strN2[]); // concatenate two character strings
bool comparestr(const char strN1[], const char strN2[]); // compare two strings

int main(void)
{
  
    int result[2] = {-1,-1};
    
    printf("Please enter the first string (MAX SIZE: %d):\n", (MAXSIZE/2)-1);
    result[0] = getstr(str1); 
    printf("Please enter the second string (MAX SIZE: %d):\n", (MAXSIZE/2)-1);
    result[1] = getstr(str2);  
  
    if ((result[0] == 0) && (result[1] == 0))
    {
        printf("\t\tString 1 with %d chars: %s\n", countchar(str1), str1);
        printf("\t\tString 2 with %d chars: %s\n", countchar(str2), str2);
        printf("\t\tString 1 == String 2? %d \n", comparestr(str1, str2));
        concatstr(strR, str1, str2);
        printf("\t\tString concatenation: %s\n", strR);        
    }
	return 0;
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
 * Count the number of characters in a string (length)
 */
int countchar(const char strN[])
{
    int counter = 0;
    
    for(int i = 0; i< (MAXSIZE/2); i++)
    {
        if((strN[i] == '\0') || (strN[i] == '\n'))
        {
            break;
        }
        
        else
        {
            counter = counter + 1;
        }
    }
    
    return counter;
}

/*
 * Compare two strings
 * true/1 if equal, otherwise false/0
 */
bool comparestr(const char strN1[], const char strN2[])
{
    bool compareFlag = false;
    int counter  = 0;
    
    if((countchar(strN1) == 0) || (countchar(strN2) == 0))
    {
        return compareFlag;
    }
    
    else if(countchar(strN1) == countchar(strN2))
    {
        for (int i = 0; i < countchar(strN1) ; i++)
        {
            if(strN1[i] == strN2[i])
            {
                counter = counter + 1;
            }
        }
        
        if(counter == countchar(strN1))
        {
            compareFlag = true;
        }
    }
    
    return compareFlag;    
} 

/*
 * Concatenate two character strings
 */
void concatstr(char strRes[], const char strN1[], const char strN2[])
{
    bool auxFlag = false;
    int auxSize = 0;
    
    if((countchar(strN1) != 0) && (countchar(strN2) != 0))
    {
        auxFlag = true;
    }
    
    if(auxFlag == 1)
    {
        for (int i = 0; i < countchar(strN1) ; i++)
        {
            strRes[i] = strN1[i];
        }
        
        for (int i = 0; i < countchar(strN2) ; i++)
        {
            strRes[i+countchar(strN1)] = strN2[i];
        }
        
        auxSize = countchar(strRes);
        
        if (strRes[auxSize+1] != '\0')
        {
            strRes[auxSize+1] = '\0';
        }
    }
}
