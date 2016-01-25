LIB = 
INCLUDE =

tst_signal : main.o
	g++ $^ $(LIB) -o $@ 

main.o: main.cpp
	g++ -c $< --verbose

.PHONY: clean
clean:
	rm -rf tst_signal *.o
