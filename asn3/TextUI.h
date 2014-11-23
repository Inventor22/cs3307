#pragma once

#include "Bank.h"
#include "BankMember.h"

class TextUI{
private:
	//BankMember currUser;
	//BankMember::UserType currUserType;
	//Database will be a member eventually
	Bank bank;
    bool bLogging;
	bool bShutdown;

public:
	TextUI();
    TextUI(bool logging);
	~TextUI();
	void displayHeader();
	BankMember* setupFirstMaintainer();
	BankMember* setupFirstManager();
	
	bool processTransaction();

	bool getShutdownStatus();

private:
	//General functions
	BankMember* promptForId();
	bool promptForPin(BankMember* user);
	bool changePIN(BankMember* user);
	bool isValidPIN(int pin);  //Makes sure that a pin is valid when it is inputted.
	//std::string moneyToStr(long amount); //moved to InputParser

	//Manager functions
	bool processManagerTransaction(BankManager* user);
	bool openAccount();
	bool closeAccount(BankManager* manager);  //Pass the user performing the delete
	void queryAccount();
	void queryAccounts();
	void showAccount(BankMember* member);
	void viewBankTotals();

	//Maintainer functions
	bool processMaintainerTransaction(BankMaintainer* user);
	bool enableLogging();
	bool printLogs();
	bool shutdown();

	//Client functions
	bool processClientTransaction(BankClient* user);
	long withdrawal(BankClient* client);
	long deposit(BankClient* client);
	long transfer(BankClient* client);
	void balances(BankClient* client);
	bool openComplimentary(BankClient* client);
	long removeMoneyFromChequing(BankClient* client, long amount);
	long removeMoneyFromSavings(BankClient* client, long amount);

};