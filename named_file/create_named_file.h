#ifndef CREATE_NAMED_FILE_H
#define CREATE_NAMED_FILE_H
#include <sys/types.h>
void createNamedPipe(const char *pipename, int mode);
#endif