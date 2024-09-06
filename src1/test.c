/*
 * Written by @asofcs
 * Copyright 2024
 */

#include <stdio.h>
#include <math.h> 

int main(void)
{
    long int nMinutes = 0; // total number of minutes (input)
    float nYears = 0.0; // total number of years (output)
    float nDays = 0.0; //total number of days (output)
    float auxDays = 0.0; // remaining days (output)
    
    /*
     * Get total minutes       
     */
    
    printf(" \tEnter the number of the Minutes:\n");
    scanf("%ld", &nMinutes);
    
    /*
     * Minutes to years       
     */
    nYears = nMinutes/(60.0*24.0*365.0); 
    
    /*
     * Remaining days       
     */
    auxDays = ceil((nYears - floor(nYears))*365.0);
    
    /*
     * Minutes to days      
     */
    nDays = ceil(nMinutes/(60.0*24.0));
     
    printf(" \t%ld minutes are approximately: \n %.0f years and %.0f days (or %.0f days) \n",nMinutes,nYears, auxDays, nDays);
  
    return 0;
}
