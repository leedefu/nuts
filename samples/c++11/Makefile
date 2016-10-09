CC=gcc
CXX=g++

#OPT ?= -O2 -g2
OPT ?= -g -Wall --verbose
#OPT ?= -g2

CFLAGS =  -std=c++0x -pthread $(OPT) 
CXXFLAGS = -std=c++0x -pthread $(OPT)

LDFLAGS = -pthread -L./lib -L./

LIBS = -lpthread

INCLUDE =-I. -I./include -I./samples -I./src/common

include ./samples/Makefile
include ./src/Makefile

#.cpp.o:
#	$(CXX) -I $(INCLUDE) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	find . -name *.o -exec rm {} \;	
	find . -name *.so -exec rm {} \;	
	find . -name *.a -exec rm {} \;	
	find . -name somenuts -exec rm {} \;	
