#include "BankCreditCard.h"

BankCreditCard::BankCreditCard(BankCreditCard::CreditType creditType) :
_creditType(creditType), _creditLimit(100), _interestAccumulation(0) {
}


BankCreditCard::BankCreditCard(BankCreditCard::CreditType creditType,
						 int creditLimit) :
_creditType(creditType), _creditLimit(creditLimit), _interestAccumulation(0) {
}

BankCreditCard::BankCreditCard(BankCreditCard::CreditType creditType,
						 int creditLimit, int interestAccumulation) :
_creditType(creditType), _creditLimit(creditLimit), _interestAccumulation(interestAccumulation) {
}

BankCreditCard::CreditType BankCreditCard::getCreditType() {
	return _creditType;
}

int BankCreditCard::getCreditLimit() {
	return _creditLimit;
}

int BankCreditCard::getInterestAccumulation() {
	return _interestAccumulation;
}

