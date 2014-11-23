#include <iostream>
#include <fstream>
#include "BankMember.h"
#include "TextUI.h"
#include <sys/syslog.h>

using namespace std;

int main(){

	TextUI ui(true);

    // Start logging, default to full traces for now.
	openlog("bank_sim", LOG_PID | LOG_NDELAY, LOG_USER);
    setlogmask(LOG_UPTO(LOG_DEBUG));

	time_t now = time(0);
	char* dt = ctime(&now);
	syslog(LOG_INFO, "Starting up system, time is %s", dt);

	//Check for saved userbase
	ifstream dbFileIn("userDB.txt");

	if (!dbFileIn.is_open()){
		//If not found, perform first time setup (add maintainer, then admin)
		ui.setupFirstMaintainer();
		ui.setupFirstManager();
	}
	dbFileIn.close();

	bool bQuit = false;
	while (!bQuit) {
        ui.processTransaction();
        if (ui.getShutdownStatus()) {
            bQuit = true;
        }
    }

	return 0;
}