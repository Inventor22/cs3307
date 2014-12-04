#include "CreditCard.h"
#include "NormalCreditState.h"


CreditCard::CreditCard()
{
  _state = reinterpret_cast<CreditState*>(new NormalCreditState(0.0, this)); //default
}

CreditCard::~CreditCard()
{
  delete _state;
}

long CreditCard::getBalance(void)
{
  return _state->getBalance();
}

void CreditCard::deposit(long amount)
{
  _state->deposit(amount);
}

void CreditCard::purchase(long amount)
{
  _state->purchase(amount);
}

void CreditCard::payInterest()
{
  _state->payInterest();
}

void CreditCard::setCreditState(CreditState* state)
{
  _state = state;
}

CreditState*CreditCard::getCreditState()
{
  return _state;
}
