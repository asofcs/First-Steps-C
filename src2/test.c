/*
 * Written by @asofcs
 * Copyright 2024
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define TEMPNAME "tmp.txt"

int main(int argc, char **argv)
{
    FILE *fp = NULL;
    FILE *fp1 = NULL;
    int counter = 0;
    char c;
    
    if(argc != 2)
    {
        printf("Invalid arguments\n");
        exit(1);
    }
   
    fp = fopen(argv[1], "r"); // argv[1] == "Test.txt"
    
    if(fp == NULL)
    {
        printf("Invalid file\n");
        exit(1);
    }
    
    fp1 = fopen(TEMPNAME, "w+"); 
    
    if(fp1 == NULL)
    {
        printf("Invalid new file\n");
        fclose(fp);
        fp = NULL;
        exit(1);
    }
    
    while (EOF != (c = fgetc(fp)))
    {
        if((islower(c) != 0) && (isalpha(c) != 0))
        {
            c = c - 32;
        }
  
        fputc(c, fp1);
    }
    
    fclose(fp);
    fp = NULL;
    
    fclose(fp1);
    fp1 = NULL;
    
    printf("Open file %s\n", TEMPNAME);
    
    return 0;
}
