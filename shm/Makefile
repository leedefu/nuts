CC = g++

CFLAGS = -c -g -Wall -std=c++11 -std=gnu++11
LDFLAGS =-lpthread -lrt -std=c++11 -std=gnu++11

#CFLAGS = -c -Wall -g -fPIC
#LDFLAGS =-lpthread -shared

LIB =
LIB +=

INCLUDE = -I./
INCLUDE += -I../

all: df_shm 

SRCS = main.cpp \

OBJS = $(SRCS:.cpp=.o)

df_shm:$(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIB)

%.o:%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -rf df_shm $(OBJS)
