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
   cout << "&x: " << &x << " &y: " << &y << endl; 
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

  cout << "Point: " << p.getX() << ", " << p.getY() << endl;
  cout << "Point: " << p.toString() << endl;

  cout << "sizeof(Point): " << sizeof(Point) << endl;
  cout << "&p: " << &p << endl;
  p.printAddrs();

  int* ptr = (int*) &p;
  *ptr = 42;
  ptr++;
  *ptr = 43;
  cout << "Point: " << p.toString() << endl;
}


