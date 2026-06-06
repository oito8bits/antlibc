int fork(void)
{
  int ret;

  __asm__ volatile("syscall" : "=a" (ret) : "a" (57));

  return ret;
}
