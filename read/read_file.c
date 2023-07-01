#include <fcntl.h>   // For file opening flags (e.g., O_RDONLY)
#include <stdio.h>   // For standard I/O functions
#include <stdlib.h>  // For memory allocation (e.g., malloc, free)
#include <unistd.h>  // For file operations (e.g., open, read, lseek, close)
#include "read_file.h"

// Function to read data from a file

/*
#TODO: readFile function
        Parameter:
            filename: like myFile.txt, which you want to read
            numBytes: like 100 bytes, number of bytes you want to read
            offset: like 0, fram which offset you want to start reading

        Input:
            ./program read file2.txt 100 0
        Output:
              Read 40 bytes from file:
              hello world!..............
              pls stand up      
*/
void readFile(const char *filename, int numBytes, off_t offset) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (lseek(fd, offset, SEEK_SET) == -1) {
        perror("Error seeking file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    char *buffer = malloc(numBytes);
    if (buffer == NULL) {
        perror("Error allocating memory");
        close(fd);
        exit(EXIT_FAILURE);
    }

    ssize_t bytesRead = read(fd, buffer, numBytes);
    if (bytesRead == -1) {
        perror("Error reading file");
        free(buffer);
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Read %zd bytes from file:\n%s\n", bytesRead, buffer);

    free(buffer);
    close(fd);
}