CC=x86_64-linux-gnu-gcc
AR=x86_64-linux-gnu-ar
LIB_NAME=antlibc.a
SRCS=$(shell find ./src/libc -name "*.c")
OBJS=$(SRCS:.c=.o)

ANT_SRCS=$(shell find ./src/sys/ant -name "*.c")
ANT_OBJS=$(ANT_SRCS:.c=.o)

$(LIB_NAME): $(OBJS) $(ANT_OBJS)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) -O2 -ffreestanding -nostdlib -nostdinc -Iinclude/ -Iinclude/sys -c -o $@ $<

.PHONY: clean

clean:
	rm -rf *.o $(LIB_NAME) $(OBJS) $(ANT_OBJS)
