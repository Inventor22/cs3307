#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <set>
#include <string>
#include "BankManager.h"
#include "BankMaintainer.h"
#include "BankClient.h"
#include "IdManager.h"
#include "BankMemberDatabase.h"

class Bank {
public:
	bool executionTrace;
	static const int MAX_ACCOUNTS;
	static const int WITHDRAWL_BALANCE_WARNING;
	static const int WITHDRAWL_FEE; // cents
	static const std::string LOG_FILE;
	enum TraceState { ON = true, OFF = false };

	BankMemberDatabase database;

	Bank();

	void setExecutionTraceStatus(TraceState traceState);
	void addManager(BankManager* bankManager);
	void addMaintainer(BankMaintainer* bankMaintainer);
	void addClient(BankClient* bankClient);
	void addBankAccount(unsigned long bankMemberId,
						BankAccount::AccountType accountType);

	BankMember* getBankMember(unsigned long id);
	bool deleteMember(unsigned long id);

	unsigned long generateNewBankMemberId();

	unsigned long generateNewBankAccountId();

	void writeStateToFile();
	void readStateFromFile();

};

#endif