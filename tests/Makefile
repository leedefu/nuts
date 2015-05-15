CPP = g++
CC = gcc

CFLAGS = -c -Wall -g
CPPFLAGS = -c -Wall -g

LIB =
INCLUDE =

all:test

test: virtual_inherit.o
	$(CPP) $(LIB) $(INCLUDE) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

.cpp.o:
	$(CPP) $(CPPFLAGS) $(INCLUDE) -c $<

clean:
	rm -rf *.o test
