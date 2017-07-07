all: lab clean

lab: perfMaze.o vertex.o
	g++ -o maze vertex.o perfMaze.o

perfMaze.o: perfMaze.cpp
	g++ -c perfMaze.cpp

vertex.o: vertex.cpp
	g++ -c vertex.cpp

edge.o: edge.cpp
	g++ -c edge.cpp

clean:
	rm -rf *.o
