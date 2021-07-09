CC = g++

CFLAGS = -c -g -Wall -std=c++11 -std=gnu++11 -fpermissive
LDFLAGS =-lpthread -lrt -std=c++11 -std=gnu++11 -fpermissive


#CFLAGS = -c -Wall -g -fPIC
#LDFLAGS =-lpthread -shared

LIB =
LIB +=

INCLUDE = -I./
INCLUDE += -I../

all: alignment

SRCS = main.cpp \

OBJS = $(SRCS:.cpp=.o)

alignment:$(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIB)

%.o:%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -rf alignment $(OBJS)
