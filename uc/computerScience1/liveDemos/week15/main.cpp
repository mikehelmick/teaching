#include <iostream>
using namespace std;

#include <LinkedList.h>

int main() {
  LinkedList ll;
  for (int i = 0; i < 1000000000; i++) {
    ll.insertFront(i);
    if (ll.getSize() % 1000 == 0) {
      cout << ll.getSize() << endl;
    }
  }
  for (int i = 1; i < 10; i += 2) {
    ll.insertAt(i, i);
    ll.print();
  }

  cout << "REMOVE" << endl;

  // Remove at
  int pos = 0;
  while (pos < ll.getSize()) {
    ll.removeAt(pos);
    ll.print();
    pos += 2;
  }

}
