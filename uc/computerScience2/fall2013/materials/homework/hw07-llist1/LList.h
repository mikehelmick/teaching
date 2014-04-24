#ifndef LLIST_H
#define LLIST_H
/*
 * LList.h
 * Name: FILL ME IN
 *
 * Nov 10, 2013
 *
 * This class implements a linked-list which mirrors the a vector<int>, as well as
 * the functionality of a matlab array (part II).
 */


using namespace std;

// You may fill in stuct here.

class LList{
public:

	// REQUIRED public class methods

	LList();
	LList(const LList& other); 	// Copy constructor
	LList(int length); 	// Creates a list of length 'length' with all 0's.
	LList(int length, int value); // Creates a list of length 'length' with 'value's.
	~LList();	// Destructor
	
	// Getters
	int size();				// Returns the size of the linked lists; # elements.
	bool isSorted();	// Returns true if the values in the list are sorted.
	int getMax();			// Returns the maximum value in the list, or 0 if none.
	int getMin();			// Returns the minimum value in the list, or 0 if none.
	int getFirst();		// Returns the value in the first element, or 0 if none.
	int getLast();		// Returns the value in the last spot, or 0 if none.
	int getNth(int n);// Returns the value in the nth spot (0 based), with negative
										// n being from the end.  If n is out of bounds, return 0.
	int getSum();			// Return the sum of all values stored.
	bool exists(int value);	// Returns true if value is present in the list.
	bool equals(const LList& other);	// Returns true if other contains the same
										// elements in the same order as this list, false otherwise.
	bool setEquals(const LList& otehr);	// Returns true if other contains the same
										// elements where order doesn't matter, false otherwise.
	
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
	
	void append(const LList& other);	// Puts all the values of other at the end of
																		// this list.
	void mesh(const LList& other);	// Inserts other's values inbetween this list's elements.
						// This list will grow by other.size()  If T is this and O is other:
						// [ T0, O0, T1, O1, .. Tn, On]
						// If either list is shorter than the other, just append the rest.  
						// Changes this LList.
	
	// These return a new LList
	LList add(const LList& other);	// Returns a new LList which is the element by element
			// sum of the current and other LList.  If the list lengths do not match return an
			// empty LList.
	LList add(int value);	// Returns a new LList where every value has 'value' added to it.
	LList multiply(const LList& other);	// Returns a new LList which is the element by element
			// multiplication of the current and other LList.  If the list lengths do not match return an
			// empty LList.
	LList multiply(int value);	// Returns a new LList where every value has 'value' 
			// multiplied to it.

	void printList();	// Prints the list to the screen like:
										// [1, 2, 3, 4, ... 2]  Starts with [ ends with ] and has ,
										// between each element, but not after the last.

private:
	// You may use any private variables or methods you'd like
};

#endif