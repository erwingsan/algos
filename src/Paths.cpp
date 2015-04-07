/*
 * Paths.cpp
 *
 *  Created on: 18 Feb 2015
 *      Author: ersanchez
 */

#include "Paths.h"
#include <queue>


Paths::Paths(Graph G, int s):_s(s) {
	marked.resize(G.vertices(), false);
	edgeto.resize(G.vertices(), -1);

	bfs(G, s);
}

bool Paths::pathTo(stack<int> &pstack, int v){
	if(!hasPathTo(v))return false;

	for(int i=v; i!=_s; i=edgeto[i]){
		pstack.push(i);
	}
	return true;

}

void Paths::printMarked(){
	for(vector<bool>::iterator it = marked.begin(); it != marked.end(); ++it){
		cout << (*it) << " ";
	}
}

void Paths::printEdgeto(){
	for(vector<int>::iterator it = edgeto.begin(); it != edgeto.end(); ++it){
		cout << (*it) << " ";
	}
}

void Paths::bfs(Graph G, int s) {

	queue<int> q;
	q.push(s);
	marked[s] = true;

	while(!q.empty()){
		int v = q.front();
		q.pop();

		for(list<int>::iterator it = G.adj(v)->begin(); it != G.adj(v)->end(); ++it){
			if(!marked[*it]){
				q.push(*it);
				marked[*it] = true;
				edgeto[*it] = v;
			}
		}
	}

}
