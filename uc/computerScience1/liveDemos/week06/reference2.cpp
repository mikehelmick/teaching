#include <iostream>
using namespace std;

void doubleBoth(int &a, double &b) {
  cout << "&a= " << &a << " a = " << a; 
  cout << " &b= " << &b << " b = " << b << endl;
  a *= 2;
  b *= 2;
}

int main() {
 
  int x = 40;
  double y = 45.1234;
  cout << "&x= " << &x << " x = " << x;
  cout << " &y= " << &y << " y = " << y << endl;
  doubleBoth(x, y);
  cout << "&x= " << &x << " x = " << x;
  cout << " &y= " << &y << " y = " << y << endl;

}
