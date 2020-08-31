CC = g++

CFLAGS = -c -g -std=c++11 -std=gnu++11
LDFLAGS =-lpthread -std=c++11 -std=gnu++11

#CFLAGS = -c -Wall -g -fPIC
#LDFLAGS =-lpthread -shared

LIB =
LIB +=

INCLUDE = -I./
INCLUDE += -I../

all: misc 

SRCS = main.cpp \

OBJS = $(SRCS:.cpp=.o)

misc:$(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIB)

%.o:%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -rf misc $(OBJS)
