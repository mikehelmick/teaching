#include <cmath>
#include <iostream>
using namespace std;

#include <Circle.h>

Circle::Circle(double radius) {
  this->radius = radius;
  cout << "Circle::Circle(double)" << endl;
  // increment static counter
  circleCount++;
}

Circle::Circle(const Circle &that) {
  cout << "Circle::Circle(Circle&)" << endl;
  this->radius = that.radius;
  circleCount++;
}

Circle& Circle::operator=(const Circle &rhs) {
  cout << "Circle::= (assignment)" << endl;
  this->radius = rhs.radius;
  return *this;
}

Circle::~Circle() {
  cout << "Circle::~Circle()" << endl;
}

double Circle::getArea() const {
  return M_PI * radius * radius;
}

double Circle::getRadius() const {
  return radius;
}

int Circle::getCircleCreationCount() {
  return circleCount;
}

// static variables MUST be initialized
int Circle::circleCount = 0;
