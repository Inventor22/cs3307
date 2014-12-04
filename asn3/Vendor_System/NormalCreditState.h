#ifndef NormalCreditState_h
#define NormalCreditState_h

#include "CreditCard.h"
#include "CreditState.h"
#include "FrozenCreditState.h"

#include <iostream>
#include <string>

class NormalCreditState : public CreditState
{
  public:
    NormalCreditState(CreditState* state);
    NormalCreditState(long balance, CreditCard * CreditCard);
    void deposit(long amount);
    void purchase(long);
    void payInterest();
    void stateChangeCheck();
 
  private:
    void Initialise();
};

#endif
