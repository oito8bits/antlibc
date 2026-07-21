#ifndef _INCLUDE_STRING_
#define _INCLUDE_STRING_

#include <stddef.h>

size_t strlen(const char *);
size_t memcmp(const void *buf1, const void *buf2, size_t count);
size_t strcmp(const char *s1, const char *s2);
void *strcpy(char *dest, const char *src);
void *memcpy(void *dest, const void *src, size_t n);
void *memset(void *buff, int c, size_t n);

#endif
