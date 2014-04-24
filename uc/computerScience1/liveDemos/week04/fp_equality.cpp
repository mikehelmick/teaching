#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
  
  double x = 0.15 + 0.15;
  double y = 0.1 + 0.2;
  
  // Move out precision to show the routing errors
  for (int p = 3; p < 19; p++) {
    cout << setw(20) << setprecision(p) << fixed << x << " -- " << y << endl;
  }
  if (x == y) {
    cout << "They are equal" << endl;
  } else if (x != y) {
    cout << "They are not equal" << endl;
  }
  
  cout << "Using delta function: ";
  if (abs(x - y) < 0.00000001) {
    cout << "They are equal" << endl;
  } else if (x != y) {
    cout << "They are not equal" << endl;
  } 
}
