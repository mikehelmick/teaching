#include <iostream>
using namespace std;

class MyClass {
public:
  MyClass() {
  	cout << "Default constructor called" << endl;
    value = 0;
  }

  MyClass(int value) {
  	cout << "1 param constructor called" << endl;
  	this->value = value;
  }

  virtual ~MyClass() {
    cout << "Destructor called" << endl;
  }

  int getValue() {
  	return value;
  }
private:
  int value;
};

int main() {
  MyClass array[10];

  for (int i = 0; i < 10; i++) {
  	cout << i << " :: " << array[i].getValue() << endl;
  }

}
