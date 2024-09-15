/*
 * Written by @asofcs
 * Copyright 2024
 */


#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAXSIZE 100

int checkYear(int xYear); // validate year
int checkSalary(int xSalary); // validate salary
void printInfo(char xName[MAXSIZE], int xYear, float xSalary); //print of the information


// defining structure
typedef struct  {
    char name[MAXSIZE];
    int hireYear;
    float salary;
} employee;

	
int  main()
{
    /*declaration, and initialization of the person1*/
    employee person1 = {"Ana Silva", 2024, 1000};
    employee person2;
      
    /*initialization of the person2*/
    printf("Enter the name of the second employee: \n");
    fgets(person2.name, MAXSIZE, stdin);
    person2.name[strcspn(person2.name, "\n")] = 0;
      
    printf("Enter the hireYear of the second employee: \n");
    scanf("%d", &person2.hireYear);
      
    printf("Enter the salary of the second employee: \n");
    scanf("%f", &person2.salary);
      
    /*validation of the hiring years and salaries*/
    person1.hireYear = checkYear(person1.hireYear);
    person2.hireYear = checkYear(person2.hireYear);
    person1.salary = checkSalary(person1.salary);
    person2.salary = checkSalary(person2.salary);
      
    /*print of the information*/
    printf(" \n\t\t Employee 1:\n ");      
    printInfo(person1.name, person1.hireYear, person1.salary);
    printf(" \n\t\t Employee 2:\n ");
    printInfo(person2.name, person2.hireYear, person2.salary);
    
    return  0;
}

/*
 * Validate year
 * IF VALID: xYear. ELSE: -1.
 */
int checkYear(int xYear)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    
    return ((xYear >=0) && (xYear <= (tm->tm_year + 1900))) ? xYear : -1;
}

/*
 * Validate salary
 * IF VALID: xSalary. ELSE: -1.
 */
int checkSalary(int xSalary)
{
    return (xSalary >=0) ? xSalary : -1;
}

/*
 * Print of the information
 */
void printInfo(char xName[MAXSIZE], int xYear, float xSalary)
{
    printf(" \n Name: %s\n\n HireYear: %.0d\n\n Salary: %.2f\n ", xName, xYear, xSalary);
}
