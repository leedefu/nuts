CPP = g++
CC = gcc

CFLAGS = -std=c++0x -c -Wall -g
CPPFLAGS = -std=c++0x -c -Wall -g 

LIB = -lpthread
INCLUDE =

all:threadcancel

threadcancel: main.o
	$(CPP) $(INCLUDE) $^ -o $@ $(LIB) 

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

.cpp.o:
	$(CPP) $(CPPFLAGS) $(INCLUDE) -c $<

clean:
	rm -rf *.o threadcancel
