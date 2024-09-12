# [First-Steps-C](https://github.com/asofcs/First-Steps-C/tree/main)


IDE: CodeLite

## Sources
- [C Programming For Beginners - Master the C Language](https://www.udemy.com/course/c-programming-for-beginners-/)
- [C Primer Plus](https://www.oreilly.com/library/view/c-primer-plus/9780133432398/)
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
  int *ptr = &i; // same as: int *ptr; ptr = &a;
  
  Expression         Type          Value
  ----------         ----          -----
         ptr         int *         Address of i
        *ptr         int           Value stored in i
        &ptr         int **        Address of ptr variable
  
  //if i changes its value, the same will occurs for *ptr.
  ```
  - Pointers in C make it easier to use arrays and strings.
  - Allow to develop and design complex data strutures like a stack, queue, or linked list.
  ### Declaration
  - int *ptr;
  - float *ptr;
  ### Initialization
  - If it doesn't point to anything: int *ptr = NULL;
  - If it points to a variable: int *ptr = &i;
  ### Arithmetic
  ### Dynamic Memory Allocation

