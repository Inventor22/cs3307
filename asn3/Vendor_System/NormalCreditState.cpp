//Obvious include statements are obvious
#include "NormalCreditState.h"

#include <iostream>
#include <string> //so we can use strings obviously

using namespace std;

NormalCreditState::NormalCreditState(CreditState* state)
{
  this->_balance = state->getBalance();
  this->_CreditCard = state->getBankCreditCard();
  Initialise();
}

NormalCreditState::NormalCreditState(long balance, CreditCard * CreditCard)
{
  this->_balance = balance;
  this->_CreditCard = CreditCard;
  Initialise();
}

void NormalCreditState::deposit(long amount)
{
  _balance += amount;

  stateChangeCheck();
}

void NormalCreditState::purchase(long amount)
{
  _balance -= 10;

  // something like rng then balance deduction
  stateChangeCheck();
}

void NormalCreditState::payInterest()
{
//  cout <<"WOW interest\n";
  _balance = _balance * _interest;
  stateChangeCheck();
}

void NormalCreditState::stateChangeCheck()
{
  // No way to get under the limit
  /*
  if (_balance < _lowerLimit)
  {
   account_->SetState(reinterpret_cast<State*>(new RedState(this)));
   delete this;
   return;
  }
  */
  // Check if above credit limit
  if (_balance > _upperLimit)
  {
   _CreditCard->setCreditState(CreditState::(reinterpret_cast<CreditState*>(new FrozenCreditState((CreditState*)this)));
   delete this;
   return;
  }
}

void NormalCreditState::Initialise()
{
 _stateName = "Normal";
 _interest = 1.0;
 _upperLimit = 1000.0;
}
