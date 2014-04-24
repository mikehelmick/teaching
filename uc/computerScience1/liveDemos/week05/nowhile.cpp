#include <iostream>
using namespace std;

int main() {

  cout << "Enter a capital letter: ";
  char ch;
  cin >> ch;

  while (!(ch >= 'A' && ch <= 'Z')) {
    cout << "No, that is not a capital letter. Please try again." << endl;
    cout << "Enter a capital letter: ";
    cin >> ch;
  }
  cout << "You did it!" << endl;
}

