#ifndef LIST_H
#define LIST_H
/*
 * List.h
 * Name: Paul Talaga
 *
 * Nov 12, 2013
 *
 * This class implements a singly linked-list.
 */


using namespace std;

// You may change the node/struct definition if needed.
struct node_t{
	int value;
	node_t* next;
};

class List{
public:

	// REQUIRED public class methods

	List();
	List(const List& other); 	// Copy constructor
	List(int length, int value); // Creates a list of length 'length' with 'value's.
	~List();	// Destructor
	
	// Getters
	int size();				// Returns the size of the linked lists; # elements.
	int getFirst();		// Returns the value in the first element, or 0 if none.
	int getLast();		// Returns the value in the last spot, or 0 if none.
	int at(int n);// Returns the value in the nth spot (0 based), with negative
										// n being from the end.  If n is out of bounds, return 0.
	bool contains(int value);	// Returns true if value is present in the list.
	bool equals(const List& other);	// Returns true if other contains the same
										// elements in the same order as this list, false otherwise.
	bool containsAll(const List& other);	// Returns true if this list contains everything
										// in other.  Order does not matter.
	
	// Setters
	void pushEnd(int value); 	// Puts value on the end of the list.
	void pushFront(int value);// Puts value on the front of the list.
	int popEnd();		// Returns the last element and shortens the list by 1. 0 if failure.
	int popFront();	// Returns the first element and shortens the list by 1. 0 if failure.
	bool setNth(int n, int value);	// Sets the value at the nth spot to value.  If
																	// n is not valid, return false.  
																	// Negative n is fron the end (-1 is last)
	bool insertNth(int n, int value);//Inserts value in spot n.  Move the value that was
							// there up.  Return true on success, false if n is not a valid index.
	int deleteNth(int n);	// Returns the value at index n (- is from end), and removes that
							// element from the list.  0 if failure.
	
	void append(const List& other);	// Puts all the values of other at the end of
																	// this list.  Creates a copy of all values.
	
	List mesh(const List& other);		// Inserts other's values inbetween this list's elements
						// and returns the meshed list.
						// [ T0, O0, T1, O1, .. Tn, On]
						// Returned list alternates between both lists, regardless of values.
						// If either list is shorter than the other, just append the rest. 
						// Creates a copy of all values.
	

	void printList();	// Prints the list to the screen like:
										// [1, 2, 3, 4, ... 2]  Starts with [ ends with ] and has ,
										// between each element, but not after the last.

private:
	node_t* head;
	node_t* tail;   // The tail pointer gives easy tail additions.
	int length;
	
	node_t* newNode(int value, node_t* next);
};

#endif
