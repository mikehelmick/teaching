#include <iostream>
using namespace std;

int main() {

  cout << "What direction do you want to go? (n, s, e, w): ";
  char ch = '0';
  
  cin >> ch;
  // Sometimes you want multiple cases to have the same output
  if (ch == 'n' || ch == 'N') {
    cout << "Moving North." << endl;
  } else if (ch == 's' || ch == 'S') {
    cout << "Moving South." << endl;        
  } else if (ch == 'e' || ch == 'E') {
    cout << "Moving East." << endl;
  } else if (ch == 'w' || ch == 'W') {
    cout << "Moving West." << endl;
  } else {
    cout << "error: please enter one of (n, s, e, or w)";  
  }
  return 0;
}