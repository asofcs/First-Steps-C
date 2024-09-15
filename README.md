# [First-Steps-C](https://github.com/asofcs/First-Steps-C/tree/main)

IDE: CodeLite

## Sources
- [C Programming For Beginners - Master the C Language](https://www.udemy.com/course/c-programming-for-beginners-/)
- [C Primer Plus](https://www.oreilly.com/library/view/c-primer-plus/9780133432398/)
## See code: [src1/test.c](https://github.com/asofcs/First-Steps-C/blob/b9-structures/src1/test.c)
## Structures
- Another tool for grouping elements together.
- Declaration
```c 
struct structure_name 
{  
	data_type member_name1;  
	data_type member_name2;  
}variable_declaration_with_structure_template;

```
- The typedef keyword is used to define an alias for the already existing datatype.
```c 
typedef struct 
{  
	data_type member_name1;  
	data_type member_name2;  
}variable_declaration_with_structure_template;

```
- [Example1](https://www.geeksforgeeks.org/structures-c/)
```c
	// C Program to illustrate the use of structures
	#include  <stdio.h>

	struct string1{
	  int  a;
	}  str2;

	struct string2{
	  int  x;
	}  str2;

        int  main()
        {
            // creating structure variables using new names
            struct string1  var1  =  {  20  }; // OR var1.a = 20;
            struct string2  var2  =  {  314  }; // OR var2.x = 314;
          
            printf("var1.a = %d\n",  var1.a);
            printf("var2.x = %d\n",  var2.x);
          
            return  0;
         }
          	
        Output
        
        var1.a = 20
        var2.x = 314

```
- [Example2](https://www.geeksforgeeks.org/structures-c/)
```c
	// C Program to illustrate the use of typedef with
	// structures
	#include  <stdio.h>

	// defining structure
	typedef  struct  {
	  int  a;
	}  str1;

	typedef  struct  {
	  int  x;
	}  str2;

	int  main()
	{
	  // creating structure variables using new names
	  str1  var1  =  {  20  }; // OR var1.a = 20;
	  str2  var2  =  {  314  }; // OR var2.x = 314;

	  printf("var1.a = %d\n",  var1.a);
	  printf("var2.x = %d\n",  var2.x);

	  return  0;
	}

	  
	Output

	var1.a = 20
	var2.x = 314
  ```
## Arrays
- Declaration:
```c
struct type array[MAXSIZE];
```
- Initialization: similar to initialization of multidimensional arrays.
- [Example](https://www.geeksforgeeks.org/c-array-of-structure/)
```c
// C program to demonstrate the array of structures 
#include <stdio.h> 
  
// structure template 
struct Employee { 
    char Name[20]; 
    int employeeID; 
    int WeekAttendence[7]; 
}; 
  
// driver code 
int main() 
{ 
    // defining array of structure of type Employee 
    struct Employee emp[5]; 
  
    // adding data 
    for (int i = 0; i < 5; i++) { 
        emp[i].employeeID = i; 
        strcpy(emp[i].Name, "Amit"); 
        int week; 
        for (week = 0; week < 7; week++) { 
            int attendence; 
            emp[i].WeekAttendence[week] = week; 
        } 
    } 
    printf("\n"); 
  
    // printing data 
    for (int i = 0; i < 5; i++) { 
        printf("Emplyee ID: %d - Employee Name: %s\n", 
               emp[i].employeeID, emp[i].Name); 
        printf("Attendence\n"); 
        int week; 
        for (week = 0; week < 7; week++) { 
            printf("%d ", emp[i].WeekAttendence[week]); 
        } 
        printf("\n"); 
    } 
  
    return 0; 
}

Output

Emplyee ID: 0 - Employee Name: Amit  
Attendence  
0 1 2 3 4 5 6   
Emplyee ID: 1 - Employee Name: Amit  
Attendence  
0 1 2 3 4 5 6   
Emplyee ID: 2 - Employee Name: Amit  
Attendence  
0 1 2 3 4 5 6   
Emplyee ID: 3 - Employee Name: Amit  
Attendence  
0 1 2 3 4 5 6   
Emplyee ID: 4 - Employee Name: Amit  
Attendence  
0 1 2 3 4 5 6
```
- It is also possible to define structures that contain arrays as members.

## Nested Structures
- Declaration
```c
struct member_str 
{
    int member_str1;
    char member_str2;
    ...
}

struct parent 
{
    int member1;
    struct member_str member2;
    ...
}

```

- Example
```c
// C Program to illustrate structure nesting along with
// forward declaration
#include <stdio.h>

// child structure declaration
struct child {
    int x;
    char c;
};

// parent structure declaration
struct parent {
    int a;
    struct child b;
};

// driver code
int main()
{
    struct parent var1 = { 25, 195, 'A' };

    // accessing and printing nested members
    printf("var1.a = %d\n", var1.a);
    printf("var1.b.x = %d\n", var1.b.x);
    printf("var1.b.c = %c", var1.b.c);

    return 0;
}

```
- It is possible to set up an array of nested structures.

