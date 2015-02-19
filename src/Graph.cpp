

#include "Graph.h"
#include <sstream>

Graph::Graph(int VV):_adj(VV) {
	V = VV;
	//adj.reserve(VV);
	for(int i=0; i<VV; ++i){
		_adj[i] = new list<int>;
	}
}

Graph::Graph(const Graph &g) {
	V = g.V;
	_adj.resize(V);

	for(int i=0; i<V; ++i){
		_adj[i] = new list<int>;
		*_adj[i] = *g._adj[i];
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

bool Graph::connected(int v, int w){
	try{
		list<int>::iterator it;
		it = find(_adj[v]->begin(), _adj[v]->end(), w);
		if(it != _adj[v]->end())
			return true;

		return false;

	}
	catch(...)
	{
		return false;
	}
}


list<int>* Graph::adj(int v){
	return _adj[v];
}

void Graph::initialize(string str){
	stringstream ss(str);
	while(!ss.eof()){
		int v, w;
		ss >> v;
		ss >> w;
		addEdge(v, w);
	}
}

string Graph::toString(){
	string str;
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

