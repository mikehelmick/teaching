#include <iostream>
using namespace std;

int main() {
  
  int x = 5;
  double y = 1.2345;
  cout << "x = " << x << " y=" << y <<  endl;
  
  {
    char x = 'x';
    cout << "x = " << x << " y=" << y << endl;
    
    {
      double x = 1.2345;
      string y = "hello";
      cout << "x = " << x << " y=" << y << endl;
    }
    cout << "x = " << x << " y=" << y << endl;
  }
  cout << "x = " << x << " y=" << y << endl;
  
  return 0;
}
