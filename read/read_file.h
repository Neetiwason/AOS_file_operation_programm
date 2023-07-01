#ifndef READ_FILE_H
#define READ_FILE_H
#include <sys/types.h>
void readFile(const char *filename, int numBytes, off_t offset);
#endif