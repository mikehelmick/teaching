#include <cstdlib>
#include <iostream>
using namespace std;

#include <Circle.h>

int main() {
  
  Circle c1(rand() % 50 + 10);
  cout << "Circle area: " << c1.getArea() << endl;

  // What gets called when this happens?
  Circle c2 = c1;
  cout << "Circle area: " << c2.getArea() << endl;

  cout << "&c1: " << &c1 << endl;
  cout << "&c2: " << &c2 << endl;

  // reverse assignment
  c1 = c2;

  cout << "Circles created: " << Circle::getCircleCreationCount() << endl;
}