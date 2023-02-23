#include "Edge.hpp"

// please implement it
void Edge::reverseEdge() {
	this->transposed = !this->transposed;
	std::swap(this->end, this->weight);
}
Edge::Edge(int start, int end, int weight){
	this->start = start;
	this->end = end;
	weight = 0;
}

