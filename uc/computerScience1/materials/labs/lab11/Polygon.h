#ifndef POLYGON_H
#define POLYGON_H

#include <string>
#include <vector>
using namespace std;

#include <Point.h>
#include <BoundingBox.h>
#include <County.h>

class Polygon {
public:
  Polygon(string name, string boundingName);

  string getRegionName();

  string getBoundingName();

  void addPoint(Point p);

  string getSvg(BoundingBox &bb, vector<County> &counties);

private:
  string regionName;
  string boundingName;
  vector<Point> points;
};

#endif