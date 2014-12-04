#ifndef CreditState_h
#define CreditState_h

#include "CreditCard.h"

#include <iostream>
#include <string>

class CreditState
{
  protected:
    CreditCard *_CreditCard;
    long _interest;
    //long _lowerLimit;
    long _upperLimit;
    long _balance;
    std::string _stateName;

  public:
    CreditCard * getBankCreditCard(void);
    void setBankCreditCard(CreditCard * CreditCard);

    long getBalance(void);
    std::string getStateName(void);
    void setBalance(long balance);

    virtual void deposit(long amount)=0;
    virtual void purchase(long)=0;
    virtual void payInterest(void)=0;
};

#endif
