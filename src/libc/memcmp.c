#include <stddef.h>

size_t memcmp(const void *buf1, const void *buf2, size_t count)
{
  const char *p = buf1;
  const char *q = buf2;

  while(count--)
  { 
    if(*p++ != *q++)
      return p[-1] < q[-1] ? -1 : 1;  
  } 
    
  return 0;
}
