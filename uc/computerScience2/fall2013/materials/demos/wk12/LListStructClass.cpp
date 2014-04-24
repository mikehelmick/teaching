#include <iostream>

using namespace std;


struct Node {
  int value;
  Node *next;
};

class LinkedList {
public:
  LinkedList() : size(0), head(NULL) {
  }

  virtual ~LinkedList() {
    // Need to clean up ALL nodes
    Node* curNode = head;
    while (curNode != NULL) {
      Node* delNode = curNode;
      curNode = curNode->next;
      delete delNode;
    }
  }

  unsigned int getSize() const {
    return size;
  }
  
  void print() {
    cout << "size=" << size << " :: ";
    Node* curNode = head;    
    while(curNode != NULL) {
      cout << curNode->value << " -> ";
      curNode = curNode->next;
    }
    cout << "NULL" << endl;
  }

  void insert(int value) {
    cout << "insert(" << value << ")" << endl;
    if (head == NULL) {
      head = createNode(value, NULL);
      size = 1;
      return;
    }
    Node* curNode = head;
    while (curNode->next != NULL) {
      curNode = curNode->next;
    }
    // Invariant - curNode->next is NULL
    curNode->next = createNode(value, NULL);
    size++;
  }
  
  void insertR(int value) {
    cout << "insertR(" << value << ")" << endl;
    head = insertR(head, value);
    size++;
  }

  void insertFirst(int value) {
    cout << "insertFirst(" << value << ")" << endl;
    Node* newHead = new Node;
    newHead->value = value;;
    newHead->next = head;
    head = newHead;
    size++;
  }
  
  // Insert a value at a specific position
  bool insertAt(int value, int position) {
    cout << "insertAt(" << value << ", " << position << ")" << endl;
    if (position < 0 || position >= size) {
      return false;
    }
    if (position == size) {
      // This is a normal insert at end.
      insert(value);
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
    // Create a new node that is essentally a clone of the current node.
    Node* newNode = createNode(curNode->value, curNode->next);
    
    // Change the value of the curentNode and change next to point to the new node
    // (and the remainder of the list)
    curNode->value = value;
    curNode->next = newNode;
    size++;
    return true;
  }
  
  void removeFirst() {
    cout << "removeFirst()" << endl;
    if (head == NULL) {
      return;
    }
    Node* delNode = head;
    head = head->next;
    delete delNode;
    size--;
  }
  
  void removeLast() {
    cout << "removeLast()" << endl;
    if (head == NULL) {
      return;
    } else if (head->next == NULL) {
      delete head;
      head = NULL;
      size = 1;
      return;
    }

    Node* curNode = head;
    while (curNode->next->next != NULL) {
      curNode = curNode->next;
    }

    // curNode->next is the last node
    delete curNode->next;
    curNode->next = NULL;
    size--;
  }

  bool removeAt(int position) {
    cout << "removeAt(" << position << ")" << endl;
    if (position < 0 || position >= size) {
      return false;
    }
    
    if (position == 0) {
      Node* delNode = head;
      head = head->next;
      delete delNode;
      size--;
      return true;
    }
    
    int index = 0;
    Node* curNode = head;
    // Advance to one before the node to be deleted.
    while (index < position - 1) {
      curNode = curNode->next;
      index++;
    }
    Node* delNode = curNode->next;
    curNode->next = curNode->next->next;
    delete delNode;
    size--;
    return true;
  }

  int indexOf(int value) {
    cout << "indexOf(" << value << ") " ;
    Node* curNode = head;
    int index = 0;
    while (curNode != NULL) {
      if (curNode->value == value) {
        return index;
      }
      curNode = curNode->next;
      index++;
    }
    return -1;
  }

private:
  unsigned int size;
  Node* head;

  Node* insertR(Node* head, int value) {
    if (head == NULL) {
      return createNode(value, NULL);
    }
    head->next = insertR(head->next, value);
    return head; 
  } 
  
  Node* createNode(int value, Node* next) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = next;
    return newNode;
  }
};


int main() {
  LinkedList ll;
  ll.insertR(2);
  ll.insertR(4);
  ll.insert(6);
  ll.insertR(8);  
  ll.print();
  ll.insertFirst(27);
  ll.print();
  ll.insertAt(1, 0);
  ll.print();
  ll.insertAt(192, 4);
  ll.print();
  ll.removeFirst();
  ll.print();
  ll.removeLast();
  ll.print();
  ll.removeAt(3);
  ll.print();
  ll.removeAt(0);
  ll.print();
  ll.removeAt(2);
  ll.print();
  ll.insert(6);
  ll.insert(8);
  ll.insert(10);
  ll.print();
  cout << ll.indexOf(4) << endl;
  cout << ll.indexOf(8) << endl;
  cout << ll.indexOf(5) << endl;
  ll.print();
}