CC = gcc
CXX = g++

CFLAGS = -std=c++0x -c -Wall -g --verbose
#CPPFLAGS = -std=c++0x -c -Wall -g --verbose
CPPFLAGS = -std=c++0x -Wall -g --verbose

LIB = -lcrypto -lpthread
INCLUDE = ./

VPATH += thread

src_files := main.cpp \
             l_nut_thread.cpp \

#object_files := $(src_files:.cpp=.o) \
#                abc.undefine \

object_files := $(src_files:%.cpp=%.o) \
                abc.undefine \

#call filter to deal with "abc.undefine" file, just a test.
tst_thread: $(filter %.o,$(object_files))
	$(CXX) $(CPPFLAGS) $^ -o $@ -I $(INCLUDE) $(LIB) 
	@echo 'compiling thread project......'
	@echo "\033[33m Final Compile: $(CXX) $(CPPFLAGS) $^ -o $@ -I $(INCLUDE) $(LIB) \033[0m"
	@echo "\033[33m src_files: $(src_files) \033[0m"
	@echo "\033[33m object_files: $(object_files) \033[0m"
	@echo "\033[33m VPATH: $(VPATH) \033[0m"

#$(object_files): %.o:%.cpp
#call filter to deal with "abc.undefine" file, just a test.
$(filter %.o,$(object_files)): %.o:%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@ -I $(INCLUDE) 
	@echo "\033[33m Compile Single File: $(CXX) $(CPPFLAGS) -c $< -o $@ -I $(INCLUDE) \033[0m"

##########################################
# $<: all .cpp
# $@: all .o
# same as below:
###########################################
# main.o:main.cpp
# $(CXX) $(CPPFLAGS) -c main.cpp -o main.o -I $(INCLUDE)
# l_nut_thread.o:l_nut_thread.cpp
# $(CXX) $(CPPFLAGS) -c l_nut_thread.cpp -o l_nut_thread.o -I $(INCLUDE)
###########################################

##################################################
# make function test start
comma:=,
empty:=
space:=$(empty) $(empty)
foo:=a b c
bar:=
func_test_src_files := a.cpp b.cpp c.cpp d.c e.h

func_test_need_strip_string :=$(space) a string $(space)

func_test_need_sort_list := banana cherry apple

func_test_word_list :=foo bar baz add remove delete update cancel

#must be "=", ":=" will not work
func_test_reverse = $(2) $(1)

.PHONY: test_func 
test_func:
	@echo "\033[33m (subst $(space),$(comma),$(foo)) \033[0m"
	@echo "\033[33m ->$(subst $(space),$(comma),$(foo)) \r\n\033[0m"
	@echo "\033[33m (patsubst %.cpp,%.o, $(func_test_src_files)) \033[0m"
	@echo "\033[33m ->$(patsubst %.cpp,%.o, $(func_test_src_files)) \r\n\033[0m"
	@echo "\033[33m (strip $(func_test_need_strip_string)) \r\n\033[0m"
	@echo "\033[33m ->$(strip $(func_test_need_strip_string)) \r\n\033[0m"
	@echo "\033[33m (findstring a, a b c) \r\n\033[0m"
	@echo "\033[33m ->$(findstring a, a b c) \r\n\033[0m"
	@echo "\033[33m (findstring a, b c) \r\n\033[0m"
	@echo "\033[33m ->$(findstring a, b c) \r\n\033[0m"
	@echo "\033[33m (filter %.cpp %.c, $(func_test_src_files)) \r\n\033[0m"
	@echo "\033[33m ->$(filter %.cpp %.c, $(func_test_src_files)) \r\n\033[0m"
	@echo "\033[33m (filter-out %.cpp %.c, $(func_test_src_files)) \r\n\033[0m"
	@echo "\033[33m ->$(filter-out %.cpp %.c, $(func_test_src_files)) \r\n\033[0m"
	@echo "\033[33m (sort, $(func_test_need_sort_list)) \r\n\033[0m"
	@echo "\033[33m ->$(sort $(func_test_need_sort_list)) \r\n\033[0m"
	@echo "\033[33m (word 2, foo bar baz) \r\n\033[0m"
	@echo "\033[33m ->$(word 2, foo bar baz) \r\n\033[0m"
	@echo "\033[33m (wordlist 3, 6, foo bar baz add remove delete update cancel) \r\n\033[0m"
	@echo "\033[33m ->$(wordlist 3, 6, $(func_test_word_list)) \r\n\033[0m"
	@echo "\033[33m (wordlist 3, 1000, foo bar baz add remove delete update cancel) \r\n\033[0m"
	@echo "\033[33m ->$(wordlist 3, 1000, $(func_test_word_list)) \r\n\033[0m"
	@echo "\033[33m (words $(func_test_word_list)) \r\n\033[0m"
	@echo "\033[33m ->$(words $(func_test_word_list)) \r\n\033[0m"
	@echo "\033[33m (word $(words $(func_test_word_list)), $(func_test_word_list)) \r\n\033[0m"
	@echo "\033[33m ->$(word $(words $(func_test_word_list)), $(func_test_word_list)) \r\n\033[0m"
	@echo "\033[33m (firstword first second third) \r\n\033[0m"
	@echo "\033[33m ->$(firstword first second third) \r\n\033[0m"
	@echo "\033[33m (dir thread/l_nut_thread.cpp thread/l_nut_thread.h main.cpp nonexist) \r\n\033[0m"
	@echo "\033[33m ->$(dir thread/l_nut_thread.cpp thread/l_nut_thread.h main.cpp nonexist) \r\n\033[0m"
	@echo "\033[33m (notdir thread/l_nut_thread.cpp thread/l_nut_thread.h main.cpp nonexist) \r\n\033[0m"
	@echo "\033[33m ->$(notdir thread/l_nut_thread.cpp thread/l_nut_thread.h main.cpp nonexist) \r\n\033[0m"
	@echo "\033[33m (suffix thread/l_nut_thread.cpp thread/l_nut_thread.h main.cpp nonexist) \r\n\033[0m"
	@echo "\033[33m ->$(suffix thread/l_nut_thread.cpp thread/l_nut_thread.h main.cpp nonexist) \r\n\033[0m"
	@echo "\033[33m (suffix thread/l_nut_thread.cpp thread/l_nut_thread.h main.cpp nonexist.cpp.h) \r\n\033[0m"
	@echo "\033[33m ->$(suffix thread/l_nut_thread.cpp thread/l_nut_thread.h main.cpp nonexist.cpp.h) \r\n\033[0m"
	@echo "\033[33m (basename thread/l_nut_thread.cpp thread/l_nut_thread.h main.cpp nonexist.cpp.h) \r\n\033[0m"
	@echo "\033[33m ->$(basename thread/l_nut_thread.cpp thread/l_nut_thread.h main.cpp nonexist.cpp.h) \r\n\033[0m"
	@echo "\033[33m (addsuffix .cpp, a b c) \r\n\033[0m"
	@echo "\033[33m ->$(addsuffix .cpp, a b c) \r\n\033[0m"
	@echo "\033[33m (addprefix src/, a.cpp b.cpp c.cpp) \r\n\033[0m"
	@echo "\033[33m ->$(addprefix src/, a.cpp b.cpp c.cpp) \r\n\033[0m"
	@echo "\033[33m (join aaa bbb, 111 222 333) \r\n\033[0m"
	@echo "\033[33m ->$(join aaa bbb, 111 222 333) \r\n\033[0m"
	@echo "\033[33m (join aaa bbb ccc ddd, 111 222 333) \r\n\033[0m"
	@echo "\033[33m ->$(join aaa bbb ccc ddd, 111 222 333) \r\n\033[0m"
	@echo "\033[33m (foreach n, a b c, $(n).cpp) \r\n\033[0m"
	@echo "\033[33m ->$(foreach n, a b c, $(n).cpp) \r\n\033[0m"
	@echo "\033[33m (if $(findstring a, a b c), findstring a from a b c, can not findstring a from a b c) \r\n\033[0m"
	@echo "\033[33m ->$(if $(findstring a, a b c), findstring a from a b c, can not findstring a from a b c) \r\n\033[0m"
	@echo "\033[33m (if $(findstring d, a b c), findstring d from a b c, can not findstring d from a b c) \r\n\033[0m"
	@echo "\033[33m ->$(if $(findstring d, a b c), findstring d from a b c, can not findstring d from a b c) \r\n\033[0m"
	@echo "\033[33m (call func_test_reverse, a, b) \r\n\033[0m"
	@echo "\033[33m ->$(call func_test_reverse, a, b) \r\n\033[0m"

# make function test end
###########################################

.PHONY: clean
clean:
	# using -rm to ignore error
	-rm -rf tst_thread *.o
