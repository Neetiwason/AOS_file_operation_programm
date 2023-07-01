#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "create_named_file.h"


// Function to create a named pipe for communication between two processes

/*
#TODO: readFile function
        Parameter:
            pipename: like myFile.txt, which you want to read
            numBytes: like 100 bytes, number of bytes you want to read
            offset: like 0, fram which offset you want to start reading

        Input:
            ./program read file2.txt 100 0
        Output:
              Read 40 bytes from file:
              hello world!..............
              pls stand up      
*/

void createNamedPipe(const char *pipename, int mode) {
    int fd;
    dev_t dev = 0 ;

    if (mode == 1) {
        // TODO: Create named pipe in read mode
        // Opening the named pipe with read-only access and required file permissions
        fd = open(pipename, O_CREAT | O_RDONLY, S_IRUSR | S_IWUSR);
    } else if (mode == 2) {
        // TODO: Create named pipe in write mode
        // Opening the named pipe with write-only access and required file permissions
        fd = open(pipename, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
    } else {
        fprintf(stderr, "Invalid pipe mode specified.\n");
        exit(EXIT_FAILURE);
    }

    if (fd == -1) {
        perror("Error opening named pipe");
        exit(EXIT_FAILURE);
    }

    if (mode == 1) {
        // TODO: Read from the pipe
        char buffer[1024];
        ssize_t bytesRead;

        while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
            printf("Read %zd bytes from the pipe: %s\n", bytesRead, buffer);
        }

        if (bytesRead == -1) {
            perror("Error reading from pipe");
            close(fd);
            exit(EXIT_FAILURE);
        }
    } else if (mode == 2) {
        // TODO: Write to the pipe
        const char *data = "Hello, pipe!";
        ssize_t bytesWritten = write(fd, data, strlen(data));

        if (bytesWritten == -1) {
            perror("Error writing to pipe");
            close(fd);
            exit(EXIT_FAILURE);
        }

        printf("Written %zd bytes to the pipe.\n", bytesWritten);
    }

    close(fd);
}









/*

*/


/*
         fd = open(pipename, O_CREAT | O_RDONLY, S_IRUSR | S_IWUSR);

         the O_CREAT flag is used to create the file if it doesn't exist, 
         and the O_WRONLY flag is used to open the file in write-only mode. 
         The S_IRUSR | S_IWUSR permissions set the file's permissions to 
         read and write for the owner of the file.
*/
