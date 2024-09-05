# See code: [src1/test.c](https://github.com/asofcs/First_Steps_C/blob/variables-and-data-types/src1/test.c)
# Brief Notes
## Constants
Types of data that do not change and retain their values throughout the life of the program.
## Variables
Types of data that may change or be assigned values as the program runs.
## Naming rules
- Begin with a letter or underscore.
- Be followed by any combination of letters, underscores, or digits.
## Boolean Variables
### C99
_Bool myBool
### Alternative
#include <stdbool.h>

bool myBool
## Enumerations (Enums)
- A data type that allows a programmer to define a variable and specify the valid values that could be stored into that variable.
- [Example](https://www.geeksforgeeks.org/enumeration-enum-c/)
```c
// An example program to demonstrate working
// of enum in C

#include<stdio.h>
 
enum week{Mon, Tue, Wed, Thur, Fri, Sat, Sun};

int main()
{
    enum week day;   
    day = Wed;
    printf("%d",day);
    
    return 0;
} 

Output: 
 2
```
