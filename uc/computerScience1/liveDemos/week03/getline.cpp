#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "Enter a line of text:" << endl;  
  string line;
  getline(cin, line);
  cout << "You entered: " << endl
      << line << endl << "-----" << endl;
  return 0;
}
