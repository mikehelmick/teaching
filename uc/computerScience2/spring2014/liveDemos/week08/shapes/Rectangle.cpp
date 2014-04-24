/*
 * Rectangle.cpp
 *
 *  Created on: Feb 24, 2014
 *      Author: student
 */

#include "Rectangle.h"
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

Rectangle::Rectangle(double length, double width)
    : length(length), width(width) {
  cout << "Rectangle::Rectangle(length, width)" << endl;
}

Rectangle::~Rectangle() {
  cout << "Rectrangle::~Rectangle()" << endl;
}

double Rectangle::area() const {
  return length * width;
}

double Rectangle::primater() const {
  return 2 * length + 2 * width;
}

const double Rectangle::getLength() const {
  return length;
}

const double Rectangle::getWidth() const {
  return width;
}

bool Rectangle::isEqual(Shape *rhs) const {
  string thisType = typeid(*this).name();
  string thatType = typeid(*rhs).name();

   if (thisType == thatType) {
     // They may be equal
     Rectangle* that = dynamic_cast<Rectangle*>(rhs);
     return doubleIsEqual(this->length, that->length, 0.0001)
         && doubleIsEqual(this->width, that->width, 0.0001);
   }
   return false;
}


