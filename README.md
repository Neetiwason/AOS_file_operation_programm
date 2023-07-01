# Project Program

This project program provides various functionalities for file operations, including reading, writing, creating, and copying files. It is a command-line tool that accepts different commands and arguments to perform specific file operations.

## Prerequisites

Before using this program, make sure you have the following installed on your system:

- C compiler (e.g., GCC)
- Standard C library
- `fcntl.h` header file
- `stdio.h` header file
- `stdlib.h` header file
- `unistd.h` header file

## Usage

To compile the program, use the following command:

```shell
gcc program.c read_file.c write_file.c create_file.c copy_file.c create_named_file.c files_stat.c -o program  
```


Replace `program.c` with the actual filename of your program source file.

To run the program, use the following command:

```shell
./program '<command>' '<arguments>'
```

Replace `<command>` and `<arguments>` with the specific command and arguments for the desired file operation. Here are the available commands and their usage:

1. `read <filename> <numBytes> <offset>` - Read data from a file.
    - Example: `./program read file2.txt 100 0`
    - Output: Displays the read bytes from the file.

2. `write <filename> <data> <numBytes> <offset>` - Write data to a file.
    - Example: `./program write file2.txt "Hello!" 6 0`
    - Output: Writes the specified data to the file.

3. `create <filename> <permissions>` - Create a new file.
    - Example: `./program create myfile.txt 0666`
    - Output: Creates a new file with the specified filename and permissions.

4. `stats <filename>` - Display file statistics.
    - Example: `./program stats file2.txt`
    - Output: Displays the statistics (e.g., file size, permissions) of the specified file.

5. `copy <srcFilename> <destFilename>` - Copy a file to another file.
    - Example: `./program copy file1.txt file2.txt`
    - Output: Copies the contents of the source file to the destination file.

6. `createpipe <pipename> <mode>` - Create a named pipe for inter-process communication.
    - Example: `./program createpipe mypipe 1`
    - Output: Creates a named pipe with the specified name and permissions.

## File Structure

The project program consists of multiple source files, each implementing a specific functionality. Here's the file structure:

- `program.c` - The main program file that handles command-line arguments and invokes the corresponding functions based on the command.
- `read_file.c` - Contains the `readFile` function to read data from a file.
- `write_file.c` - Contains the `writeFile` function to write data to a file.
- `create_file.c` - Contains the `createFile` function to create a new file.
- `copy_file.c` - Contains the `copyFile` function to copy a file to another file.
- `create_named_file.c` - Contains the `createNamedPipe` function to create a named pipe for communication between two processes.
- `files_stat.c` - Contains the `displayFileStats` function to display statistical information of a file.
- Other header files - Included as necessary for the required functionality.

## Contributing

If you want to contribute to this project, you can fork the repository and make the desired changes. Then, submit a pull request with your changes to be reviewed and merged.

## License

This project is licensed under the [MIT License](LICENSE).


