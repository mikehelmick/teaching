#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

const double HEIGHT = 500 * 5;
const double WIDTH = 1130 * 5;

double translateLong(double min, double max, double longitude) {
  // min is zero and max is width
  // longitudes are all negative for our map, so we just add the min
  longitude += (-1 * min);
  return (WIDTH / abs(min - max) * longitude);
}

double translateLat(double min, double max, double lat) {
  lat -= min;
  return HEIGHT - (HEIGHT / (max - min) * lat);
}

int main() {
  // Open input and output files
  ifstream inFile;
  inFile.open("USA.txt");
  ofstream outFile;
  outFile.open("usa.html");

  double minLong, minLat, maxLong, maxLat;
  inFile >> minLong >> minLat >> maxLong >> maxLat;
  int totalRegions;
  inFile >> totalRegions;

  cout << "Min long: " << minLong << " lat: " << minLat << endl;
  cout << "Max long: " << maxLong << " lat: " << maxLat << endl;
  cout << "Regions: " << totalRegions << endl;

  outFile << "<html><body>" << endl;
  outFile << "<svg width=\"" << WIDTH << "\" height=\"" << HEIGHT << "\">" << endl;

  outFile << "<polygon points=\"";

  outFile << translateLong(minLong, maxLong, minLong) << ","
          << translateLat(minLat, maxLat, minLat) << " ";
  outFile << translateLong(minLong, maxLong, minLong) << ","
          << translateLat(minLat, maxLat, maxLat) << " ";
  outFile << translateLong(minLong, maxLong, maxLong) << ","
          << translateLat(minLat, maxLat, maxLat) << " ";
  outFile << translateLong(minLong, maxLong, maxLong) << ","
          << translateLat(minLat, maxLat, minLat) << " ";

  outFile << "\" style=\"fill:white;stroke:red;stroke-width:2\" />" << endl;

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
      outFile << translateLong(minLong, maxLong, longitude) << ","
          << translateLat(minLat, maxLat, latitude) << " ";
    }
    outFile << "\" style=\"fill:white; stroke:black;stroke-width:1\" />" << endl;
  }

  outFile << "</svg></body></html>" << endl;

  inFile.close();
}
