#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void readFile(vector<int> &vec, string &fName) {
  ifstream inFile;
  inFile.open(fName.c_str());

  int score;
  inFile >> score;
  while (score != -1) {
    vec.push_back(score);
    inFile >> score;
  }

  inFile.close();
}

void removeValues(vector<int> &vec) {
  while (!vec.empty()) {
    int val = vec[vec.size() - 1];
    vec.pop_back();
    cout << val << " ";
  }
  cout << endl;
}

int main() {

  string filename("scores.txt");
  vector<int> vec;
  readFile(vec, filename);

  cout << "Read in: " << vec.size()  << " values." << endl;

  long long sum = 0;
  for (int i = 0; i < vec.size(); i++) {
    sum += vec[i]; 
  }
  double average = sum / (double) vec.size();
  cout << "Sum: " << sum << endl;
  cout << "Average: " << average << endl;

  cout << endl << "Removing valueS" << endl;
  removeValues(vec);
  cout << "size is: " << vec.size() << endl;

  cout << endl << "Reading vals again " << endl;
  readFile(vec, filename);

  cout << "size: " << vec.size() << endl;
  cout << "clearing " << endl;
  vec.clear();
  cout << "size: " << vec.size() << endl;
  

  return 0;
}
