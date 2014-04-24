#include <iostream>
#include <string>

using namespace std;

void print_stats(const string& str) {
  cout << " char 5 is '" << str[5] << "'" << endl;
  cout << " length is " << str.length() << endl;
  cout << " substr(4,9) '" << str.substr(4, 9) << "'" << endl;
}

int main() {
  string str = "Hello, my name is Joe.";
  print_stats(str);
}
