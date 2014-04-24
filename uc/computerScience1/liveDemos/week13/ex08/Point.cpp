#include <string>
#include <sstream>
#include <cmath>
#include <iostream>
using namespace std;

#include <Point.h>

Point::Point(double x, double y) {
  cout << "Point::Point(double, double)" << endl;
  this->x = new double;
  *(this->x) = x;
  this->y = new double;
  *(this->y) = y;
}

Point::Point(const Point &that) {
  cout << "Point::Point(Point&)" << endl;
  this->x = new double;
  *x = that.getX();
  this->y = new double;
  *y = that.getY();
}


Point::~Point() {
  cout << "Point::~Point()" << endl;
  // Delete any pointers that I own.
  delete x;
  delete y;
}

double Point::getX() const {
  return *x;
}

double Point::getY() const {
  return *y;
}

double Point::distance(const Point& that) const {
  return sqrt(pow(*x - *(that.x), 2.0) + pow(*y - *(that.y), 2.0));
}

string Point::toString() const {
  stringstream ss;
  ss << "(" << *x << " (" << x << ") ," << *y << " (" << y << "))";
  return ss.str();
}
