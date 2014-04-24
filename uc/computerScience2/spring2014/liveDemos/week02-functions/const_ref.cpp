#include <iostream>
using namespace std;

void square(const int& input) {
	// Compiler error!!!
	input = input * input;
}

int main() {
	int x = 42;
	cout << "x = " << x << endl;
	square(x);
	cout << "function called" << endl;
	cout << "x = " << x << endl;

	return 0;
}