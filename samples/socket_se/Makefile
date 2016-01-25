#LIB = -lssl -lcrypto
LIB = -lcrypto
INCLUDE =

socket_se: main.o
	g++ $^ $(LIB) -o $@ 

main.o: main.cpp
	g++ -c $< --verbose

.PHONY: clean
clean:
	rm -rf socket_se *.o
