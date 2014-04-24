/*
 * Account.h
 *
 *  Created on: Mar 31, 2014
 *      Author: student
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>
using namespace std;

class Account {
public:
  Account(long accountNumber, double balance);
  virtual ~Account();

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

#endif /* ACCOUNT_H_ */
