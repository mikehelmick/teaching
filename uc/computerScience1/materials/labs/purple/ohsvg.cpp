#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

int main() {
  const int states = 51;
  string files[states] = 
     {
       "purple/AK.txt",
       "purple/AL.txt",
       "purple/AR.txt",
       "purple/AZ.txt",
       "purple/CA.txt",
       "purple/CO.txt",
       "purple/CT.txt",
       "purple/DC.txt",
       "purple/DE.txt",
       "purple/FL.txt",
       "purple/GA.txt",
       "purple/HI.txt",
       "purple/IA.txt",
       "purple/ID.txt",
       "purple/IL.txt",
       "purple/IN.txt",
       "purple/KS.txt",
       "purple/KY.txt",
       "purple/LA.txt",
       "purple/MA.txt",
       "purple/MD.txt",
       "purple/ME.txt",
       "purple/MI.txt",
       "purple/MN.txt",
       "purple/MO.txt",
       "purple/MS.txt",
       "purple/MT.txt",
       "purple/NC.txt",
       "purple/ND.txt",
       "purple/NE.txt",
       "purple/NH.txt",
       "purple/NJ.txt",
       "purple/NM.txt",
       "purple/NV.txt",
       "purple/NY.txt",
       "purple/OH.txt",
       "purple/OK.txt",
       "purple/OR.txt",
       "purple/PA.txt",
       "purple/RI.txt",
       "purple/SC.txt",
       "purple/SD.txt",
       "purple/TN.txt",
       "purple/TX.txt",
       "purple/UT.txt",
       "purple/VA.txt",
       "purple/VT.txt",
       "purple/WA.txt",
       "purple/WI.txt",
       "purple/WV.txt",
       "purple/WY.txt"
     };
  
  ofstream outFile;
  outFile.open("usa.html");
  
  outFile << "<html><body>" << endl;
  long zoom = 10;
  long height = 360 * zoom;
  outFile << "<svg height=\"" << height << "\" width=\"" << height << "\">" << endl;
  
  for (int state = 0; state < states; state++) {
    ifstream inFile;
    inFile.open(files[state]);
  
    string line;
    // burn 2 lines
    getline(inFile, line);
    getline(inFile, line);
    getline(inFile, line);
    int counties = atoi(line.c_str());
    cout << "Reading " << counties << " counties" << endl;
  

    for (int county = 0; county < counties; county++) {
      getline(inFile, line); // burn
      getline(inFile, line); // county name
      cout << "Reading county: " << line << endl;
      getline(inFile, line); // state name
      getline(inFile, line); // # of points
      int points = atoi(line.c_str());
      cout << " # of points: " << points << endl;
    
    
      stringstream pointOutput;
      for (int pointLine = 0; pointLine < points; pointLine++) {
        getline(inFile, line);
        stringstream ss(line);
        double longitude, latitude;
        ss >> longitude >> latitude;
        longitude += 180.0;
        latitude += 90;
        cout << height - longitude << " " << latitude << endl;
    
        pointOutput << longitude * zoom << "," << height - latitude * zoom;
        if (pointLine < points - 1) {
          pointOutput << " ";
        }
      }
    
      outFile << "<polygon points=\""
          << pointOutput.str()
          << "\" style=\"fill:blue; stroke:black;stroke-width:1\" />" << endl;
    } 
  
    inFile.close();
  }
  
  outFile << "</svg>" << endl;
  outFile << "</body></html>" << endl;
  
  
  outFile.close(); 
}