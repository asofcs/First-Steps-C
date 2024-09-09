/*
 * Written by @asofcs
 * Copyright 2024
 */

#include <stdio.h>

#define ERRORINT -1

float absoluteValue(float a); // absolute value of a number
int gcd(int a, int b); // greatest common divisor. -1 if argument is non-positive.
float squareRoot(float a); // square root of a number. -1 if argument is negative.


int main(void)
{
    printf(" \n Absolute value of 6: %.3f\n ", absoluteValue(6));
    printf(" \n Absolute value of -6: %.3f\n ", absoluteValue(-6));
    printf(" \n Greater common divisor between 24 and 18: %d\n ",  gcd(24,18));
    printf(" \n Greater common divisor between 24 and -18: %d\n ",  gcd(24,-18));
    printf(" \n Square root value for 50000: %.3f\n ",  squareRoot(50000));
    printf(" \n Square root value for -50000: %.3f\n ",  squareRoot(-50000));
    printf(" \n Square root value for 0: %.3f\n ",  squareRoot(0));
  
	return 0;
}

float absoluteValue(float a)
{
    return (a < 0) ? -a : a;   
}


int gcd(int a, int b)
{
    
    int gcdValue = 0;
    
    /* return -1 if a or b are negative*/
    if (((int)absoluteValue(a) != a) || ((int)absoluteValue(b) != b))
    {
        return ERRORINT;
    }
    
    /* return -1 if a or b are 0*/
    if ((a == 0) || (b == 0))
    {
        return ERRORINT;
    }
    
    /*initial guess: minimum value*/
    gcdValue = (a < b) ? a : b;
    
    /*solution found: if both values divisible by gcdvalue. else: decrement gcdvalue*/
    while (gcdValue > 0)
    {
        if( (a % gcdValue == 0) && (b % gcdValue == 0))
        {
            break;
        }
        gcdValue = gcdValue - 1;
    }
    
    return gcdValue;    
}


float squareRoot(float a)
{
    float sqrtFloats[6] = {0, 0, 0.1, 0.1, 0, 0}; //0: start, 1: end, 2: increment; 3: error; 4: average, 5: average^2;
    
    /* return -1 if a is negative*/
    if (absoluteValue(a) != a)
    {
        return ERRORINT;
    }
    
    /*initial upper limit (end)*/
    sqrtFloats[1] = a;
    
    while(absoluteValue(sqrtFloats[5]-a) >= sqrtFloats[3])
    {
        /* average */ 
        sqrtFloats[4] = (sqrtFloats[0]+sqrtFloats[1])/2;
        
        /* average*average*/
        sqrtFloats[5] = sqrtFloats[4] * sqrtFloats[4];
        
        /*Perfect square*/
        if (sqrtFloats[5] == a)
        {
            break;
        }
        
        /* Decrement end if too high*/
        if (sqrtFloats[5] > a)
        {
            sqrtFloats[1] =  sqrtFloats[1] - sqrtFloats[2];
        }
        
        /* Increment start if too low*/
        if (sqrtFloats[5] < a)
        {
            sqrtFloats[0] =  sqrtFloats[0] + sqrtFloats[2];
        }
    }
    
    return sqrtFloats[4];
}
