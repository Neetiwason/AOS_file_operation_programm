#include <stdio.h>   // For standard I/O functions (e.g., printf)
#include <stdlib.h>  // For general utilities (e.g., exit)
#include <sys/types.h>  // For data types used in system calls (e.g., off_t)
#include <fcntl.h>   // For file opening flags (e.g., O_WRONLY)
#include <unistd.h>  // For file operations (e.g., open, write, lseek, close)


#include "write_file.h"
// Function to write data to a file

/*
#TODO: WriteFile Function
        Parameter:
            filename: like myfile.txt, where we want to write the data
            data: like "Hello Neeti here", text we want to write
            numBytes: like 16, bytes we have to write
            offset: like 0, start writing from offset 0

        Input: ./program write myFile.txt "Hello!" 6 0

        Output: Written 6 bytes to file     

*/
void writeFile(const char *filename, const char *data, int numBytes, off_t offset) {
    int fd = open(filename, O_WRONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (lseek(fd, offset, SEEK_SET) == -1) {
        perror("Error seeking file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    ssize_t bytesWritten = write(fd, data, numBytes);
    if (bytesWritten == -1) {
        perror("Error writing to file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Written %zd bytes to file.\n", bytesWritten);

    close(fd);
}
