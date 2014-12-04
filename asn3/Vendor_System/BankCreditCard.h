#ifndef BANK_CREDIT_CARD_H
#define BANK_CREDIT_CARD_H

#include <iostream>
#include <fstream>
#include <vector>

#include "CreditState.h"
class CreditState;

class BankCreditCard {

public:
  BankCreditCard(unsigned int id);
  ~BankCreditCard();
  void purchase();
  void payInterest();
  void setCreditState(CreditState* state);
  CreditState* getCreditState();

  long getBalance(void);
  void deposit(long amount);

private:
  CreditState* _state;
  unsigned int _id;
  BankCreditCard();
};

#endif

