#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class BankAccount {
public:
  typedef enum AccountType { CHECKING = 0, SAVING = 1 };
  static const int INSUFFICIENT_FUNDS = -1;

private:
  AccountType _accountType;
  int _balance;
  unsigned long _id;

public:
  BankAccount(AccountType accountType);
  BankAccount(AccountType accountType, unsigned long id);
  BankAccount(AccountType accountType, unsigned long id, int balance);

  AccountType getAccountType();
  int getBalance();
  unsigned long getAccountId();
  int deposit(int const amount);
  int withdrawal(int const amount);
};

#endif

