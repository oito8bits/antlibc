#include <unistd.h>

size_t read(int fd, void *buf, size_t count)
{
  size_t ret;

  __asm__ volatile("syscall" : "=a" (ret) : "a" (0), "D" (fd), "S" (buf), "d" (count));

  return ret;
}
