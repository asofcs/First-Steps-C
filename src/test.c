/*
 * Written by @asofcs
 * Copyright 2024
 */

#include <stdio.h>
#include <stdlib.h>


int fibonacci(int n);

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Invalid arguments\n");
        exit(1);
    }
    
    if (atoi(argv[1]) < 0) // argv[1] == 10
    {
        printf("Invalid input\n");
        exit(1);
    }
	printf("Fibonacci number of index %d:  %d", atoi(argv[1]), fibonacci(atoi(argv[1])));
	return 0;
}

int fibonacci(int n)
{
    // base condition to terminate the recursion when N = 0
    if (n == 0) {
        return 0;
    }
    
    if (n == 1) {
        return 1;
    }

    // recursive case / recursive call
    int res = fibonacci(n - 1) + fibonacci(n-2);

    return res;
}
