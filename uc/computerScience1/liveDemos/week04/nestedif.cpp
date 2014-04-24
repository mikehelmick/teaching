#include <iostream>
using namespace std;

int main() {
  cout << "Enter a number: ";
  int x = 0;
  cin >> x;
  
  if (x <= 0) {
    cout << x << " is negative or zero." << endl;
  } else {
    // INVARIANT: We know that x is positive.
    cout << x << " is positive and ";
    // Now we will check if it is even or odd.
    if (x % 2 == 0) {
      cout << "even." << endl;
    } else {
      cout << "odd." << endl;
    }  
  }

  return 0;
}