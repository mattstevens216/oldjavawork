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
    cout << "------------ dfs -----------" << endl;
    my_graph.getDFS(1);
    for (std::vector<Vertex>::iterator i = my_graph.vertices.begin(); i != my_graph.vertices.end(); ++i)
		cout << i->label << ": " << i->start_stamp << ", " << i->end_stamp << endl;

    cout << endl;	

    //transpose
    cout << "------------ transpose -----------" << endl;
    Graph gt(num_vertices);
    my_graph.reverseGraph(gt);
    cout << endl;
    gt.displayGraph();
    cout << endl;
    
   //dfs transpose
    cout << "------------ dfs transpose -----------" << endl;
    while(!my_graph.stamps.empty()){
	int i = 1;
	Vertex temp = my_graph.stamps[my_graph.stamps.size()-1];
	my_graph.stamps.pop_back();
	//get acyclic components
	if(gt.vertices[temp.label].color == 0){
		gt.getDFS(gt.vertices[temp.label],i);
		gt.connections.push_back(gt.vertices[temp.label]);
	}
    }  

    //display ACG and adj list
//    cout << "----------- ACG and adj List -----------" << endl;
    
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
