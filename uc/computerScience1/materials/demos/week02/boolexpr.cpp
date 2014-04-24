#include <iostream>
using namespace std;

int main() {
  bool a = true;
  bool b = false;

  cout << "not" << endl;
  cout << "a !a " << endl;
  cout << true << "  " << !true << endl;
  cout << false << "  " << !false << endl;
  cout << endl;

  // BOOL operator for or is ||
  cout << "or" << endl;
  cout << "a b | a||b" << endl;
  cout << false << " " << false << " | " << (false||false) << endl;
  cout << false << " " << true  << " | " << (false||true) << endl;
  cout << true  << " " << false << " | " << (true||false) << endl;
  cout << true  << " " << true  << " | " << (true||true) << endl;

  // BOOl operator for and is &&
  cout << "and" << endl;
  cout << "a b | a&&b" << endl;
  cout << false << " " << false << " | " << (false&&false) << endl;
  cout << false << " " << true  << " | " << (false&&true) << endl;
  cout << true  << " " << false << " | " << (true&&false) << endl;
  cout << true  << " " << true  << " | " << (true&&true) << endl;


  return 0;
}
