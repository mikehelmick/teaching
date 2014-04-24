#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

template<class T> class List {
private:
  template<class NT> class Node {
  public:
    Node(NT initValue) : value(initValue) {
    }
    Node(NT initValue, Node<NT>* prev, Node<NT>* next ) : value(initValue), prev(prev), next(next) {
    }
    ~Node() {
      // Nothing to clean up here, container destructor is responsible for cleanup.
    }

    void print() {
      cout << value << " <-> ";
    }

    NT value;
    Node<NT>* prev;
    Node<NT>* next;
  };


public:
  List() : llSize(0), head(NULL), tail(NULL) {
  }

  List(const List<T> &other) : llSize(0), head(NULL), tail(NULL) {
    if (other.head == NULL) {
      return;
    }

    for (List<T>::Iterator it = other.begin(); it != other.end(); it++) {
      this->pushEnd(*it);
    }
  }

  virtual ~List() {
    clear();
  }

  void print() {
    cout << "size=" << llSize << " :: NULL <-> ";
    Node<T>* curNode = head;
    while (curNode != NULL) {
      if (curNode->prev == NULL && curNode != head) {
        cout << "*linkerror-prev*";
      }
      curNode->print();
      if (curNode->next == NULL && curNode != tail) {
        cout << "*linkerror-next*";
      }
      curNode = curNode->next;
    }
    cout << "NULL" << endl;
  }

  bool pushFront(T value) {
    head = new Node<T>(value, NULL, head);
    if (tail == NULL) {
      tail = head;
    } else {
      head->next->prev = head;
    }
    llSize++;
    return true;
  }

  bool pushEnd(T value) {
    tail = new Node<T>(value, tail, NULL);
    if (head == NULL) {
      head = tail;
    } else {
      tail->prev->next = tail;
    }
    llSize++;
    return true;
  }

  bool insertNth(unsigned int position, T value) {
    int index = 0;
    try {
      index = resolveIndex(position, true);
    } catch (length_error &e) {
      return false;
    }
    // Inserting at the beginning or end is really efficient, and it already exists,
    // so we will use them.
    if (position == 0) {
      pushFront(value);
      return true;
    } else if (position == llSize) {
      pushEnd(value);
      return true;
    }

    // Advance to the thing currently at that index.
    Node<T>* curNode = head;
    int counter = 0;
    while (counter < position) {
      curNode = curNode->next;
      counter++;
    }

    // We now have a pointer to where the value goes.
    // Create a new node that is essentally a clone of the current node.
    Node<T>* newNode = new Node<T>(value, curNode->prev, curNode);
    newNode->prev->next = newNode;
    newNode->next->prev = newNode;
    llSize++;
    return true;
  }

  int size() {
    return llSize;
  }

  T popFront() {
    if (head == NULL) {
      throw length_error("list is empty, nothing to remove.");
    }
    T rtnVal = head->value;
    Node<T>* delNode = head;
    head = head->next;
    delete delNode;
    if (head == NULL) {
      // list was 1 element long, set tail to null too.
      tail = NULL;
    } else {
      // set prev pointer on new head
      head->prev = NULL;
    }
    llSize--;
      return rtnVal;
  }

  T popEnd() {
    if (tail == NULL) {
      throw length_error("list is empty, nothing to remove.");
    }
    T rtnVal = tail->value;
    Node<T>* delNode = tail;
    tail = tail->prev;
    delete delNode;
    if (tail == NULL) {
      head = NULL;
    } else {
      tail->next = NULL;
    }
    llSize--;
    return rtnVal;
  }

  T deleteNth(unsigned int position) {
    int target = resolveIndex(position);

    if (target == 0) {
      return popFront();
    } else if (target == llSize - 1) {
      return popEnd();
    }
    bool forward = true;
    if (position > llSize/2) {
      target = llSize-position-1;
      forward = false;
    }

    Node<T>* curNode = head;
    if (!forward) {
      curNode = tail;
    }
    int counter = 0;
    while (counter < target) {
      if (forward) {
        curNode = curNode->next;
      } else {
        curNode = curNode->prev;
      }
      counter++;
    }
    // curNode is the one being removed
    curNode->prev->next = curNode->next;
    curNode->next->prev = curNode->prev;
    T rtnVal = curNode->value;
    delete curNode;
    llSize--;
    return rtnVal;
  }

  void clear() {
    Node<T>* curNode = head;
    while (curNode != NULL) {
      Node<T>* delNode = curNode;
      curNode = curNode->next;
      delete delNode;
    }
    head = NULL;
    tail = NULL;
    llSize = 0;
  }

  // Returns the value in the first element.  Throws length_error exception on error.
	T getFirst() {
    if (head == NULL) {
      throw length_error("List is empty");
    }
    return head->value;
  }

  // Returns the value in the last spot.  Throws length_error exception on error.
	T getLast() {
    if (tail == NULL) {
      throw length_error("list is empty");
    }
    return tail->value;
  }

  // Returns the value in the nth spot (0 based), with negative
  // n being from the end.  .  Throws length_error exception on error.
	T at(int n) {
    int target = resolveIndex(n);
    int counter = 0;

    Node<T>* curNode = head;
    while (counter != target) {
      curNode = curNode->next;
      counter++;
    }
    return curNode->value;
  }

  // Returns true if value is present in the list.
	bool contains(T value) {
    for (List<T>::Iterator it = begin(); it != end(); it++) {
      if (*it == value) {
        return true;
      }
    }
    return false;
  }

  // Returns true if other contains the same
  // elements in the same order as this list, false otherwise.
	bool equals(const List<T>& other) {
    if (size() != other.size()) {
      return false;
    }

    List<T>::Iterator thisIt = this->begin();
    List<T>::Iterator thatIt = other.begin();

    while (thisIt != this->end()) {
      if (*thisIt != *thatIt) {
        return false;
      }
      thisIt++;
      thatIt++;
    }
    return false;
  }

  // Returns true if this list contains everything
  // in other.  Order does not matter.
	bool containsAll(const List<T> &other) {
    for (List<T>::Iterator it = other.begin(); it != other.end(); it++) {
      if (!this->contains(*it)) {
        return false;
      }
    }
    return true;
  }

  // Sets the value at the nth spot to value.  If
  // n is not valid, return false.
  // Negative n is fron the end (-1 is last)
	bool setNth(int n, T value) {
    int target = n;
    try {
      target = resolveIndex(n);
    } catch (length_error &e) {
      return false;
    }

    int counter = 0;
    Node<T>* curNode = head;
    while (counter != target) {
      curNode = curNode->next;
      counter++;
    }

    curNode->value = value;

    return true;
  }

  // Puts all the values of other at the end of
  // this list.  Creates a copy of all values.
	void append(const List<T> &other) {
    for (List<T>::Iterator it = other.begin(); it != other.end(); it++) {
      this->pushEnd(*it);
    }
  }

  // Inserts other's values inbetween this list's elements
  // and returns the meshed list.
  // [ T0, O0, T1, O1, .. Tn, On]
  // Returned list alternates between both lists, regardless of values.
  // If either list is shorter than the other, just append the rest.
  // Creates a copy of all values.
	List<T> mesh(const List<T> &other) {
    List<T> newList;

    List<T>::Iterator thisIt = this->begin();
    List<T>::Iterator thatIt = other.begin();

    while (thisIt != this->end() && thatIt != other.end()) {
      newList.pushEnd(*thisIt);
      thisIt++;
      newList.pushEnd(*thatIt);
      thatIt++;
    }

    // pull in the rest of the longer list
    while (thisIt != this->end()) {
      newList.pushEnd(*thisIt);
      thisIt++;
    }

    while (thatIt != other.end()) {
      newList.pushEnd(*thatIt);
      thatIt++;
    }

    // sad... another copy constructor
    return newList;
  }

  class Iterator {
  public:
    Iterator(Node<T>* starting) : curNode(starting) {
    }

    bool hasNext() {
      return curNode != NULL;
    }

    T next() {
      checkRange();
      T rtnVal = curNode->value;
      curNode = curNode->next;
      return rtnVal;
    }

    T operator*() {
      checkRange();
      return curNode->value;
    }

    Iterator& operator++() {
      checkRange();
      curNode = curNode->next;
      return *this;
    }

    Iterator& operator++(int) {
      checkRange();
      curNode = curNode->next;
      return *this;
    }

    bool operator==(const typename List<T>::Iterator &rhs) {
      return this->curNode == rhs.curNode;
    }

    bool operator!=(const typename List<T>::Iterator &rhs) {
      return this->curNode != rhs.curNode;
    }

  private:
    Node<T>* curNode;

    void checkRange() {
      if (curNode == NULL) {
        throw out_of_range("Iterator is past the end of the list");
      }
    }
  };

  Iterator begin() const {
    Iterator it(head);
    return it;
  }

  Iterator end() const {
    Iterator it(NULL);
    return it;
  }

private:
  int resolveIndex(int idx, bool insertSizing = false) {
    if (idx >= 0) {
      int maxAllowed = insertSizing ? llSize : llSize - 1;
      if (idx > maxAllowed) {
        throw length_error("Invalid index requested");
      }
      return idx;
    } else {
      // Check the negative indices
      // insert sizing doesn't matter
      // Add the negative index, to get the actual position.
      int fromFront = llSize + idx;
      if (fromFront < 0) {
        throw length_error("Invalid index requested");
      }
      return fromFront;
    }
  }

  int llSize;
  Node<T>* head;
  Node<T>* tail;
};

#endif
