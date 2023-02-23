#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <stack>
#include "Vertex.hpp"

using namespace std;

class Graph {
public:
    // we use a vector to store vertices in the graph
    // and use label (int) to be a subscript to access a vertex
    vector<Vertex> vertices;
    vector<Vertex> connections;
    vector<Vertex> stamps;
    Graph(int size);
    // build a graph according to the input file
    void buildGraph(ifstream& stream);
    // display the graph
    void displayGraph();
    void reverseGraph(Graph& gt);
    void getDFS(int start);
    void getDFS(Vertex& current, int& time);
};


vector<int> split(const char *str, char c = ' '){
	vector<int> result;
	do{
		const char *begin = str;
		while(*str != c && *str){
		   str++;
		}
		result.push_back(stoi(string(begin, str)));
	}
	while(0 != *str++);
	return result;
}

Graph::Graph(int size){
	for(int i=1; i < size; i++){
		vertices.push_back(Vertex(i));
		vertices.back().color = 0;
	}
}

void Graph::buildGraph(ifstream& stream){
	string line;
	while(getline(stream, line, '\n')){
		vector<int> temp = split(line.c_str());
		int label = temp[0];
		for(int i=1; i < temp.size() - 1; i++){
			vertices[label-1].connectTo(temp[i]);
		}	
	}		
}

void Graph::displayGraph(){
	for(std::vector<Vertex>::iterator v = vertices.begin(); v != vertices.end(); v++){
		cout << v->label << ": ";
		for(std::list<Edge>::iterator l = v->edgeList.begin(); l != v->edgeList.end(); l++)
			cout << l->end << "  ";
	cout << -1 << endl;
	}
}

void Graph::reverseGraph(Graph& gt){
	for (int i = 0; i < vertices.size(); i++){
		for (std::list<Edge>::iterator e = vertices[i].edgeList.begin(); e != vertices[i].edgeList.end(); e++){
	//		Edge edge = reverseEdge(*e);
			gt.vertices[e->end-1].connectTo(e->start);
		}
	}

return;
}


void Graph::getDFS(int start){
	int time = 0;
	for (int i = start-1; i < vertices.size(); i++)
		if(vertices[i].color == 0)
			getDFS(vertices[i],time);
}

void Graph::getDFS(Vertex& v, int &time){
     //set color to white and start time
	v.color = 1;
	time++;
	v.start_stamp = time;
    //iterate through EDge List of V
    //call dfs if white
	std::list<Edge>::iterator child = v.edgeList.begin();
	while(child != v.edgeList.end()){
		if(vertices[(*child).end-1].color==0)
			getDFS(vertices[(*child).end-1], time);
		++child;
	}
	
	//set color to black and end time
	v.color = 2;
	++time;
	v.end_stamp = time;

	//push on stack for transpose DFS later
	stamps.push_back(Vertex(v.label-1));
}
#endif /* Graph_hpp */
