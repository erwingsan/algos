

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Graph {
private:
	int V; // vertices
	vector< list<int> *> _adj;

public:
	Graph(int VV);
	Graph(const Graph &g);
	void addEdge(int v, int w);
	void rmvEdge(int v, int w);
	void initialize(string str);
	list<int>* adj(int v);
	bool connected(int v, int w);

	int vertices(){return V;}

	string toString();
};

#endif /* GRAPH_H_ */
