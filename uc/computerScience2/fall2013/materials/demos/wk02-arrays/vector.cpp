#include <iostream>
// New include!
#include <vector>

using namespace std;

void stats(const vector<int> &entries) {
	cout << " capacity: " << entries.capacity() << " size: " << entries.size() << endl;
}

void double_values(vector<int> &entries) {
	for (int i = 0; i < entries.size(); i++) {
		entries[i] = entries[i] * 2;
	}
}

void print_values(const vector<int> &entries) {
	cout << " --- values --- " << endl;
	for (int i = 0; i < entries.size(); i++) {
		cout << entries[i] << " ";
	}
	cout << endl;
}

int main() {
	// create a vector of int, with initial default capacity
	vector<int> entries;
	
	for (int i = 0; i < 100; i++) {
		entries.push_back(i);
		cout << entries[i] << endl;
		stats(entries);
  }

  // access an element
	cout << "entries[10] is " << entries[10] << endl;

  // remove an element
	entries.pop_back();
	stats(entries);

  // This works - that is bad. Don't do this!	
	cout << "entries[492] is " << entries[492] << endl;

	double_values(entries);
	print_values(entries);
}