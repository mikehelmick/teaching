/*
 * main.cpp
 *
 *  Created on: Oct 7, 2013
 *      Author: helmicmt
 */

#include <Shape.h>
#include <Square.h>

#include <iostream>
using namespace std;

int main() {
  Shape* myShape = new Square(5);
  
  cout << "area: " << myShape->area() << endl;
  cout << "area: " << (*myShape).area() << endl;
  cout << "primater: " << myShape->primater() << endl;

  delete myShape;

  return 0;
}
