CC = g++

CFLAGS = -c -g -std=c++11 -std=gnu++11
LDFLAGS =-lpthread -std=c++11 -std=gnu++11

#CFLAGS = -c -Wall -g -fPIC
#LDFLAGS =-lpthread -shared

LIB =
LIB +=

INCLUDE = -I./
INCLUDE += -I../

all: variadic_template 

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

variadic_template:$(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIB)

%.o:%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -rf variadic_template $(OBJS)
