/*
 * Account.cpp
 *
 *  Created on: Mar 31, 2014
 *      Author: student
 */

#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

#include <Account.h>

Account::Account(long accountNumber, double balance) {
  this->accountNumber = accountNumber;
  this->balance = balance;
}

Account::~Account() {
  // Nothing to do.
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

bool Account::transferTo(Account & other, double amount) {
  if (withdrawal(amount)) {
    other.deposit(amount);
    return true;
  }
  return false;
}

string Account::toString() const {
  stringstream ss;
  ss << "Account: " << accountNumber
      << " Balance: $" << setprecision(2) << fixed << balance;
  return ss.str();
}

