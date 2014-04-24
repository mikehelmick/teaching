#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "What is your name?";
  string name = "";
  cin >> name;

  cout << "Enter a number: ";
  int number1 = 0;
  cin >> number1;

  cout << "Enter two more numbers:" << endl;
  int number2 = 0;
  int number3 = 0;
  cin >> number2 >> number3;
  
  cout << endl << "Hello " << name << endl
      << "You entered: " << number1 << ", " << number2 << ", and " << number3 << endl;
}