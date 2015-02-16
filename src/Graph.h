

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Graph {
private:
	int V; // vertices
	vector< list<int> > adj;

public:
	Graph(int VV);
	void addEdge(int v, int w);
};

#endif /* GRAPH_H_ */
