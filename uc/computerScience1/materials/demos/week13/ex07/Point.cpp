// ex08/Point.cpp

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

// We have to include the definition of the point class
#include "Point.h"

Point::Point(double x, double y) {
  cout << "CONSTRUCTOR" << endl;
  this->x = new double;
  *(this->x) = x; 
  this->y = new double;
  *(this->y) = y;
}

Point::~Point() {
  cout << "DESTRUCTOR" << endl;
  delete x;
  delete y;
}

double Point::getX() const {
  return *x;
}

double Point::getY() const {
  return *y;
}

double Point::distance(const Point& that) {
  return sqrt(pow(*x - *(that.x), 2.0) + (pow(*y - *(that.y), 2.0)));
}

string Point::toString() const {
  stringstream ss;
  // this works on function calls too!
  ss << "(" << this->getX() << "," << this->getY() << ")";
  return ss.str();
}

