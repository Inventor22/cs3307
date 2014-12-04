#include "BankMaintainer.h"

BankMaintainer::BankMaintainer(std::ifstream& i) : BankMember(i) {
}

BankMaintainer::BankMaintainer(std::string fN, std::string lN, unsigned int pin) :
BankMember(fN, lN, pin, MemberType::MAINTENANCE) {
}

BankMaintainer::BankMaintainer(std::string fN, std::string lN, unsigned long id, unsigned int pin) :
BankMember(fN, lN, id, pin, MemberType::MAINTENANCE) {
}

//void setTrace(Bank::TraceState traceState)
//{
//	_bank->setExecutionTraceStatus(traceState);
//}

void BankMaintainer::printTrace() {
	std::ifstream traceFile("trace.txt");
	std::string currentLine;
	if (traceFile.is_open()) {
		while (std::getline(traceFile, currentLine)) {
			std::cout << currentLine << std::endl;
		}
	}
	traceFile.close();
}

void BankMaintainer::write(std::ofstream& o) {
	o << "Maintainer" << " ";
	BankMember::writeToFile(o);
}