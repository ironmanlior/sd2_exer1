CXX = g++
CXXFLAGS = -g -Wall

all: main

main: main.o
	$(CXX) $(CXXFLAGS) -o main main.o 

main.o: main.cpp graph.hpp algorithems.hpp queue.hpp unionfind.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

test:
	$(CXX) $(CXXFLAGS) -o test test.cpp -I -std=c++11

valgrind:
	valgrind ./main

clean:
	rm -f *.o main test