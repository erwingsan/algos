

#include "Graph.h"
#include <sstream>

Graph::Graph(int VV):_adj(VV) {
	V = VV;
	//adj.reserve(VV);
	for(int i=0; i<VV; ++i){
		_adj[i] = new list<int>;
	}
}

void Graph::addEdge(int v, int w){
	try{
	_adj[v]->push_back(w);
	_adj[w]->push_back(v);
	}
	catch(...)
	{
		cout << "Error!";
	}
}

void Graph::rmvEdge(int v, int w){
	_adj[v]->remove(w);
	_adj[w]->remove(v);
}


list<int>* Graph::adj(int v){
	return _adj[v];
}

string Graph::toString(){
	string str = "\nGraph  ";
	for(size_t i=0; i<_adj.size(); ++i){
		for(list<int>::iterator it = _adj[i]->begin(); it != _adj[i]->end(); ++it){
			stringstream oo;
			oo << i << "-" << *it << "  ";
			str += oo.str();
		}
	}

	str += "\n";
	return str;
}

