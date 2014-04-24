#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ofstream oFile;
  oFile.open("svg.html");

  oFile << "<html><body>" << endl;
  oFile << "<svg height=\"1000\" width=\"1000\">" << endl;

  for (int xy = 0; xy <= 1000; xy += 100) {
  	oFile << "<line x1=\"" << xy << "\" y1=\"" << 0 << "\" x2=\""
  	    << xy << "\" y2=\"" << 1000 
  	    << "\" style=\"stroke:rgb(255,0,0);stroke-width:2\" />" << endl;
  	oFile << "<line x1=\"" << 0 << "\" y1=\"" << xy << "\" x2=\""
  	    << 1000 << "\" y2=\"" << xy 
  	    << "\" style=\"stroke:rgb(255,0,0);stroke-width:2\" />" << endl;
  }

  for (int x = 0; x <= 1000; x += 100) {
  	for (int y = 0; y <= 1000; y += 100) {
      oFile << "<text x=\"" << x << "\" y=\"" << y
          << "\" fill=\"black\">" << x << "," << y << "</text>" << endl;
  	}
  }  

  oFile << "</svg>" << endl;
  oFile << "</body></html>" << endl;

  oFile.close();  
}
