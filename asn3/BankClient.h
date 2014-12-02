#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BankAccount.h"
#include "BankMember.h"
#include "IdManager.h"

class BankClient : public BankMember {
private:
  std::vector<BankAccount> bankAccounts;

public:
  BankClient(std::ifstream& is);

  BankClient(std::string firstName, std::string lastName, unsigned int pin);
  BankClient(std::string firstName, std::string lastName, unsigned long id, unsigned int pin);

  BankAccount* getAccount(BankAccount::AccountType accountType);

  long checkChequingBalance();
  long checkSavingsBalance();
  bool hasChequing();
  bool hasSavings();

  bool addAccount(BankAccount::AccountType accountType, unsigned long accountId);
  bool setAccount(BankAccount account);
  bool removeAccount(BankAccount::AccountType accountType);

  bool openChequing(unsigned long id);

  bool openSavings(unsigned long id);

protected:
  virtual void writeToFile(std::ofstream& o);
};

#endif

