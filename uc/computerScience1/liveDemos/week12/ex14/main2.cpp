#include <iostream>
using namespace std;

class MyClass {
public:
  MyClass(int value) {
  	cout << "1 param constructor called: " << value << endl;
  	this->value = value;
  }

  MyClass(int value, int value2) {
    cout << "2 param constructor called" << endl;
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
  MyClass array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  for (int i = 0; i < 10; i++) {
  	cout << i << " :: " << array[i].getValue() << endl;
  }

}
