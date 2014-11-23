#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "BankMember.h"
#include "TextUI.h"
#include <ctime>

#include "mtk/mtktrace.hpp"
//#include "mkt\mtktrace.cpp"

using namespace std;

int main(){

	TextUI ui;
	
	mtkSetEnable(true);
	time_t now = time(0);
	char* dt = ctime(&now);
	mtklog("Starting up system, time is %s", dt);

	//Check for saved userbase
	ifstream dbFileIn("userDB.txt");

	if (!dbFileIn.is_open()){
		//If not found, perform first time setup (add maintainer, then admin)
		ui.setupFirstMaintainer();
		ui.setupFirstManager();
	}
	dbFileIn.close();

	bool bQuit = false;
	while (!bQuit){
		ui.processTransaction();
		if (ui.getShutdownStatus()){
			bQuit = true;
		}
	}

	//cout << endl;

	//bool bQuit = false;
	//while (!bQuit){
	//	//Promt to log in.
	//	long lngID;
	//	int intIdx;
	//	string strBranchName = "the Bank of Dustiness";
	//	bool bFound = false;
	//	while (!bFound){
	//		printBanner();
	//		cout << "Enter your ID to begin.\n";
	//		cin >> lngID;
	//		//Check if ID exists:
	//		for (int i = 0; i < users.size(); i++){
	//			if (users[i].getID() == lngID){
	//				bFound = true;
	//				intIdx = i;
	//				break;
	//			}
	//		}
	//		if (!bFound){
	//			cout << "\tUser with ID " << lngID << " not found.\n";
	//		}
	//	}
		
		////Find user name, and ask for pin.  Ask if they're actually that user?
		//string strName = users[intIdx].getFirstName();
		//int intPin;
		//bool bCorrect = false;
		//cout << "Welcome " << strName << "!\nPlease enter yout PIN to continue.\n";
		//for (int i = 0; i < 3; i++){
		//	cin >> intPin;
		//	if (intPin == users[intIdx].getPIN()){
		//		bCorrect = true;
		//		break;
		//	}
		//	if (i < 2)
		//		cout << "Incorrect pin, please try again (attempt " << i + 1 << "/3):\n";
		//	else
		//		cout << "Too many attempts, please contact your bank manager.\n";
		//}
		
		//If they failed the third time, throw them out.
		//if (!bCorrect){ continue; }

		//printBanner();

		//cout << "Welcome " << users[intIdx].getFirstName() << "!\n";
		//bool bContinue = true;
		//while (bContinue){
		//	switch (users[intIdx].getUserType()){
		//	case BankMember::CLIENT:
		//		cout << "Client\n";
		//		break;
		//	case BankMember::TECH:
		//		cout << "Ducks\n";
		//		break;
		//	case BankMember::MAN:
		//		cout << "Like a man\n";
		//		break;
		//	}
		//	char cont;
		//	cout << "\tWould you like to perform another transaction? (Y = y, N = any):\n";
		//	cin >> cont;
		//	if ((cont != 'y') && (cont != 'Y'))
		//		bContinue = false;
		//}

		//cout << "\tGoodbye!\n\n";
	//}

	return 0;
}