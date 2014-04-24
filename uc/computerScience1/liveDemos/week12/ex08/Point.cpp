
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
 
#include <Point.h>

Point::Point(double x, double y) {
  this->x = x;
  this->y = y;
}

double Point::getX() const {
  return x;
}

double Point::getY() const {
  return y;
}

double Point::distance(const Point& that) {
  return sqrt(pow(x - that.x, 2.0) + pow(y - that.y, 2.0));
}

string Point::toString() const {
  stringstream ss;
  ss << "(" << getX() << "," << getY() << ")";
  return ss.str();
}

