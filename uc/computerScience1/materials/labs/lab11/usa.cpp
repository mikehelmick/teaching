#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <set>
#include <vector>
using namespace std;

#include <BoundingBox.h>
#include <Point.h>
#include <Polygon.h>
#include <County.h>

const double HEIGHT = 500 * 10;
const double WIDTH = 1130 * 10;

int main() {
  // Open input and output files
  ifstream inFile;
  inFile.open("USA-county.txt");
  ofstream outFile;
  outFile.open("usa-county.html");

  string line;
  getline(inFile, line);
  Point bbMin(line);
  getline(inFile, line);
  Point bbMax(line);

  BoundingBox bb(bbMin, bbMax, WIDTH, HEIGHT);

  getline(inFile, line);
  int totalRegions = atoi(line.c_str());

  outFile << "<html><body>" << endl;
  outFile << "<svg width=\"" << WIDTH << "\" height=\"" << HEIGHT << "\">" << endl;

  vector<Polygon> polygons;
  for (int regionNum = 0; regionNum < totalRegions; regionNum++) {
    getline(inFile, line); // blank line
    string regionName;
    getline(inFile, regionName);
    string boundingName;
    getline(inFile, boundingName);

    getline(inFile, line);
    int numPoints = atoi(line.c_str());
    cout << "Region: " << regionName << " points: " << numPoints << endl;

    Polygon pgon(regionName, boundingName);
    for (int i = 0; i < numPoints; i++) {
      getline(inFile, line);
      Point p(line);
      pgon.addPoint(p);
    }

    polygons.push_back(pgon);
  }
  inFile.close();

  set<string> states;
  for (int i = 0; i < polygons.size(); i++) {
    states.insert(polygons[i].getBoundingName());
  }

  vector<County> counties;
  for (set<string>::iterator it = states.begin(); it != states.end(); it++) {
    string fileName = (*it) + "2012.txt";
    ifstream countyFile;
    countyFile.open(fileName.c_str());

    string countyLine;
    getline(countyFile, countyLine);

    while (!countyFile.eof()) {
      getline(countyFile, countyLine);
      if (countyLine == "") {
        continue;
      }
      string state = (*it);
      County county(countyLine, state);
      counties.push_back(county);
    }

    countyFile.close();
  }

  for (int i = 0; i < polygons.size(); i++) {
    outFile << "<!-- " << polygons[i].getRegionName() << " -->" << endl;
    outFile << polygons[i].getSvg(bb, counties) << endl;
  }

  outFile << "</svg></body></html>" << endl;
  outFile.close();
}