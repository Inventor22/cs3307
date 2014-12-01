#pragma once
#ifndef BANK_MEMBER_DATABASE
#define BANK_MEMBER_DATABASE

#include <string>
#include <vector>
#include <map>
#include "BankMember.h"
#include "BankClient.h"
#include "BankManager.h"
#include "BankMaintainer.h"
#include "IdManager.h"

class BankMemberDatabase {
private:
	std::map<unsigned long, BankMember*> bankMembers;
	typedef std::map<unsigned long, BankMember*>::iterator BankMemberItr;
	typedef std::pair<unsigned long, BankMember*> MemberPair;

	std::map<unsigned long, BankAccount*> bankAccounts;
	typedef std::map<unsigned long, BankAccount*>::iterator BankAccountItr;
	typedef std::pair<unsigned long, BankAccount*> AccountPair;

public:
	BankMemberDatabase();

	BankMember* getBankMember(unsigned long id);

	bool addBankMember(BankMember* bankMember);

	bool deleteBankMember(unsigned long id);

	bool addBankAccount(unsigned long bankMemberId,
						BankAccount::AccountType accountType);

	bool deleteBankAccount(unsigned long bankAccountId);

	void writeDatabaseToFile(std::ofstream& os);
	
	void loadDatabaseFromFile(std::ifstream& is, bool& executionTrace);

	unsigned long generateNewBankMemberId();

	unsigned long generateNewBankAccountId();

    /*
    For each user, check if amount owing >0, if >0 then automatically take minimum payment
    from chequing, then process interest: 2%
    */

    void processMonthlyCreditPayments();

};

#endif