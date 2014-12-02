//Contains code for the bank, which stores the execution trace, and allows for members to be added. 
//Also handles the writing/reading
//Made for CS3307A Final Project
#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <fstream>
#include <set>
#include <string>

#include "BankManager.h"
#include "BankMaintainer.h"
#include "BankClient.h"

#include "IdManager.h"
#include "BankMemberDatabase.h"

class Bank {
public:
  //Deprecated
  //bool executionTrace;
  static const int MAX_ACCOUNTS;
  static const int WITHDRAWL_BALANCE_WARNING;
  static const int WITHDRAWL_FEE; // cents
  static const std::string LOG_FILE;
  enum TraceState { ON = true, OFF = false };

  BankMemberDatabase database;

  Bank();

// Deprecated
//  void setExecutionTraceStatus(TraceState traceState);
//  void setExecutionTraceStatus(bool traceState);
  void addManager(BankManager* bankManager);
  void addMaintainer(BankMaintainer* bankMaintainer);
  void addClient(BankClient* bankClient);
  void addBankAccount(unsigned long bankMemberId,
            BankAccount::AccountType accountType);

  BankMember* getBankMember(unsigned long id);
  bool deleteMember(unsigned long id);

  unsigned long generateNewBankMemberId();

  unsigned long generateNewBankAccountId();

  void writeStateToFile(bool logging);
  bool readStateFromFile(std::ifstream file);
};

#endif

