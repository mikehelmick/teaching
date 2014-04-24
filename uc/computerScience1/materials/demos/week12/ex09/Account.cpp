#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

// Ok to use <> or ""
// As long as you have the compiler flags set correctly!
#include <Account.h>


Account::Account(long accountNumber, double balance) {
  this->accountNumber = accountNumber;
  this->balance = balance;
}

long Account::getAccountNumber() const {
  return accountNumber;
}

double Account::getBalance() const {
  return balance;
}

void Account::deposit(double amount) {
  balance += amount;
}

bool Account::withdrawal(double amount) {
  if (amount > balance) {
    return false;
  }
  balance -= amount;
  return true;
}

bool Account::transferTo(Account &other, double amount) {
  if (!withdrawal(amount)) {
    return false;
  }
  // successfully made withdrawal from this account
  other.deposit(amount);
  return true;
}

string Account::toString() const {
  stringstream ss;
  ss << "Account: " << accountNumber;
  ss << " Balance: $" << setprecision(2) << fixed << balance;
  return ss.str();
}
