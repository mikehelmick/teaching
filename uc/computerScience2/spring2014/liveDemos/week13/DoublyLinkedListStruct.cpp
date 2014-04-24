#include <iostream>
using namespace std;

struct Node {
  int value;
  Node* next;
  Node* prev;
};

class DoublyLinkedList {
public:
  DoublyLinkedList()
      : head(NULL), tail(NULL), size(0) {
  }

  virtual ~DoublyLinkedList() {
    clear();
  }

  void clear() {
    Node* curNode = head;
    while (curNode != NULL) {
      Node* tmpNode = curNode->next;
      delete curNode;
      curNode = tmpNode;
    }
    size = 0;
    head= NULL;
    tail = NULL;
  }

  void print() const {
    Node* curNode = head;
    cout << "NULL <-> ";
    while (curNode != NULL) {
       cout << curNode->value << " <-> ";
       curNode = curNode->next;
    }
    cout << "NULL" << endl;
  }

  unsigned int getSize() const {
    return size;
  }

  void insertFirst(int value) {
    Node* newNode = createNode(value, head, NULL);
    head = newNode;
    if (newNode->next != NULL) {
      newNode->next->prev = newNode;
    } else {
      tail = head;
    }
    size++;
  }

  void insertLast(int value) {
    Node* newNode = createNode(value, NULL, tail);
    tail = newNode;
    if (newNode->prev != NULL) {
      newNode->prev->next = newNode;
    } else {
      head = tail;
    }
    size++;
  }

  void insertAt(int value, int pos) {
    if (pos < 0 || pos >= size) {
      cout << "ERROR - cannot insert" << endl;
    }

    if (pos == 0) {
      return insertFirst(value);
    } else if (pos == size) {
      return insertLast(value);
    }
    
    Node* curNode = head;
    int counter = 0;
    while (counter != pos) {
      curNode = curNode->next;
      counter++;
    }

    Node* newNode = createNode(value, curNode, curNode->prev);
    newNode->next->prev = newNode;
    newNode->prev->next = newNode;
    size++;
  }

  int valueAt(int position) {
    if (position < 0 || position >= size) {
      cout << "ERROR: cannot get value at position " << position << endl;
      return -20000000;
    }

    bool forward = (position) < (size - position);

    Node* curNode = forward ? head : tail;
    int target = forward ? position : size - position - 1;

    int counter = 0;
    while (counter != target) {
      curNode = forward ? curNode->next : curNode->prev;
      counter++;
    }
    return curNode->value;
  }  

private:
  Node* head;
  Node* tail;
  unsigned int size;

  Node* createNode(int value, Node* next, Node* prev) {
   Node* newNode = new Node;
   newNode->value = value;
   newNode->next = next;
   newNode->prev = prev;
   return newNode;
  }
};

int main() {
  DoublyLinkedList ll;

  for (int i = 10; i >= 0; i--) {
    ll.insertFirst(i);
    ll.print();
  }
  ll.clear();
  ll.print();

  for (int i = 0; i <= 10; i++) {
    ll.insertLast(i);
    ll.print();
  }
  ll.clear();

  for (int i = 0; i <= 10; i += 2) {
    ll.insertLast(i);
    ll.print();
  } 
  cout << "size: " << ll.getSize() << endl;

  for (int i = 1; i < 10; i += 2) {
    cout << "inserting " << i << "at position " << i << " size: " << ll.getSize() << endl;
    ll.insertAt(i, i); 
    ll.print();
  }

  for (int i = 0; i <= ll.getSize(); i++) {
    cout << "value at " << i << " = " << ll.valueAt(i) << endl;
  }
}



