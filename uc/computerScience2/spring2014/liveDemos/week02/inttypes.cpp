#include <climits>
#include <iostream>
using namespace std;

int main() {

  unsigned long long x = 4;
  cout << "sizeof x is " << sizeof(x) << endl;
  cout << "MIN value is " << 0 << endl;
  cout << "MAX value is " << ULLONG_MAX << endl;

  return 0;
}
