#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  {
    LinkedList<string> ll;
    ll.insertFirst("first");
    ll.print();
    ll.insertLast("last");
    ll.print();
    ll.insertAt("second", 1);
    ll.print();
    ll.removeFirst();
    ll.print();
    ll.removeLast();
    ll.print();
  }
  
  {
    LinkedList<int> ll;
    for(int i = 0; i < 15; i++) {
      ll.insertLast(i);
    }
    ll.print();
    ll.removeAt(2);
    ll.print();
    ll.insertAt(2, 2);
    ll.print();
    ll.removeAt(12);
    ll.print();
    ll.clear();
    ll.print();
  }

  {
    Stack<int>* stack = new LinkedList<int>();
    
    stack->push(5);
    stack->push(10);
    stack->print();
    cout << "peek: " << stack->peek() << endl;
    stack->pop();
    stack->print();
    
    delete stack;
  }
  
  {
    Queue<string>* queue = new LinkedList<string>();
    queue->offer("one");
    queue->offer("two");
    queue->offer("three");
    queue->print();
    queue->poll();
    queue->print();
  }
  
  {
    LinkedList<int> ll;
    for(int i = 0; i < 5; i++) {
      ll.insertLast(i);
    }
    
    int item = 0;
    LinkedList<int>::Iterator it = ll.begin();
    while (it.hasNext()) {
      int value = it.next();
      cout << "item=" << item << " is " << value << endl;
      item++;
    }
    ll.print();
    
    item = 0;
    for (LinkedList<int>::Iterator it2 = ll.begin(); it2 != ll.end(); it2++) {
      int value = *it2;
      cout << "item=" << item << " is " << value << endl;
      item++;
    }
  }
}