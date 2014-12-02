#ifndef BANK_MANAGER
#define BANK_MANAGER

#include "BankMember.h"

class BankManager : public BankMember {
public:
	BankManager(std::ifstream& is);
	BankManager(std::ifstream& is, int memType);

	BankManager(std::string fN, std::string lN, unsigned int pin);
	BankManager(std::string fN, std::string lN, unsigned long id, unsigned int pin);

	void openNewClientAccount();

	void closeClientAccount(unsigned long id);

protected:
	virtual void writeToFile(std::ofstream& o);
};

#endif

