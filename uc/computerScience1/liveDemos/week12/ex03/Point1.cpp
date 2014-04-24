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

 int getX() {
   return x;
 }

 int getY() {
   return y;
 }

 string toString() {
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

  cout << "Point: " << p.getX() << ", " << p.getY() << endl;
  cout << "Point: " << p.toString() << endl;
}


