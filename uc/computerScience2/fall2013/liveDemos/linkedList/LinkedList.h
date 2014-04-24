
#include <Stack.h>

#include <iostream>
#include <stdexcept>
using namespace std;

template<class T> class LinkedList : public Stack<T> {
private:
  template<class NT> class Node {
  public:
    Node(NT initValue) : value(initValue) {
    } 

    Node(NT initValue, Node<NT>* prev, Node<NT>* next)
      : value(initValue), prev(prev), next(next) {    
    }

    virtual ~Node() {
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
    
  }

  void print() {
    cout << "size=" << size << " :: NULL <-> ";
    Node<T>* curNode = head;
    while (curNode != NULL) {
      curNode->print();
      curNode = curNode->next;
    }
    cout << "NULL" << endl;
  }
  
  T getFirst() {
    if (head == NULL) {
      throw length_error("list is empty, nothing to remove");
    }
    return head->value;
  }
  
  T peek() {
    return getFirst();
  }
  
  void push(T value) {
    insertFirst(value);
  }
  
  T pop() {
    return removeFirst();
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

  T removeFirst() {
    if (head == NULL) {
      throw length_error("list is empty, nothing to remove");
    }
    
    T rtnVal = head->value;
    
    Node<T>* delNode = head;
    head = head->next;
    delete delNode;
    
    if (head == NULL) {
      // was a one element list
      tail = NULL; 
    } else {
      head->prev = NULL;
    }
    
    size--;
    return rtnVal;
  }
  
  class Iterator {
  public:
    Iterator(Node<T>* starting) : curNode(starting) {
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
        throw out_of_range("Iterator is off the end of the list");
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
















