#include <stdio.h>
#include <unistd.h>
#include <string.h>

int vfprintf(FILE *stream, const char *format, va_list ap)
{
  int ret = 0;

  while(*format != '\0')
  {
    if(*format == '%')
    {
      format++;

      switch(*format)
      {
        case 's':
          char *str = va_arg(ap, char *);
          write(1, str, strlen(str));
          break;
      }
    }
    else
    {
      char ch = *format;
      write(1, &ch, 1); 
    }
  
    format++;
    ret++;
  }

  return ret;
}
