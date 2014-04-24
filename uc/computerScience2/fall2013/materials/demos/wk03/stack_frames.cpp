#include <iostream>
using namespace std;

struct color {
  long r;
  long g;
  long b;
};

color funWithPointers(int x) {
  int* address = (&x) + 0;
  cout << "  x addr = " << address << endl;
  cout << "addraddr = " << &address << endl;

  int* rtnAddress = address - 24;
  cout << "maybe rtn addres: " << rtnAddress << endl;
  
  (*(rtnAddress + 0)) = 0xffff;
  //(*(rtnAddress + 4)) = 0xff;
  //(*(rtnAddress + 8)) = 0xff;
  //address += 4;
  //*address = 8;
  //cout << "w addr= " << address << endl;

  
  
  
  //cout << "Val at y = " << *address << endl;
}

int main() {
  int x  = 42;
  color y = funWithPointers(x);
  cout << "y addr= " << &y << endl;
  cout << "y.r= " << y.r << endl;
  cout << "y.g= " << y.g << endl;
  cout << "y.b= " << y.b << endl;
}