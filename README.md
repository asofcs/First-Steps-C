# [First-Steps-C](https://github.com/asofcs/First-Steps-C/tree/main)

IDE: CodeLite

## Sources
- [C Programming For Beginners - Master the C Language](https://www.udemy.com/course/c-programming-for-beginners-/)
- [C Primer Plus](https://www.oreilly.com/library/view/c-primer-plus/9780133432398/)
## See code: [src1/test.c](https://github.com/asofcs/First-Steps-C/blob/b5-arrays/src1/test.c) and [src2/test.c](https://github.com/asofcs/First-Steps-C/blob/b5-arrays/src2/test.c)
## Brief Notes

### Arrays
- Allow to group variables under a single name.
- An array is a fixed number of data items (elements) that are all the same type.
- Examples:
    - int arr[5] = {10, 20, 30, 40, 50} *(all elements initialized)*
    - int arr[5] = {10} *(the first element initialized)*
    - int arr[5] *(none of the elements initialized)*
- First element: arr[0]
- Out of bounds error is a runtime error.

### Multidimension Arrays
- Example (2D) - 3 rows and 4 columns:
    - int x[3][4] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}} *(all elements initialized)*
    - int x[3][4] = {{0}, {4}, {8}} *(the first element initialized / per row)*
    - int x[3][4] *(none of the elements initialized)*

### Variable Length Arrays (VLAs)
- Example: int arr[size(int)+1]
