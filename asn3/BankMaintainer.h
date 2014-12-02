#ifndef BANK_MAINTENANCE
#define BANK_MAINTENANCE

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "BankMember.h"

class BankMaintainer : public BankMember {
private:

public:
  BankMaintainer(std::ifstream& i);

  BankMaintainer(std::string fN, std::string lN, unsigned int pin);

  BankMaintainer(std::string fN, std::string lN, unsigned long id, unsigned int pin);

  //void setTrace(Bank::TraceState traceState)
  //{
  //  _bank->setExecutionTraceStatus(traceState);
  //}

  void printTrace();

protected:
  virtual void writeToFile(std::ofstream& o);
};

#endif

