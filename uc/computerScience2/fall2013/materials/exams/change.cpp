#include <iostream>
#include <string>
using namespace std;

string changeMe(int cents) {
  if (cents == 0) {
    return "";
  }
  
  if (cents >= 100) {
    return "dollar " + changeMe(cents - 100);
  }
  if (cents >= 50) {
    return "halfdollar " + changeMe(cents - 50);
  }
  if (cents >= 25) {
    return "quarter " + changeMe(cents - 25);
  }
  if (cents >= 10) {
    return "dime " + changeMe(cents - 10);
  }
  if (cents >= 5) {
    return "nickel " + changeMe(cents - 5);
  }
  return "penny " + changeMe(cents - 1);
}

int main() {
  cout << changeMe(65) << endl << endl;
  cout << changeMe(76) << endl << endl;
  cout << changeMe(100) << endl << endl;
  cout << changeMe(49) << endl << endl;
}