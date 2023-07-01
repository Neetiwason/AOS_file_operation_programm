#include <stdio.h>   // For standard I/O functions (e.g., fprintf)
#include <stdlib.h>  // For general utilities (e.g., exit, atoi, strtol)
#include <string.h>  // For string operations (e.g., strcmp)
#include <sys/types.h>  // For data types used in system calls (e.g., mode_t, off_t)
#include <fcntl.h>   // For file opening flags (e.g., O_RDONLY)
#include <unistd.h>  // For file operations (e.g., open, read, lseek, close)

#include "create/create_read_write.h"
#include "named_file/create_named_file.h"
#include "read/read_file.h"
#include "write/write_file.h"
#include "copy/copy_file.h"
#include "stats/files_stat.h"
/*
                      POSSIBLE INPUTS
  argv[0]  argv[1]    argv[2]   argv[3]     argv[4]  argv[5]
./program   read     file2.txt   100          0
./program   write    file2.txt   "Hello!"     6       0
./program   create   file2.txt    0666
./program   stats    file2.txt
./program   copy     file1.txt   file2.txt

#TODO 1:
        argv[1] == 'read':
            argc < 5:
                input wrongly "Something is missing in command"
            else: 
                call readFile func    
#TODO 2:
        argv[1] == 'write':
            argc < 6:
                exit with failure "Something is missing in command"
            else:
                call writeFile func    
#TODO 3:
        argv[1] == 'create':
            argc < 4:
                exit with failure "Something is wrong"
            else: 
                call createFile func    
#TODO 4:
        argv[1] == 'stats':
            argc < 3:
                exit with failure
            else:
                call displayFileStats function    
#TODO 5:
        argv[1] == 'copy':
            argc < 4:
                exit with failure
            else:
               call copyFile function 
#TODO 6:
        argv[1] == 'createpipe':

*/
int main(int argc, char *argv[]) {

    const char *filename = argv[2];

    if(strcmp(argv[1],"create") == 0)
    {    if (argc < 4) {
            /*
            stderr: pointer to FILE object representing the stream 
            to which the ouput will be written 

            #COMMAND
            ./createfile create myfile.txt 0666

            usage: executable_fileName(argv[0]) create <filename> <permission>
            */
            fprintf(stderr, "Usage: %s create <filename> <permissions>\n", argv[0]);
            /*
            exit the program with failure status
            */
            exit(EXIT_FAILURE);
        }
        /*
        strtol: is used here to convert the permission provided
        as a string to an integer value of type 'mode_t'
        
        argv[3]:0666---Third argument

        8: Number Base (Octal-format'0666')
        */
        mode_t permissions = strtol(argv[3], NULL, 8);

        createFile(filename, permissions);
    }
    else if (strcmp(argv[1], "read") == 0){
        if (argc < 5){
            fprintf(stderr, "Usage: %s read <filename> <numBytes> <offset>\n", argv[0]);
            exit(EXIT_FAILURE);
        }

        int numBytes = atoi(argv[3]);
        off_t offset = atoi(argv[4]);
        readFile(filename, numBytes, offset);

    }
    else if (strcmp(argv[1], "write") == 0) {
        if (argc < 6) {
            fprintf(stderr, "Usage: %s write <filename> <data> <numBytes> <offset>\n", argv[0]);
            exit(EXIT_FAILURE);
        }
        const char *data = argv[3];
        int numBytes = atoi(argv[4]);
        off_t offset = atoi(argv[5]);
        writeFile(filename, data, numBytes, offset);
    }
    else if (strcmp(argv[1], "stats") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Usage: %s stats <filename>\n", argv[0]);
            exit(EXIT_FAILURE);
        }
        displayFileStats(filename);
    }
    else if (strcmp(argv[1], "copy") == 0) {
        if (argc < 4) {
            fprintf(stderr, "Usage: %s copy <srcFilename> <destFilename>\n", argv[0]);
            exit(EXIT_FAILURE);
        }
        const char *srcFilename = argv[2];
        const char *destFilename = argv[3];
        copyFile(srcFilename, destFilename);
    }
     else if (strcmp(argv[1], "createpipe") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Usage: %s createpipe <pipename> <mode>\n", argv[0]);
            exit(EXIT_FAILURE);
        }
        const char *pipename = argv[2];
        int mode = atoi(argv[3]);
        createNamedPipe(pipename, mode);
    } else {
        fprintf(stderr, "Invalid command.\n");
        exit(EXIT_FAILURE);
    }

    

    return EXIT_SUCCESS;
}
