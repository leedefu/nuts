CC = g++

CFLAGS = -c -g -std=gnu++17
LDFLAGS =-lpthread -std=gnu++17

#CFLAGS = -c -Wall -g -fPIC
#LDFLAGS =-lpthread -shared

LIB =
LIB +=

INCLUDE = -I./
INCLUDE += -I../


targets = std-mutex std-recursive_mutex

all: $(targets)


########################################################
SRCS-std-mutex = main-std-mutex.cpp \

OBJS-std-mutex = $(SRCS-std-mutex:.cpp=.o)

std-mutex:$(OBJS-std-mutex)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIB)
########################################################


########################################################
SRCS-std-recursive_mutex = main-std-recursive_mutex.cpp \

OBJS-std-recursive_mutex = $(SRCS-std-recursive_mutex:.cpp=.o)

std-recursive_mutex:$(OBJS-std-recursive_mutex)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIB)
########################################################





%.o:%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -rf $(targets) $(OBJS-std-mutex) $(OBJS-std-recursive_mutex) *.o
