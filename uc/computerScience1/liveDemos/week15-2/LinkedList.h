#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdexcept>
#include <iostream>
using namespace std;

template <class T> struct Node {
  T value;
  Node<T>* next;
};

template <class T> class LinkedList {
private:
  unsigned int size;
  Node<T>* head;

public:
  LinkedList() {
    head = NULL;
    size = 0;
  }

  virtual ~LinkedList() {
    Node<T>* curNode = head;
    while (curNode != NULL) {
      Node<T>* nextNode = curNode->next;
      delete curNode;
      curNode = nextNode;
    }
  }

  unsigned int getSize() {
    return size;
  }

  void print() {
    Node<T>* curNode = head;
    while (curNode != NULL) {
      cout << curNode->value << " ";
      curNode = curNode->next;
    }
    cout << "NULL" << endl;
  }

  void insertFront(T value) {
    head = createNode(value, head);
    size++;
  }

  void insertBack(T value) {
    if (head == NULL) {
      insertFront(value);
      return;
    }

    Node<T>* curNode = head;
    while (curNode->next != NULL) {
      curNode = curNode->next;
    }
    curNode->next = createNode(value, NULL);
    size++;
  }

  void insertAt(T value, unsigned int position) {
    if (position == 0) {
      insertFront(value);
      return;
    } else if (position == size) {
      insertBack(value);
      return;
    } else if (position < 0 || position > size) {
      throw length_error("Out of bounds");
    }
  
    // INVARIANT: We know position is in the middle somewhere
    unsigned int curPos = 0;
    Node<T>* curNode = head;
    while (curPos != position - 1) {
      curNode = curNode->next;
      curPos++;
    } 
  
    Node<T>* newNode = createNode(value, curNode->next);
    curNode->next = newNode;
    size++;
  }

  void removeFront() {
    if (head == NULL) {
      return;
    }

    Node<T>* delNode = head;
    head = head->next;
    delete delNode;
    size--;
  }

  void removeAt(unsigned int position) {
    if (position == 0) {
      removeFront();
      return;
    } else if (position < 0 || position >= size) {
      throw length_error("Out of bounds");
    }

    unsigned int curPos = 0;
    Node<T>* curNode = head;
    while (curPos != position - 1) {
      curNode = curNode->next;
      curPos++;
    }

    Node<T>* delNode = curNode->next;
    curNode->next = curNode->next->next;
    delete delNode;
    size--;
  }

  T at(unsigned int index) {
    if (index >= size) {
      throw length_error("Out of bounds");
    }

    unsigned int position = 0;
    Node<T>* curNode = head;
    while (position != index) {
      curNode = curNode->next;
      position++;
    }
    return curNode->value;
  }

private:
  Node<T>* createNode(T value, Node<T>* next) {
    Node<T>* newNode = new Node<T>;
    newNode->value = value;
    newNode->next = next;
    return newNode;
  }

};

#endif



