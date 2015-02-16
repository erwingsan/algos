

#include "Graph.h"

Graph::Graph(int VV) {
	V = VV;
	for(int i = 0; i < VV; ++i){
		adj[i].push_back(i);
	}
}

void Graph::addEdge(int v, int w){
	try{
	adj[v].push_back(w);
	adj[w].push_back(v);
	}
	catch(...)
	{
		cout << "Error!";
	}
}


