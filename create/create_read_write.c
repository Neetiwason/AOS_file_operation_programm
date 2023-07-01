#include "create_read_write.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

// Function to create a file or named pipe

/*
#TODO: CreateFile function
         Parameter:
            filename: like myfile.txt
            permission: like 0666

         Input:
            ./program create myfile.txt 0666
         Output:
            "File/Named pipe created successfully."
*/

void createFile(const char *filename, mode_t permissions)
{
    dev_t dev = 0; // Dummy device number ,since named pipe does not require it
    if (mknod(filename, S_IFIFO | permissions, dev) == -1)
    {
        perror("Error creating file/named pipe");
        exit(EXIT_FAILURE);
    }

    printf("File/Named pipe created successfully.\n");
}
