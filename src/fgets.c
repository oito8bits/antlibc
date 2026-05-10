#include <file.h>
#include <sys/unistd.h>

char *fgets(char *s, int size, FILE *stream)
{
  size_t ret = read(stream->fd, s, size);
  s[ret] = '\0';
}
