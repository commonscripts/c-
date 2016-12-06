CXX      = g++
CXXFLAGS = -g3 -O0

ebk2totxt: ebk2totxt.o
	$(CXX) $(CXXFLAGS) -o ebk2totxt ebk2totxt.o -lz

ebk2totxt.o: ebk2totxt.cpp
	$(CXX) $(CXXFLAGS) -c ebk2totxt.cpp

clean:
	rm -rf *.o ebk2totxt
	rm -rf uncompressed_file.txt	

