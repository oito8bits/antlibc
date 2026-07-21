#include <stddef.h>

void *memset(void *buff, int c, size_t n)
{
  char *p = buff;

  while(n--)
    *p++ = c;

  return buff;
}
