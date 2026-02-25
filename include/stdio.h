#ifndef _INCLUDE_STDIO_
#define _INCLUDE_STDIO_

#include <stdarg.h>
#include <file.h>

extern FILE *stdout;

int printf(const char *format, ...);
int vfprintf(FILE *stream, const char *format, va_list ap);

#endif
