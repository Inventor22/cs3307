//Contains code initializing the Text UI, reading in from database (if applicable), and quitting the program!
//Made for CS3307A Final Project
#include <iostream>
#include <fstream>

#include "TextUI.h" //See TextUI object below

using namespace std; //Replace this with something else?

//PURPOSE: control centre
//RETURNS: 0 aka program done
int main(){

	// Initialize text ui
	TextUI ui;

	// Check for saved userbase
	ifstream dbFileIn("BankDatabase.txt");
	
	// If not found, perform first time setup (add maintainer, then manager)
	if (!dbFileIn.is_open()){
		ui.setupFirstMaintainer();
		ui.setupFirstManager();
	}
	//Otherwise, read data from database
	else
		ui.readFromBase();
	
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
