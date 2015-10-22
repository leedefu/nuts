LIB = -lcrypto -lpthread -lcurl
INCLUDE = ./ 

catch_webpage: main.o
	g++ $^ $(LIB) -I $(INCLUDE) -o $@ 

main.o: main.cpp
	g++ -c $< --verbose -I $(INCLUDE) 

.PHONY: clean
clean:
	rm -rf catch_webpage *.o
