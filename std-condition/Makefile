CC = g++

CFLAGS = -c -g -std=gnu++17
LDFLAGS =-lpthread -std=gnu++17

#CFLAGS = -c -Wall -g -fPIC
#LDFLAGS =-lpthread -shared

LIB =
LIB +=

INCLUDE = -I./
INCLUDE += -I../


targets = std-condition_variable std-condition_variable_any

all: $(targets)


########################################################
SRCS-std-condition_variable = main-std-condition_variable.cpp \

OBJS-std-condition_variable = $(SRCS-std-condition_variable:.cpp=.o)

std-condition_variable:$(OBJS-std-condition_variable)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIB)
########################################################


########################################################
SRCS-std-condition_variable_any = main-std-condition_variable_any.cpp \

OBJS-std-condition_variable_any = $(SRCS-std-condition_variable_any:.cpp=.o)

std-condition_variable_any:$(OBJS-std-condition_variable_any)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIB)
########################################################




%.o:%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -rf $(targets) $(OBJS-std-condition_variable) $(OBJS-std-condition_variable_any) *.o
