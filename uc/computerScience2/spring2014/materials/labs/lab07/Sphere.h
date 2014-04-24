#ifndef SPHERE_H
#define SPHERE_H

#include <cmath>
#include <Shape.h>

/**
 * Abstract class that defines the basis for a 3 dimensional
 * shape.
 */
class Sphere : public Shape {
public:
  Sphere(double radius) : Shape("Sphere") {
    this->radius = radius;
  }

  virtual ~Sphere() {
  }

  /**
   * Returns the surface area of the 3D object.
   */
  double getSurfaceArea() const {
    return 4 * M_PI * radius * radius;
  }

  /**
   * Returns the volume of a 3D object.
   */
  double getVolume() const {
    return 4.0 / 3.0 * M_PI * pow(radius, 3);
  }

private:
  double radius;
};

#endif

