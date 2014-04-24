#include <iostream>
using namespace std;

class MyClass {
public:
  MyClass() {
    cout << "Constructor called" << endl;
  }

  virtual ~MyClass() {
    cout << "Destructor called" << endl;
  }
};

int main() {
  cout << "Opening scope " << endl;
  {
    MyClass a;
  }
  cout << "Closing scope " << endl;

  cout << "----" << endl;
  cout << "Opening scope " << endl;
  {
    MyClass* a = new MyClass();
    a->~MyClass();
    delete a;
  }
  cout << "Closing scope " << endl;

}
