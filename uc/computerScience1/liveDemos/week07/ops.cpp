#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inFile;
  inFile.open("numbers.txt");

  int size;
  inFile >> size;

  int scores[size];
  for (int i = 0; i < size; i++) {
    inFile >> scores[i];
  }
  inFile.close();

  double sum = 0;
  int min = scores[0];
  int max = scores[0];

  for (int i = 0; i < size; i++) {
    if (scores[i] < min) {
      min = scores[i];
    }
    if (scores[i] > max) {
      max = scores[i];
    }
    sum += scores[i];
  }

  double average = sum / size;
  cout << "Total scores: " << size << endl;
  cout << "Average: " << average << endl;
  cout << "Min: " << min << endl;
  cout << "Max: " << max << endl;

  return 0;
}
