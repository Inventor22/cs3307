#include "BankAccount.h"

BankAccount::BankAccount(std::ifstream &is) {
  readFromFile(is);
}

BankAccount::BankAccount(BankAccount::AccountType accountType) :
_accountType(accountType), _balance(0) {
}

BankAccount::BankAccount(BankAccount::AccountType accountType, unsigned long id) :
_accountType(accountType), _id(id), _balance(0) {
}

BankAccount::BankAccount(BankAccount::AccountType accountType,
             unsigned long id, int balance) :
_accountType(accountType), _id(id), _balance(balance) {
}

BankAccount::AccountType BankAccount::getAccountType() {
  return _accountType;
}

unsigned long BankAccount::getAccountId() {
  return _id;
}

int BankAccount::getBalance() {
  return _balance;
}

int BankAccount::deposit(int const amount) {
  _balance += amount;
  return _balance;
}

int BankAccount::withdrawal(int const amount) {
  if (_balance - amount < 0) {
    return INSUFFICIENT_FUNDS;
  }
  _balance -= amount;
  return amount;
}

void BankAccount::writeToFile(std::ofstream& o){
  o << "Account ";
  o << _accountType << _balance << " " << _id;
}

void BankAccount::readFromFile(std::ifstream& i){
  int accountType;
  i >> accountType;
  i >> _id >> _balance;
  _accountType = (AccountType)accountType;
}