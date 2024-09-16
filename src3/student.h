/*****************************************************************/
/*       LIBRARY STUDENT  | Vector based | asofcs | 2024         */
/*****************************************************************/

#ifndef STUDENT_H

/*
 * Store of which unit
 */
typedef struct{
    char *name;
    int ects;
    float grade;
    
}unit;

/*
 * Store a group/vector of units. Contains the total size, capacity, and average
 * 
 */
typedef struct{
    float average; // weighted average of every grade
    int size;
    int capacity;
    unit *units;

    
}student;

/*
 * Create an empty student with size 0, capacity 0, and average 0.
 * return: IF VALID: pointer to the new student. ELSE: NULL.
 */
student *student_new();

/*
 * Delete student and free all memory IF it is not NULL.
 */
void student_delete(student *stdnew);

/*
 * Update the student's average with only positive grades. 
 * return: IF VALID: average. ELSE: 0.
 */
float student_average(student *stdnew);

/*
 * Print the information for all units, and the total grade's average.
 */
void student_print(student *stdnew);

/*
 * Remove the unit with specified name.
 * return: IF VALID: 0. ELSE: -1.
 */
int student_remove(student *stdnew, const char *name);

/*
 * Insert unit in the specified position. For the last position: pos = -1.
 * return: IF VALID: inserted position. ELSE: -1.
 */
int student_insert(student *stdnew, const char *name, int ects, float grade, int pos);

/*
 * Get the total number of units/size. 
 * return: IF VALID: student's size. ELSE: -1.
 */
int student_size(student *stdnew);

/*
 * Order units by alphabetical order. 
 * return: IF VALID: 0. ELSE: -1.
 */
int student_order(student *stdnew);

#define STUDENT_H
#endif