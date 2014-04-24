#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
  double val = 54.692813023948;
  
  for (int i = 0; i < 15; i++) {
    cout << "-" << setw(3) << i << "- : -"
        << setw(3) << setprecision(i) << val << "-" << endl;
  }
  
}
