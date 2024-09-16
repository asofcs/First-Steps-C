/*
 * Written by @asofcs
 * Copyright 2024
 */


#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    FILE *fp = NULL; // input file
    int counter = 0; // output number of lines
    char line[256]; // string to extract each line
    
    if(argc != 2)
    {
        printf("Invalid arguments\n");
        exit(1);
    }
   
    fp = fopen(argv[1], "r"); // argv[1](argument) == "Test.txt" 
    
    if(fp == NULL)
    {
        printf("Invalid file\n");
        exit(1);
    }
    
    while (fgets(line, sizeof(line), fp)) 
    {
        counter = counter +1;
    }
    
    fclose(fp);
    fp = NULL;
    
    printf("Total number of lines: %d\n", counter);
    
    return 0;
}
