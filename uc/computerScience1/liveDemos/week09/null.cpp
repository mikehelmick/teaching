// null.cpp
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int* x = NULL;

  *x = 15;

  cout << *x << endl;
}
