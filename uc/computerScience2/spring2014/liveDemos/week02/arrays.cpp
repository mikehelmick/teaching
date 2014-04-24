#include <iostream>
using namespace std;

int main() {

  int size = 10;
  int myArr[10];
  for (int i = 0; i < size; i++) {
    cout << myArr[i] << endl;
  }
  for (int j = size; j < size * 300; j++) {
    cout << myArr[j] << endl;
  }

  return 0;
}
