#include <iostream>

using namespace std;


struct Node {
  int value;
  Node* prev;
  Node* next;
};

class CircularLinkedList {
public:
  CircularLinkedList() : size(0), head(NULL) {
  }

  virtual ~CircularLinkedList() {
    if (head != NULL) {
      // Disconnect the circular nature of the list to make deletion easier.
      head->prev->next = NULL;
    }
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
    if (head != NULL) {
      cout << head->value << " <-> ";
      Node* curNode = head->next;    
      while(curNode != head) {
        cout << curNode->value << " <-> ";
        curNode = curNode->next;
      }
      cout << " (head) " << endl;
    } else {
      cout << "NULL" << endl;
    }
  }

  // inserts (at end)
  void insert(int value) {
    cout << "insert(" << value << ")" << endl;
    if (head == NULL) {
      head = createNode(value, NULL, NULL);
      // single node list points to self in both directions.
      head->prev = head;
      head->next = head;
      size = 1;
      return;
    }
    
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    newNode->prev = head->prev;
    newNode->prev->next = newNode;
    newNode->next->prev = newNode; //head
    size++;
  }
  
  // removes first (returns value)
  int remove() {
    cout << "remove()" << endl;
    if (head == NULL) {
      return -1;
    }
    
    if (head->next == head) {
      int delValue = head->value;
      delete head;
      head = NULL;
      return delValue;
    }

    // Delete the old head, save it off for later deletion.    
    Node* delNode = head;
    // Save off the return value for later returning
    int delValue = delNode->value;
    
    // Adjust the pointers around the old head node.
    head->next->prev = head->prev;
    head->prev->next = head->next;
    // Reset head to point to the next node
    head = head->next;
    
    // Delete the old head (delNode)
    delete delNode;
    size--;
    return delValue;
  }

private:
  unsigned int size;
  Node* head;

  Node* createNode(int value, Node* prev, Node* next) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = next;
    return newNode;
  }
};


int main() {
  CircularLinkedList ll;
  for (int i = 1; i <= 10; i++) {
    ll.insert(i);
    ll.print();
  }
  for (int i = 1; i <= 10; i++) {
    ll.remove();
    ll.print();
  }
}