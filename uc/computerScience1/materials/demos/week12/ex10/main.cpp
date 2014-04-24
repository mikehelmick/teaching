/// ex09 main.cpp
#include <iostream>
using namespace std;

#include <Account.h>

int main() {

  Account* account1 = new Account(123345678, 1234.56);
  Account* account2 = new Account(756481390, 500.23);

  cout << account1->toString() << endl;
  cout << account2->toString() << endl;

  account1->transferTo(account2, 200.00);

  cout << account1->toString() << endl;
  cout << account2->toString() << endl;

  //
  delete account1;
  delete account2;
}