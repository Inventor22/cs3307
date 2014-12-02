#include "BankClient.h"

BankClient::BankClient(std::ifstream& is) : BankMember(is) {
  int numAccounts = 0;
  is >> numAccounts;
  if (numAccounts == 0) return;
  int accountType = 0;
  for (int i = 0; i < numAccounts; i++) {
    unsigned long accountId;
    int accountBalance;
    is >> accountType;
    is >> accountId;
    is >> accountBalance;
    this->addAccount((BankAccount::AccountType)accountType, accountId);
    this->getAccount((BankAccount::AccountType)accountType)->deposit(accountBalance);
  }
}

BankClient::BankClient(std::string firstName, std::string lastName, unsigned int pin) : BankMember(firstName, lastName, pin, CLIENT) {
    std::string s = std::to_string(_id);
    failedPayments.open(s, std::ios::app);
}

BankClient::BankClient(std::string firstName, std::string lastName, unsigned long id, unsigned int pin) : BankMember(firstName, lastName, id, pin, CLIENT) {
    std::string s = std::to_string(_id);
    failedPayments.open(s, std::ios::app);
}

BankAccount* BankClient::getAccount(BankAccount::AccountType accountType) {
  std::vector<BankAccount>::iterator itr;
  for (itr = bankAccounts.begin(); itr != bankAccounts.end(); ++itr) {
    if (itr->getAccountType() == accountType) {
      return &(*itr);
    }
  }
  return NULL;
}

bool BankClient::addAccount(BankAccount::AccountType accountType, unsigned long accountId) {
  if (bankAccounts.size() >= 2) {
    return false;
  }
  std::vector<BankAccount>::iterator itr;
  for (itr = bankAccounts.begin(); itr != bankAccounts.end(); ++itr) {
    if (itr->getAccountType() == accountType) {
      return false;
    }
  }
  bankAccounts.push_back(
    BankAccount(accountType, accountId));
  return true;
}

bool BankClient::setAccount(BankAccount account) {
  if (bankAccounts.size() >= 2) {
    return false;
  }
  std::vector<BankAccount>::iterator itr;
  for (itr = bankAccounts.begin(); itr != bankAccounts.end(); ++itr) {
    if (itr->getAccountType() == account.getAccountType()) {
      return false;
    }
  }
  bankAccounts.push_back(account);
  return true;
}

bool BankClient::removeAccount(BankAccount::AccountType accountType) {
  std::vector<BankAccount>::iterator itr;
  for (itr = bankAccounts.begin(); itr != bankAccounts.end(); ++itr) {
    if (itr->getAccountType() == accountType && itr->getBalance() == 0) {
      bankAccounts.erase(itr);
      return true;
    }
  }
  return false;
}

long BankClient::checkChequingBalance() {
  BankAccount* bankAccount = getAccount(BankAccount::CHECKING);
  if (bankAccount) {
    return bankAccount->getBalance();
  }
  return -1;
}

long BankClient::checkSavingsBalance() {
  BankAccount* bankAccount = getAccount(BankAccount::SAVING);
  if (bankAccount) {
    return bankAccount->getBalance();
  }
  return -1;
}

bool BankClient::hasChequing() {
  BankAccount* bankAccount = getAccount(BankAccount::CHECKING);
  return bankAccount != NULL;
}

bool BankClient::hasSavings() {
  BankAccount* bankAccount = getAccount(BankAccount::SAVING);
  return bankAccount != NULL;
}

bool BankClient::openChequing(unsigned long id) {
  if (getAccount(BankAccount::CHECKING) != NULL) {
    return false;
  }
  bankAccounts.push_back(
    BankAccount(BankAccount::CHECKING, id));
  return true;
}

bool BankClient::openSavings(unsigned long id) {
  if (getAccount(BankAccount::CHECKING) != NULL) {
    return false;
  }
  bankAccounts.push_back(
    BankAccount(BankAccount::SAVING, id));
  return true;
}

void BankClient::writeToFile(std::ofstream& o) {
  o << "Client" << " ";
  BankMember::writeToFile(o);
  for (int i=0; i<bankAccounts.size(); i++){
    // Write out accounts

  }
}

int BankClient::payCreditCard() {
    if (hasCreditCard && creditBalance > 0) {

        BankAccount* b = getAccount(BankAccount::AccountType::CHECKING);
        long chequingBal = checkChequingBalance();

        if (payMinimum) {
            long payment = creditBalance * minimumPayment;

            if (chequingBal > payment) {
                creditBalance -= b->withdrawal(payment);
            } else {
                creditBalance -= b->withdrawal(chequingBal);
            }

            creditBalance *= 1.02;
        } else {
            if (chequingBal > creditBalance) {
                creditBalance -= b->withdrawal(creditBalance);
            } else {
                creditBalance -= b->withdrawal(chequingBal);
                creditBalance *= 1.02;
            }
        }
    }
}
