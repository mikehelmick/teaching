// ex08/main.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>yes
using namespace std;

#include <Point.h>

int main() {

  Point* p1 = new Point(1, 2);
  Point* p2 = new Point(*p1);

  cout << "cleaning up points" << endl;

  cout << "deleting p1: " << p1->toString() << endl;
  delete p1;
  cout << "deleting p2: " << p2->toString() << endl;
  delete p2;
}
