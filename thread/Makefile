LIB = -lcrypto -lpthread
INCLUDE = ./ 

mythread: main.o l_nut_thread.o
	g++ $^ $(LIB) -I $(INCLUDE) -o $@ 

main.o: main.cpp
	g++ -c $< --verbose -I $(INCLUDE) 

l_nut_thread.o: thread/l_nut_thread.cpp
	g++ -c $< --verbose -I $(INCLUDE) 

.PHONY: clean
clean:
	rm -rf mythread *.o
