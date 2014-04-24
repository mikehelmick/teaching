#include <iostream>
#include <vector>

using namespace std;

void stats(const vector<int> &entries) {
  cout << "capacity: " << entries.capacity()
      << " size: " << entries.size() << endl;
}

int main() {
  vector<int> entries;

  for (int i = 0; i < 100; i++) {
    entries.push_back(i);
    cout << entries[i] << endl;
    stats(entries);
  }

  for (int i = 0; i < entries.size(); i++) {
    cout << "entry[" << i << "] = " << entries[i] << endl;
  }

  for (vector<int>::iterator it = entries.begin();
    it != entries.end(); it++) {
    cout << *it << endl;
  }
}









