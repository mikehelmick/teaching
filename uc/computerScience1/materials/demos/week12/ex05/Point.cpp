// ex05/Point.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;


class Point {
public:

  void setX(double x) {
    this->x = x;
  }

  void setY(double y) {
    this->y = y;
  }

  double getX() const {
    // Here, use of "this" is optional.
    return this->x;
  }

  double getY() const {
    return this->y;
  }

  double distance(const Point& that) {
    return sqrt(pow(x - that.x, 2.0) + (pow(y - that.y, 2.0)));
  }

  string toString() const {
    stringstream ss;
    // this works on function calls too!
    ss << "(" << this->getX() << "," << this->getY() << ")";
    return ss.str();
  }

private:
  double x;
  double y;
};

int main() {

  Point p1;
  p1.setX(4);
  p1.setY(6);

  Point p2;
  p2.setX(3.5);
  p2.setY(4.5);

  cout << "Point1: " << p1.toString() << endl;
  cout << "Point2: " << p2.toString() << endl;
  cout << "Distance: " << p1.distance(p2) << endl;
}


