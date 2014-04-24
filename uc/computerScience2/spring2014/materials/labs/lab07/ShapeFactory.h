#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

#include <Shape.h>
#include <Cube.h>
#include <Cylinder.h>
#include <Sphere.h>

class ShapeFactory {
public:
  static Shape* getShape(ifstream &inFile) {
    const string CUBE = "cube";
    const string CYLINDER = "cylinder";
    const string SPHERE = "sphere";

    const string SHAPE_NAME = "shape";

    string shapeName;
    inFile >> shapeName;

    if (shapeName == CUBE) {
      double side;
      inFile >> side;
      return new Cube(side);

    } else if (shapeName == CYLINDER) {
      double radius, height;
      inFile >> radius >> height;
      return new Cylinder(radius, height);

    } else if (shapeName == SPHERE) {
      double radius;
      inFile >> radius;
      return new Sphere(radius);

    }

    return NULL;
  }
};

#endif

