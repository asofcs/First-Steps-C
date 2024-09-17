# [First-Steps-C](https://github.com/asofcs/First-Steps-C/tree/main)

IDE: CodeLite

## Sources
- [C Programming For Beginners - Master the C Language](https://www.udemy.com/course/c-programming-for-beginners-/)
- [C Primer Plus](https://www.oreilly.com/library/view/c-primer-plus/9780133432398/)
## See code: [src1/test.c](https://github.com/asofcs/First-Steps-C/blob/b10-files/src1/test.c) [src2/test.c](https://github.com/asofcs/First-Steps-C/blob/b10-files/src2/test.c), and [src3/test.c](https://github.com/asofcs/First-Steps-C/blob/b10-files/src3/test.c) 
## Files
- Text files: It contains data in the form of ASCII characters and is generally used to store a stream of characters: *plain text files, html, xml, etc.*
- Binary files: It requires a knowledge of the structure so that it can be read correctly: *images, videos, songs, etc.*
- Main functions:
  - fopen(): opens the filename pointed to, by filename using the given mode:
    
    - **r**: *Opens the file for reading only*. If the file is opened successfully fopen() loads it into memory and sets up a pointer that points to the first character in it. If the file cannot be opened fopen() returns NULL.
    - **r+**: *Opens the file for both reading and writing*. If opened successfully, fopen() loads it into memory and sets up a pointer that points to the first character in it. Returns NULL, if unable to open the file.
    - **rb**: *Open the binary file in read mode*. If the file does not exist, the open() function returns NULL.
    - **rb+**: *Open the binary file in read and write mode*. If the file does not exist, the open() function returns NULL.
    - **a**: If the file is opened successfully fopen() loads it into memory and sets up a pointer that points to the last character in it. If the file doesn’t exist, a new file is created. Returns NULL, if unable to open the file. *The file is opened only for appending(writing at the end of the file).*
    - **ab**: *Open the binary file in append mode*. The file pointer is set after the last character in the file. A new file is created if no file exists with the name.
    - **ab+**: *Open the binary file in read and append mode*. A file will be created if the file does not exist.
    - **a+**: If the file is opened successfully fopen( ) loads it into memory and sets up a pointer that points to the last character in it. If the file doesn’t exist, a new file is created. Returns NULL, if unable to open the file. *The file is opened for reading and appending(writing at the end of the file).*
    - **w**: If the file exists already, its contents are overwritten. If the file doesn’t exist, a new file is created. Returns NULL, if unable to open the file. *It creates a new file for writing only(no reading).*
    - **w+**: If the file exists, its contents are overwritten. If the file doesn’t exist, a new file is created. Returns NULL, if unable to open the file. *The difference between w and w+ is that we can also read the file created using w+.*
    - **wb**: *Open the binary file in write mode.* As the pointer is set to the start of the file, the contents are overwritten. If the file does not exist, a new file is created
    - **wb+**: *Open the binary file in read and write mode.* Contents are overwritten if the file exists. It will be created if the file does not exist.

  - fclose(): used to close a file that was previously opened using fopen().
  - fgets(): reads a line from the specified stream -  from a file or from standard input (stdin) -, and stores it into the string pointed to by str.
  - fputs(): writes a string to the specified stream up to but not including the null character.
  - fscanf(): reads formatted input from a stream. This function allows for extracting and parsing data from a file according to a specified format.
  - fprintf(): used to write formatted data to a stream.
  - fwrite(): writes the to the file stream in the form of binary data block.
  - fread(): reads data from the given stream into the array pointed to, by ptr. It is commonly used for reading binary files but can be used for text files as well.
  - fseek(): sets the file position of the stream to the given offset:
    - **SEEK_SET**: Beginning of the file.
    - **SEEK_CUR**: Current position of the file pointer.
    - **SEEK_END**: End of the file.
  - ftell(): returns the current file position of the given stream.
  - rename(): causes the filename referred to by old_filename to be changed to new_filename. *The file must be closed.*



