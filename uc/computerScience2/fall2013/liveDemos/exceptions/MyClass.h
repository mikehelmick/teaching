#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <stdexcept>
using namespace std;

class MyClass {
public:
  MyClass() { 
  }

  bool isValid(int x) {
    if (x % 2 == 0) {
      return true;
    }
    throw invalid_argument("x must be even");
  }
};

#endif