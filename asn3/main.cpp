#include <iostream>
#include <fstream>
#include <syslog.h>
#include "BankMember.h"
#include "TextUI.h"
#include "Bank.h"

#include "TextUI.h" //See TextUI object below

using namespace std; //Replace this with something else?

int main(){

	// Log the start up time
	time_t now = time(0);
	char* dt = ctime(&now);
	syslog(LOG_INFO, "Starting up system, time is %s", dt);

	// Initialize text ui, starting debug level debugging
	TextUI ui(true);
	Bank

	// Check for saved userbase
	ifstream dbFileIn("BankDatabase.txt");
	
	// If not found, perform first time setup (add maintainer, then manager)
	if (!dbFileIn.is_open()){
		ui.setupFirstMaintainer();
		ui.setupFirstManager();
	}
	//Otherwise, read data from database
	else
		ui.loadDatabase();
	
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
