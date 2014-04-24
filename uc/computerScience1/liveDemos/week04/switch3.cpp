#include <iostream>
using namespace std;

int main() {

  cout << "What direction do you want to go? (n, s, e, w): ";
  char ch = '0';
  
  cin >> ch;
  // Sometimes you want multiple cases to have the same output
  switch (ch) {
    case 'n':
    case 'N':
      cout << "Moving North." << endl;
      break;
    case 's':
    case 'S':
      cout << "Moving South." << endl;        
      break;
    case 'e':
    case 'E':
      cout << "Moving East." << endl;
      break;
    case 'w':
    case 'W':
      cout << "Moving West." << endl;
      break;
    default:
      cout << "error: please enter one of (n, s, e, or w)";  
  }

  return 0;
}