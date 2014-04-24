#include <iostream>
using namespace std;

int main() {
  
  char ch = 'A';
  
  for (int i = 0; i < 26; i++) {
    int value = ch;
    cout << "ch = '" << ch << "'  value = " << value << endl;
    ch++;
  }
  
  return 0;
}

