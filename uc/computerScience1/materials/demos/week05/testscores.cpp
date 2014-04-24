// week05/testscores.cpp

#include <iostream>
#include <iomanip>

const int ENDING_SCORE = -1;

using namespace std;

int main() {
  
  long long score = 0;
  long long total = 0;
  int count = 0;
  
  cin >> score;
  while (score != ENDING_SCORE) {
    count++;
    total += score;
    cin >> score;
  }
  
  cout << "Read : " << count << " scores." << endl;
  double average = total / (double)count;
  cout << "Average score: " << setprecision(2) << fixed << average << endl;
  
  return 0;
}