LIB = -lcrypto -lpthread
INCLUDE = ./ 

synctime: main.o l_nut_thread.o timesyncthread.o
	g++ $^ $(LIB) -I $(INCLUDE) -o $@ 

main.o: main.cpp
	g++ -c $< --verbose -I $(INCLUDE) 

l_nut_thread.o: thread/l_nut_thread.cpp
	g++ -c $< --verbose -I $(INCLUDE) 

timesyncthread.o: timesyncthread.cpp
	g++ -c $< --verbose -I $(INCLUDE) 

.PHONY: clean
clean:
	rm -rf synctime *.o
