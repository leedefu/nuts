CC = g++

CFLAGS = -c -g -std=c++14 -std=gnu++14
LDFLAGS =-lpthread -std=c++14 -std=gnu++14

#CFLAGS = -c -Wall -g -fPIC
#LDFLAGS =-lpthread -shared

LIB =
LIB +=

INCLUDE = -I./
INCLUDE += -I../

all: unique_ptr 

SRCS = main.cpp \

OBJS = $(SRCS:.cpp=.o)

unique_ptr:$(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIB)

%.o:%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -rf unique_ptr $(OBJS)
