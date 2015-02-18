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

int main() {

//  Graph

Graph gg(10);
gg.addEdge(1, 4);
gg.addEdge(3, 1);

cout << gg.toString();

gg.initialize("1 2 5 6 4 5 3 2");

cout << gg.toString();

Paths pp(gg,1);

if(pp.hasPathTo(5)){
	stack<int> st;
	pp.pathTo(st, 5);
	cout << endl;
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
}


gg.rmvEdge(1,4);

cout <<  gg.toString();



//  Stack of strings
//	string instr;
////	getline(cin, instr);
////		LinkedStackOfStrings lss;
//
//	while(!cin.eof()){
//		cin >> instr;
//	}

	return 0;
}
