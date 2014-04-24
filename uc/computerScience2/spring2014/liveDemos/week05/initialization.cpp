#include <iostream>

using namespace std;

class MyClass {
public:
  MyClass(int x, int y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  int getX() { return x; }
  int getY() { return y; }
  float getZ() { return z; }
  
private:
  int x;
  int y;
  float z;
};

void pointerExample() {
  
}

int main() {
  int x;
  int y = 3;
  cout << "x=" << x << " y=" << y << endl;
  cout << "x*y=" << x * y << endl;
  
  
  MyClass* pMyClass = new MyClass(1, 2, 3.3);
  cout << "x=" << pMyClass->getX()
      << " y=" << pMyClass->getY()
      << " z=" << pMyClass->getZ() << endl;
  delete pMyClass;
  pMyClass = NULL;
}




