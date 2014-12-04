#ifndef NormalCreditState_h
#define NormalCreditState_h

#include "BankCreditCard.h"
#include "CreditState.h"

#include <iostream>
#include <string>

class CreditState;
class BankCreditCard;

class NormalCreditState : public CreditState
{
  public:
    NormalCreditState(CreditState* state);
    NormalCreditState(long balance, BankCreditCard* CreditCard);
    void deposit(long amount);
    void purchase();
    void payInterest();
    void stateChangeCheck();
 
  private:
    NormalCreditState();
    void Initialise();
};

#endif
