#include <stdio.h>
#include <unistd.h>
#include <string.h>

void strrev(char *str)
{
  char *str_end = str + strlen(str) - 1;
  char ch;
  while(str_end > str)
  {
    ch = *str;
    *str++ = *str_end;
    *str_end-- = ch;
  }
}

void int_to_ascii(char *src, unsigned long n)
{
  char *str = src;

  if(!n)
  {
    *str++ = '0';
    *str = '\0';
    return;
  }

  while(n)
  {
    *str++ = n % 10 + '0';
    n /= 10;
  }

  *str = '\0';

  strrev(src);
}

int vfprintf(FILE *stream, const char *format, va_list ap)
{
  int ret = 0;
  int fd = stream->fd;
  char *str;
  while(*format != '\0')
  {
    if(*format == '%')
    {
      format++;

      switch(*format)
      {
        case 's':
          str = va_arg(ap, char *);
          write(fd, str, strlen(str));
          break;
        case 'd':
          char res[22];
          str = res;
          int_to_ascii(str, va_arg(ap, int));
          write(fd, str, strlen(str));
          break;
      }
    }
    else
    {
      char ch[2];
      ch[0] = *format;
      ch[1] = '\0';
      write(fd, &ch, 1); 
    }
  
    format++;
    ret++;
  }
  
  return ret;
}
