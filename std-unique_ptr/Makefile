CC = g++

CFLAGS = -c -g -std=gnu++17
LDFLAGS =-lpthread -std=gnu++17

#CFLAGS = -c -Wall -g -fPIC
#LDFLAGS =-lpthread -shared

LIB =
LIB +=

INCLUDE = -I./
INCLUDE += -I../


targets = std-unique_ptr

all: $(targets)

########################################################
SRCS-std-unique_ptr = main-std-unique_ptr.cpp \

OBJS-std-unique_ptr = $(SRCS-std-unique_ptr:.cpp=.o)

std-unique_ptr:$(OBJS-std-unique_ptr)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIB)
########################################################


%.o:%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -rf $(targets) $(OBJS-std-unique_ptr) *.o
