#include <iostream>
using namespace std;

double mpg(double liters, double miles) {
  return miles / (liters * 0.264179);
}

int main() {
  cout << mpg(34, 280) << endl;
}