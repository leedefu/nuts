#libmycommon.so: src/common/common.o
#	$(CXX) -fPIC -shared $(LDFLAGS) $(LIBS) $^ -o $@ 

libmycommon.so: src/common/common.o
	$(CXX) -fPIC -shared $(INCLUDE) $(LDFLAGS) $(LIBS) $^ -o $@ 

common.o: src/common/common.cpp
	$(CXX) $(INCLUDE) $(CXXFLAGS) -o src/common/common.o -c $< 

