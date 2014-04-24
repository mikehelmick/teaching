// week05/powers.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  
  cout << "This program prints out to powers of 2." << endl;
  cout << "What is the limit I should print up to? ";
  // Allow for bigger numbers
  unsigned long long limit = 0;
  cin >> limit;
  
  for (unsigned long long val = 1; val <= limit; val *= 2) {
    cout << setw(15) << val << endl;
  }
  
}