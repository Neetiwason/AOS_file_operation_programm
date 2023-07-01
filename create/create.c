#include "create.h"
#include <stdio.h>     // Standard input/output operations (e.g., printf)
#include <stdlib.h>    // General utilities (e.g., exit)
#include <sys/types.h> // Data types used in system calls (e.g., dev_t)
#include <sys/stat.h>  // File status and mode (e.g., S_IFIFO, permissions)
#include <fcntl.h>     // File control options (e.g., mknod)

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
