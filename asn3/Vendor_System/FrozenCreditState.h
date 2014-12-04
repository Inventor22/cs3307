#ifndef NormalCreditState_h
#define NormalCreditState_h

#include "CreditCard.h"
#include "CreditState.h"

#include <iostream>
#include <string>

class FrozenCreditState : public CreditState
{
  public:
    FrozenCreditState(CreditState* state);
    FrozenCreditState(long balance, CreditCard * CreditCard);
    void deposit(long amount);
    void purchase(long);
    void payInterest();
    void stateChangeCheck();

  private:
    void Initialise();
};

#endif
