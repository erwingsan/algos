

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>
#include <iostream>
#include <string>

using namespace std;

class Graph {
private:
	int V; // vertices
	vector< list<int> *> _adj;

public:
	Graph(int VV);
	void addEdge(int v, int w);
	void rmvEdge(int v, int w);
	list<int>* adj(int v);

	string toString();
};

#endif /* GRAPH_H_ */
