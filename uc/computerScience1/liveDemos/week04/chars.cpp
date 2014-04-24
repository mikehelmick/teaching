#include <iostream>
using namespace std;

int main() {
  cout << "Type a 3 letter word: ";
  char a, b, c;
  cin >> a >> b >> c;
  
  if (a >= b && a >= c) {
    cout << a << " is >= than both " << b << " and " << c << endl;
  } else if (b >= a && b >= c) {
    cout << b << " is >= than both " << a << " and " << c << endl;
  } else {
    cout << c << " is >= than both " << a << " and " << b << endl;
  }

  return 0;
}