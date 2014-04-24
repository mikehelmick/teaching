#ifndef QUEUE_H
#define QUEUE_H
/*
 * Queue.h
 * Name: FILL ME IN
 *
 * Nov 20, 2013
 *
 * This class implements queue using a linked-list.
 */

class Queue{
public:

	// REQUIRED public class methods

	Queue();
	Queue(const Queue& other); 	// Copy constructor
	~Queue();	// Destructor
	
	// Getters
	int size();				// Returns the size of the queue; # elements.
	int front();			// Returns the value at the front of the queue.  Throws length_error exception on error (length 0)
	int back();				// Returns the value in the end of the queue.  Throws length_error exception on error (length 0)
	
	// Setters
	void push(int value); 	// Puts value at the end of the queue.
	void pop();							// Removes the value at the front of the queue but does not return it.
													//  Throws length_error exception on error (length 0)
	


	void print();	// Prints the queue to the screen like:
										// [1, 2, 3, 4, ... 2]  Starts with [ ends with ] and has ,
										// between each element, but not after the last.
										// The front of the queue is on the left.

private:
	// You may use any private variables or methods you'd like
};

#endif
