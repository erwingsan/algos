

/******
 *
 *
 * CODINGAME!!


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
bool createWall(Graph &gg, int pos, int next, int dest);

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

    int mydest, g1dest, g2dest;

    Graph *g1, *g2;

switch(myId){
	case 0: // from left to right
	    g1 = new Graph(gg);
	    g2 = new Graph(gg);
		// right node (83)
		gg.initialize("83 8 83 17 83 26 83 35 83 44 83 53 83 62 83 71 83 80");
		mydest = 83;
		g1->initialize("81 0 81 9 81 18 81 27 81 36 81 45 81 54 81 63 81 72");
		g1dest = 81;
		g2->initialize("84 72 84 73 84 74 84 75 84 76 84 77 84 78 84 79 84 80");
		g2dest = 84;
		break;

	case 1: // from right to left
		g1 = new Graph(gg);
		g2 = new Graph(gg);
		// left node (81)
		 gg.initialize("81 0 81 9 81 18 81 27 81 36 81 45 81 54 81 63 81 72");
		 mydest = 81;
		 g1->initialize("83 8 83 17 83 26 83 35 83 44 83 53 83 62 83 71 83 80");
		 g1dest = 83;
		 g2->initialize("84 72 84 73 84 74 84 75 84 76 84 77 84 78 84 79 84 80");
		 g2dest = 84;
		break;

	case 2: // from top to bottom
	    g1 = new Graph(gg);
	    g2 = new Graph(gg);
		// bottom node (84)
		gg.initialize("84 72 84 73 84 74 84 75 84 76 84 77 84 78 84 79 84 80");
		mydest = 84;
		 g1->initialize("83 8 83 17 83 26 83 35 83 44 83 53 83 62 83 71 83 80");
		 g1dest = 83;
		 g2->initialize("81 0 81 9 81 18 81 27 81 36 81 45 81 54 81 63 81 72");
		 g2dest = 81;
		break;
}
    int mypos, g1pos, g2pos;
    Paths *pp=0, *p1=0;
    int run = 0;
    int mywalls;
    bool playerOut = false;
    bool player1Out = false;
    bool player2Out = false;
    int posv[3];
    int wallsv[3];
    bool playerOutv[3] = {false, false, false};
    int hopsToAttack = 3;

    // game loop
    while (1) {
        for (int i = 0; i < playerCount; i++) {
            int x; // x-coordinate of the player
            int y; // y-coordinate of the player
            int wallsLeft; // number of walls available for the player
            cin >> x >> y >> wallsLeft; cin.ignore();

           // cerr << i << " " << x << " " << y << endl;

            //set data
            posv[i] = x + y*9;
            wallsv[i] = wallsLeft;
            if(x == -1) playerOutv[i] = true;

        }

        //set my position and enemy 1
        mypos = posv[myId];
        mywalls = wallsv[myId];
        cerr << "mypos mywalls " << mypos << mywalls << endl;
        switch(myId){
            case 0:
                g1pos = posv[1];
                player1Out = playerOutv[1];
                if(playerCount == 3){
                    g2pos = posv[2];
                    player2Out = playerOutv[2];
                }
                break;
            case 1:
                g1pos = posv[0];
                player1Out = playerOutv[0];
                if(playerCount == 3){
                    g2pos = posv[2];
                    player2Out = playerOutv[2];
                }
                break;
            case 2:
                g1pos = posv[0];
                player1Out = playerOutv[0];
                if(playerCount == 3){
                    g2pos = posv[1];
                    player2Out = playerOutv[1];
                }
                break;
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
            updateGraph(*g2, wallX, wallY, wallOrientation);
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        string go;
        // Compute paths
        pp = new Paths(gg, mypos);

        // Compute my path
        stack<int> st;
	    pp->pathTo(st, mydest);
	    playerOut = player1Out;

	    // if enemy 1 is out -> go against 2
	    if(player1Out && playerCount == 3){
	     playerOut = player2Out;
	     g1 = g2;
	     g1pos = g2pos;
	     g1dest = g2dest;
	    }

       if(mywalls > 0 && !playerOut){
            // compute path 1
            p1 = new Paths(*g1, g1pos);
            // check hop
            stack<int> st1;
	        p1->pathTo(st1, g1dest);

	        cerr << "g1 hops " << st1.size() << endl;

	        if(st1.size() <= hopsToAttack  && st.size() >= st1.size()){ //st1.size() <= 7  &&
                int g1nextnode = st1.top();
                hopsToAttack++;
                cerr << "g1pos " << g1pos << " " << g1pos%9 << g1pos/9 << endl;
                cerr << "g1next " << g1nextnode << " " << g1nextnode%9 << g1nextnode/9 << endl;


                if (createWall(gg, g1pos, g1nextnode, g1dest)){
                    delete pp;
                    if(p1) delete p1;
                    run++;
                    continue;
                }

               hopsToAttack = 3;
	        }
        }

        // get next hop
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
        //if(p1 != 0 ) delete p1;
        run++;
    }
}

bool createWall(Graph &gg, int pos, int next, int dest){
    int delta = -1;

    if(pos == next+1 || pos == next-1){ // enemy going left or rigth -> vertical wall

       int wallnode = next == pos-1? pos : next; // going left or right

       cerr << "wallnode V " << wallnode << endl;
       if(gg.connected(wallnode, wallnode+delta) &&
            gg.connected(wallnode+9, wallnode+9+delta) &&
            gg.connected(wallnode, wallnode+9) &&
            gg.connected(wallnode+delta, wallnode+9+delta)){

            //prepare wall
            int x1 = wallnode%9;
            int y1 = wallnode/9;
            cout << x1 << " " << y1 << " " << "V" << endl;
            return true;
        }
        else{
            wallnode -= 9;
            cerr << "new wallnode V " << wallnode << endl;
            if(gg.connected(wallnode, wallnode+delta) &&
                gg.connected(wallnode+9, wallnode+9+delta) &&
                gg.connected(wallnode, wallnode+9) &&
                gg.connected(wallnode+delta, wallnode+9+delta)){

                //prepare wall
                int x1 = wallnode%9;
                int y1 = wallnode/9;
                cout << x1 << " " << y1 << " " << "V" << endl;

                return true;
            }
        }
    }
    else{
        if(next == pos+9 || next == pos-9){ //enemy going down or up

            int wallnode = next == pos+9? next : pos; // going down or up
            cerr << "wallnode H " << wallnode << endl;

            if(gg.connected(wallnode, wallnode-9) &&
                gg.connected(wallnode+1, wallnode-8) &&
                gg.connected(wallnode, wallnode+1) &&
                gg.connected(wallnode-9, wallnode-8)){

                //prepare wall
                int x1 = wallnode%9;
                int y1 = wallnode/9;
                cout << x1 << " " << y1 << " " << "H" << endl;
                return true;
            }
            else{
                wallnode -= 1;
                cerr << "new wallnode H " << wallnode << endl;
                if(gg.connected(wallnode, wallnode-9) &&
                gg.connected(wallnode+1, wallnode-8) &&
                gg.connected(wallnode, wallnode+1) &&
                gg.connected(wallnode-9, wallnode-8)){

                //prepare wall
                int x1 = wallnode%9;
                int y1 = wallnode/9;
                cout << x1 << " " << y1 << " " << "H" << endl;
                return true;
                }
            }
        }
    }

    return false;
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
		if(v<0 || w<0 || v >= V || w >= V ) return false;

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


*/

