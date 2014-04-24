#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include <Point.h>

class BoundingBox {
public:
  BoundingBox(double minLat, double maxLat, double minLong, double maxLong,
  	  double width, double height);

  void translatePoint(Point &point);

private:
  double minLatitude;
  double maxLatitude;
  double minLongitude;
  double maxLongitude;

  double width;
  double height;

  double translateLatitude(double latitude);

  double translateLongitude(double longitude);
};

#endif