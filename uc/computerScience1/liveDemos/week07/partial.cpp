#include <iostream>
using namespace std;


int main() {

  int capacity = 100;
  int size = 0;
  int values[capacity];

  cout << "Enter up to " << capacity << " values (0 to stop): " << endl;

  int val;
  cin >> val;
  while (val != 0 && size < capacity) {
    values[size++] = val;
    cin >> val;
  }

  cout << "You entered: " << size << " numbers" << endl;
  long long sum = 0;
  for (int i = 0; i < size; i++) {
    sum += values[i];
  }
  cout << "The sum of the values is " << sum << endl;
}
