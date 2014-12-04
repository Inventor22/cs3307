#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

#include <syslog.h>
#include <fstream>

#include "TextUI.h"

#include "InputParser.h"

#include "BankClient.h"
#include "BankMaintainer.h"
#include "BankManager.h"
#include "BankMemberDatabase.h"

TextUI::TextUI(bool logging, Bank &bank) : _bank(bank){
    _bShutdown = false;
    _bLogging = logging;
    if (logging){
        setlogmask(LOG_UPTO(LOG_DEBUG));
    }
    else {
        setlogmask(LOG_UPTO(LOG_INFO));
    }
}

TextUI::~TextUI(){
  //Nothing to release.
}

void TextUI::displayHeader(){
  syslog(LOG_DEBUG, "displayHeader() entered");
  std::cout << "\n" << "****************************************************" << std::endl
    << "\tVendor Machine v0.9c.b42" << std::endl
    << "****************************************************" << std::endl << std::endl;
  syslog(LOG_DEBUG, "displayHeader() exited");
  return;
}

bool TextUI::processTransaction(){
  syslog(LOG_DEBUG, "processTransaction() entered");
  bool successful = true;
  //Get user ID
  BankMember* user = promptForId();
  //Get user to input their PIN, and confirm that they're ok
  if (!promptForPin(user)){
    syslog(LOG_DEBUG, "processTransaction() exited");
    return true;  //Exit, but don't shutdown
  }
  bool cont = true;

  while (cont){
    //User has entered correct PIN, check user type and continue:
    if (BankManager * bm = dynamic_cast<BankManager*>(user)){
      cont = processManagerTransaction(bm);
    }
    else if (BankMaintainer * bt = dynamic_cast<BankMaintainer*>(user)){
      cont = processMaintainerTransaction(bt);
    }
    else if (BankClient * bc = dynamic_cast<BankClient*>(user)){
      cont = processClientTransaction(bc);
    }
    else{
      //Should be unreachable, will just end if user does not have a type
      syslog(LOG_ERR, "Reached unreachable case. Invalid type.");
      break;
      cont = false;
    }

    //If user cancels before selecting a transation, it returns false and quits immediately,
    if (!cont){
      break;
    }

    //Otherwise they are prompted below
    char choice;
    std::cout << "\nWould you like to make another transaction?  Yes=y/Y, No=Any\n";  //Space out with extra newline
    while (cont){
      if (!InputParser::getChar(choice)){
        std::cout << "Invalid choice, please try again:\n";
        continue;
      }
      if ((choice == 'y') || (choice == 'Y')){
        cont = true;
        break;
      }
      else {
        cont = false;
        break;
      }
    }
  }

  std::cout << "Goodbye " << user->getFirstName() << "!\n";

  //Check if it is time to shut down
  if (_bShutdown == true){
    successful = false;
  }

  syslog(LOG_DEBUG, "processTransaction() exited");
  return successful;
}

bool TextUI::getShutdownStatus(){
  return _bShutdown;
}

BankMember* TextUI::promptForId(){
  syslog(LOG_DEBUG, "promptForID() entered");
  //Promt to log in.
  long lngID;
  int intIdx;
  BankMember* member = NULL;
  bool bFound = false;
  while (!bFound){
    displayHeader();
    std::cout << "Enter your ID to begin.\n";
    if (!InputParser::getLong(lngID)){
      std::cout << "Invalid ID, please try again.\n";
      continue;
    }
    if ((member = _bank.getBankMember(lngID)) == NULL){
      std::cout << "\tUser with ID " << lngID << " not found.\n";
    }
    else{
      bFound = true;
    }
  }
  syslog(LOG_DEBUG, "promptForID() exited");
  return member;
}

bool TextUI::promptForPin(BankMember* user) {
  syslog(LOG_DEBUG, "promptForPin(BankMember) entered");
  bool successful = true;
  char attempts = 0;
  long pin;
  std::cout << "Hello " << user->getFirstName() << ", please enter your PIN to login.\n";
  while ((!InputParser::getLong(pin)) || (pin != user->getPin())) {
    attempts++;
    if (attempts >= 3) {
      std::cout << "Maximum login attempt count exceeded.\n\n";
      syslog(LOG_DEBUG, "promptForPin(BankMember) exited");
      return false;
    }
    std::cout << "You have entered the incorrect PIN, please try again ("
        << attempts + 1 << "/3):\n";
  }
  syslog(LOG_DEBUG, "promptForPin(BankMember) exited");
  return successful;
}

bool TextUI::isValidPIN(int pin){
  syslog(LOG_DEBUG, "isValidPin(int) entered");
  // Pin must be 4 digits and positive
  bool isValid = (pin < 10000) && (pin>999);
  syslog(LOG_DEBUG, "isValidPin(int) exited");
  return isValid;
}

bool TextUI::processManagerTransaction(BankManager* user){
  syslog(LOG_DEBUG, "processManagerTransaction(BankMember) entered");
  bool successful = true;
  std::cout 
      << "====================================\n"
      << "  Welcome manager " << user->getFirstName() << "!\n"
      << "====================================\n"
      << "There are no manager transactions\n"
      << "on this machine, please enter a\n"
      << "character to retrun the the idle\n"
      << "screen:n\"
      << "------------------------------------\n   ";
  char choice;
  // Dont' care what they input, just get something so they can
  // see the message.
  InputParser::getChar(choice);

  syslog(LOG_DEBUG, "processManagerTransaction(BankMember) exited");
  return successful;
}

bool TextUI::processMaintainerTransaction(BankMaintainer* user){
  syslog(LOG_DEBUG, "processMaintainerTransaction(BankMember) entered");
  bool successful = true;
  std::cout
      << "====================================\n"
      << "  Welcome manager " << user->getFirstName() << "!\n"
      << "====================================\n"
      << "There are no manager transactions\n"
      << "on this machine, please enter a\n"
      << "character to retrun the the idle\n"
      << "screen:n\"
      << "------------------------------------\n   ";
  char choice;
  // Dont' care what they input, just get something so they can
  // see the message.
  InputParser::getChar(choice);

  syslog(LOG_DEBUG, "processMaintainerTransaction(BankMember) exited");
  return successful;
}

bool TextUI::processClientTransaction(BankClient* user){
  syslog(LOG_DEBUG, "processClientTransaction(BankMember) entered");
  bool cont = true;
  //Check if there is a complimentary account
  bool bMissingComplimentary = !((user->hasChequing())&&(user->hasSavings()));
  int i = 5;
  std::cout 
      << "============================\n"
      << "  Welcome user " << user->getFirstName() << "!\n"
      << "============================\n"
      << "Please select a transaction:\n"
      << "  (1) -- Purchase\n"
      << "  (2) -- Deposit\n"
      << "  (3) -- Transfer\n"
      << "  (4) -- View Balances\n";
  std::cout << "----------------------------\n   ";
  char choice;
  bool bBreak;
  while (!InputParser::getChar(choice) || !((choice >= '1') && (choice <= '5'))){
    if ((choice==6)&&(!bMissingComplimentary)){ //Add complimentary not valid if user has both already
      std::cout << "Invalid choice, please try again.\n\n";
      continue;
    }
    else if (choice == '6'){
      //If user presses 6 and does not have missing accounts, they have cancelled
      break;
    }
  }
  switch (choice){
  case '1':
    purchase(user);
    break;
  case '2':
    viewPurchases(user);
    break;
  default:
    //Should be unreachable
    syslog(LOG_ERR, "Reached unreachable case. Invalid type.");
    break;
  }
  
  syslog(LOG_DEBUG, "processClientTransaction(BankMember) exited");
  return cont;
}

long TextUI::purchase(BankClient* client){
  syslog(LOG_DEBUG, "withdrawal(BankClient*) entered");
  long amount = 0;
  //Print out balances
  //balances(client);
  //Ask which account to withdraw from
  bool hasChequing = client->hasChequing();
  bool hasSavings  = client->hasSavings();
  bool fromChequing;
  char choice;

  std::cout << "Withdraw from:\n";
  if ((hasChequing) && (hasSavings)){
    std::cout << "  (1) - Chequing\n"
      << "  (2) - Savings\n";
    while (!InputParser::getChar(choice) || !((choice == '1') || (choice == '2'))){
      std::cout << "Invalid choice. Please try again:\n";
    }
    if (choice == '1'){
      fromChequing = true;
    }
    else{
      fromChequing = false;
    }
  }
  else if (hasChequing){
    std::cout << "  (1) - Chequing\n";
    while (!InputParser::getChar(choice) || choice != '1'){
      std::cout << "Invalid choice. Please try again:\n";
    }
    fromChequing = true;
  }
  else{ // hasSavings must be true
    std::cout << "  (1) - Savings\n";
    while (!InputParser::getChar(choice) || choice != '1'){
      std::cout << "Invalid choice. Please try again:\n";
    }
    fromChequing = false;
  }

  //Get Amount
  std::cout << "How much would you like to withdraw?\n";
  while (!InputParser::getMoney(amount)){
    std::cout << "Invalid entry, please try again:\n";
  }

  //Actually do withdrawal
  if (fromChequing){
    amount = removeMoneyFromChequing(client, amount);
  }
  else{
    amount = removeMoneyFromSavings(client, amount);
  }

  if (fromChequing){
    std::cout << InputParser::moneyToStr(amount) << " withdrawn from chequing account.\n";
    std::cout << "Your new chequing balance is " << InputParser::moneyToStr(client->checkChequingBalance()) << ".\n";
  }
  else{
    std::cout << InputParser::moneyToStr(amount) << " withdrawn from savings account.\n";
    std::cout << "Your new savings balance is " << InputParser::moneyToStr(client->checkSavingsBalance()) << ".\n";
  }

  syslog(LOG_DEBUG, "withdrawal(BankClient*) exited");
  return amount;
}

void TextUI::balances(BankClient* client){
  syslog(LOG_DEBUG, "balances(BankClient*) entered");
  bool hasChequing = client->hasChequing();
  bool hasSavings = client->hasSavings();

  std::cout << "Balance(s):\n";
  if (hasChequing){
    std::cout << "  Chequing: " << InputParser::moneyToStr(client->checkChequingBalance()) << "\n";
  }
  if (hasSavings){
    std::cout << "  Savings:  " << InputParser::moneyToStr(client->checkSavingsBalance()) << "\n";
  }
  syslog(LOG_DEBUG, "balances(BankClient*) entered");
  return;
}

long TextUI::removeMoneyFromChequing(BankClient* client, long amount){
  syslog(LOG_DEBUG, "removeMoneyFromChequing(BankClient*,long) entered");
  if (amount > client->checkChequingBalance()){
    std::cout << "Error: Insufficient funds.\n";
    amount=0;
  }
  else if ((client->checkChequingBalance() > 100000) && ((client->checkChequingBalance()-amount) < 100000)){
    char choice;
    std::cout << "Warning: this transaction will cause your chequing balance to fall below $1000.00.\n"
      << "This transaction, and all subsequent transactions removing money from your chequing account while it contains less than $1000.00 "
      << "will cost an additonal fee of $2.00.\n"
      << "Are you sure you want to continue?\n"
      << "Yes = Y/y, No = Any other";
    while (!InputParser::getChar(choice)){
      std::cout << "Invalid input, please try again:\n";
    }
    if ((choice == 'Y') || (choice == 'y')){
            client->getAccount(BankAccount::CHECKING)->withdrawal(amount + 200);
    }
    else{
      amount = 0;
    }
  }
  else if (client->checkChequingBalance() < 100000){
    char choice;
    std::cout << "Warning: your chequing balance is below $1000.00.\n"
      << "This transaction will cost an additonal fee of $2.00.\n"
      << "Are you sure you want to continue?\n"
      << "Yes = Y/y, No = Any other";
    while (!InputParser::getChar(choice)){
      std::cout << "Invalid input, please try again:\n";
    }
    if ((choice == 'Y') || (choice == 'y')){
            client->getAccount(BankAccount::CHECKING)->withdrawal(amount + 200);
    }
    else{
      amount = 0;
    }
  }
  else { //Has enough money, won't incur an extra fee
        client->getAccount(BankAccount::CHECKING)->withdrawal(amount);
  }

  syslog(LOG_DEBUG, "removeMoneyFromChequing(BankClient*,long) exited");
  return amount;
}
