#include <string>
#include <iostream>

using namespace std;

void print_stats(const string& str) {
	cout << " char 5 is '" << str[5] << "'" << endl;
	cout << " length is " << str.length() << endl;
	cout << " substr(4,9) is '" << str.substr(4, 9) << "'" << endl;
	if (str.length() > 11) {
  	cout << " substr(5, length-10) is '" << str.substr(5, str.length() - 10) << "'" << endl;
  }
}

int main() {
	string str = "Hello, my name is Joe.";
	print_stats(str);
	
	cout << "***" << endl;

  // start with push_back -- ERROR
  // then append
  // then +=
	str.append(" This is another sentance.");
	print_stats(str);
	
}