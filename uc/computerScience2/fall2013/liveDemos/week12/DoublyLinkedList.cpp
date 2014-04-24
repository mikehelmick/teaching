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
  }  

  void print() {
    cout << "NULL ";
    Node* curNode = head;
    while (curNode != NULL) {
      cout << curNode->value << " <-> ";
      curNode = curNode->next;
    }
    cout << "NULL" << endl;
  }

  void insertFirst(int value) {
    Node* newNode = createNode(value, NULL, head);
    head = newNode;
    if (tail == NULL) {
      tail = head;
    } else {
      head->next->prev = head;
    }
    size++;
  }
  
  void insertLast(int value) {
    Node* newNode = createNode(value, tail, NULL);
    tail = newNode;
    if (head == NULL) {
      head = tail;
    } else {
      tail->prev->next = tail;
    }
    size++;
  }

  int valueAt(int position) {
    if (position < 0 || position >= size) {
      return -200000;
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
  
  int calculateSize() {
    Node* curNode = head;
    int counter = 0;
    
    while (curNode != NULL) {
      curNode = curNode->next;
      counter++;
    }
    
    return counter;
  }
  
  int getSize() {
    return size;
  }
  
private:
  Node* head;
  Node* tail;
  int size;

  Node* createNode(int value, Node* prev, Node* next) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->prev = prev;
    newNode->next = next;
    return newNode;
  }

};

int main() {
  {
    DoublyLinkedList ll;
    for (int i = 1; i<= 8; i++) {
      ll.insertLast(i);
    }
    ll.print();

    for (int i = 0; i < ll.getSize(); i++) {
      cout << "ll[i] = " << ll.valueAt(i)
        << " should be: " << i+1 << endl;
    }
  }
}
