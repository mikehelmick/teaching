#include <iostream>
using namespace std;


int main() {
  int z = 0;
  int y = 66;
  int x = 65;

  char myStr[5];
  myStr[0] = 'H';
  myStr[1] = 'E';
  myStr[2] = 'L';
  myStr[3] = 'L';
  myStr[4] = 'O';

  char* fake = (char*)(&myStr+5);
  (*fake) = 'A';

  int a = 65;
  int b = 66;
  int c = 0;

  cout << myStr << endl;

}
