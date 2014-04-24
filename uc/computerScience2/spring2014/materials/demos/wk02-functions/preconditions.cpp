#include <assert.h>
#include <iostream>
using namespace std;

/**
 * prints a line "x" number of stars on the screen, and a newline
 * 
 * @param x The number of stars to print on the screen, must be > 0
 */
void print_stars(int x) {
	//assert(x > 0);
	long counter = 0;
	for (int i = x; i != 0; i--) {
		//cout << "*";
		counter++;
		if (counter % 1000000 == 0) {
			cout << " ** " << counter << endl;
		}
	}
	cout << endl;
	cout << "trips through the loop: " << counter << endl;
}

int main() {
	print_stars(52);
	print_stars(-1);
}