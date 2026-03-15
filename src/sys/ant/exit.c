void _exit(int status)
{
  __asm__ volatile("syscall" : : "a" (60), "D" (status));
}
