#include <iostream>
using namespace std;

int main() {
  
  int x = 8;
  
  // BAD variant #1
  if (x % 2 == 0)
    cout << "x is even" << endl;
  else;
    cout << "x is odd" << endl;
  
  return 0;
}