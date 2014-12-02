#ifndef BANK_PROFILE_H
#define BANK_PROFILE_H

#include <iostream>
#include <string>

using namespace std; 

class BankProfile {
public:
	static const int MAX_ACCOUNTS = 2;
	static const int WITHDRAWL_BALANCE_WARNING = 1000;
	static const int WITHDRAWL_FEE = 200; // cents
};

#endif

