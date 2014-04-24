/*
 * Circle.cpp
 *
 *  Created on: Feb 24, 2014
 *      Author: student
 */

#include "Circle.h"

#include <string>
#include <typeinfo>
using namespace std;

Circle::Circle(double r) : Oval(r, r) {

}

Circle::~Circle() {
}

bool Circle::isEqual(Shape *rhs) const {
  string thisType = typeid(*this).name();
  string thatType = typeid(*rhs).name();

  if (thisType == thatType) {
    // They may be equal
    Circle* that = dynamic_cast<Circle*>(rhs);
    return doubleIsEqual(this->getA(), that->getA(), 0.0001);
  }
  return false;
}



