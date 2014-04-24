// ex03/Point1.cpp
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

  cout << "Point: " << p.getX() << "," << p.getY() << endl;
  cout << "Point: " << p.toString() << endl;
}


