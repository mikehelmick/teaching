#ifndef STACK_H
#define STACK_H
/*
 * Stack.h
 * Name: helmick
 */

#include <iostream>
using namespace std;

#include <List.h>

template <class T> class Stack {
public:

	// REQUIRED public class methods

	Stack() {
    list = new List<T>();
  };

	Stack(const Stack<T>& other) {
    list = new List<T>(other.list);
  }

	~Stack() {
    delete list;
  }

	// Getters
  // Returns the size of the stack; # elements.
	int size() {
    return list->size();
  }

  // Returns the value on the top of the stack.
  // Throws length_error exception on error (length 0)
	T top() {
    return list->getLast();
  }

	// Setters
  // Puts the value on the top of the stack.
	void push(T value) {
    list->pushEnd(value);
  }

  // Removes the top value from the stack, but does not return it.
                          // Throws length_error exception on error (length 0)
	void pop() {
    list->popEnd();
  }

	void print() {
    cout << "stack: ";
    list->print();
  }

private:
  List<T>* list;
};

#endif
