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

  void printTrace();

  void writeToFile(std::ofstream& o);

protected:
};

#endif

