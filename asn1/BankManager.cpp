#include "BankManager.h"

BankManager::BankManager(std::ifstream& is) : BankMember(is) {
}

BankManager::BankManager(std::string fN, std::string lN, unsigned int pin) :
BankMember(fN, lN, pin, MemberType::MANAGER) {

}

BankManager::BankManager(std::string fN, std::string lN, unsigned long id, unsigned int pin) :
BankMember(fN, lN, id, pin, MemberType::MANAGER) {

}

void BankManager::openNewClientAccount() {

}

void BankManager::closeClientAccount(unsigned long id) {

}

void BankManager::writeToFile(std::ofstream& o) {
	o << "Manager" << " ";
	BankMember::writeToFile(o);
}
