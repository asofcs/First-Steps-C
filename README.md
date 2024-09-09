# First_Steps_C

IDE: CodeLite

## Sources
- [C Programming For Beginners - Master the C Language](https://www.udemy.com/course/c-programming-for-beginners-/)
- [C Primer Plus](https://www.oreilly.com/library/view/c-primer-plus/9780133432398/)

## Brief Notes
### Function
- A self-contained unit of program code designed to accomplish a particular task.
- Allow for the divide and conquer strategy.
- [Example](https://www.geeksforgeeks.org/c-functions/):
```c
// C program to show function
// call and definition
#include <stdio.h>

// Function that takes two parameters 
// a and b as inputs and returns 
// their sum
int sum(int a, int b) 
{ 
  return a + b; 
}

// Driver code
int main()
{
  // Calling sum function and 
  // storing its value in add variable
  int add = sum(10, 30);
  
  printf("Sum is: %d", add);
  return 0;
}

Output
Sum is: 40
```

### Function Prototypes
- Function prototype works like a function declaration where it is necessary where the function reference or call is present before the function definition.
- [Example](https://www.geeksforgeeks.org/function-prototype-in-c/)
```c
/ C program to illustrate the function prototye
#include <stdio.h>
 
// Function prototype
float calculateRectangleArea(float length, float width);
 
int main()
{
    float length = 5.0;
    float width = 3.0;
 
    // Function call
    float area = calculateRectangleArea(length, width);
 
    printf("The area of the rectangle is: %.2f\n", area);
 
    return 0;
}
 
// Function definition
float calculateRectangleArea(float length, float width)
{
    return length * width;
}

Output
The area of the rectangle is: 15.00


```


