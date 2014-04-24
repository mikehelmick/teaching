/*
 * Shape.cpp
 *
 *  Created on: Oct 7, 2013
 *      Author: helmicmt
 */

#include "Shape.h"
#include <cmath>
#include <iostream>

using namespace std;

Shape::Shape() {
  cout << "Shape::Shape()" << endl;
}

Shape::~Shape() {
  cout << "Shape::~Shape()" << endl;
}

bool Shape::doubleIsEqual(double a, double b, double delta) const {
  return abs(a - b) < delta;
}


