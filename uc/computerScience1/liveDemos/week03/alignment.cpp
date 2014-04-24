#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
  string moose = "Bullwinkle Moose";
  cout << moose.length() << " characters in the string" << endl;
  cout << "12345678911234567892" << endl;
  cout << setw(20) << left << moose << endl;
  cout << setw(20) << right << moose << endl;

  double fNum = 12345.6789012345678;
  cout << "12345678911234567892" << endl;
  cout << setw(20) << left << fNum << endl;
  cout << setw(20) << right << fNum << endl;
  cout << setw(20) << setprecision(10) << left << fNum << endl;
  cout << setw(20) << setprecision(10) << right << fNum << endl;
  cout << setw(20) << setprecision(10) << left << fixed << fNum << endl;
  cout << setw(20) << setprecision(10) << right << fixed << fNum << endl;

  return 0;
}
