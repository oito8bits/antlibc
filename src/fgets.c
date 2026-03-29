#include <file.h>
#include <sys/unistd.h>

char *fgets(char *s, int size, FILE *stream)
{
  read(stream->fd, s, size);
}
