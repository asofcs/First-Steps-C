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


