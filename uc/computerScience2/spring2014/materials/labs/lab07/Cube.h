#ifndef CUBE_H
#define CUBE_H

#include <Shape.h>

/**
 */
class Cube : public Shape {
public:
  Cube(double size) : Shape("Cube") {
    this->size = size;
  }

  virtual ~Cube() {
  }

  /**
   * Returns the surface area of the 3D object.
   */
  double getSurfaceArea() const  {
    return (size * size) * 6;
  }

  /**
   * Returns the volume of a 3D object.
   */
  double getVolume() const {
    return size * size * size;
  }

private:
  double size;
};

#endif

