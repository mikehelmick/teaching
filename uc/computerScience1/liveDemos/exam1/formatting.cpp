#include <iostream>
#include <iomanip>
using namespace std;

int main() {

  int x = 12345;
  int y = 99999;

  cout << "|" << setw(10) << left << x << "|"
    << setw(10) << y << "|" << endl;
  cout << "|" << setw(10) << x << "|" 
       << setw(10) << y << "|" << endl;

  double a = 1.234;
  double b = 1.235;

  cout << setprecision(2) << fixed
    << "|" << setw(10) << a
    << "|" << setw(10) << b << endl;

  return 0;
}
