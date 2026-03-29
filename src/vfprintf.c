#include <stdio.h>
#include <unistd.h>
#include <string.h>

int vfprintf(FILE *stream, const char *format, va_list ap)
{
  int ret = 0;
  int fd = stream->fd;
  while(*format != '\0')
  {
    if(*format == '%')
    {
      format++;

      switch(*format)
      {
        case 's':
          char *str = va_arg(ap, char *);
          write(fd, str, strlen(str));
          break;
      }
    }
    else
    {
      char ch = *format;
      write(fd, &ch, 1); 
    }
  
    format++;
    ret++;
  }

  return ret;
}
