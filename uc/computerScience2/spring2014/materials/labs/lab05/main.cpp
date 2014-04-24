#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

#include <Scores.h>

string getStars(const Scores &s, int min, int max) {
  int num = s.countScoresInRange(min, max);
  
  int numStars = round(num / (float) s.getSize() * 100 / 5);
  stringstream ss;
  for (int i = 0; i < numStars; i++) {
    ss << "*";
  }
  return ss.str();
}

int main(int argc, char* argv[]) {
  // Check the arguments;
  if (argc != 3) {
    cout << "Usage ./a.out inputFile outputFile" << endl;
    return 1;
  }
  
  // open the input file.
  ifstream inFile;
  inFile.open(argv[1]);
  // open the output file.
  ofstream outFile;
  // better to crash early if this can't be opened.
  outFile.open(argv[2]);
  
  // read in scores
  Scores s;
  // This will loop until the "end of file" (eof) is reached.
  while (!inFile.eof()) {
    int score;
    inFile >> score;
    s.addScore(score);
  }
  
  // make sure you close the input file when you are done with it.
  inFile.close();
  
  // print out stats, write to the output file.
  // use outFile << just like you would use cout <<
  outFile << " Scores: " << setw(5) << s.getSize() << endl;
  outFile << "Minimum: " << setw(5) << s.getMinimum() << endl;
  outFile << "Maximum: " << setw(5) << s.getMaximum() << endl;
  outFile << "Average: " << setprecision(2) << fixed << setw(8) << s.getAverage() << endl;
  outFile << "Histogram" << endl;
  outFile << " A: " << getStars(s, 90, s.getMaximum() + 1) << endl;
  outFile << " B: " << getStars(s, 80, 90) << endl;
  outFile << " C: " << getStars(s, 70, 80) << endl;
  outFile << " D: " << getStars(s, 60, 70) << endl;
  outFile << " F: " << getStars(s,  0, 60) << endl;

  // Make sure you close the output file when done.
  outFile.close();
}
