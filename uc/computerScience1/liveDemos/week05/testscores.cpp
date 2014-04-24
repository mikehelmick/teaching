#include <iostream>
#include <iomanip>

using namespace std;

const int ENDING_SCORE = -1;

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

  cout << "read : " << count << " scores." << endl;
  double average = total / (double)count;
  cout << "Average score: " << setprecision(2) << fixed << average << endl;

  return 0;
}
