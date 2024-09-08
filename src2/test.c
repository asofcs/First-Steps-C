/*
 * Written by @asofcs
 * Copyright 2024
 */


#include <stdio.h>

#define ROWSIZE 5
#define COLSIZE 12
#define STARTYEAR 2018


int main(void)
{
    float weatherArray[ROWSIZE][COLSIZE] = 
    { 
        {32, 34, 35, 37, 36, 40, 45, 26, 38, 32, 34, 40},
        {42, 34, 45, 37, 36, 40, 45, 26, 48, 32, 34, 40},                              
        {22, 34, 35, 27, 46, 20, 25, 26, 38, 32, 34, 30}, 
        {24, 24, 25, 37, 26, 40, 25, 26, 28, 32, 34, 20},
        {22, 24, 25, 27, 26, 20, 15, 26, 28, 22, 24, 20},
    }; // (x, y): rainfall amount for month y in year x
    float yearlyAverage[ROWSIZE][2]; //yearly average rainfall amount in year x. (x,0): year, (x, 1): value
    float monthAverage[2][COLSIZE]; //monthly average rainfall amount in month y. (0,y): month, (1,y): value
    float totalYearAve = 0; // total yearly average
   
    /*Yearly averages*/
    
    printf("Year \t Average\n");

    for (int i = 0; i< ROWSIZE; i++)
    {
        
        yearlyAverage[i][0] = i + STARTYEAR;

        for (int j = 0; j < COLSIZE; j++)
        {
            yearlyAverage[i][1] = yearlyAverage[i][1] + weatherArray[i][j];
        }
        
        yearlyAverage[i][1] = yearlyAverage[i][1]/COLSIZE;
        totalYearAve = totalYearAve + yearlyAverage[i][1];
        
        printf("%.0f \t %.2f\n", yearlyAverage[i][0], yearlyAverage[i][1]);
    }
    
    totalYearAve = totalYearAve/ROWSIZE;
    
    printf(" \nYearly average: %.2f\n", totalYearAve);
    
    /*Monthly average*/
    
    printf("\nMonth \t Average\n");
    
    for (int i = 0; i< COLSIZE; i++)
    {
        
        monthAverage[0][i] = i + 1;

        for (int j = 0; j < ROWSIZE; j++)
        {
            monthAverage[1][i] = monthAverage[1][i] + weatherArray[j][i];
        }
        
        monthAverage[1][i] = monthAverage[1][i]/ROWSIZE;
        
        printf("%.0f \t\t %.2f\n", monthAverage[0][i], monthAverage[1][i]);
    }
    return 0;
}
