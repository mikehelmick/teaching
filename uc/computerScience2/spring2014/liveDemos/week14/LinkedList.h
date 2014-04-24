#include <iostream>
#include <stdexcept>

using namespace std;

template<class T> class LinkedList {
private:
  template<class NT> class Node {
  public:
    Node(NT initValue) : value(initValue), prev(NULL), next(NULL) {
    }

    Node(NT initValue, Node<NT>* prev, Node<NT>* next)
        : value(initValue), prev(prev), next(next) {
    }

    virtual ~Node() {
      // maybe do somethin later
    }

    void print() {
      cout << value << " <-> ";
    }

    NT value;
    Node<NT>* prev;
    Node<NT>* next;
  };

public:
  class iterator {
  public:
    iterator(Node<T>* head) {
      curNode = head;
    }

    T operator*() {
      checkRange();
      return curNode->value;
    }

    iterator& operator++() {
      checkRange();
      curNode = curNode->next;
      return *this;
    }

    iterator& operator++(int) {
      checkRange();
      curNode = curNode->next;
      return *this;
    }

    bool operator==(const typename LinkedList<T>::iterator &rhs) {
      return this->curNode == rhs.curNode;
    }

    bool operator!=(const typename LinkedList<T>::iterator &rhs) {
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

  LinkedList() : size(0), head(NULL), tail(NULL) {
  }

  virtual ~LinkedList() {
    if (head != NULL) {
      Node<T>* curNode = head;
      while (curNode != NULL) {
        curNode = curNode->next;
        delete head;
        head = curNode;
      }
    }
  }

  iterator begin() {
    iterator it(head);
    return it;
  }

  iterator end() {
    iterator it(NULL);
    return it;
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

  void insertFirst(T value) {
    Node<T>* newNode = new Node<T>(value, NULL, head);
    head = newNode;
    if (newNode->next != NULL) {
      newNode->next->prev = newNode;
    } else {
      tail = head;
    }   
    size++;
  }

  T getFirst() {
    if (head == NULL) {
      throw length_error("list is empty, nothing to remove");
    } 
    return head->value;
  }

  unsigned int getSiez() {
    return size;
  }

  bool isEmpty() {
    return size == 0;
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
      tail = NULL;
    } else {
      head->prev = NULL;
    }

    size--;
    return rtnVal;
  }

private:
  unsigned int size;
  Node<T>* head;
  Node<T>* tail;

};










