# echo current directory
LIB = -lcrypto -lpthread -lcurl
INCLUDE = ./

foo: main.o
	g++ $^ $(LIB) -I $(INCLUDE) -o $@ 
	$(shell pwd)

	main.o: main.cpp
		g++ -c $< --verbose -I $(INCLUDE) 

.PHONY: clean
clean:
	rm -rf foo *.o

