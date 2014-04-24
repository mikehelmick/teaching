/*
 * Oval.cpp
 *
 *  Created on: Feb 24, 2014
 *      Author: student
 */

#include "Oval.h"

#include <typeinfo>
#include <string>
using namespace std;

Oval::Oval(double a, double b) :
    a(a), b(b) {
}

Oval::~Oval() {
}

double Oval::area() const {
  return M_PI * a * b;
}

double Oval::primater() const {
  return 2 * M_PI * sqrt((pow(a, 2) + pow(b, 2)) / 2);
}

const double Oval::getA() const {
  return a;
}

bool Oval::isEqual(Shape *rhs) const {
  string thisType = typeid(*this).name();
  string thatType = typeid(*rhs).name();

  if (thisType == thatType) {
    // They may be equal
    Oval* that = dynamic_cast<Oval*>(rhs);
    return doubleIsEqual(this->a, that->a, 0.0001)
        && doubleIsEqual(this->b, that->b, 0.0001);
  }
  return false;
}

