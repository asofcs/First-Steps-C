/*
 * Written by @asofcs
 * Copyright 2024
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> 

#define RANDMAX 20 // Minimum value to the random number
#define RANDMIN 10 // Maximum value to the random number
#define GUESSES 5 // Total number of guesses


int main(void)

{   
    unsigned int rightNumber =  RANDMIN; // right number
    unsigned int guessedNumber  = 0; // guessed number
    int auxGuess = 0; // current number of guesses
    time_t t = 0; // time variable for random number generator seed
    
    
    /*Random number generator seed*/
    srand((unsigned) time(&t));
     
    /*Random number generator*/
    rightNumber =  rand() % (RANDMAX - RANDMIN + 1) + RANDMIN;
    
    for (auxGuess = 1; auxGuess <= GUESSES; auxGuess++)
    {
        printf(" \nGuess a integer number (%u-%u) - Try %u/%u:\n ", RANDMIN, RANDMAX, auxGuess, GUESSES);
        scanf("%u", &guessedNumber);
        
        /*Right Guess*/
        if (guessedNumber == rightNumber)
        {
            printf(" \n\tCorrect!\n ");
            break;
        }
        
        /*Wrong guess - Too high*/
        else if ((guessedNumber > rightNumber) && (auxGuess != GUESSES) && ((guessedNumber <= RANDMAX)  && (guessedNumber >= RANDMIN)))
        {
            printf(" \n\tToo High...Try Again!\n ");
        }
        
        /*Wrong guess - Too Low*/
        else if ((guessedNumber < rightNumber) && (auxGuess != GUESSES) && ((guessedNumber <= RANDMAX)  && (guessedNumber >= RANDMIN)))
        {
            printf(" \n\tToo Low...Try Again!\n ");
        }
        
        /*Wrong guess - Limits*/
        else if (((guessedNumber > RANDMAX) || (guessedNumber < RANDMIN) ) && (auxGuess != GUESSES))
        {
            printf(" \n\tOut of limits...Try Again!\n ");
        }
        
        /*Wrong guess - Last guess*/
        else
        {
            printf(" \n\tGame Over! The number was %u\n ", rightNumber);
        }
    }
    
	return 0;
}
