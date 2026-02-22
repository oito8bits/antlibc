#ifndef _INCLUDE_STDIO_
#define _INCLUDE_STDIO_

#include <stdarg.h>

typedef struct
{
  unsigned fd;
} FILE;

FILE stdout[] = {{.fd = 1}};

int printf(const char *format, ...);
int vfprintf(FILE *stream, const char *format, va_list ap);

#endif
