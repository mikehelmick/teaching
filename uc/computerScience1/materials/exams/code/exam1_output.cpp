#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int x = 4;
  int y = 5;
  double z = 10;
  
  cout << "012345678911234567892123" << endl;
  
  cout << setw(12) << x << setw(12) << y << endl;
  cout << setw(12) << left << x << setw(12) << left << y << endl;
  cout << setw(12) << right << x << setw(12) << right << y << endl;
  
  cout << "x*y = " << setw(1) << x * y << endl;
  
  double a = y / x;
  cout << setw(10) << setprecision(5) << a << endl;
  cout << setw(10) << setprecision(5) << fixed << a << endl;
  
  double b = y / z;
  cout << setw(10) << setprecision(5) << fixed << b << endl;
  
  return 0;
}