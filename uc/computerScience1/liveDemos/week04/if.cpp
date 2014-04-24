#include <iostream>
using namespace std;

int main() {
  
  cout << "Enter the temperature (deg F): ";
  double temp = 0;
  cin >> temp;
  
  // the {} is not strictly required, but if not there
  // you can only have 1 (ONE, UNO) statement in the if.
  if (temp <= 32) {
    cout << "It is freezing!" << endl;
    cout << "You should wear a coat." << endl;
  }

  // I recommend (And good style dictates) that you
  // should always use the {}, so you don't make the above
  // mistake.
  if (temp >= 85) {
    cout << "Warm temperatures!" << endl;
    cout << "You should stop using this computer, and go outside." << endl;
  }
  
  return 0;
}
