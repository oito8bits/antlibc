#include <string.h>

size_t strcmp(const char *s1, const char *s2)
{
  size_t s1_len = strlen(s1);
  size_t s2_len = strlen(s2);
  if(s1_len < s2_len)
    return -1;
  else if (s1_len > s2_len)
    return 1;

  return memcmp(s1, s2, s1_len);
}
