LIB = 
INCLUDE =
CPPFLAGS = -std=c++0x -Wall -g --verbose

tst_signal : main.o
	g++ $(CPPFLAGS) -g $^ $(LIB) -o $@ 

main.o: main.cpp
	g++ $(CPPFLAGS) -g -c $< --verbose

.PHONY: clean
clean:
	rm -rf tst_signal *.o
