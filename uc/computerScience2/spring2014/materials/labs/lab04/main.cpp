#include <iostream>
#include <string>

#include <Money.h>

using namespace std;

int main() {
  cout << "There's nothing here. Add stuff if you like, but remember the unit tests are what is graded." << endl << endl;

  Money m1(1, 52);
  cout << m1.toString() << " d: " << m1.getAsDouble() << endl;
  
  
  Money m2(1.52);
  cout << m1.toString() << " d: " << m1.getAsDouble() << endl;
}