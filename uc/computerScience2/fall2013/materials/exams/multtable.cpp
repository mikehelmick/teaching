#include <iostream>
#include <string>
using namespace std;

int main() {
  cout.width(3);  // This sets the next thing printed to be of width 3.  Does not stick!
  cout << "Enter the dimension of the multiplication table? "; 

  string s("test");
  s.size();
 
  int dim = 0;
  cin >> dim;
  for (int y = 0; y <= dim; y++) {
    for (int x = 0; x <= dim; x++) {
      cout.width(3);
      cout << (y * x);
      cout << ' ';
    }
    cout << endl;
  }
}
