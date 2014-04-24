#include <iostream>

using namespace std;


struct Node {
  int value;
  Node *next;
};


void printList(const Node* head) {
  if (head == NULL) {
    cout << "NULL" << endl;
    return;
  }
  cout << head->value << " -> ";
  printList(head->next);
}


int main() {
  
  Node* head = new Node;
  head->value = 1;
  
  head->next = new Node;
  head->next->value = 2;
  head->next->next = NULL;
  
  printList(head);
}