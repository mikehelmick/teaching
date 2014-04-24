#include <cstdlib>
#include <iostream>
using namespace std;

#include <Circle.h>

int main() {
  
  Circle c1(rand() % 50 + 10);
  cout << "Circle area: " << c1.getArea() << endl;

  Circle c2(c1);
  cout << "Circle area: " << c2.getArea() << endl;

  cout << "&c1: " << &c1 << endl;
  cout << "&c2: " << &c2 << endl;

  cout << "Circles created: " << Circle::getCircleCreationCount() << endl;
}