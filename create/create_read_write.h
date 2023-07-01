#ifndef CREATE_READ_WRITE_H
#define CREATE_READ_WRITE_H
#include <sys/types.h>
void createFile(const char *filename, mode_t permissions);
void displayFileStats(const char *filename);
void copyFile(const char *srcFilename, const char *destFilename); 
#endif