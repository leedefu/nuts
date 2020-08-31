CC = g++

CFLAGS = -c -g -std=c++11 -std=gnu++11
LDFLAGS =-lpthread -std=c++11 -std=gnu++11

#CFLAGS = -c -Wall -g -fPIC
#LDFLAGS =-lpthread -shared

LIB =
LIB +=

INCLUDE = -I./
INCLUDE += -I../

all: tst_cpp2.0

SRCS = main.cpp \
    tst_unique_ptr.cpp \
    tst_move_iterator.cpp \
    tst_inherit_type.cpp \
    tst_vector_emplace.cpp \


OBJS = $(SRCS:.cpp=.o)

tst_cpp2.0:$(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIB)

%.o:%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -rf tst_cpp2.0 $(OBJS)
