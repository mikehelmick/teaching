#include <cstring>
#include <iostream>

using namespace std;

int main() {
  char str[80];

  str[0] = 'H';
  str[1] = 'i';
  str[15] = 0;

  cout << "str= '" << str << "'" << endl;
  cout << "length=" << strlen(str) << endl;
}
