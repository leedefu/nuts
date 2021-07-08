LIB = 
INCLUDE =

tst_process : main.o
	g++ $^ $(LIB) -o $@ 

main.o: main.cpp
	g++ -c $< --verbose

tst_sayhello: SayHello.o
	g++ $^ $(LIB) -o $@ 

SayHello.o: SayHello.cpp
	g++ -c $< --verbose

.PHONY: clean
clean:
	rm -rf tst_sayhello tst_process *.o
