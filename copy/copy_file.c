#include <unistd.h>    // For pipe, fork, read, write, close functions
#include <fcntl.h>     // For file opening flags (e.g., O_RDONLY, O_WRONLY, O_CREAT)
#include <sys/stat.h>  // For file permissions (e.g., S_IRUSR, S_IWUSR)
#include <sys/types.h> // For data types (e.g., ssize_t, mode_t)
#include <stdio.h>     // For standard I/O functions
#include <stdlib.h>    // For exit function
#include <sys/wait.h>  // For wait function

#include "copy_file.h"


// Function to copy data from one file to another using an unnamed pipe

/*
#TODO: copyFile function
        Parameter:
            srcfilesname: like file2.txt, from where you want to read data from
            destFilename: like file1.txt, to which you want to copy the data from srcfile
        Input: ./program copy file2.txt file1.txt
        Output: Done Copying
*/
void copyFile(const char *srcFilename, const char *destFilename) {
    int pipefd[2];
    
    if (pipe(pipefd) == -1) {
        perror("Error creating pipe");
        exit(EXIT_FAILURE);
    }

    int pid = fork();
    if (pid == -1) {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    }
    /*
    child: read from srcfile and write to pipe(pipfd[1])
    parent: read from pipe(pipfd[0]) and write to destination file 
    */
    if (pid == 0) {
        // Child process - write to pipe
        close(pipefd[0]);  // Close read end of the pipe

        int srcfd = open(srcFilename, O_RDONLY);
        if (srcfd == -1) {
            perror("Error opening source file");
            close(pipefd[1]);
            exit(EXIT_FAILURE);
        }

        char buffer[1024];
        ssize_t bytesRead;
        
        while ((bytesRead = read(srcfd, buffer, sizeof(buffer))) > 0) {
            if (write(pipefd[1], buffer, bytesRead) == -1) {
                perror("Error writing to pipe");
                close(srcfd);
                close(pipefd[1]);
                exit(EXIT_FAILURE);
            }
        }

        close(srcfd);
        close(pipefd[1]);
        exit(EXIT_SUCCESS);
    } else {
        
        // Parent process - read from pipe
        close(pipefd[1]);  // Close write end of the pipe
        /*
        S_IRUSR | S_IWUSR is used to set the file permissions 
        to allow the owner of the file to read and write to it.
        */
        int destfd = open(destFilename, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
        if (destfd == -1) {
            perror("Error opening destination file");
            close(pipefd[0]);
            exit(EXIT_FAILURE);
        }

        char buffer[1024];
        ssize_t bytesRead;
       
        while ((bytesRead = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
            if (write(destfd, buffer, bytesRead) == -1) {
                perror("Error writing to destination file");
                close(destfd);
                close(pipefd[0]);
                exit(EXIT_FAILURE);
            }
        }
        printf("Done Copying\n");
        close(destfd);
        close(pipefd[0]);
        wait(NULL);  // Wait for the child process to finish
        exit(EXIT_SUCCESS);
    }
}