#include <string>
#include "Bank.h"

const int Bank::MAX_ACCOUNTS = 2;
const int Bank::WITHDRAWL_BALANCE_WARNING = 1000;
const int Bank::WITHDRAWL_FEE = 200;
const std::string Bank::LOG_FILE = "trace.txt";

Bank::Bank() {
}

void Bank::setExecutionTraceStatus(Bank::TraceState traceState) {
	executionTrace = traceState;
}

void Bank::addManager(BankManager* bankManager) {
	database.addBankMember(bankManager);
}

void Bank::addMaintainer(BankMaintainer* bankMaintainer) {
	database.addBankMember(bankMaintainer);
}

void Bank::addClient(BankClient* bankClient) {
	database.addBankMember(bankClient);
}

void Bank::addBankAccount(unsigned long bankMemberId,
						  BankAccount::AccountType accountType) {
	database.addBankAccount(bankMemberId, accountType);
}

BankMember* Bank::getBankMember(unsigned long id) {
	return database.getBankMember(id);
}

bool Bank::deleteMember(unsigned long id) {
	return database.deleteBankMember(id);
}

unsigned long Bank::generateNewBankMemberId() {
	return database.generateNewBankMemberId();
}

unsigned long Bank::generateNewBankAccountId() {
	return database.generateNewBankAccountId();
}

void Bank::writeStateToFile() {
	std::ofstream bankFile;
	bankFile.open("BankDatabase.txt");
	bankFile << executionTrace << std::endl;
	database.writeDatabaseToFile(bankFile);
}

void Bank::readStateFromFile() {
	std::ifstream bankFile("BankDatabase.txt");
	database.loadDatabaseFromFile(bankFile, executionTrace);
}