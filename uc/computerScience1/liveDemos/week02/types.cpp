#include <iostream>
#include <climits>
using namespace std;

int main() {

  // Compile warning
  int x = 42.42;
  cout << "x = " << x << endl;
  
  unsigned long y = ULONG_MAX - 1000;
  cout << "y = " << y << endl;
  cout << "Assigning y to x " << endl;
  x = y;
  cout << "x = " << x << " instead of " << y << endl;
    

  return 0;
}