#include <iostream>
#include <fstream>
#include <syslog.h>

#include "TextUI_Vendor.h"
#include "Bank.h"

using namespace std; //Replace this with something else?

int main(){

  // Log the start up time
  time_t now = time(0);
  char* dt = ctime(&now);
  syslog(LOG_INFO, "Starting up system, time is %s", dt);

  // Check for saved userbase
  ifstream dbFileIn("BankDatabase.txt");

  // Intialize the bank backend
  Bank bank;

  // Initialize text ui, starting debug level debugging
  TextUI_Vendor ui(true, bank);

  // If not found, perform first time setup (add maintainer, then manager)
  if (!dbFileIn.is_open()){
    ui.setupFirstMaintainer();
    ui.setupFirstManager();
  }
    //Otherwise, read data from database
  else
    bank.readStateFromFile(dbFileIn);
  
  dbFileIn.close();

  // Process transactions until the quit flag is raised
  bool bQuit = false;
  while (!bQuit) {
    ui.processTransaction();
  
    if (ui.getShutdownStatus()) {
      bQuit = true;
    }
    }
  return 0;
}
