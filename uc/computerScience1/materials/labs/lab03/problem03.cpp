#include <iostream>
using namespace std;

bool isMagic(int month, int day, int year) {
  return month * day == year;
}

int main() {
  cout << "Enter a date in the format m/d/y: ";
  int month = 0;
  int day = 0;
  int year = 0;
  char trash;
  cin >> month >> trash >> day >> trash >> year;
  cout << "The date " << month << "/" << day << "/" << year << " is "; 
  if (!isMagic(month, day, year)) {
    cout << "NOT ";
  }
  cout << "a magic date." << endl;
}