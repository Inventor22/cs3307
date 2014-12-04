//Obvious include statements are obvious
#include "FrozenCreditState.h"

#include <iostream>
#include <string> //so we can use strings obviously

using namespace std;

FrozenCreditState::FrozenCreditState(CreditState* state)
{
  this->_balance = state->getBalance();
  this->_CreditCard = state->getBankCreditCard();
  Initialise();
}

FrozenCreditState::FrozenCreditState(long balance, CreditCard * CreditCard)
{
  this->_balance = balance;
  this->_CreditCard = CreditCard;
  Initialise();
}

void FrozenCreditState::deposit(long amount)
{
  _balance += amount;

  stateChangeCheck();
}

void FrozenCreditState::purchase(long amount)
{
  _balance -= 10;

  // something like rng then balance deduction
  stateChangeCheck();
}

void FrozenCreditState::payInterest()
{
  _balance = _balance * _interest;
  stateChangeCheck();
}

void FrozenCreditState::stateChangeCheck()
{
//  if (_balance < _lowerLimit)
//  {
//     _CreditCard->SetState(reinterpret_cast<State*>(new RedState(this)));
//     delete this;
//     return;
//  }
//  else if (balance_ > _upperLimit)
//  {
//    _CreditCard->SetState(reinterpret_cast<State*>(new GoldState(this)));
//     delete this;
//     return;
//  }
}

void FrozenCreditState::Initialise()
{
 _stateName = "Frozen";
 _interest = 1.0;
 //_lowerLimit = 0.0;
 _upperLimit = 1000.0;
}
