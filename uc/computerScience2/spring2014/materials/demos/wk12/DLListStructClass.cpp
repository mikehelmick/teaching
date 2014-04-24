#include <iostream>
using namespace std;

struct Node {
  int value;
  Node* next;
  Node* prev;
};

class DoublyLinkedList {
public:
  DoublyLinkedList() : head(NULL), tail(NULL), size(0) {
  }

  virtual ~DoublyLinkedList() {
    while (head != NULL) {
      Node* next = head->next;
      delete head;
      head = next;
    }
  }
  
  void print() {
    cout << "size=" << size << " :: ";
    Node* curNode = head; 
    cout << "NULL" << " <--> ";
    while(curNode != NULL) {
      cout << curNode->value << " <-> ";
      curNode = curNode->next;
    }
    cout << "NULL" << endl;
  }

  void insertFirst(int value) {
    cout << "insertFirst(" << value << ")" << endl;
    Node* newNode = createNode(value, NULL, head);
    head = newNode;
    if (tail == NULL) {
      // list was empty before.
      tail = head;
    } else {
      // list wasn't empty, set up link.
      newNode->next->prev = newNode;
    }
    size++;
  }

  void insertLast(int value) {
    cout << "insertLast(" << value << ")" << endl;
    Node* newNode = createNode(value, tail, NULL);
    tail = newNode;
    if (head == NULL) {
      head = tail;
    } else {
      newNode->prev->next = newNode;
    }
    size++;
  }

  void removeFirst() {
    cout << "removeFirst()" << endl;
    if (head != NULL) {
      Node* delNode = head;
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
    }
  }
  
  void removeLast() {
    cout << "removeLast()" << endl;
    if (tail != NULL) {
      Node* delNode = tail;
      tail = tail->prev;
      delete delNode;
      if (tail == NULL) {
        head = NULL;
      } else {
        tail->next = NULL;
      }
      size--;
    }
  }

  bool insertAt(int value, int position) {
    cout << "insertAt(" << value << ", " << position << ")" << endl;
    if (position < 0 || position > size) {
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
    Node* curNode = head;
    int counter = 0;
    while (counter < position) {
      curNode = curNode->next;
      counter++;
    }
    
    // We now have a pointer to where the value goes.
    Node* newNode = createNode(value, curNode->prev, curNode);
    newNode->prev->next = newNode;
    newNode->next->prev = newNode;    
    size++;
    return true;
  }
  
  int getSize() {
    return size;
  }
  
  int peek() {
    if (head != NULL) {
      return head->value;
    }
    return 0;
  }

private:
  Node* head;
  Node* tail;
  int size;

  Node* createNode(int value, Node* prev, Node* next) {
    Node* node = new Node;
    node->value = value;
    node->prev = prev;
    node->next = next;
    return node;
  }
};

int main() {
  DoublyLinkedList ll;
  for (int i = 1; i <= 9; i += 2) {
    ll.insertFirst(i);
    ll.print();
  }
  for (int i = 10; i >= 2; i -= 2) {
    ll.insertLast(i);
    ll.print();
  }
  for (int i = 0; i < 4; i++) {
    ll.removeFirst();
    ll.print();
  }
  for (int i = 0; i < 4; i++) {
    ll.removeLast();
    ll.print();
  }
  ll.insertAt(0, 0);
  ll.print();
  ll.insertAt(11, 3);
  ll.print();
  for (int i = 2; i <= 9; i++) {
    ll.insertAt(i, i);
    ll.print();
  }
}
