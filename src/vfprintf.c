int vfprintf(FILE *stream, const char *format, va_list ap)
{
  va_list arg;
  va_start(arg, format);
  
  while(*format != '\0')
  {
    if(*format == '%')
    {
      format++;

      switch(*format)
      {
        //case 's':
          //syscall(SYSCALL_WRITE, );
      }
    }
  }

  va_end(arg);
}
