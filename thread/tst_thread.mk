CPP = g++
CC = gcc

CFLAGS = -std=c++0x -c -Wall -g --verbose
#CPPFLAGS = -std=c++0x -c -Wall -g --verbose
CPPFLAGS = -std=c++0x -Wall -g --verbose

LIB = -lcrypto -lpthread
INCLUDE = ./

VPATH=thread

object_files = main.o \
			   l_nut_thread.o \
			   abc.undefine \

#call filter to deal with "abc.undefine" file, just a test.
tst_thread: $(filter %.o,$(object_files))
	$(CPP) $(CPPFLAGS) $^ -o $@ -I $(INCLUDE) $(LIB) 
	@echo 'compiling thread project......'
	@echo $(CPP) $(CPPFLAGS) $^ -o $@ -I $(INCLUDE) $(LIB) 

#$(object_files): %.o:%.cpp
#call filter to deal with "abc.undefine" file, just a test.
$(filter %.o,$(object_files)): %.o:%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@ -I $(INCLUDE) 
	@echo $(CPP) $(CPPFLAGS) -c $< -o $@ -I $(INCLUDE) 
##########################################
# $<: all .cpp
# $@: all .o
# same as below:
###########################################
# main.o:main.cpp
# $(CPP) $(CPPFLAGS) -c main.cpp -o main.o -I $(INCLUDE)
# l_nut_thread.o:l_nut_thread.cpp
# $(CPP) $(CPPFLAGS) -c l_nut_thread.cpp -o l_nut_thread.o -I $(INCLUDE)
###########################################


.PHONY: clean
clean:
	# using -rm to ignore error
	-rm -rf tst_thread *.o
