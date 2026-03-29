#ifndef _INCLUDE_STDIO_
#define _INCLUDE_STDIO_

#include <stdarg.h>
#include <file.h>

extern FILE _stdin;
extern FILE _stdout;

#define stdin &_stdin
#define stdout &_stdout

char *fgets(char *s, int size, FILE *stream);
int printf(const char *format, ...);
int vfprintf(FILE *stream, const char *format, va_list ap);

#endif
