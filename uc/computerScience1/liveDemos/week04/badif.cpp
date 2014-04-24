#include <iostream>
using namespace std;

int main() {
  
  cout << "Enter an integer: ";
  int num = 0;
  cin >> num;

  cout << "num is " << num << endl;
  if (num % 2 == 0) {
    cout << "num is even" << endl;
  }

  return 0;
}

