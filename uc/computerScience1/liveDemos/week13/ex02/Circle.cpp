#include <cmath>
#include <iostream>
using namespace std;

#include <Circle.h>

Circle::Circle(double radius) {
  this->radius = radius;
  cout << "Circle::Circle(double)" << endl;
  // increment the static counter
  circleCount++;
}

Circle::Circle(Circle &other) {
  this->radius = other.radius;
  cout << "Circle::Circle(Circle&)" << endl;
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

// Static method
int Circle::getCircleCreationCount() {
  return circleCount;
}

int Circle::circleCount = 0;


