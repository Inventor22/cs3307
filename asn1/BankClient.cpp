#include "BankClient.h"
#include "IdManager.h"

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

BankClient::BankClient(std::string firstName, std::string lastName, unsigned int pin) :
BankMember(firstName, lastName, pin, MemberType::CLIENT) {
}

BankClient::BankClient(std::string firstName, std::string lastName, unsigned long id, unsigned int pin) :
BankMember(firstName, lastName, id, pin, MemberType::CLIENT) {
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

void BankClient::write(std::ofstream& o) {
	o << "Client" << " ";
	BankMember::writeToFile(o);
}

long BankClient::checkChequingBalance() {
	BankAccount* bankAccount = getAccount(BankAccount::AccountType::CHECKING);
	if (bankAccount) {
		return bankAccount->getBalance();
	}
	return -1;
}

long BankClient::checkSavingsBalance() {
	BankAccount* bankAccount = getAccount(BankAccount::AccountType::SAVING);
	if (bankAccount) {
		return bankAccount->getBalance();
	}
	return -1;
}

bool BankClient::hasChequing() {
	BankAccount* bankAccount = getAccount(BankAccount::AccountType::CHECKING);
	return bankAccount != NULL;
}

bool BankClient::hasSavings() {
	BankAccount* bankAccount = getAccount(BankAccount::AccountType::SAVING);
	return bankAccount != NULL;
}

bool BankClient::openChequing(unsigned long id) {
	if (getAccount(BankAccount::AccountType::CHECKING) != NULL) {
		return false;
	}
	bankAccounts.push_back(
		BankAccount(BankAccount::AccountType::CHECKING, id));
	return true;
}

bool BankClient::openSavings(unsigned long id) {
	if (getAccount(BankAccount::AccountType::CHECKING) != NULL) {
		return false;
	}
	bankAccounts.push_back(
		BankAccount(BankAccount::AccountType::SAVING, id));
	return true;
}