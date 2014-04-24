#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {

  string name = "Steve";
  int age = 25;
  double myPi = 3.14;
  
  printf("Hello, %s. I understand you are %3d years old.\n I also know that PI is %5.2f\n", name.c_str(), age, myPi);
  

  return 0;
}
