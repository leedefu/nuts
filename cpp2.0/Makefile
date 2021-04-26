CC = g++

#CFLAGS = -c -g -std=gnu++17
#LDFLAGS =-lpthread -std=gnu++17
CFLAGS = -c -g
LDFLAGS =-lpthread

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
    tst_lrvalue.cpp \


OBJS = $(SRCS:.cpp=.o)

tst_cpp2.0:$(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIB)

%.o:%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -rf tst_cpp2.0 $(OBJS)
