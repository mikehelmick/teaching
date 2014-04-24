#include <iostream>

using namespace std;

int main() {

  int x;
  cout << "size of int is " << sizeof(x) << endl;

  int* px = NULL;
  cout << "size of int* is " << sizeof(px) << endl; 

  px = new int[2092];
  cout << "size of px is " << sizeof(px) << endl;

  cout << "size of *px " << sizeof(*px) << endl;  
  delete[] px;
}
