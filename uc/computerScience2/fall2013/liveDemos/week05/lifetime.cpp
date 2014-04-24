#include <iostream>
using namespace std;

// Gets a pointer to
int* get5() {
  int x = 5;
  cout << "in get5, x = " << x << endl;
  return &x;
}

void myCoolFunction() {
  int largeArray[200];
  for (int i = 0; i < 200; i++) {
    largeArray[i] = i * 2;
  }
  return;
}

int main() {
  int* pX = get5();
  myCoolFunction();
  cout << "in main, pX=" << *pX << endl;
}
