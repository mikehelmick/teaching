#include <iostream>
using namespace std;

int main() {

  cout << "Continue? (y/n): ";
  char ch;
  cin >> ch;

  while (ch != 'y' && ch != 'n') {
    cout << "ERROR, enter y or n. Continue? (y/n): ";
    cin >> ch;
  }

  cout << "Thank you for entering a valid choice." << endl;
}

