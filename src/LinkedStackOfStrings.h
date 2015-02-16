/*
 * LinkedStackOfStrings.h
 *
 *  Created on: 13 Feb 2015
 *      Author: ersanchez
 */

#ifndef SRC_LINKEDSTACKOFSTRINGS_H_
#define SRC_LINKEDSTACKOFSTRINGS_H_


#include <string>
using namespace std;

class LinkedStackOfStrings {
public:
	LinkedStackOfStrings();
	bool isEmpty();
	void push(string item);
	string pop();

private:
	class Node{
	public:
		string item;
		Node* next;
	};
	Node* first;

};

#endif /* SRC_LINKEDSTACKOFSTRINGS_H_ */
