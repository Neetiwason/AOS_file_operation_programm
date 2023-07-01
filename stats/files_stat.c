#include <sys/types.h> // For data types (e.g., uid_t, mode_t)
#include <sys/stat.h>  // For file information (e.g., struct stat, stat)
#include <stdio.h>     // For standard I/O functions
#include <stdlib.h>    // For exit function
#include <time.h>      // For time-related functions (e.g., ctime)

#include "files_stat.h"

// Function to display statistical information of a file

/*
#TODO: displayFileStats function
        Parameter:
            filesname: like myfile.txt, of which you want to see stats of

        Input: ./program stats  myfile.txt

        Output:File Information:
                Owner: 501
                Permissions: 10644
                Inode: 6034742
                Access time: Wed Jun 28 18:42:14 2023
                Modification time: Wed Jun 28 18:42:14 2023
                Change time: Wed Jun 28 18:42:14 2023
*/
void displayFileStats(const char *filename)
{
    struct stat fileStat;

    if (stat(filename, &fileStat) == -1)
    {
        perror("Error getting file statistics");
        exit(EXIT_FAILURE);
    }

    printf("File Information:\n");
    printf("Owner: %u\n", fileStat.st_uid);
    printf("Permissions: %o\n", fileStat.st_mode);
    printf("Inode: %llu\n", fileStat.st_ino);
    printf("Access time: %s", ctime(&fileStat.st_atime));
    printf("Modification time: %s", ctime(&fileStat.st_mtime));
    printf("Change time: %s", ctime(&fileStat.st_ctime));
}