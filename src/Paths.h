/*
 * Paths.h
 *
 *  Created on: 18 Feb 2015
 *      Author: ersanchez
 */

#ifndef SRC_PATHS_H_
#define SRC_PATHS_H_


#include "Graph.h"
#include <stack>

class Paths {
public:
	Paths(Graph G, int s);
	bool hasPathTo(int v){return marked[v];}
	bool pathTo(stack<int> &pstack, int v);

	void printMarked();
	void printEdgeto();

private:
	int _s;
	vector<bool> marked;
	vector<int> edgeto;

	void bfs(Graph G, int s);
};


#endif /* SRC_PATHS_H_ */
