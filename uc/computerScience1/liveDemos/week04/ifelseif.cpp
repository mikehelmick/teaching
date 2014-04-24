#include <iostream>
using namespace std;

int main() {

  cout << "Enter an integer: " << endl;
  int x = 0;
  cin >> x;
  
  // Order matters here. If we switch the order of 4 and 2,
  // then 4 would never match, since 2 would always match first.
  if (x % 2 == 0) {
    cout << x << " is a multiple of 2" << endl;
  } else if (x % 4 == 0) {
    cout << x << " is a multiple of 4" << endl;
  } else {
    cout << x << " not not a multiple of 4 or 2" << endl;
  }

  return 0;
}
