#include <iostream>
using namespace std;

#include <ExC.h>

ExC::ExC() {
  cout << "ExC::ExC()" << endl;
  myInt = new int;
  *myInt = 42;
}

ExC::~ExC() {
  cout << "ExC::~ExC()" << endl;
  delete myInt;
}

