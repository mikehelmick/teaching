#include <Square.h>
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

Square::Square(int sideLength) : Rectangle(sideLength, sideLength) {
  cout << "Square::Square(int)" << endl;
}

Square::~Square() {
  cout << "Square::~Square()" << endl;
}

bool Square::isEqual(Shape *rhs)
{
  string thisType = typeid(*this).name();
  string thatType = typeid(*rhs).name();

  if (thisType == thatType) {
    // They may be equal
    Square* that = dynamic_cast<Square*>(rhs);
    return doubleIsEqual(this->getLength(), that->getLength(), 0.0001)
        && doubleIsEqual(this->getWidth(), that->getWidth(), 0.0001);
  }
  return false;
}


  
