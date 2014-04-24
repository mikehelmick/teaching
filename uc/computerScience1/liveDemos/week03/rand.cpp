#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

  // Seed the rand against the time
  srand(time(NULL));
  // Seed consistently
  //srand(5);

  for (int i = 0; i < 10; i++) {
    cout << rand() << endl;
  }

  return 0;
}
