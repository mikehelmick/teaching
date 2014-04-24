#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {

  for (int h = 0; h <= 23; h++) {
    for (int m = 0; m <= 59; m++) {
      for (int s = 0; s <= 59; s++) {
        printf("%02d:%02d:%02d\n", h, m, s); 
      }
    }
  }
  return 0;
}
