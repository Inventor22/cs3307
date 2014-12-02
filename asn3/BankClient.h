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

    const float minimumPayment = 0.1;
    bool hasCreditCard;
    bool payMinimum; // true
    long creditBalance;

public:
	BankClient(std::ifstream& is);
	BankClient(std::ifstream& is, int memType);

	BankClient(std::string firstName, std::string lastName, unsigned int pin);
	BankClient(std::string firstName, std::string lastName, unsigned long id, unsigned int pin);

	BankAccount* getAccount(BankAccount::AccountType accountType);

	long checkChequingBalance();
	long checkSavingsBalance();
	bool hasChequing();
	bool hasSavings();

	bool addAccount(BankAccount::AccountType accountType, unsigned long accountId);
	bool removeAccount(BankAccount::AccountType accountType);

	bool openChequing(unsigned long id);

	bool openSavings(unsigned long id);

    /*
    For each user, check if amount owing >0, if >0 then automatically take minimum payment
    from chequing, then process interest: 2%
    */
    int payCreditCard();

protected:
	virtual void write(std::ofstream& o);
};

#endif

