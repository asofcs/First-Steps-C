/*
 * Written by @asofcs
 * Copyright 2024
 */


#include <stdio.h>


int square1(int *a); //passing by reference but a is changed only inside the function.

int square2(int *a); //passing by reference and a is changed (outside and inside).

int square3(int a); // passing by value and a is changed only inside the function.

int main(int argc, char **argv)
{
  
    int i = 0, j = 0, k = 0; // inputs
    int res1 = 0, res2 = 0, res3 = 0; //outputs
    
    printf("Please enter a integer 1:");
    scanf("%d", &i);
    
    printf("Please enter a integer 2:");
    scanf("%d", &j);
    
    printf("Please enter a integer 3:");
    scanf("%d", &k);
    
    res1 = square1(&i); // i != res1
    res2 = square2(&j); // j == res2
    res3 = square3(k); // k != res3


    printf(" \n\t\tSquare 1) : %d (final i = %d)\n ", res1, i);
    printf(" \n\t\tSquare 2) : %d (final j = %d)\n ", res2, j);
    printf(" \n\t\tSquare 3) : %d (final k = %d)\n ", res3, k);


    return 0;
}

int square1(int *a)
{
    return *a * *a;
}

int square2(int *a)
{
    *a = *a * *a;
    return *a;
}

int square3(int a)
{
    a = a * a;
    return a;
}
