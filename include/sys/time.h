#ifndef _INCLUDE_TIME_
#define _INCLUDE_TIME_

typedef long time_t;
typedef long tv_usec;

struct timeval
{
  time_t tv_sec;
  suseconds tv_usec;
};

#endif
