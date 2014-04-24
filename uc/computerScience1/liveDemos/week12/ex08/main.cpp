#include <iostream>
using namespace std;

#include <Point.h>
 
int main() {
  Point p1(1.25, 3.45);
  Point p2(2.24, 4.56);

  cout << "p1: " << p1.toString() << endl;
  cout << "p2: " << p2.toString() << endl;
  cout << "dist: " << p1.distance(p2) << endl;
}
