
#include <Stack.h>
#include <LinkedList.h>

#include <string>
#include <vector>
#include <iostream>
using namespace std;


int main() {
  /*
  LinkedList<string> lls;
  lls.insertFirst("one");
  lls.insertLast("two");
  lls.insertLast("three");
  lls.insertLast("four");
  lls.insertLast("five");
  lls.insertLast("six");
  lls.print();
  
  for (LinkedList<string>::Iterator it = lls.begin(); it != lls.end(); it++) {
    cout << *it << endl; 
  }
  */
  
  Stack<int>* stack = new LinkedList<int>();
  stack->push(1);
  stack->push(3);
  stack->push(5);
  stack->print();
  cout << "pop: " << stack->pop() << endl;
  stack->print();
}