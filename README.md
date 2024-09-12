# [First-Steps-C](https://github.com/asofcs/First-Steps-C/tree/main)

IDE: CodeLite

## Sources
- [C Programming For Beginners - Master the C Language](https://www.udemy.com/course/c-programming-for-beginners-/)
- [C Primer Plus](https://www.oreilly.com/library/view/c-primer-plus/9780133432398/)

## Brief Notes
### Strings
- A string constant or string literal is a sequence of characters or symbols between a pair of double-quote characters.
- Includes any special characters and embedded spaces.
- A sequence of characters terminated with a null character ‘\0’.
- [Examples:](https://www.geeksforgeeks.org/strings-in-c/)
    - char str[50];
    - char str[] = "GeeksforGeeks";
    - char str[50] = "GeeksforGeeks";
    - char str[14] = { 'G','e','e','k','s','f','o','r','G','e','e','k','s','\0'};
    - char str[] = { 'G','e','e','k','s','f','o','r','G','e','e','k','s','\0'};
- To assign a value to a char array after it has been declared or initialized is required to use strncpy() or strcpy()
- No need to use the & on scanf(). The string is read only until the whitespace is encountered.
```c
// C Program to take input string which is separated by
// whitespaces
#include <stdio.h>
 
// driver code
int main()
{
 
    char str[20];
    // taking input string
    scanf("%s", str);
 
    // printing the read string
    printf("%s", str);
   
    return 0;
}

Input
Geeks for Geeks

Output
Geeks
```
- fgets(): scanf() alternative.
- puts(): printf() alternative.
- strcmp(): string comparison.

  


