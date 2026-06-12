int execve(const char *pathname, const char *argv, const char *argp)
{
  int ret;

  __asm__ volatile("syscall" : "=a" (ret) : "a" (59), "D" (pathname), "S" (argv), "d" (argp));

  return ret;
}
