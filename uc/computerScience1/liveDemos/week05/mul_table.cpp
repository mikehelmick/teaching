#include <iostream>
#include <iomanip>
using namespace std;

int main() {
 
  for (int x = 0; x < 15; x++) {
    for (int y = 0; y < 15; y++) {
      int answer = x * y;
      cout << setw(4) << answer << " "; 
    }
    cout << endl;
  }

}
