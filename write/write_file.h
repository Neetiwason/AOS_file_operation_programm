#ifndef WRITE_FILE_H
#define WRITE_FILE_H
#include <sys/types.h>
void writeFile(const char *filename, const char *data, int numBytes, off_t offset);
#endif