OBJ = main.o Vertex.o Edge.o
MAIN = main

$(MAIN): $(OBJ)
	g++ -std=c++11 -o $(MAIN) $(OBJ)

main.o: main.cpp
	g++ -std=c++11 -g -c main.cpp 

Vertex.o: Vertex.cpp Vertex.hpp
	g++ -std=c++11 -g -c Vertex.cpp 

Edge.o: Edge.cpp Edge.hpp
	g++ -std=c++11 -g -c Edge.cpp 

clean: 
	rm -f $(OBJ) $(MAIN)
