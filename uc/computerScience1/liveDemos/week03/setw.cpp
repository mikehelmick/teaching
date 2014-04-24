#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
  string name = "Thomas the Tank Engine";
  cout << "len: " << name.length() << endl;

  cout << "-" << setw(30) << name << "-" << endl;
  cout << "-" << setw(22) << name << "-" << endl;
  cout << "-" << setw(20) << name << "-" << endl;
  cout << "-" << setw(5) << name << "-" << endl;

  return 0;
}
