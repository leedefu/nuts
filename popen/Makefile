#LIB = -lssl -lcrypto
LIB =
INCLUDE =

popen_test: main.o
	g++ $^ $(LIB) -o $@ 

main.o: main.cpp
	g++ -c $< --verbose

.PHONY: clean
clean:
	rm -rf popen_test *.o
