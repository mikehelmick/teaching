#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "What is your name and favorite number? " << endl;
  
  string name = "";
  int number = 0;
  
  // Oops, These are being read in the incorrect orrder!
  cin >> number >> name;
  
  cout << "You entered:" << endl
      << name << endl
      << number << endl;
  
  cout << endl << endl << "Enter a floating point number: ";
  // Opps, wrong type!
  int floatingPointNumber = 0;
  cin >> floatingPointNumber;
  cout << "You entered: " << floatingPointNumber << endl;
  
}