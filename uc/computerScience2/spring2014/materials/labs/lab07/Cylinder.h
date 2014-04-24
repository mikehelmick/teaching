#ifndef CYLINDER_H
#define CYLINDER_H

#include <cmath>
#include <Shape.h>

/**
 * Abstract class that defines the basis for a 3 dimensional
 * shape.
 */
class Cylinder : public Shape {
public:
  Cylinder(double radius, double height) : Shape("Cylinder") {
    this->radius = radius;
    this->height = height;
  }

  virtual ~Cylinder() {
  }

  /**
   * Returns the surface area of the 3D object.
   */
  double getSurfaceArea() const {
    return (M_PI * radius * radius * 2) + (2 * M_PI * radius * height);
  }

  /**
   * Returns the volume of a 3D object.
   */
  double getVolume() const {
    return M_PI * radius * radius * height;
  }

private:
  double radius;
  double height;
};

#endif

