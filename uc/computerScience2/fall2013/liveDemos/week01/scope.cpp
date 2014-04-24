#include <iostream>

using namespace std;

int main() {

  int x = 5;
  {
    int x = 6;







    cout << "x is " << x << endl;
  }
  cout << "x is " << x << endl;
}
