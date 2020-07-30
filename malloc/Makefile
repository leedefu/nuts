CC = gcc

CFLAGS = -c -Wall -g -fPIC
LDFLAGS =-lpthread -shared -dynamiclib

LIB =
INCLUDE = -I../

all:libmymalloc.so

SRCS = main.c \

OBJS = $(SRCS:.c=.o)

libmymalloc.so:$(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -rf libmymalloc.so $(OBJS)
