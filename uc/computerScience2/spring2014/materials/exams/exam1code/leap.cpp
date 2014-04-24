#include <iostream>
using namespace std;

bool leap(int year) {
  return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int main() {
  cout << leap(1900) << endl;
  
  for (int year = 1990; year <= 2013; year++) {
    cout << year << " " << leap(year) << endl;
  }
}