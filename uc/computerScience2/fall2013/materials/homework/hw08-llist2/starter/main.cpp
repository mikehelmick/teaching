/*
 * main.cpp
 * Name: FILL ME IN
 *
 * This file has NO PURPOSE, other than allowing you to 'play'
 * with your List, Queue, and Stack and verify operation.  What you do here
 * will probably be what you should put in your unit tests!
 *
 * Nov 20 ,2013
 */

#include <iostream>

#include "List.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main(int argc, char* argv[]){
	//List<int> l; // This needs to work!
	List l;
	l.pushEnd(5);
	l.pushEnd(6);
	l.print();
	
	//Queue<float> q;  // This needs to work!
	Queue q;
	q.push(5);
	q.push(6);
	q.print();
	
/*	Stack<string> s;  // This needs to work!
	Statck s;
	s.push("bob");
	s.push("bill");
	s.print(); */
	
	return 0;
}