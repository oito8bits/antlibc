#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BIT_POS(n) (1U << (n))

#define HEX_PREFIX_FLAGS BIT_POS(0)
#define ZERO_PADDED_FLAGS BIT_POS(1)
#define RIGHT_BLANK_PADDED_FLAGS BIT_POS(2)
#define BLANK_POSITIVE_SIGN_FLAGS BIT_POS(3)
#define SIGNED_NUMBER_FLAGS BIT_POS(4)

enum conversion
{
  INTEGER_CONVERSION,
  DECIMAL_CONVERSION,
  FLOAT_CONVERSION,
  HEX_CONVERSION,
  HEX_UPPERCASE_CONVERSION
};

struct format
{
  uint64_t flags;
  enum conversion conversion;
};

static void write_char(int fd, char c)
{
  char ch[2];
  ch[0] = c;
  ch[1] = '\0';
  write(fd, &ch, 1); 
}

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

void int_to_hex(char *src, unsigned long n)
{
  size_t i;
  for(i = 0; i < 16; i++)
    src[15 - i] = "0123456789abcdef"[(n >> (i * 4)) & 0xf];

  src[i] = '\0';
}

static int parse_flags(char *fmt_str, struct format *fmt)
{
  char *fmt_strp = fmt_str;
  while(*fmt_strp)
  {
    char c = *fmt_strp;
    fmt_strp++;
    switch(c)
    {
      case '#':
        fmt->flags |= HEX_PREFIX_FLAGS;
        break;
      case '0':
        fmt->flags |= ZERO_PADDED_FLAGS;
        break;
      case '-':
        fmt->flags |= RIGHT_BLANK_PADDED_FLAGS;
        break;
      case ' ':
        fmt->flags |= BLANK_POSITIVE_SIGN_FLAGS;
        break;
      case '+':
        fmt->flags |= SIGNED_NUMBER_FLAGS;
        break;
      case 'i':
        fmt->conversion = INTEGER_CONVERSION;
        goto end;
      case 'x':
        fmt->conversion = HEX_CONVERSION;
        goto end;
      default:
        goto end;
    } 
  }

end:
  return fmt_strp - fmt_str;
}

static int parse_len_mod(char *fmt_str, struct format *fmt)
{
  return 0;
}

void print_flags(FILE *stream, struct format *fmt)
{
  uint8_t flags = fmt->flags;
  size_t i;
  for(i = 0; i < 8; i++)
  {
    switch(flags & (1U << i))
    {
      case HEX_PREFIX_FLAGS:
        write(stream->fd, "0x", 2);
        return;
    }
  }
}

void print_conversion(FILE *stream, struct format *fmt, va_list ap)
{
  char res[22];
  switch(fmt->conversion)
  {
    case HEX_CONVERSION:
      int_to_hex(res, va_arg(ap, unsigned));
      write(stream->fd, res, strlen(res));
      return;
    case INTEGER_CONVERSION:
      int_to_ascii(res, va_arg(ap, int));
      write(stream->fd, res, strlen(res));
      return;
  }
}

static size_t parse_format(char *fmt_str, struct format *fmt)
{
  size_t size;
  size = parse_flags(fmt_str, fmt);
  return size;
}

int vfprintf(FILE *stream, const char *format, va_list ap)
{
  int ret = 0;
  int fd = stream->fd;
  char *str;
  struct format fmt;
  while(*format != '\0')
  {
    if(*format == '%')
    {
      memset(&fmt, 0, sizeof(struct format));
      format++;
      format += parse_format((char *) format, &fmt);
      print_flags(stream, &fmt);
      print_conversion(stream, &fmt, ap);
      continue;
    }
    else
    {
      write_char(fd, *format); 
    }
  
    format++;
    ret++;
  }
  
  return ret;
}
