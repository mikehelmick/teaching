// week05/continue.cpp
//

#include <iostream>
using namespace std;

int main() {
 
  while(true) {
    cout << "Enter an even number: ";

    int even;
    cin >> even;
    if (even % 2 != 0) {
      cout << "Error : the number was not even." << endl;
      continue;
    }

    cout << "Enter an odd number: ";
    int odd;;
    cin >> odd;
    if (odd % 2 != 1) {
      cout << "Error : the number was not odd." << endl;
      continue;
    }

    // The user successfully entered an even and an odd number
    break;
  }
  cout << "You win!" << endl;
}

