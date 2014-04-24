#include <stdexcept>
#include <iostream>
using namespace std;

#include <LinkedList.h>

LinkedList::LinkedList() {
  head = NULL;
  size = 0;
}

LinkedList::~LinkedList() {
  Node* curNode = head;
  while (curNode != NULL) {
    Node* nextNode = curNode->next;
    delete curNode;
    curNode = nextNode;
  }
}

int LinkedList::getSize() {
  return size;
}

void LinkedList::print() {
  Node* curNode = head;
  while (curNode != NULL) {
    cout << curNode->value << " ";
    curNode = curNode->next;
  }
  cout << "NULL" << endl;
}

void LinkedList::insertFront(int value) {
  head = createNode(value, head);
  size++;
}

void LinkedList::insertBack(int value) {
  if (head == NULL) {
    insertFront(value);
    return;
  }

  Node* curNode = head;
  while (curNode->next != NULL) {
    curNode = curNode->next;
  }
  curNode->next = createNode(value, NULL);
  size++;
}

void LinkedList::insertAt(int value, unsigned int position) {
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
  Node* curNode = head;
  while (curPos != position - 1) {
    curNode = curNode->next;
    curPos++;
  } 
  
  Node* newNode = createNode(value, curNode->next);
  curNode->next = newNode;
  size++;
}

void LinkedList::removeFront() {
  if (head == NULL) {
    return;
  }

  Node* delNode = head;
  head = head->next;
  delete delNode;
  size--;

}

void LinkedList::removeAt(unsigned int position) {
  if (position == 0) {
    removeFront();
    return;
  } else if (position < 0 || position >= size) {
    throw length_error("Out of bounds");
  }

  unsigned int curPos = 0;
  Node* curNode = head;
  while (curPos != position - 1) {
    curNode = curNode->next;
    curPos++;
  }

  Node* delNode = curNode->next;
  curNode->next = curNode->next->next;
  delete delNode;
  size--;
}

int LinkedList::at(unsigned int index) {
  if (index >= size) {
    throw length_error("Out of bounds");
  }

  unsigned int position = 0;
  Node* curNode = head;
  while (position != index) {
    curNode = curNode->next;
    position++;
  }
  return curNode->value;
}

Node* LinkedList::createNode(int value, Node* next) {
  Node* newNode = new Node;
  newNode->value = value;
  newNode->next = next;
  return newNode;
}





