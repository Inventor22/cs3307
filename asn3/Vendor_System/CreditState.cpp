//This contains all the TARGET code aka library specific item class code
//Made for CS3307a Assignment #2 - Scenario 2 by Andy and Dave

//Obvious include statements are obvious
#include "CreditState.h"

#include <iostream>

using namespace std;

CreditCard * CreditState::getBankCreditCard(void)
{
  return _CreditCard;
}

void CreditState::setBankCreditCard(CreditCard * CreditCard)
{
  _CreditCard = CreditCard;
}

string CreditState::getStateName(void)
{
  return _stateName;
}

long CreditState::getBalance(void)
{
 return _balance;
}

void CreditState::setBalance(long balance)
{
  _balance = balance;
}
