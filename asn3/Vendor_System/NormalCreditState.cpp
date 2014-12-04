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

NormalCreditState::NormalCreditState(long balance, BankCreditCard* CreditCard)
{
  this->_balance = balance;
  this->_CreditCard = CreditCard;
  Initialise();
}

void NormalCreditState::deposit(long amount)
{
  cout << "Original Balance: " << _balance;  
  _balance += amount;
  cout << "New Balance: " << _balance;  

  stateChangeCheck();
}

void NormalCreditState::purchase()
{
  cout <<"Purchase DONE\n";
  cout << "Original Balance: " << _balance;  
  _balance -= 10;
  cout << "New Balance: " << _balance;  

  // something like rng then balance deduction
  stateChangeCheck();
}

void NormalCreditState::payInterest()
{
  cout <<"WOW interest\n";
  _balance = _balance * _interest;
  stateChangeCheck();
}

void NormalCreditState::stateChangeCheck()
{
  cout <<"WOW change check\n";

/*
 if (_balance < _lowerLimit)
 {
   account_->SetState(reinterpret_cast<State*>(new RedState(this)));
   delete this;
   return;
 }
 else if (balance_ > _upperLimit)
 {
   account_->SetState(reinterpret_cast<State*>(new GoldState(this)));
   delete this;
   return;
 }
*/
}

void NormalCreditState::Initialise()
{
 _stateName = "Normal";
 _interest = 1.0;
 _lowerLimit = 0.0;
 _upperLimit = 1000.0;
}
