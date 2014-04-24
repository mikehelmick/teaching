#include <iostream>
#include <vector>
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

  MyClass(int value, int value2) {
    cout << "2 param constructor called: " << value << " , " << value2 << endl;
    this->value = value + value2;
  }

  virtual ~MyClass() {
    cout << "Destructor called, value: " << value << endl;
  }

  int getValue() {
  	return value;
  }
private:
  int value;
};

int main() {
  // Causes the 1 param constructor to be called
  vector<MyClass> array;
  for (int i = 1; i <= 10; i++) {
    MyClass mc(i, i + 1);
    array.push_back(mc);
  }

  for (int i = 0; i < 10; i++) {
  	cout << i << " :: " << array[i].getValue() << endl;
  }

}
