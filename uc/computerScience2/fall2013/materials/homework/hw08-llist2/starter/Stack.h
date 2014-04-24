#ifndef STACK_H
#define STACK_H
/*
 * Stack.h
 * Name: FILL ME IN
 *
 * Nov 20, 2013
 *
 * This class implements a stack datastructure using a linked-list.
 */


using namespace std;

class Stack{
public:

	// REQUIRED public class methods

	Stack();
	Stack(const Stack& other); 	// Copy constructor
	~Stack();	// Destructor
	
	// Getters
	int size();				// Returns the size of the stack; # elements.
	int top();				// Returns the value on the top of the stack.
										// Throws length_error exception on error (length 0)
	
	// Setters
	void push(int value); 	// Puts the value on the top of the stack.
	void pop();							// Removes the top value from the stack, but does not return it.
													// Throws length_error exception on error (length 0)



	void print();	// Prints the stack to the screen like:
										// [1, 2, 3, 4, ... 2]  Starts with [ ends with ] and has ,
										// between each element, but not after the last.
										// The front of the stack is on the left.

private:
	// You may use any private variables or methods you'd like
};

#endif
