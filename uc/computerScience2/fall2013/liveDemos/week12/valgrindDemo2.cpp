/*
 * Demo for valgrind and memory leaks.
 * Author: Paul Talaga
 * Date: 11/13/2013
 *
 * Compile this with 'g++ valgrindDemo1.cpp' (just like normal).
 * Then check memory with 'valgrind ./a.out'
 */

#include <iostream>

using namespace std;

struct node_t {
  int value;
  node_t* next;
};

int main(){
  node_t* a = new node_t;
  node_t* head = a;
  a->value = 5;
	a->next = NULL;
  for(int i = 0; i < 1000; i++){
	  node_t* b = new node_t;
	  b->value = i;
	  b->next = NULL;
	  a->next = b;
	  a = b;
	}
	a = head;
	while(a != NULL){
	  cout << a->value << " ";
	  a = a->next;
	}
	// return memory
	a = head;
	while(a != NULL){
	  node_t* temp = a;
	  a = a->next;
	  delete temp;
	  temp = NULL;
	}
	
}
