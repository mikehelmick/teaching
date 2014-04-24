#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<int> vec;
  for (int i = 0; i < 20; i++) {
    vec.push_back(i);
  }

  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << endl;
  }
}
