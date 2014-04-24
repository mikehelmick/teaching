#include <Gradebook.h>

#include <fstream>
#include <iostream>

using namespace std;

void writeToFile(const string &filename, Gradebook &gradebook) {
  ofstream outFile;
  outFile.open(filename.c_str(), ios::out);
  
  outFile << " Input File: " << gradebook.getSourceFile() << endl;
  outFile << "Score count: " << gradebook.getCount() << endl;
  outFile << "       Mean: " << gradebook.getMean() << endl;
  outFile << "       Mode: " << gradebook.getMedian() << endl;
  outFile << "     stdDev: " << gradebook.getStdDev() << endl;
  outFile << "        Max: " << gradebook.getMax() << endl;
  outFile << "        Min: " << gradebook.getMin() << endl;
  outFile << "          A: " << gradebook.scoresInRange(90, 100.00001) << endl;
  outFile << "          B: " << gradebook.scoresInRange(80, 90) << endl;
  outFile << "          C: " << gradebook.scoresInRange(70, 80) << endl;
  outFile << "          D: " << gradebook.scoresInRange(60, 70) << endl;
  outFile << "          F: " << gradebook.scoresInRange(0, 70) << endl;

  outFile.close();
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cout << " You mut pass an input and output filename on the command line." << endl;
    return 1;
  }

  string inputFilename(argv[1]);
  Gradebook gb(inputFilename);
  writeToFile(string(argv[2]), gb);
}