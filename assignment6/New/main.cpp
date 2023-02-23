#include <iostream>
#include <fstream>
#include "Graph.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream ifs("input.data");

    if(!ifs.good()){
		cout << "No file" << endl;
    }
    
    string line;
    int num_vertices;

    while(getline(ifs, line, '-')){
	num_vertices++;
    }
    Graph my_graph(num_vertices);

    ifs.clear();

    ifs.seekg(0, ifs.beg);

    my_graph.buildGraph(ifs);

    my_graph.displayGraph();

    //dfs
    my_graph.getDFS(1);
    for (std::vector<Vertex>::iterator i = my_graph.vertices.begin(); i != my_graph.vertices.end(); ++i)
		cout << i->label << ": " << i->start_stamp << ", " << i->end_stamp << endl;
    cout << endl;	

    //transpose
    Graph gt(num_vertices);
    Edge reverseEdge();
    cout << endl;
    gt.displayGraph();
    cout << endl;
    
   //dfs transpose
    while(!my_graph.stamps.empty()){
	int i = 1;
	Vertex temp = my_graph.stamps.top();
	my_graph.stamps.pop();
	//get acyclic components
	if(gt.vertices[temp.label-1].color == 0){
		gt.getDFS(gt.vertices[temp.label-1],i);
		gt.connections.push_back(gt.vertices[temp.label-1]);
	}
    }  

    //display ACG and adj list
    for(Vertex v: gt.connections){
	cout << v.label;
	for(Edge e: my_graph.vertices[v.label-1].edgeList){
		for(Vertex v1: gt.connections){
			if(e.end == v1.label)
				cout << " -> " << e.end;
		}
	}
	cout << endl;
    }

  return 0;

}
