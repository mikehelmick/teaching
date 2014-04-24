// ex08/Point.cpp

#include <string>
#include <sstream>
#include <cmath>
using namespace std;

// We have to include the definition of the point class
#include "Point.h"

Point::Point(double x, double y) {
  this->x = x;
  this->y = y;
}

double Point::getX() const {
  return this->x;
}

double Point::getY() const {
  return this->y;
}

double Point::distance(const Point& that) {
  return sqrt(pow(x - that.x, 2.0) + (pow(y - that.y, 2.0)));
}

string Point::toString() const {
  stringstream ss;
  // this works on function calls too!
  ss << "(" << this->getX() << "," << this->getY() << ")";
  return ss.str();
}

