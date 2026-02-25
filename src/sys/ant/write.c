#include <unistd.h>

size_t write(int fd, const void *buf, size_t count)
{
  size_t ret;

  __asm__ volatile("syscall" : "=a" (ret) : "a" (1), "D" (fd), "S" (buf), "d" (count));

  return ret;
}
