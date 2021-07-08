#LIB = -lssl -lcrypto
LIB = -lcrypto
INCLUDE =

sha1_tool: main.o sc_sha1.o
	g++ $^ $(LIB) -o $@ 

main.o: main.cpp
	g++ -c $< --verbose

sc_sha1.o: sc_sha1.cpp
	g++ -c $< --verbose

.PHONY: clean
clean:
	rm -rf sha1_tool *.o
