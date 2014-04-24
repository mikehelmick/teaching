// Program that prints the powers of 2
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  cout << "How many powers of two should I print? ";
  int times;
  cin >> times;

  int res = 0;
  for (int i = 0; i < times; i++) {
    if (i == 0) {
      res = 1;
    } else if (i == 1) {
      res = 2;
    } else {
      res = res * 2;
    }
    cout << "2^" << i << " = " << res << endl;
  }

  return 0;
}

// Single line comment

/*
 Multi line comment
*/ 

