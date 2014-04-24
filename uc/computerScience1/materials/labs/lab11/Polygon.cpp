#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <iostream>
using namespace std;

#include <Point.h>
#include <BoundingBox.h>
#include <Polygon.h>

Polygon::Polygon(string name, string boundingName) {
  this->regionName = name;
  this->boundingName = boundingName;
}

string Polygon::getRegionName() {
  return regionName;
}

string Polygon::getBoundingName() {
  return boundingName;
}

void Polygon::addPoint(Point p) {
  points.push_back(p);
}

string Polygon::getSvg(BoundingBox &bb, vector<County> &counties) {
  stringstream ss;

  ss << "<polygon points=\"";
  for (int i = 0; i < points.size(); i++) {
    Point p = points[i];
    bb.translatePoint(p);
    ss << p.getX() << "," << p.getY() << " ";
  }
 
  // determine color
  int countyIndex = -1;
  for (int i = 0; i < counties.size() && countyIndex < 0; i++) {
  	if (counties[i].getState() == boundingName) {
  	  string parishName = counties[i].getCounty() + " Parish";
  	  if (counties[i].getCounty() == regionName || parishName == regionName) {
        countyIndex = i;
  	  }
  	}
  }

  long r = 255;
  long g = 255;
  long b = 255;
  if (countyIndex >= 0) {
  	County c = counties[countyIndex];
  	double total = c.getRVote() + c.getDVote() + c.getOVote();
  	r = round(c.getRVote() / total * 255.0);
  	g = round(c.getOVote() / total * 255.0);
  	b = round(c.getDVote() / total * 255.0);
  }

  ss << "\" style=\"fill:rgb(" << r << "," << g << "," << b << "); stroke:black;stroke-width:1\" />";

  return ss.str();
}