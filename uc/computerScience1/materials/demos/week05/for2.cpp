// week05/for2.cpp

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  
  int x = 0;
  int y = 0;
  
  for (x = 10, y = 0; x != y; x--, y++) {
    cout << "x = " << setw(2) << x << "  y = " << setw(2) << y << endl;
  }

}
