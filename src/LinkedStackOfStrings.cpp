/*
 * LinkedStackOfStrings.cpp
 *
 *  Created on: 13 Feb 2015
 *      Author: ersanchez
 */

#include "LinkedStackOfStrings.h"

LinkedStackOfStrings::LinkedStackOfStrings() {
	first = 0;
}

bool LinkedStackOfStrings::isEmpty(){
	return first == 0;
}

void LinkedStackOfStrings::push(string item){
	Node *oldfirst = first;
	Node *tmp = new Node();

	first = tmp;
	first->item = item;
	first->next = oldfirst->next;
}

string LinkedStackOfStrings::pop(){
	string str = first->item;
	first = first->next;
	return str;

}
