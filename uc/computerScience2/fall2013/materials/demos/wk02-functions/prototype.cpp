#include <iostream>
using namespace std;

int my_function(double x) {
	return x;
}

int my_function(double x, double y) {
	return x + y;
}

int my_function(int x) {
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
	cout << my_function(4, 4) << endl;
}