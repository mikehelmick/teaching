#include <iostream>
using namespace std;

void square(int& input) {
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