/*
 * main.cpp
 *
 *  Created on: Oct 7, 2013
 *      Author: helmicmt
 */

#include <Shape.h>
#include <Square.h>
#include <Circle.h>
#include <Rectangle.h>
#include <Oval.h>

#include <iostream>
#include <vector>
using namespace std;

void printAreas(const vector<Shape*> &shapes) {
  for (unsigned int i = 0; i < shapes.size(); i++) {
    cout << "area: " << shapes[i]->area() << endl;
  }
}

void anyElementsEqual(const vector<Shape*> &shapes) {
  for (unsigned int i = 0; i < shapes.size() - 1; i++) {
    for (unsigned int j = i + 1; j < shapes.size(); j++) {
      if (shapes[i]->isEqual(shapes[j])) {
        cout << "Shapes #" << i << " and " << j << " are equal" << endl;
      }
    }
  }
}

void sortByArea(vector<Shape*> &shapes) {
  for (unsigned int fill = 0; fill < shapes.size() - 1; fill++) {
    unsigned int posMin = fill;
    for (unsigned int next = fill + 1; next < shapes.size(); next++) {
      if (shapes[next]->area() < shapes[posMin]->area()) {
        posMin = next;
      }
    }
    // I know that posMin is the position of the next smallest area
    if (fill != posMin) {
      Shape* tmp = shapes[fill];
      shapes[fill] = shapes[posMin];
      shapes[posMin] = tmp;
    }
  }
}

int main() {
  vector<Shape*> shapes;
  
  shapes.push_back(new Circle(5));
  shapes.push_back(new Oval(4, 5));
  shapes.push_back(new Rectangle(4, 3.456));
  shapes.push_back(new Square(45));
  shapes.push_back(new Oval(4, 5));
  shapes.push_back(new Circle(5));
  shapes.push_back(new Oval(4, 5));
  shapes.push_back(new Rectangle(4, 3.456));
  shapes.push_back(new Square(45));
  printAreas(shapes);

  cout << "equality check" << endl;
  anyElementsEqual(shapes);

  cout << endl << " -- sorted -- " << endl;
  sortByArea(shapes);
  printAreas(shapes);
  cout << endl << " -- sorted -- " << endl;

  for (unsigned int i = 0; i < shapes.size(); i++) {
    delete shapes[i];
  }

  return 0;
}
