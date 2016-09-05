LIB = 
INCLUDE =
CPPFLAGS = -std=c++0x -Wall -g --verbose
CC=g++

cpp11 : main.o
	$(CC) $(CPPFLAGS) $^ $(LIB) -o $@ 

main.o: main.cpp
	$(CC) $(CPPFLAGS) -c $<

.PHONY: clean
clean:
	rm -rf cpp11 *.o
