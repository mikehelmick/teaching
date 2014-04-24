#include <iostream>
using namespace std;

int my_function(double x) {
  cout << "my_function(double) was called" << endl;
  return x;
}

double my_function(double x, double y) {
  cout << "my_function(double,double) was called" << endl;
  return x + y;
}

int my_function(int x) {
  cout << "my_function(int) was called" << endl;
  return x;
}

/**

int my_function(int x) {
	return x;
}

*/

/*

double my_function(int x) {
	return x;
}

*/

int main() {
  cout << my_function(4) << endl;
  double i = 4.5;
  double j = 4.75;
  cout << my_function(i, j) << endl;
}
