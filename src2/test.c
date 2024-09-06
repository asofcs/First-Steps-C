/*
 * Written by @asofcs
 * Copyright 2024
 */
 
#include <stdio.h>

int main(void)
{
    /*
    * Display the total number of bytes (size) for different data types       
    */
    
    printf(" \t Bytes number for: \n ");
    printf(" int: %zd, char: %zd\n ", sizeof(int), sizeof(char));
    printf(" long: %zd, long long: %zd\n ", sizeof(long), sizeof(long long));
    printf(" double: %zd,  long double : %zd\n ", sizeof(double), sizeof(long double));
    
    return 0;
}

