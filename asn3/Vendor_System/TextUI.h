#ifndef _TEXTUI_H
#define _TEXTUI_H

#include "Bank.h"
#include "BankMember.h"

class TextUI{
private:
  //BankMember currUser;
  //BankMember::UserType currUserType;
  //Database will be a member eventually
  Bank &_bank;
  bool _bLogging;
  bool _bShutdown;

public:
  TextUI(bool logging, Bank &bank);
  ~TextUI();
  void displayHeader();
  
  bool processTransaction();

  bool getShutdownStatus();

private:
  //General functions
  BankMember* promptForId();
  bool promptForPin(BankMember* user);
  bool isValidPIN(int pin);  //Makes sure that a pin is valid when it is inputted.

  //Manager functions
  bool processManagerTransaction(BankManager* user);

  //Maintainer functions
  bool processMaintainerTransaction(BankMaintainer* user);

  //Client functions
  bool processClientTransaction(BankClient* user);
  long purchase(BankClient* client);
  void viewPurchases(BankClient* client);
  //long removeMoneyFromChequing(BankClient* client, long amount);

};

#endif
