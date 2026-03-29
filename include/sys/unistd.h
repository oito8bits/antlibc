#ifndef _INCLUDE_WRITE_
#define _INCLUDE_WRITE_

#include <stddef.h>

size_t write(int, const void *, size_t);
size_t read(int, void *, size_t);
void _exit(int);

#endif
