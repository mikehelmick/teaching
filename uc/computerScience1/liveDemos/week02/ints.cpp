#include <iostream>
using namespace std;

int main() {
  short a = 32760;  
  cout << "Size of shorts " << sizeof(a) << endl;
  
  for (int i = 0; i < 20; i++) {
    a++;
    cout << a << endl;
  }
  cout << "done." << endl;
}