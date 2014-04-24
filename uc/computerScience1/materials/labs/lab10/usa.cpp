#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

#include <BoundingBox.h>

const double HEIGHT = 500;
const double WIDTH = 1130;

int main() {
  // Open input and output files
  ifstream inFile;
  inFile.open("USA.txt");
  ofstream outFile;
  outFile.open("usa.html");

  double minLong, minLat, maxLong, maxLat;
  inFile >> minLong >> minLat >> maxLong >> maxLat;

  BoundingBox bb(minLat, maxLat, minLong, maxLong, WIDTH, HEIGHT);

  int totalRegions;
  inFile >> totalRegions;

  cout << "Min long: " << minLong << " lat: " << minLat << endl;
  cout << "Max long: " << maxLong << " lat: " << maxLat << endl;
  cout << "Regions: " << totalRegions << endl;

  outFile << "<html><body>" << endl;
  outFile << "<svg width=\"" << WIDTH << "\" height=\"" << HEIGHT << "\">" << endl;

  for (int regionNum = 0; regionNum < totalRegions; regionNum++) {
    // Process a region
    string token = "";
    string regionName = "";
    while (token != "USA") {
      inFile >> token;
  	  if (token != "USA") {
  	    if (regionName == "") {
  	  	  regionName = token;
  	    } else {
  	  	  regionName += " ";
  	  	  regionName += token;
  	    }
  	  }
    }
    int numPoints;
    inFile >> numPoints;
    cout << "Region: " << regionName << " points: " << numPoints << endl;

    outFile << "<!-- " << regionName << " -->" << endl;
    outFile << "<polygon points=\"";
    double latitude, longitude;
    for (int i = 0; i < numPoints; i++) {
      inFile >> longitude >> latitude;
      Point p(longitude, latitude);
      bb.translatePoint(p);
      outFile << p.getX() << "," << p.getY() << " ";
    }
    outFile << "\" style=\"fill:white; stroke:black;stroke-width:1\" />" << endl;
  }

  outFile << "</svg></body></html>" << endl;

  inFile.close();
}