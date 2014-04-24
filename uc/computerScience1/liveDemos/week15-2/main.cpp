#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string intToString(int val) {
  stringstream ss;
  ss << "#:" << val;
  return ss.str();
}

#include <LinkedList.h>

int main() {
  LinkedList<string> ll;
  for (int i = 0; i < 10; i++) {
    ll.insertFront(intToString(i));
    if (ll.getSize() % 1000 == 0) {
      cout << ll.getSize() << endl;
    }
  }
  for (int i = 1; i < 10; i += 2) {
    ll.insertAt(intToString(i), i);
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
