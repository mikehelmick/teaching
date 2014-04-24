#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<bool> isCrowded(vector<int> &populations) {
  if (populations.size() == 1) {
    vector<bool> rtn;
    rtn.push_back(populations[0] >= 10);
    return rtn;
  }
  
  vector<bool> crowded;
  int max = populations.size() - 1;
  for (int i = 0; i <= max; i++) {
    if (i == 0) {
      crowded.push_back(populations[i] + populations[i + 1] >= 10);
    } else if (i == max) {
      crowded.push_back(populations[i] + populations[i - 1] >= 10);
    } else {
      crowded.push_back(
          populations[i - 1] + populations[i] + populations[i + 1] >= 15);
    }
  }
  return crowded;
}

int main() {
  vector<int> populations;
  populations.push_back(6);
  populations.push_back(4);
  populations.push_back(2);
  populations.push_back(11);
  populations.push_back(1);
  populations.push_back(5);
  populations.push_back(8);
  populations.push_back(8);
  populations.push_back(1);
  
  vector<bool> crwd = isCrowded(populations);
  for (int i = 0; i < crwd.size(); i++) {
    cout << setw(3) << populations[i] << " "
        << crwd[i] << endl;
  }
  
}