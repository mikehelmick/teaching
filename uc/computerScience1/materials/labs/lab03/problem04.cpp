#include <iostream>
#include <string>
using namespace std;

int readAmount(const string &label, int value) {
  int amount = -1;
  cout << "Enter the number of " << label << " you have: ";
  cin >> amount;
  bool first = true;
  if (amount <= 0 || amount * value >= 100) {
    cout << "You must have at least 1 of each coin, and less than 1 dollar of that coin type." << endl;
    return -1;
  }
  return amount;
}

int totalValue(int quarters, int dimes, int nickels, int pennies) {
  return quarters * 25 + dimes * 10 + nickels * 5 + pennies;
}

int main() {
  cout << "Welcome to the change-for-a dollar game!" << endl;
  int quarters = readAmount("quarters", 25);
  if (quarters <= 0) return 0;
  int dimes = readAmount("dimes", 10);
  if (dimes <= 0) return 0;
  int nickels = readAmount("nickels", 5);
  if (nickels <= 0) return 0;
  int pennies = readAmount("pennies", 1);
  if (pennies <= 0) return 0;

  int total = totalValue(quarters, dimes, nickels, pennies);
  if (total == 100) {
    cout << "You win! The total adds up to 1 dollar!" << endl;
  } else {
    cout << "You loose, your total of " << total << " cents is ";
    if (total > 100) {
      cout << "greater";
    } else {
      cout << "less";
    }
    cout << " than 1 dollar." << endl;
  }
  
  return 0;
}
