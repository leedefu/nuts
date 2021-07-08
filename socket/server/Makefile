#LIB = -lssl -lcrypto
LIB = -lcrypto
INCLUDE =

server: main.o
	g++ $^ $(LIB) -o $@ 

main.o: main.cpp
	g++ -c $< --verbose

.PHONY: clean
clean:
	rm -rf server *.o
