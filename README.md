# [First-Steps-C](https://github.com/asofcs/First-Steps-C/tree/main)


IDE: CodeLite

## Sources
- [C Programming For Beginners - Master the C Language](https://www.udemy.com/course/c-programming-for-beginners-/)
- [C Primer Plus](https://www.oreilly.com/library/view/c-primer-plus/9780133432398/)
## See code: [src1/test.c](https://github.com/asofcs/First-Steps-C/blob/b8-pointers/src1/test.c), [src2/test.c](https://github.com/asofcs/First-Steps-C/blob/b8-pointers/src2/test.c), [src3/test.c](https://github.com/asofcs/First-Steps-C/blob/b8-pointers/src3/test.c), and [src4/test.c](https://github.com/asofcs/First-Steps-C/blob/b8-pointers/src4/test.c) 

## Brief Notes

### Indirection
- The ability to reference something using name, reference, or container, instead of the value itself.
 Its most commom form is the act of manipulating a value through its memory address.

### Pointers
- A pointer provides an indirect means of accessing the value of a particular data item:
  - a variable whose value is a memory address.
  - its value is the address of another location in memory that contain a value.
- Every pointer will be associated with a specific variable type.
- Its is possible to update memory in one location and the change can be seen from another location.
  - [Example](https://stackoverflow.com/questions/25044422/c-pointers-ptr-vs-ptr-vs-ptr):
    ```c
    int *ptr = &i; // same as: int *ptr; ptr = &i;
    
    Expression         Type          Value
    ----------         ----          -----
           ptr         int *         Address of i
          *ptr         int           Value stored in i
          &ptr         int **        Address of ptr variable
    
    //if i changes its value, the same will occurs for *ptr (and vice versa).
    ```

- Pointers in C make it easier to use arrays and strings.
- Allow to develop and design complex data strutures like a stack, queue, or linked list.
- Example of scanf():
    ```c
    scanf("%d", ptr);
    ```

  ### Declaration
- int *ptr;
- float *ptr;
- pointer can be of any type: void *ptr;
  - Example:
  ```c
   int i = 10;
   char ch = 'k';

   void *ptr;
   ptr = &i;
   printf("Value of i = %d\n", *(int*)ptr);
   ptr = &ch;
   printf("Value of ch = %c\n", *(char*)ptr);

  ```

  ### Initialization
- If it doesn't point to anything: int *ptr = NULL;
- If it points to a variable: int *ptr = &i;
- The value pointed by ptr (*ptr) is constant, even if its address is changed: const int *ptr = &i;
- The pointer's address is constant (&ptr), even if the value it points is changed: int *const ptr = &i;
-  *ptr and &ptr are constants: const int *const ptr  = &i;

  ### Arrays
- The pointer ptr points to the 0th element of the array (or to the first address).
  - [Example 1](https://www.geeksforgeeks.org/pointer-array-array-pointer/)
     ```c
      int arr[5] = { 1, 2, 3, 4, 5 };
      int *ptr = arr; // or  int *ptr = &arr[0]; 
      ``` 
  - [Example 2](https://www.geeksforgeeks.org/pointer-array-array-pointer/)
      ```c
     int arr[3][4] = {{10, 11, 12, 13}, {20, 21, 22, 23}, {30, 31, 32, 33}};
     int (*ptr)[4];
     ptr = arr; // or ptr = &arr[0];
      ``` 
- The expression arr[i] is equivalent to *(arr+i).

  ### Functions
- Two types of pass data to a function: pass by value, and pass by reference.
- Pass by value: a function copies the actual value of an argument into the formal parameter of the function.
  - Changes made to the parameter inside the function have no effect on the argument.
  - [Example](https://www.tutorialspoint.com/cprogramming/c_function_call_by_value.htm)
    ```c

    #include <stdio.h>

    int add(int x, int y){
    
       int z = x + y;
    
       return z;
    }
    
    int main(){
    
       int a = 10, b = 20;
       
       int c = add(a, b);
    
       printf("Addition: %d", c);
    }
    ``` 
- Pass by reference: a function copies the address of an argument into the formal parameter.
  - Changes made to the parameter affect the passed argument.
  - [Example](https://www.tutorialspoint.com/cprogramming/c_function_call_by_reference.htm)
    ```c
    #include <stdio.h>

    /* function declaration */
    int add(int *x, int *y);
    
    int main(){
    
       int a = 10, b = 20;
       int c = add(&a, &b);
       
       printf("Addition: %d", c);
    }
    
    int add(int *x, int *y){
       
       int z = *x + *y;
       
       return z;
    }
    ```
  - const int *x : The function will treat the argument that is passed for this parameter as a constant (only the address 
    can be changed).

  ### Arithmetic
- ptr++ or *(ptr+1) or ptr = ptr + 1; : Increment the address to be pointed by one. If it points to an array, it access to arr[x+1], being x the previous position.
   - [Example1](https://www.geeksforgeeks.org/pointer-arithmetics-in-c-with-examples/)
   ```c
   // C program to illustrate the array
   // traversal using pointers
   #include <stdio.h>
    
   // Driver Code
   int main()
   {
    
       int N = 5;
    
       // An array
       int arr[] = { 1, 2, 3, 4, 5 };
    
       // Declare pointer variable
       int* ptr;
    
       // Point the pointer to first
       // element in array arr[]
       ptr = arr;
    
       // Traverse array using ptr
       for (int i = 0; i < N; i++) {
    
           // Print element at which
           // ptr points
           printf("%d ", ptr[0]);
           ptr++;
       }
   }
   Output
   1 2 3 4 5 
   ```
   - [Example2](https://www.geeksforgeeks.org/strings-in-c/)
   ```c
   // C program to print string using Pointers
   #include <stdio.h>
    
   int main()
   {
    
       char str[20] = "GeeksforGeeks";
    
       // Pointer variable which stores
       // the starting address of
       // the character array str
       char* ptr = str;
    
       // While loop will run till 
       // the character value is not
       // equal to null character
       while (*ptr != '\0') {
           printf("%c", *ptr);
          
           // moving pointer to the next character.
           ptr++;
       }
    
       return 0;
   }
   Output
   GeeksforGeeks
   ```
- ++*ptr or *ptr = *ptr+1;: Increment the value to be pointed by i.

  ### Dynamic Memory Allocation
- This approach enables to allocate memory as the program is executing, and depends on the concept of a pointer.
- Dynamic memmory allocation reserves space in the Heap.
- Main functions:
  - malloc() :  dynamically allocate a single large block of memory with the specified size. It returns a pointer of type 
  void which can be cast into a pointer of any form. It doesn’t initialize memory at execution time so that it has 
  initialized each block with the default garbage value initially.[Example:](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)
  ```c
  ptr = (int*) malloc(100 * sizeof(int));
  ```
  - calloc(): dynamically allocate the specified number of blocks of memory of the specified type. it is very much similar    to malloc() but has two different points and these are: It initializes each block with a default value ‘0’, and it has 
  two parameters or arguments as compare to malloc(). [Example:](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)  
  ```c
  ptr = (int*)calloc(100, sizeof(int));
  ```
  - realloc(): dynamically change the memory allocation of a previously allocated memory. [Example:](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)  
  ```c
  ptr = (int*)realloc(ptr, 200 * sizeof(int));
  ```
  - free():  used to dynamically de-allocate the memory. [Example:](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)
  ```c
  #include <stdio.h>
  #include <stdlib.h>
  
  int main()
  {
  
      // This pointer will hold the
      // base address of the block created
      int *ptr, *ptr1;
      int n, i;
  
      // Get the number of elements for the array
      n = 5;
      printf("Enter number of elements: %d\n", n);
  
      // Dynamically allocate memory using malloc()
      ptr = (int*)malloc(n * sizeof(int));
  
      // Dynamically allocate memory using calloc()
      ptr1 = (int*)calloc(n, sizeof(int));
  
      // Check if the memory has been successfully
      // allocated by malloc or not
      if (ptr == NULL || ptr1 == NULL) {
          printf("Memory not allocated.\n");
          exit(0);
      }
      else {
  
          // Memory has been successfully allocated
          printf("Memory successfully allocated using malloc.\n");
  
          // Free the memory
          free(ptr);
          ptr = NULL;
          printf("Malloc Memory successfully freed.\n");
  
          // Memory has been successfully allocated
          printf("\nMemory successfully allocated using calloc.\n");
  
          // Free the memory
          free(ptr1);
          ptr1 = NULL;
          printf("Calloc Memory successfully freed.\n");
      }
  
      return 0;
  }
  
  Output
  Enter number of elements: 5
  Memory successfully allocated using malloc.
  Malloc Memory successfully freed.
  
  Memory successfully allocated using calloc.
  Calloc Memory successfully freed.
  ```
    

