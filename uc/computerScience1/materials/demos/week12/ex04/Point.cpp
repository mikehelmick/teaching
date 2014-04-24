// ex04/Point.cpp
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Point {
public:

  void setX(int x) {
    this->x = x;
  }

  void setY(int y) {
    this->y = y;
  }

  int getX() const {
    // Here, use of "this" is optional.
    return this->x;
  }

  int getY() const {
    return this->y;
  }

  string toString() const {
    stringstream ss;
    // this works on function calls too!
    ss << "(" << this->getX() << "," << this->getY() << ")";
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

  cout << "Point: " << p.getX() << "," << p.getY() << endl;
  cout << "Point: " << p.toString() << endl;
}


