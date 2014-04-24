#include <iostream>
using namespace std;

int main() {

  cout << "What direction do you want to go? (n, s, e, w): ";
  char ch = '0';
  
  cin >> ch;
  switch (ch) {
    case 'n':
      cout << "Moving North." << endl;
      break;
    case 's':
      cout << "Moving South." << endl;        
      break;
    case 'e':
      cout << "Moving East." << endl;
      break;
    case 'w':
      cout << "Moving West." << endl;
      break;
    default:
      cout << "error: please enter one of (n, s, e, or w)";  
  }

  return 0;
}