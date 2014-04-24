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

// Performs mergesort on a linked lists of unknown size.
// Returns a pointer to the new head of the sorted list.
Node* mergeSort(Node* head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  // partition into left and right
  // Anchor the left at the start
  Node* left = head;
  Node* curLeft = left;
  head = head->next;
  Node* right = head;
  Node* curRight = right;
  head = head->next;
  while (head != NULL) {
    curLeft->next = head;
    head = head->next;
    curLeft = curLeft->next;
    if (head != NULL) {
      curRight->next = head;
      head = head->next;
      curRight = curRight->next;
    }
  }
  // Ensure both lists are terminated
  curLeft->next = NULL;
  curRight->next = NULL;
  
  left = mergeSort(left);
  right = mergeSort(right);
  
  // Perform the merge step
  // Cheat - make head not null, for easy advancement, we will take it off later
  Node* newHead = new Node;
  Node* curNode = newHead;
  while (left != NULL || right != NULL) {
    if (left != NULL && right != NULL) {
      if (left->value <= right->value) {
        curNode->next = left;
        curNode = curNode->next;
        left = left->next;
      } else {
        curNode->next = right;
        curNode = curNode->next;
        right = right->next;
      }
    } else if (left == NULL) {
      // left is empty, just add the riest of right
      curNode->next = right;
      // null out right so that the loop stops
      right = NULL;
    } else if (right == NULL) {
      curNode->next = left;
      left = NULL;
    }
  }
  Node* delNode = newHead;
  newHead = newHead->next;
  delete delNode;
  return newHead;
}

int main() {
  Node* head = NULL;
  for (int i = 0; i <= 11; i++) {
    head = insertFront(i, head);
  }

  print(head);
  head = mergeSort(head);
  print(head);
}