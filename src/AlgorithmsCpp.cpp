//============================================================================
// Name        : AlgorithmsCpp.cpp
// Author      : E. Sanchez
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include "LinkedStackOfStrings.h"
#include "Graph.h"

using namespace std;

int main() {

//  Graph

Graph gg(10);
gg.addEdge(1, 4);
gg.addEdge(3, 1);

cout << gg.toString();

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
