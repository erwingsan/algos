//============================================================================
// Name        : AlgorithmsCpp.cpp
// Author      : E. Sanchez
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include "LinkedStackOfStrings.h"
#include "Graph.h"
#include "Paths.h"

using namespace std;


void printPath(Paths &p, int tov);
void nextHop(Paths &p, int mynode, int finalnode);

int main() {

//  Graph

Graph gg(89);


cout << gg.toString();

	gg.initialize("0 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 ");
    gg.initialize("0 9 1 10 2 11 3 12 4 13 5 14 6 15 7 16 8 17");

    gg.initialize("9 10 10 11 11 12 12 13 13 14 14 15 15 16 16 17");
    gg.initialize("9 18 10 19 11 20 12 21 13 22 14 23 15 24 16 25 17 26");
    //3rd row
    gg.initialize("18 19 19 20 20 21 21 22 22 23 23 24 24 25 25 26");
    gg.initialize("18 27 19 28 20 29 21 30 22 31 23 32 24 33 25 34 26 35");
     //4rd row
    gg.initialize("27 28 28 29 29 30 30 31 31 32 32 33 33 34 34 35");
    gg.initialize("27 36 28 37 29 38 30 39 31 40 32 41 33 42 34 43 35 44");

    //5th row
    gg.initialize("36 37 37 38 38 39 39 40 40 41 41 42 42 43 43 44");
    gg.initialize("36 45 37 46 38 47 39 48 40 49 41 50 42 51 43 52 44 53");

    //6th row
    gg.initialize("45 46 46 47 47 48 48 49 49 50 50 51 51 52 52 53");
    gg.initialize("45 54 46 55 47 56 48 57 49 58 50 59 51 60 52 61 53 62");

    //7th row
    gg.initialize("54 55 55 56 56 57 57 58 58 59 59 60 60 61 61 62");
    gg.initialize("54 63 55 64 56 65 57 66 58 67 59 68 60 69 61 70 62 71");

    //8th row
    gg.initialize("63 64 64 65 65 66 66 67 67 68 68 69 69 70 70 71");
    gg.initialize("63 72 64 73 65 74 66 75 67 76 68 77 69 78 70 79 71 80");

    //9th row
    gg.initialize("72 73 73 74 74 75 75 76 76 77 77 78 78 79 79 80");



    	int w = 9; // width of the board
        int h = 9; // height of the board
        int playerCount = 2; // number of players (2,3, or 4)
        int myId = 0; // id of my player (0 = 1st player, 1 = 2nd player, ...)


switch(myId){
	case 0: // from left to right
		// right node (83)
		gg.initialize("83 8 83 17 83 26 83 35 83 44 83 53 83 62 83 71 83 80");
		break;

	case 1: // from right to left
		// left node (81)
		 gg.initialize("81 0 81 9 81 18 81 27 81 36 81 45 81 54 81 63 81 72");
		break;

	case 2: // from top to bottom
		// bottom node (84)
		gg.initialize("84 72 84 73 84 74 84 75 84 76 84 77 84 78 84 79 84 80");
			break;
}

Graph g2(gg);
g2.initialize("81 0 81 9 81 18 81 27 81 36 81 45 81 54 81 63 81 72");

//    // left node (81)
//       gg.initialize("81 0 81 9 81 18 81 27 81 36 81 45 81 54 81 63 81 72");
//       // top node (82)
//       gg.initialize("82 0 82 1 82 2 82 3 82 4 82 5 82 6 82 7 82 8");
//       // right node (83)
//       gg.initialize("83 8 83 17 83 26 83 35 83 44 83 53 83 62 83 71 83 80");
//       // bottom node (84)
//       gg.initialize("84 72 84 73 84 74 84 75 84 76 84 77 84 78 84 79 84 80");

cout << gg.toString();

	int x = 0; // x-coordinate of the player
    int y = 5; // y-coordinate of the player
    // 0 0 top left corner
    int mynode = x + y*9;


Paths *pp = new Paths(gg,mynode);

Paths *p2 = new Paths(g2, mynode);

//pp.printEdgeto();
//pp.printMarked();

int tov = 75;
cout << "Path from " << mynode << " to " << tov << "\n";

nextHop(*pp, mynode, tov);
printPath(*pp, tov);


//int tov2 = 75;
//cout << "Path 2 from " << mynode << " to " << tov2 << "\n";
//
//nextHop(*p2, mynode, tov2);
//printPath(*p2, tov2);


int wallX = x+2; // x-coordinate of the wall
int wallY = y; // y-coordinate of the wall
string wallOrientation = "V";

if (wallOrientation == "H"){
	// remove edge with upper node
	gg.rmvEdge(wallX + wallY*9, wallX + (wallY-1)*9);
	// remove next edge
	gg.rmvEdge(wallX+1 + wallY*9, wallX+1 + (wallY-1)*9);
}else{ // Vertical wall
	//remove edge with left node
	gg.rmvEdge(wallX + wallY*9, wallX-1 + wallY*9);
	// remove next edge
	gg.rmvEdge(wallX + (wallY+1)*9, wallX-1 + (wallY+1)*9);
}

if(gg.connected(-5, -6))
	gg.rmvEdge(mynode, mynode+1);

delete pp;
pp = new Paths(gg,mynode);
cout << "Path from " << mynode << " to " << tov << "\n";
nextHop(*pp, mynode, tov);
printPath(*pp, tov);


cout <<  gg.toString();



//  Stack of strings
//	string instr;
////	getline(cin, instr);
////		LinkedStackOfStrings lss;
//
//	while(!cin.eof()){
//		cin >> instr;
//	}

	cout << "done!" << endl;
	return 0;
}


void printPath(Paths &p, int tov){
	if(p.hasPathTo(tov)){
		stack<int> st;
		p.pathTo(st, tov);
		while(!st.empty()){
			int topPath = st.top();
			cout << topPath << " ";
			st.pop();
		}
		cout << endl;
	}
}

void nextHop(Paths &p, int mynode, int finalnode){
	stack<int> st;
	p.pathTo(st, finalnode);
	int nextnode = st.top();

	if(nextnode > mynode){
		if( nextnode == mynode+1)
			cout << "RIGHT" << endl;
		else
			cout << "DOWN" << endl;
	}
	else{
		if (nextnode == mynode - 1)
			cout << "LEFT" << endl;
		else
			cout << "UP" << endl;
	}

}

/******
 *
 *
 * CODINGAME!!
 *

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <list>
#include <sstream>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.


class Graph {
private:
	int V;
	vector< list<int> *> _adj;

public:
	Graph(int VV);
	Graph(const Graph &g);
	void addEdge(int v, int w);
	void rmvEdge(int v, int w);
	void initialize(string str);
	list<int>* adj(int v);
	int vertices(){return V;}
	bool connected(int v, int w);
};

class Paths {
public:
	Paths(Graph G, int s);
	bool hasPathTo(int v){return marked[v];}
	bool pathTo(stack<int> &pstack, int v);

private:
	int _s;
	vector<bool> marked;
	vector<int> edgeto;

	void bfs(Graph G, int s);
};

void updateGraph(Graph &gg, int wallX, int wallY, string wallOrientation);

int main()
{
    int w; // width of the board
    int h; // height of the board
    int playerCount; // number of players (2,3, or 4)
    int myId; // id of my player (0 = 1st player, 1 = 2nd player, ...)
    cin >> w >> h >> playerCount >> myId; cin.ignore();

    Graph gg(85);

    gg.initialize("0 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 ");
    gg.initialize("0 9 1 10 2 11 3 12 4 13 5 14 6 15 7 16 8 17");

    gg.initialize("9 10 10 11 11 12 12 13 13 14 14 15 15 16 16 17");
    gg.initialize("9 18 10 19 11 20 12 21 13 22 14 23 15 24 16 25 17 26");
    //3rd row
    gg.initialize("18 19 19 20 20 21 21 22 22 23 23 24 24 25 25 26");
    gg.initialize("18 27 19 28 20 29 21 30 22 31 23 32 24 33 25 34 26 35");
     //4rd row
    gg.initialize("27 28 28 29 29 30 30 31 31 32 32 33 33 34 34 35");
    gg.initialize("27 36 28 37 29 38 30 39 31 40 32 41 33 42 34 43 35 44");

    //5th row
    gg.initialize("36 37 37 38 38 39 39 40 40 41 41 42 42 43 43 44");
    gg.initialize("36 45 37 46 38 47 39 48 40 49 41 50 42 51 43 52 44 53");

    //6th row
    gg.initialize("45 46 46 47 47 48 48 49 49 50 50 51 51 52 52 53");
    gg.initialize("45 54 46 55 47 56 48 57 49 58 50 59 51 60 52 61 53 62");

    //7th row
    gg.initialize("54 55 55 56 56 57 57 58 58 59 59 60 60 61 61 62");
    gg.initialize("54 63 55 64 56 65 57 66 58 67 59 68 60 69 61 70 62 71");

    //8th row
    gg.initialize("63 64 64 65 65 66 66 67 67 68 68 69 69 70 70 71");
    gg.initialize("63 72 64 73 65 74 66 75 67 76 68 77 69 78 70 79 71 80");

    //9th row
    gg.initialize("72 73 73 74 74 75 75 76 76 77 77 78 78 79 79 80");

    int mydest, g1dest;

    Graph *g1;

switch(myId){
	case 0: // from left to right
	    g1 = new Graph(gg);
		// right node (83)
		gg.initialize("83 8 83 17 83 26 83 35 83 44 83 53 83 62 83 71 83 80");
		mydest = 83;
		g1->initialize("81 0 81 9 81 18 81 27 81 36 81 45 81 54 81 63 81 72");
		g1dest = 81;
		break;

	case 1: // from right to left
		g1 = new Graph(gg);
		// left node (81)
		 gg.initialize("81 0 81 9 81 18 81 27 81 36 81 45 81 54 81 63 81 72");
		 mydest = 81;
		 g1->initialize("83 8 83 17 83 26 83 35 83 44 83 53 83 62 83 71 83 80");
		 g1dest = 83;
		break;

	case 2: // from top to bottom
	    g1 = new Graph(gg);
		// bottom node (84)
		gg.initialize("84 72 84 73 84 74 84 75 84 76 84 77 84 78 84 79 84 80");
		mydest = 84;
		g1->initialize("81 0 81 9 81 18 81 27 81 36 81 45 81 54 81 63 81 72");
		g1dest = 81;
		break;
}
    int mypos, g1pos;
    Paths *pp, *p1;
    int run = 0;
    int mywalls;
    bool playerOut = false;

    // game loop
    while (1) {
        for (int i = 0; i < playerCount; i++) {
            int x; // x-coordinate of the player
            int y; // y-coordinate of the player
            int wallsLeft; // number of walls available for the player
            cin >> x >> y >> wallsLeft; cin.ignore();

            cerr << i << " " << x << " " << y << endl;

            //set my position
            if(i == myId){
                mypos = x + y*9;
                cerr << mypos << endl;
                mywalls = wallsLeft;
            }else{
                if (i == 0 || i == 1) {
                    g1pos = x + y*9;
                    cerr << g1pos << endl;
                    if(x == -1)
                         playerOut = true;
                }
            }
        }

        int wallCount; // number of walls on the board
        cin >> wallCount; cin.ignore();
        for (int i = 0; i < wallCount; i++) {
            int wallX; // x-coordinate of the wall
            int wallY; // y-coordinate of the wall
            string wallOrientation; // wall orientation ('H' or 'V')
            cin >> wallX >> wallY >> wallOrientation; cin.ignore();

            updateGraph(gg, wallX, wallY, wallOrientation);
            updateGraph(*g1, wallX, wallY, wallOrientation);
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        string go;
        // Compute paths
        cerr << "Mypos " << mypos << endl;
        pp = new Paths(gg, mypos);
        p1 = new Paths(*g1, g1pos);

        //if(run > 3 && run%4 == 0 && mywalls > 0 && !playerOut){
        if(mywalls > 0 && !playerOut){
            // check hop
            stack<int> st;
	        p1->pathTo(st, g1dest);

	        cerr << "g1 hops " << st.size() << endl;

	        if(st.size() < 4){

                int g1nextnode = st.top();

                cerr << "g1pos " << g1pos << " " << g1pos%9 << g1pos/9 << endl;
                cerr << "g1next " << g1nextnode << " " << g1nextnode%9 << g1nextnode/9 << endl;

                int delta = -1;


                if(g1pos == g1nextnode+1 || g1pos == g1nextnode-1){
                    int wallnode = g1dest == 81? g1pos : g1nextnode;
                    cerr << "wallnode " << wallnode << endl;
                if(gg.connected(wallnode, wallnode+delta) &&
                    gg.connected(wallnode+9, wallnode+9+delta) &&
                    gg.connected(wallnode, wallnode+9) &&
                    gg.connected(wallnode+delta, wallnode+9+delta)){
                    //prepare wall
                    int x1 = wallnode%9;
                    int y1 = wallnode/9;

                    cout << x1 << " " << y1 << " " << "V" << endl;
                    delete pp;
                    delete p1;
                    run++;
                    continue;
                }else
                {
                    wallnode -= 9;
                    cerr << "new wallnode " << wallnode << endl;
                    if(gg.connected(wallnode, wallnode+delta) &&
                    gg.connected(wallnode+9, wallnode+9+delta) &&
                    gg.connected(wallnode, wallnode+9) &&
                    gg.connected(wallnode+delta, wallnode+9+delta)){
                    //prepare wall
                    int x1 = wallnode%9;
                    int y1 = wallnode/9;

                    cout << x1 << " " << y1 << " " << "V" << endl;
                    delete pp;
                    delete p1;
                    run++;
                    continue;
                    }
                }

                }
	        }
        }
        // get next hop
        stack<int> st;
	    pp->pathTo(st, mydest);

        int nextnode = st.top();

        cerr << "Nextnode  " << nextnode << endl;

        if(nextnode > mypos){
		    if( nextnode == mypos+1)
			    go="RIGHT";
		    else
			    go="DOWN";
	    }
	    else{
		    if (nextnode == mypos-1)
			    go="LEFT";
		    else
			    go="UP";
	    }

        cout << go << endl; // action: LEFT, RIGHT, UP, DOWN or "putX putY putOrientation" to place a wall

        delete pp;
        delete p1;
        run++;
    }
}


void updateGraph(Graph &gg, int wallX, int wallY, string wallOrientation){
    if (wallOrientation == "H"){
    	// remove edge with upper node
    	gg.rmvEdge(wallX + wallY*9, wallX + (wallY-1)*9);
    	// remove next edge
    	gg.rmvEdge(wallX+1 + wallY*9, wallX+1 + (wallY-1)*9);
    }else{ // Vertical wall
    	//remove edge with left node
    	gg.rmvEdge(wallX + wallY*9, wallX-1 + wallY*9);
    	// remove next edge
    	gg.rmvEdge(wallX + (wallY+1)*9, wallX-1 + (wallY+1)*9);
    }
}


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


***/
