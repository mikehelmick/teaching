#include <iostream>
using namespace std;

struct Node {
  int value;
  Node* next;
};

class LinkedList {
private:
  Node* head;
  
public:
  LinkedList() {
    head = NULL;
  }
  
  void push(int val) {
    if (head == NULL) {
      head = new Node;
      head->value = val;
      head->next = NULL;
    } else {
      Node* curN = new Node;
      curN->value = val;
      curN->next = head;
      head = curN;
    }
  }
  
  void print() {
    Node* curNode = head;
    while (curNode != NULL) {
      cout << curNode->value << " ";
      curNode = curNode->next;
    }
    cout << endl;
  }
  
  void rearrange() {

  }
};   

int main() {
  LinkedList ll;
  for (int i = 9; i >= 0; i--) {
    ll.push(i);
  }
  ll.print();
}
