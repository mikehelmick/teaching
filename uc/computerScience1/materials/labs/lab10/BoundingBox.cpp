#include <BoundingBox.h>
#include <cmath>
using namespace std;

BoundingBox::BoundingBox(double minLat, double maxLat,
    double minLong, double maxLong, double width, double height) {
  minLatitude = minLat;
  maxLatitude = maxLat;
  minLongitude = minLong;
  maxLongitude = maxLong;

  this->width = width;
  this->height = height;
}

void BoundingBox::translatePoint(Point &point) {
  point.setX(translateLongitude(point.getX()));
  point.setY(translateLatitude(point.getY()));
}

double BoundingBox::translateLatitude(double latitude) {
  latitude -= minLatitude;
  return height - (height / (maxLatitude - minLatitude) * latitude);
}

double BoundingBox::translateLongitude(double longitude) {
  longitude += (-1 * minLongitude);
  return (width / abs(minLongitude - maxLongitude) * longitude);
}
