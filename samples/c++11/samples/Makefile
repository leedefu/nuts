somenuts: samples/main.o libmycommon.so
	$(CXX) $(LDFLAGS) $(LIBS)  samples/main.o libmycommon.so -o $@ 

main.o: samples/main.cpp libmycommon.so
	$(CXX) -I $(INCLUDE) $(CXXFLAGS) -c $< -L./ libmycommon.so -o samples/main.o
