/*
 * LinkedStackOfStrings.h
 *
 *  Created on: 13 Feb 2015
 *      Author: ersanchez
 */

#ifndef SRC_LINKEDSTACKOFSTRINGS_H_
#define SRC_LINKEDSTACKOFSTRINGS_H_


#include <String>


class LinkedStackOfStrings {
public:
	LinkedStackOfStrings();
	bool isEmpty():
	void push(String item);
	String pop();

private:
	class Node{
		String item;
		Node* next;
	};
	Node* first;

};

#endif /* SRC_LINKEDSTACKOFSTRINGS_H_ */
