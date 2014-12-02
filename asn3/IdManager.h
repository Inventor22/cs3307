#pragma once

#include <map>
#include "BankMember.h"
#include "BankAccount.h"

class IdManager {
public:
  static const unsigned long MIN_ID = 0;

  static unsigned long generateNewUniqueId(std::map<unsigned long, BankMember*>& account) {
    unsigned long nextLargestId = getLargestId(account) + 1;
    while (idExists(account, nextLargestId)) {
      ++nextLargestId;
    }
    return nextLargestId;
  }
private:
  static unsigned long getLargestId(std::map<unsigned long, BankMember*>& account) {
    if (account.size() == 0) {
      return MIN_ID;
    }
    return account.rbegin()->second->getId();
  }
  static bool idExists(std::map<unsigned long, BankMember*>& account, unsigned long bankId) {
    return account.find(bankId) != account.end();
  }

public:

  static unsigned long generateNewUniqueId(std::map<unsigned long, BankAccount*>& account) {
    unsigned long nextLargestId = getLargestId(account) + 1;
    while (idExists(account, nextLargestId)) {
      ++nextLargestId;
    }
    return nextLargestId;
  }
private:
  static unsigned long getLargestId(std::map<unsigned long, BankAccount*>& account) {
    if (account.size() == 0) {
      return MIN_ID;
    }
    return account.rbegin()->second->getAccountId();
  }
  static bool idExists(std::map<unsigned long, BankAccount*>& account, unsigned long bankId) {
    return account.find(bankId) != account.end();
  }
};

