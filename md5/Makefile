#LIB = -lssl -lcrypto
LIB = -lcrypto
INCLUDE =

mymd5: main.o
	g++ $^ $(LIB) -o $@ 

main.o: main.cpp
	g++ -c $< --verbose

.PHONY: clean
clean:
	rm -rf mymd5 *.o
