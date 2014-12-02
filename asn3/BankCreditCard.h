#ifndef BANK_CREDIT_CARD_H
#define BANK_CREDIT_CARD_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class BankCreditCard {
public:
	typedef enum CreditType { FROZEN = 0, UNFROZEN = 1 };
	static const int INSUFFICIENT_FUNDS = -1;

private:
	CreditType _creditType;
	int _creditLimit;
	int _interestAccumulation;

public:
	BankCreditCard(CreditType creditType);
	BankCreditCard(CreditType creditType, int creditLimit);
	BankCreditCard(CreditType creditType, int creditLimit, int interestAccumulation);

	CreditType getCreditType();
	int getCreditLimit();
	int getInterestAccumulation();

};

#endif

