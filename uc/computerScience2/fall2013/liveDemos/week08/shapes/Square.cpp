#include <Square.h>
#include <iostream>
using namespace std;

Square::Square(int sideLength) {
  cout << "Square::Square(int)" << endl;
  this->sideLength = sideLength;
}

Square::~Square() {
  cout << "Square::~Square()" << endl;
}

double Square::area() const {
  return sideLength * sideLength;
}

double Square::primater() const {
  return 4 * sideLength;
}

Square::Square() {
  cout << "Square::Square()" << endl;
}
  