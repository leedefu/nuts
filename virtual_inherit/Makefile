CPP = g++
CC = gcc

CFLAGS = -std=c++0x -c -Wall -g
CPPFLAGS = -std=c++0x -c -Wall -g 

LIB =
INCLUDE =

all:virtual_inherit

virtual_inherit: main.o
	$(CPP) $(LIB) $(INCLUDE) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

.cpp.o:
	$(CPP) $(CPPFLAGS) $(INCLUDE) -c $<

clean:
	rm -rf *.o virtual_inherit
