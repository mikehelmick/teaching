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
  for(int i = 0; i < 1000; i++){
	  node_t* a = new node_t;
	  a->value = 5;
	  a->next = NULL;
	}
}
