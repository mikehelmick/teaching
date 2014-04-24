#include <iostream>
using namespace std;

struct Node {
  int value;
  Node* next;
};

void printList(const Node* head) {
  if (head == NULL) {
    cout << "NULL" << endl;
    return;
  }
  cout << head->value << " -> ";
  printList(head->next);
}

// A linked list of integer
class LinkedList {
public:
  LinkedList() : size(0), head(NULL) {}

  ~LinkedList() {
    // Memory leak for now, fill in later
    Node* curNode = head;
    while (curNode != NULL) {
      Node* delNode = curNode;
      curNode = curNode->next;
      delete delNode;
    }
  }
  
  void print() {
    Node* curNode = head;
    while (curNode != NULL) {
      cout << curNode->value << " -> ";
      curNode = curNode->next;
    }
    cout << "NULL" << endl;
  }
  
  void removeFirst() {
    if (head == NULL) {
      return;
    }
    
    Node* delNode = head;
    head = head->next;
    delete delNode;
    size--;
  } 
  
  bool removeAt(int position) {
    if (position < 0 || position >= size) {
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
    size--;
    return true;
  }
  
  bool insertAt(int value, int position) {
    if (position < 0 || position > size) {
      return false;
    }

    if (position == size) {
      insert(value);
      return true;
    } else if (position == 0) {
      insertFirst(value);
      return true;
    }

    Node* curNode = head;
    int counter = 0;
    while (counter < position - 1) {
      curNode = curNode->next;
      counter++;
    }
    
    Node* newNode = createNode(value, curNode->next);
    curNode->next = newNode;
    size++;
    return true;
  }
  
  void insertFirst(int value) {
    head = createNode(value, head);
    size++;
  }
  
  void insert(int value) {
    if (head == NULL) {
      head = createNode(value, NULL);
      size++;
      return;
    }
    
    Node* curNode = head;
    while (curNode->next != NULL) {
      curNode = curNode->next;
    }
    
    curNode->next = createNode(value, NULL);
    size++;
  }
  
  void insertR(int value) {
    head = insertR(head, value);
    size++;
  }
  
  int search(int target) {
    if (head == NULL) {
      return -1;
    }
    
    int position = 0;
    Node* curNode = head;
    while (curNode != NULL) {
      if (curNode->value == target) {
        return position;
      }
      position++;
      curNode = curNode->next;
    }
    return -1;
  }
  
  int searchR(int target) {
    return searchR(head, target);
  }
  
  int sum() {
    return sum(head);
  }
  
private:
  unsigned int size;
  Node* head;
  
  int sum(Node* head) {
    if (head == NULL) {
      return 0;
    }
    return head->value + sum(head->next);
  }
  
  Node* insertR(Node* head, int value) {
    if (head == NULL) {
      return createNode(value, head);
    }
    head->next = insertR(head->next, value);
    return head;
  }
  
  int searchR(Node* head, int target) { 
    if (head == NULL) {
      return -1;
    }
    
    if (head->value == target) {
      return 0;
    }
    
    int result = searchR(head->next, target);
    if (result < 0) {
      return result;
    } else {
      return 1 + result;
    }
  }
    
  
  Node* createNode(int value, Node* next) {
    Node* newNode = new Node;
    newNode->value = value;
    // (*newNode).value = value; <- same as prev line
    newNode->next = next;
    return newNode;
  }
};


int main() {
  LinkedList myLL;
  for (int i = 3; i >= 1; i--) {
    myLL.insertFirst(i);
    myLL.print();
  }  
  for (int i = 4; i <= 7; i++) {
    myLL.insert(i);
    myLL.print();
  }
  for (int i = 8; i <= 11; i++) {
    myLL.insertR(i);
    myLL.print();
  }
  for (int i = 3; i >= 1; i--) {
    myLL.removeFirst();
    myLL.print();
  }
  myLL.removeAt(1);
  myLL.print();
  myLL.removeAt(2);
  myLL.print();
  myLL.removeAt(3);
  myLL.print();
  myLL.removeAt(4);
  myLL.print();
  
  cout << "search(4) : " << myLL.search(4) << endl;
  cout << "search(999) : " << myLL.search(999) << endl;
  
  for (int i = 2; i <= 12; i += 2) {
    cout << "searchR(" << i << ") : " << myLL.searchR(i) << endl;
  }
  cout << "sum() = " << myLL.sum() << endl;
}




