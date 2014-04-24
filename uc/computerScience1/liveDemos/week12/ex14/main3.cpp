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

  MyClass(int value, int value2) {
    cout << "2 param constructor called: " << value << " , " << value2 << endl;
    this->value = value + value2;
  }

  int getValue() {
  	return value;
  }
private:
  int value;
};

int main() {
  // Causes the 1 param constructor to be called
  MyClass array[10] = {
    MyClass(1, 2),
    MyClass(2, 3),
    MyClass(3, 4),
    MyClass(4, 5),
    MyClass(5, 6),
    MyClass(6, 7),
    MyClass(7, 8),
    MyClass(8, 9),
    MyClass(9, 10),
    MyClass(10, 11)
  };

  for (int i = 0; i < 10; i++) {
  	cout << i << " :: " << array[i].getValue() << endl;
  }

}
