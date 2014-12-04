#include "BankCreditCard.h"
#include "NormalCreditState.h"


BankCreditCard::BankCreditCard(unsigned int id):_id(id)
{
  _state = reinterpret_cast<CreditState*>(new NormalCreditState(0.0, this)); //default
}

BankCreditCard::~BankCreditCard()
{
  delete _state;
}

long BankCreditCard::getBalance(void)
{
  return _state->getBalance();
}

void BankCreditCard::deposit(long amount)
{
  _state->deposit(amount);
}

void BankCreditCard::purchase()
{
  _state->purchase();
}

void BankCreditCard::payInterest()
{
  _state->payInterest();
}

void BankCreditCard::setCreditState(CreditState* state)
{
  _state = state;
}

CreditState* BankCreditCard::getCreditState()
{
  return _state;
}
