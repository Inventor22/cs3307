#ifndef CreditState_h
#define CreditState_h

#include "BankCreditCard.h"

#include <iostream>
#include <string>

class BankCreditCard;

class CreditState
{
	protected:
		BankCreditCard *_CreditCard;
		long _interest;
		long _lowerLimit;
		long _upperLimit;
		long _balance;
		std::string _stateName;

	public:
		BankCreditCard* getBankCreditCard(void);
		void setBankCreditCard(BankCreditCard* CreditCard);
  
  		long getBalance(void);
		std::string getStateName(void);
		void setBalance(long balance);

		virtual void deposit(long amount)=0;
		virtual void purchase(void)=0;
		virtual void payInterest(void)=0;
};

#endif
