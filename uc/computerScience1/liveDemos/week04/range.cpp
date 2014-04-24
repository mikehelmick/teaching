#include <iostream>
using namespace std;

int main() {
  
  cout << "Enter an integer between 0 and 100: ";
  int x = 0;
  cin >> x;
  
  // Using AND and OR we can write this two different way
  if (x <= 0 || x >= 100) {
    cout << x << "is outside the requested range, between 20 and 40." << endl;
  }
  
  if (!(x > 0 && x < 100)) {
    cout << x << "is outside the requested range, between 20 and 40." << endl;
  }
  
}