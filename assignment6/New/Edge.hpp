#ifndef Edge_hpp
#define Edge_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
class Edge {
public:
    // start vertex's label
    int start;
    // end vertex's label
    unsigned end;
    // the weight of this edge
    unsigned weight;
    bool transposed;

    Edge(int start, int end, int weight);

    void reverseEdge();
};

#endif /* Edge_hpp */
