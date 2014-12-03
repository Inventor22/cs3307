#include "BankMaintainer.h"

BankMaintainer::BankMaintainer(std::ifstream& i) : BankMember(i) {
  _memberType = MAINTENANCE;
}

BankMaintainer::BankMaintainer(std::string fN, std::string lN, unsigned int pin) :
BankMember(fN, lN, pin, MAINTENANCE) {
}

BankMaintainer::BankMaintainer(std::string fN, std::string lN, unsigned long id, unsigned int pin) :
BankMember(fN, lN, id, pin, MAINTENANCE) {
}

//void setTrace(Bank::TraceState traceState)
//{
//  _bank->setExecutionTraceStatus(traceState);
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

void BankMaintainer::writeToFile(std::ofstream& o) {
  o << "Maintainer" << " ";
  BankMember::writeToFile(o);
  // Nothing special to do, go to next line
  o << std::endl;
}

