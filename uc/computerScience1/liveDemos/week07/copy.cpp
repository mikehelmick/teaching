#include <iostream>
#include <cstring>
using namespace std;

int main() {

  int first[5] = {1, 2, 3, 4, 5};
  // Does not work
  //int second[5] = first;

  int second[5];
  for (int i = 0; i < 5; i++) {
    second[i] = first[i];
  }

  for (int j = 0; j < 5; j++) {
    cout << first[j] << " " << second[j] << endl;
  }
}
