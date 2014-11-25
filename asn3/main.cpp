#include <iostream>
#include <fstream>
#include "BankMember.h"
#include "TextUI.h"
#include <sys/syslog.h>

using namespace std;

int main(){

	// Initialize ui, starting debug level logging
	TextUI ui(true);

	// Log the start up time
	time_t now = time(0);
	char* dt = ctime(&now);
	syslog(LOG_INFO, "Starting up system, time is %s", dt);

	// Check for saved userbase
	ifstream dbFileIn("userDB.txt");

	if (!dbFileIn.is_open()){
		// If not found, perform first time setup (add maintainer, then admin)
		ui.setupFirstMaintainer();
		ui.setupFirstManager();
	}
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