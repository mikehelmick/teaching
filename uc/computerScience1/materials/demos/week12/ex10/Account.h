// ex09 account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account {
public:
  Account(long accountNumber, double balance);

  long getAccountNumber() const;

  double getBalance() const;

  void deposit(double amount);

  bool withdrawal(double amount);

  bool transferTo(Account* other, double amount);

  string toString() const;

private:
  long accountNumber;
  double balance;
};

#endif
