/*
 * Written by @asofcs
 * Copyright 2024
 */

#include <stdio.h>

#define PAYRATE 12.00 
#define TAXRATE_300 .15 // 15% of tax rate of the first 300 
#define TAXRATE_150 .20 // 20% of tax rate of the next 150 
#define TAXRATE_REST .25 // 25% of tax rate of the rest
#define OVERTIME 40
#define HOURS_WEEK 168

int main(void)
{
    int nHours = 0; // total number of work hours in a week
    float taxesPay = 0.0; // total gross payment
    float grossPay = 0.0; // total taxes payment
    
    printf("Please enter the number of hours worked in a week:\n");
    scanf("%d", &nHours);
    
     /*
     * 168h in a week 
     * Basic pay rate : 12/hour
     * Overtime (> 40h): total time + a half
     */
    if (nHours <= HOURS_WEEK)
    {
        grossPay = nHours > OVERTIME ? nHours*1.5*PAYRATE :  nHours*PAYRATE;
    }
    else
    {
        printf(" \n Invalid hours!\n");
        return -1;
    }
    
    /*
     * Taxes payment
     */
    
    if (grossPay > 450)
    {
        taxesPay = 300*TAXRATE_300+150*TAXRATE_150+(grossPay-450)*TAXRATE_REST;
    }
    else if ((grossPay > 300) && ( grossPay <= 450))
    {
        taxesPay = 300*TAXRATE_300+(grossPay-300)*TAXRATE_150;
    }
    else
    {
        taxesPay = grossPay*TAXRATE_300;
    }
    
    printf(" \n Gross Pay: %.3f\n", grossPay);
    printf(" \n Net Pay: %.3f\n", grossPay - taxesPay);
    printf(" \n Taxes: %.3f\n", taxesPay);
    
    return 0;
}
