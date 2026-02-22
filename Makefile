CC=x86_64-linux-gnu-gcc
AR=x86_64-linux-gnu-ar
LIB_NAME=antlibc.a
OBJS=src/printf.o

$(LIB_NAME): $(OBJS)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) -O2 -ffreestanding -nostdlib -nostdinc -Iinclude/ -c -o $@ $<

.PHONY: clean

clean:
	rm -rf *.o $(LIB_NAME)
