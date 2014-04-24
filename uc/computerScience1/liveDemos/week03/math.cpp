#include <iostream>
#include <cmath>
using namespace std;

int main() {
  
  double x = 0;
  double y = 0;
  cout << "Enter x: ";
  cin >> x;
  cout << "Enter y: ";
  cin >> y;
  cout << "x^y = " << pow(x,y) << endl;
  
  // Non-standard, but usually there (from what I can tell)
  cout << "PI: " << M_PI << endl;
  
  return 0;
}