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

Circle::Circle(Circle &that) {
  cout << "Circle::Circle(Circle&)" << endl;
  this->radius = that.radius;
  circleCount++;
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
