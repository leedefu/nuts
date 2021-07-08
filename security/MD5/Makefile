#LIB = -lssl -lcrypto
LIB = -lcrypto
INCLUDE =

MD5_tool: main.o
	g++ $^ $(LIB) -o $@ 

main.o: main.cpp
	g++ -c $< --verbose

.PHONY: clean
clean:
	rm -rf MD5_tool *.o
