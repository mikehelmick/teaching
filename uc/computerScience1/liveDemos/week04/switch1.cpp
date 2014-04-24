#include <iostream>
using namespace std;

int main() {

  cout << "What direction do you want to go? (n, s, e, w): ";
  char ch = '0';
  
  cin >> ch;
  // Missing the "break" statements
  switch (ch) {
    case 'n':
      cout << "Moving North." << endl;
    case 's':
      cout << "Moving South." << endl;        
    case 'e':
      cout << "Moving East." << endl;
    case 'w':
      cout << "Moving West." << endl;
    default:
      cout << "error: please enter one of (n, s, e, or w)";  
  }

  return 0;
}