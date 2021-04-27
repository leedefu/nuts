CC = g++

CFLAGS = -c -g -std=gnu++17
LDFLAGS =-lpthread -std=gnu++17

#CFLAGS = -c -Wall -g -fPIC
#LDFLAGS =-lpthread -shared

LIB =
LIB +=

INCLUDE = -I./
INCLUDE += -I../


targets = std-shared_ptr

all: $(targets)

########################################################
SRCS-std-shared_ptr = main-std-shared_ptr.cpp \

OBJS-std-shared_ptr = $(SRCS-std-shared_ptr:.cpp=.o)

std-shared_ptr:$(OBJS-std-shared_ptr)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIB)
########################################################




%.o:%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -rf $(targets) $(OBJS-std-shared_ptr) *.o
