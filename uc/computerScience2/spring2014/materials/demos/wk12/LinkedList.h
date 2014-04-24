#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template<class T> class LinkedList : public Stack<T>, public Queue<T> {
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
  LinkedList() : size(0), head(NULL), tail(NULL) { 
  }

  virtual ~LinkedList() {
    clear();
  }

  void print() {
    cout << "size=" << size << " :: NULL <-> ";
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

  virtual void push(T value) {
    insertFirst(value);
  }
  
  virtual void offer(T value) {
    insertLast(value);
  }
  
  virtual T poll() {
    return pop();
  }
  
  virtual T pop() {
    if (head == NULL) {
      throw length_error("list is empty, nothing to remove.");
    }
    return removeFirst();
  }

  virtual T peek() {
    if (head == NULL) {
      throw length_error("list is empty, nothing to peel.");
    }
    return head->value;
  }

  bool insertFirst(T value) {
    head = new Node<T>(value, NULL, head);
    if (tail == NULL) {
      tail = head;
    } else {
      head->next->prev = head;
    }
    size++;
    return true;
  }

  bool insertLast(T value) {
    tail = new Node<T>(value, tail, NULL);
    if (head == NULL) {
      head = tail;
    } else {
      tail->prev->next = tail;
    }
    size++;
    return true;
  }

  bool insertAt(T value, unsigned int position) {
    if (position > size) {
      return false;
    }
    // Inserting at the beginning or end is really efficient, and it already exists,
    // so we will use them.
    if (position == 0) {
      insertFirst(value);
      return true;
    } else if (position == size) {
      insertLast(value);
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
    size++;
    return true;
  }
  
  unsigned int getSize() {
    return size;
  }
  
  T removeFirst() {
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
    size--;
      return rtnVal;
  }
  
  T removeLast() {
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
    size--;
    return rtnVal;
  }

  T removeAt(unsigned int position) {
    if (position >= size) {
      throw out_of_range("position is larger then the list size");
    }

    if (position == 0) {
      return removeFirst();
    } else if (position == size - 1) {
      return removeLast();
    }

    int target = position;
    bool forward = true;
    if (position > size/2) {
      target = size-position-1;
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
    size--;
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
    size = 0;
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

    bool operator==(const typename LinkedList<T>::Iterator &rhs) {
      return this->curNode == rhs.curNode;
    }
    
    bool operator!=(const typename LinkedList<T>::Iterator &rhs) {
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

  Iterator begin() {
    Iterator it(head);
    return it;
  }

  Iterator end() {
    Iterator it(NULL);
    return it;
  }
  
private:
  
  unsigned int size;
  Node<T>* head;
  Node<T>* tail;
};
