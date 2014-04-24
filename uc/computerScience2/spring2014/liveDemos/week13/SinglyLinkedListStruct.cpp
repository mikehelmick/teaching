#include <iostream>
using namespace std;

struct Node {
  int value;
  Node* next;
};

class LinkedList {
public:
  LinkedList() : llSize(0), head(NULL) {
  }

  virtual ~LinkedList() {
    clear();
  }

  void clear() {
    if (head != NULL) {
      Node* tmp = head->next;
      while (head != NULL) {
        delete head;
        head = tmp;
        if (head != NULL) {
          tmp = head->next;
        }
      }
    }
    head = NULL;
    llSize = 0;
  }

  void print() {
    Node* curNode = head;
    while (curNode != NULL) {
      cout << curNode->value << " ";
      curNode = curNode->next;
    }
    cout << endl;
  }

  unsigned int size() {
    return llSize;
  }

  void insertFirst(int value) {
    head = createNode(value, head);
    llSize++;
  }

  bool insertAt(int value, unsigned int index) {
    // Deal w/ invalid indexes and special cases.
    if (index > size()) {
      return false;
    } else if (index == size()) {
      insert(value);
    } else if (index == 0) {
      insertFirst(value);
    }

    // I know that I'm not inserting at the front/back of list
    // AND that the index is valid.
    Node* newNode = createNode(value, NULL);
    // Advance to the correct position.
    Node* curNode = head;
    unsigned int curIndex = 0;
    while (curIndex != index - 1) {
      curNode = curNode->next;
      curIndex++;
    }
    // Do the next assignments
    newNode->next = curNode->next;
    curNode->next = newNode;
    llSize++;
  }
  
  void insert(int value) {
    if (head == NULL) {
      head = createNode(value, NULL);
    } else {
      Node* curNode = head;
      while (curNode->next != NULL) {
        curNode = curNode->next;
      }
      curNode->next = createNode(value, NULL);
    }
    llSize++;
  }

  void insertR(int value) {
    head = insertR(head, value);
    llSize++;
  }

  void removeFirst() {
    if (head == NULL) {
      return;
    }
    Node* delNode = head;
    head = head->next;
    delete delNode;
    llSize--;
  }

  bool removeAt(int position) {
    if (position < 0 || position >= llSize) {
      return false;
    }
    
    if (position == 0) {
      removeFirst();
      return true;
    }
    
    int counter = 0;
    Node* curNode = head;
    while (counter < position - 1) {
      curNode = curNode->next;
      counter++;
    }
    
    Node* delNode = curNode->next;
    curNode->next = curNode->next->next;
    delete delNode;
    llSize--;
    return true;
  }

  int getAt(int index) {
    if (index < 0 || index >= size()) {
      return -1;
    }

    Node* curNode = head;
    int counter = 0;
    while (counter < index) {
      curNode = curNode->next;
      counter++;
    }
    return curNode->value;
  }

  bool contains(int value) {
    Node* curNode = head;
    while (curNode != NULL) {
      if (curNode->value == value) {
        return true;
      }
      curNode = curNode->next;
    }
    return false;
  }
  
private:
  unsigned int llSize;
  Node* head;

  Node* insertR(Node* head, int value) {
    if (head == NULL) {
      return createNode(value, NULL);
    }
    head->next = insertR(head->next, value);
    return head;
  }

  Node* createNode(int value, Node* next) {
    Node* nn = new Node;
    nn->value = value;
    nn->next = next;
    return nn;
  }

};

int main() {
  
  LinkedList ll;
  for (int i = 0; i <= 10; i += 2) {
    ll.insert(i);
    ll.print();
  }
  cout << "size: " << ll.size() << endl;

  for (int i = 1; i < 10; i += 2) {
    ll.insertAt(i, i);
    ll.print();
  }

  cout << "Remove first:" << endl;
  ll.removeFirst();
  ll.print();
  cout << "Remove last:" << endl;
  while (ll.size() > 0) {
    ll.removeAt(ll.size() - 1);
    ll.print();
  }

  for (int i = 0; i < 10;  i++) {
    ll.clear();
    for (int j = 0; j < 10; j++) {
      ll.insert(j);
    }
    cout << "Remove at " << i << endl;
    ll.print();
    ll.removeAt(i);
    ll.print();
    int offset = 0;
    for (int verify = 0; verify < 9; verify++) {
      if (verify == i) {
        offset = 1;
      }
      if (offset == 0) {
        if (verify != ll.getAt(verify)) {
          cout << "ERROR - list incorrect" << endl;
        }
      } else {
        // offset must be one
        if (verify + 1 != ll.getAt(verify)) {
          cout << "ERROR - list incorrect" << endl;
        }
       }
    }
  }

  ll.clear();
  for (int i = 0; i <= 10; i += 2) {
    ll.insert(i);
  }
  for (int i = 0; i <= 10; i++) {
    bool contains = ll.contains(i);
    if (contains && i % 2 == 0) {
      cout << "Found " << i << " like I expected. " << endl;
    } else if (contains) {
      cout << "Found << " << i << " but DID NOT EXPECT TO" << endl;
    } else {
      cout << "Didn't find " << i << " as expected" << endl;
    }
  }
  
  return 0;
}
