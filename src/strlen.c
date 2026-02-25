#include <string.h>

size_t strlen(const char *string)
{
  const char *string_ptr = string;
  
  while(*string++);

  return string - string_ptr - 1; 
}
