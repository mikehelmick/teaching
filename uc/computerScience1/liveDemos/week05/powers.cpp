#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  cout << "Max num? ";
  int limit;
  cin >> limit;

  int power = 0;
  for (int val = 1; val < limit; val *= 2, power++) {
    cout << "2^" << setw(3) << power << "  " << setw(10) << val << endl;
  }

}
