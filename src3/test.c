/*
 * Written by @asofcs
 * Copyright 2024
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char **argv)
{
    FILE *fp = NULL;
    long totalSize = 0;
    
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
    
    fseek(fp, 0, SEEK_END); // seek to end of file
    totalSize = ftell(fp); // get total size in the current position


    for (int i = totalSize-1; i >= 0; i--)
    {   
        fseek(fp, i, SEEK_SET); // seek to position i from the beginning
        printf("%c", fgetc(fp)); // print reversed char
    }
   
    fclose(fp);
    fp = NULL;
    
    return 0;
}
