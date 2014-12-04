#ifndef BANK_CREDIT_CARD_H
#define BANK_CREDIT_CARD_H

#include <iostream>
#include <fstream>
#include <vector>

#include "CreditState.h"
class CreditState;

class CreditCard {

public:
  CreditCard();
  ~CreditCard();
  void purchase(long);
  void payInterest();
  void setCreditState(CreditState* state);
  CreditState* getCreditState();

  long getBalance(void);
  void deposit(long amount);

private:
  CreditState* _state;
};

#endif

