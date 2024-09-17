# [First-Steps-C](https://github.com/asofcs/First-Steps-C/tree/main)


IDE: CodeLite

## Sources
- [C Programming For Beginners - Master the C Language](https://www.udemy.com/course/c-programming-for-beginners-/)
- [C Primer Plus](https://www.oreilly.com/library/view/c-primer-plus/9780133432398/)

## See code: [src/test.c](https://github.com/asofcs/First-Steps-C/blob/b11-recursion/src/test.c) 

## Recursion
- Recursion is the process of a function calling itself repeatedly till the given condition is satisfied. A function that calls itself directly or indirectly is called a recursive function and such kind of function calls are called recursive calls.

```c
type function_name (args) {
    // function statements
    // base condition
    // recursion case (recursive call)
}
```
- [Example](https://www.geeksforgeeks.org/c-recursion/)
  ```c
  // C Program to calculate the sum of first N natural numbers
  // using recursion
  #include <stdio.h>
  
  int nSum(int n)
  {
      // base condition to terminate the recursion when N = 0
      if (n == 0) {
          return 0;
      }
  
      // recursive case / recursive call
      int res = n + nSum(n - 1);
  
      return res;
  }
  
  int main()
  {
      int n = 5;
  
      // calling the function
      int sum = nSum(n);
  
      printf("Sum of First %d Natural Numbers: %d", n, sum);
      return 0;
  }
  
  Output
  Sum of First 5 Natural Numbers: 15


  1- nSum(5) = 5 + nSum(4)
  2- nSum(4) = 4 + nSum(3) -> nSum(5) = 5+4+nSum(13)
  3- nSum(3) = 3 + nSum(2) -> nSum(5) = 5+4+3+nSum(2)
  4- nSum(2) = 2 + nSum(1) -> nSum(5) = 5+4+3+2+nSum(1)
  5- nSum(1) = 1 + nSum(0) -> nSum(5) = 5+4+3+2+1+nSum(0)
  6- nSum(0) = 0           -> nSum(5) = 15 + 0;

  
  ```
