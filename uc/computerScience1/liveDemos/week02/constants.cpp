#include <iostream>
using namespace std;

const int STARS_PER_ROUND = 3;

int main() {
  
  for (int rnd = 0; rnd <= 10; rnd++) {
    int limit = STARS_PER_ROUND * rnd;
    for (int i = 0; i < limit; i++) {
      cout << '*';
    }
    cout << endl;
  }
  
  // Compile error
  //STARS_PER_ROUND = 7;
  
  return 0;
}
