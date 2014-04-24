#include <iostream>
using namespace std;

class A {
public:
  A() {
    cout << "A()" << endl;
    aPointer = new int;
    *aPointer = 7;
  }
  ~A() {
    cout << "~A()" << endl;
    delete aPointer;
  }  
private:
  int* aPointer;
};

class B : public A {
public:
  B() {
    cout << "B()" << endl;
    bPointer = new int;
    *bPointer = 42;
  }
  ~B() {
    cout << "~B()" << endl;
    delete bPointer;
  }  
private:
  int* bPointer;
};

int main() {
  A* a = new B();
  delete a;
}