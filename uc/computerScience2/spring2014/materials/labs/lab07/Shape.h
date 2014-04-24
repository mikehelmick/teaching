#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;

/**
 * Abstract class that defines the basis for a 3 dimensional
 * shape.
 */
class Shape {
public:
  Shape(string name) {
    this->name = name;
  }

  virtual ~Shape() {
  }

  /**
   * Returns the name of the shape represented.
   */
  string getName() const {
    return name;
  }

  /**
   * Returns the surface area of the 3D object.
   */
  virtual double getSurfaceArea() const = 0;

  /**
   * Returns the volume of a 3D object.
   */
  virtual double getVolume() const = 0;

private:
  string name;
};

#endif

