# antlibc
Libc used in Ant.

# How to build

You will need:
- `x86_64-linux-gnu-gcc`
- `make`
- `x86_64-linux-gnu-ar`

After installing the dependencies, just run:
```bash
$ make
```

# How to use

Simply implement the syscalls (or their equivalent) on whichever side uses the libc.
