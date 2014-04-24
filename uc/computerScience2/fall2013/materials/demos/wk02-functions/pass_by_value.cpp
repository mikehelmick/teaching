#include <iostream>
using namespace std;

int square(int input) {
	input = input * input;
	return input;
}

int main() {
	int x = 42;
	cout << "x = " << x << endl;
	int y = square(x);
	cout << "function called" << endl;
	cout << "x = " << x << " y = " << y << endl;

	return 0;
}