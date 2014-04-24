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

Point::Point(const Point &that) {
  cout << "COPY CONSTRUCTOR" << endl;
  // needs to be fixed - shared pointers!
  this->x = that.x;
  this->y = that.y;

  /*
  this->x = new double;
  *(this->x) = that.getX(); 
  this->y = new double;
  *(this->y) = that.getY();
  */
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
  ss << "(" << this->getX() << "," << this->getY() << ") ";
  ss << " [" << x << " , " << y << "]";
  return ss.str();
}

