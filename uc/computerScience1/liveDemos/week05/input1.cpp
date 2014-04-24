#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

const int ENDING_SCORE = -1;

int main() {

  long long score = 0;
  long long total = 0;
  int count = 0;

  ifstream inFile;
  inFile.open("scores.txt");

  inFile >> score;
  while (score != ENDING_SCORE) {
    count++;
    total += score;
    inFile >> score;
  }

  inFile.close();

  cout << "Read : " << count << " scores." << endl;
  double average = total / (double)count;
  cout << "Average score: " << setprecision(2) << fixed << average
      << endl;

  return 0;
}
