#include <iostream>

using namespace std;

int x = 5; // global

int f(int x) {
  cout << "f(x) " << x << " &x= " << &x << endl;
}

int main() {
  cout << "X= " << x << " &x= " << &x << endl;
  int y = x;
  for (int x = 0; x < y; x++) {
    cout << "x= " << x << " &x= " << &x << endl;
  }
  
  f(x);
  
  cout << "X= " << x << " &x= " << &x << endl;
}