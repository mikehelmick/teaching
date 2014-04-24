#include <Point.h>

Point::Point(double x, double y) {
  this->x = x;
  this->y = y;
}

void Point::setX(double x) {
  this->x = x;
}

void Point::setY(double y) {
  this->y = y;
}

double Point::getX() {
  return x;
}

double Point::getY() {
  return y;
}
