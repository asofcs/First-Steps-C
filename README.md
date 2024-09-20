# [First-Steps-C](https://github.com/asofcs/First-Steps-C/tree/main)

IDE: CodeLite

## Sources
- [C Programming For Beginners - Master the C Language](https://www.udemy.com/course/c-programming-for-beginners-/)
- [C Primer Plus](https://www.oreilly.com/library/view/c-primer-plus/9780133432398/)
- [Problem Solving in Data Structures and Algorithms using C](https://www.amazon.com/Problem-Solving-Structures-Algorithms-Using-dp-935620280X/dp/935620280X/ref=dp_ob_image_bk)

## See code: [src1/test.c](https://github.com/asofcs/First-Steps-C/blob/b9-structures/src1/test.c) [src2/test.c](https://github.com/asofcs/First-Steps-C/blob/b9-structures/src2/test.c), [src3/test.c](https://github.com/asofcs/First-Steps-C/blob/b9-structures/src3/test.c), and  [src4/test.c](https://github.com/asofcs/First-Steps-C/blob/b9-structures/src4/test.c)
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

- [Example](https://www.geeksforgeeks.org/structures-c/)
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

## Pointers
- In some older versions of C, a structure can't be passed as an argument to a function, but a pointer to structure can. 
- [Example](https://www.geeksforgeeks.org/structures-c/)
```c
// C program to illustrate the structure pointer
#include  <stdio.h>

// structure declaration
typedef struct{
    int  x,  y;
} point;

int  main()
{
    point  str  =  {  1,  2  };

    // p2 is a pointer to structure str
    point  *ptr  =  &str;

    // Accessing structure members using structure pointer
    printf("%d %d",  ptr->x,  ptr->y); // or (*ptr).x, (*ptr).y 

    return  0;
}

    
Output

1 2

```
- A pointer also can be a member of a structure.

## Functions
- [Passing by value method](https://www.geeksforgeeks.org/how-to-pass-or-return-a-structure-to-or-from-a-function-in-c/)
```c
// C program to pass structure as an argument to the
// functions using Call By Value Method
#include <stdio.h>
 
struct car {
    char name[30];
    int price;
};
 
void print_car_info(struct car c)
{
    printf("Name : %s", c.name);
    printf("\nPrice : %d\n", c.price);
}
 
int main()
{
    struct car c = { "Tata", 1021 };
    print_car_info(c);
    return 0;
}

Output
Name : Tata
Price : 1021

```
- [Passing by reference method](https://www.geeksforgeeks.org/how-to-pass-or-return-a-structure-to-or-from-a-function-in-c/)
```c
// C program to pass structure as an argument to the
// functions using Call By Reference Method
 
#include <stdio.h>
 
struct student {
    char name[50];
    int roll;
    float marks;
};
 
void display(struct student* student_obj)
{
    printf("Name: %s\n", student_obj->name);
    printf("Roll: %d\n", student_obj->roll);
    printf("Marks: %f\n", student_obj->marks);
}
int main()
{
    struct student st1 = { "Aman", 19, 8.5 };
 
    display(&st1);
 
    return 0;
}
Output
Name: Aman
Roll: 19
Marks: 8.500000
```
- [Return a structure From functions](https://www.geeksforgeeks.org/how-to-pass-or-return-a-structure-to-or-from-a-function-in-c/)
```c
// C program to return a structure from a function
#include <stdio.h>
 
struct student {
    char name[20];
    int age;
    float marks;
};
 
// function to return a structure
struct student get_student_data()
{
    struct student s;
 
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter age: ");
    scanf("%d", &s.age);
    printf("Enter marks: ");
    scanf("%f", &s.marks);
 
    return s;
}
 
int main()
{
    // structure variable s1 which has been assigned the
    // returned value of get_student_data
    struct student s1 = get_student_data();
    // displaying the information
    printf("Name: %s\n", s1.name);
    printf("Age: %d\n", s1.age);
    printf("Marks: %.1f\n", s1.marks);
 
    return 0;
}
Output:

Enter name: Krishna
Enter age: 21
Enter marks: 99
Name: Krishna
Age: 21
Marks: 99.0

```

## Vectors
Basically dynamic arrays in which storage is handled automatically allowing it to be expanded and contracted as needed.

## Graphs
- A graph is represented by ordered pair G where G = (V,E):
   - V: a finite set of points called vertices
   - E: a finite set of points called edges. Each edge is a pair (a,b) where a,b ∈ V.

![GeeksForGeeks](https://github.com/user-attachments/assets/c4302e4c-2d4a-45ef-a4c9-58c5ccbcae03)

- Undirected Graph: a graph in which edges have no directions. An edges (a,b) is identical to an edge (b,a).
- Directed Graph: a graph in which edges have a direction. The edges of the graph are one way.
