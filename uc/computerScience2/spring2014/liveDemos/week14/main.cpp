#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;

#include <LinkedList.h>

int main() {
 /*
  LinkedList<string>* sLL = new LinkedList<string>();
  sLL->insertFirst("Hello");
  sLL->insertFirst("world");

  sLL->print();

  string val = sLL->removeFirst();
  cout << "Removed: " << val << endl;
  sLL->print();
  sLL->removeFirst();
  sLL->print();
  try {
    sLL->removeFirst();
    // For unit testing, put this in to automatically fail a test
    // if this line is reached, in this case because expected exception
    // was not thrown.
    // TS_FAIL("Exception not thrown");
  } catch (length_error &err) {
    cout << "Removal failed with: " << err.what() << endl;
  }

  delete sLL;
  */

  /*
  // Standard STL iterator syntax
  vector<string> myVec;
  myVec.push_back("one");
  myVec.push_back("two");

  for (vector<string>::iterator it = myVec.begin(); it != myVec.end(); it++) {
    cout << *it << endl;
  }
  */

  {
  LinkedList<int> myLL;
  myLL.insertFirst(3);
  myLL.insertFirst(2);
  myLL.insertFirst(1);

  for (LinkedList<int>::iterator it = myLL.begin(); it != myLL.end(); it++) {
    cout << "item: " << *it << endl;
  }

  }
}
















