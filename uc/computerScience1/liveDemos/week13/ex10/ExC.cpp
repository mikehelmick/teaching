#include <iostream>
using namespace std;

#include <ExC.h>

ExC::ExC() {
  cout << "ExC::ExC()" << endl;
  myInt = new int;
  *myInt = 42;
}

ExC::ExC(const ExC &that) {
  cout << "ExC::ExC(ExC&)" << endl;
  myInt = new int;
  *myInt = *(that.myInt);
}

ExC::~ExC() {
  cout << "ExC::~ExC()" << endl;
  delete myInt;
}

