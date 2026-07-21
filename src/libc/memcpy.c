#include <stddef.h>

void *memcpy(void *dest, const void *src, size_t n)
{
  char *p = dest;
  const char *q = src;

  while(n--)
    *p++ = *q++;;

  return dest;
}
