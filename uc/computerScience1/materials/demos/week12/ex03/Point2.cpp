// ex03/Point2.cpp
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Point {
public:

  void setX(int newX) {
    x = newX;
  }

  void setY(int newY) {
    y = newY;
  }

  int getX() const {
    return x;
  }

  int getY() const {
    return y;
  }

  void printAddrs() const {
    cout << "&x: " << &x << "  &x: " << &y << endl;
  }

  string toString() const {
    stringstream ss;
    ss << "(" << getX() << "," << getY() << ")";
    return ss.str();
  }

private:
  int x;
  int y;
};

int main() {

  Point p;
  p.setX(4);
  p.setY(6);

  cout << "size of a Point: " << sizeof(Point) << endl;
  cout << "&p " << &p << endl;
  p.printAddrs();

  Point* pPtr = &p;
  int* ptr = (int*) pPtr;
  cout << "x = " << *ptr << endl;
  cout << "y = " << *(ptr + 1) << endl;

  *ptr = 32;
  *(ptr + 1) = 33;
  cout << "point: " << p.toString() << endl;
}


