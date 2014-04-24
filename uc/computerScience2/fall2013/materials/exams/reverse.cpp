#include <iostream>

using namespace std;

struct Node {
  int value;
  Node* next;
};

Node* insertFront(int value, Node* head) {
  Node* newNode = new Node;
  newNode->value = value;
  newNode->next = head;
  return newNode;
}

void print(Node* head) {
  cout << "head: ";
  Node* cur = head;
  while (cur != NULL) {
    cout << cur->value << " -> ";
    cur = cur->next;
  }
  cout << "NULL" << endl;
}

Node* reverse(Node* head) {
  Node* newHead = NULL;
  while (head != NULL) {
    Node* nextNode = head->next;
    head->next = newHead;
    newHead = head;
    head = nextNode;
  }
  return newHead;
}


int main() {
  Node* head = NULL;
  for (int i = 0; i <= 11; i++) {
    head = insertFront(i, head);
  }

  print(head);
  head = reverse(head);
  print(head);
}