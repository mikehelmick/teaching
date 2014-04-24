#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
  int value;
  Node* next;
};

class LinkedList {
public:
  LinkedList();

  virtual ~LinkedList();

  int getSize();

  void print();

  void insertFront(int value);
  void insertBack(int value);
  void insertAt(int value, unsigned int position);

  void removeFront();
  void removeAt(unsigned int position);

  int at(unsigned int index);

private:
  Node* head;
  unsigned int size;

  Node* createNode(int value, Node* next);
};

#endif
