#ifndef BANK_MAINTENANCE
#define BANK_MAINTENANCE

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "BankMember.h"
#include "mtk\mtktrace.hpp"


class BankMaintainer : public BankMember {
private:

public:
	BankMaintainer(std::ifstream& i);

	BankMaintainer(std::string fN, std::string lN, unsigned int pin);

	BankMaintainer(std::string fN, std::string lN, unsigned long id, unsigned int pin);

	//void setTrace(Bank::TraceState traceState)
	//{
	//	_bank->setExecutionTraceStatus(traceState);
	//}

	void printTrace();

protected:
	virtual void write(std::ofstream& o);
};

#endif