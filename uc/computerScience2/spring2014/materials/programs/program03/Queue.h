#ifndef QUEUE_H
#define QUEUE_H
/*
 * Queue.h
 * Name: helmick
 */

#include <iostream>
using namespace std;

#include <List.h>

template <class T> class Queue{
public:

	// REQUIRED public class methods

	Queue() {
    list = new List<T>();
  }

	Queue(const Queue<T>& other) {
    list = new List<T>(other.list);
  } 	// Copy constructor

	virtual ~Queue() {
    delete list;
  }	// Destructor

	// Getters
  // Returns the size of the queue; # elements.
	int size() {
    return list->size();
  }

  // Returns the value at the front of the queue.  Throws length_error exception on error (length 0)
	T front() {
    return list->getFirst();
  }

  // Returns the value in the end of the queue.  Throws length_error exception on error (length 0)
	T back() {
    return list->getLast();
  }

	// Setters
  // Puts value at the end of the queue.
	void push(T value) {
    list->pushEnd(value);
  }

  // Removes the value at the front of the queue but does not return it.
  //  Throws length_error exception on error (length 0)
	void pop() {
    return list->getFirst();
  }

  // Prints the queue to the screen like:
  // [1, 2, 3, 4, ... 2]  Starts with [ ends with ] and has ,
  // between each element, but not after the last.
  // The front of the queue is on the left.
	void print() {
    cout << "queue: ";
    list->print();
  }

private:
	List<T>* list;
};

#endif
