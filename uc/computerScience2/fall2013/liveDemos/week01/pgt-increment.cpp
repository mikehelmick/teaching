/**
   filename: pgt-increment.cpp
   other stuff here
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  float b = 4.13;
  
  cout << "b is:" << b << endl;
  cout << "b is2:" << ++b << endl; // NEVER DO THIS
  cout << "b is:" << b << endl;
  return 0;
}
