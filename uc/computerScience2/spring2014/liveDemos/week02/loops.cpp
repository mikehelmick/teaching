#include <iostream>
using namespace std;

int main() {

  bool runAgain = true;
  while (runAgain) {
    cout << "Do stuff." << endl;
    cout << "Do you want to play again? (y/n): ";
    char resp = 'n';
    cin >> resp;
    runAgain = resp == 'y';
    /*
    if (resp == 'y') {
      runAgain = true;
    } else {
      runAgain = false;
    }
    */
  }

  for (int i = 1; i <= 10; i++) {
    cout << "i=" << i << endl;
  }

  for (double i = 0; i < 10; i += 1.1) {
    cout << "i=" << i << endl;
  }

}
