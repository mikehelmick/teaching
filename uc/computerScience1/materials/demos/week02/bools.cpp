#include <iostream>
using namespace std;

int main() {
  
  bool val = true;
  cout << "val = " << val << endl;
  val = false;
  cout << "val = " << val << endl;
  val = !val;
  cout << "val = " << val << endl;
  
  val = 25;
  cout << "val = " << val << endl;

  val = 0;
  cout << "val = " << val << endl;

  if (!val) {
    cout << "Val is false!" << endl;
  }
  
  return 0;
}

