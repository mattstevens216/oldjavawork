// please implement it

#include "Graph.hpp"
#include <iostream>


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
	for(int i=0; i < size; i++){
		vertices.push_back(Vertex(i));
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
