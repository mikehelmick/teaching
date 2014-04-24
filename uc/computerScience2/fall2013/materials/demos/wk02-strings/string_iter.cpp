#include <string>
#include <iostream>

using namespace std;

int main() {
	string str = "Example string";
	cout << str << endl;

	for (string::iterator iter = str.begin(); iter != str.end(); iter ++) {
		// Note the *
		cout << *iter << endl;
	}
}