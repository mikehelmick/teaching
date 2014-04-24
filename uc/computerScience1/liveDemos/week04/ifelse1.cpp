#include <iostream>
using namespace std;

int main() {
  
  int x = 7;
  
  // BAD variant #2
  if (x % 2 == 0);
    cout << "x is even";
  else 
    cout << "x is odd";
  
  return 0;
}