all: main

main: main.o Bank.o BankAccount.o BankMember.o BankMemberDatabase.o BankProfile.o IdManager.o BankManager.o BankClient.o IdManager.o BankMaintainer.o TextUI.o InputParser.o 
	g++ main.o Bank.o BankAccount.o BankMember.o BankMemberDatabase.o BankProfile.o IdManager.o BankManager.o BankClient.o BankMaintainer.o TextUI.o InputParser.o -o main

main.o: main.cpp BankMember.h TextUI.h
	g++ -c main.cpp

Bank.o: Bank.cpp Bank.h BankManager.h BankMaintainer.h BankClient.h IdManager.h BankMemberDatabase.h
	g++ -c Bank.cpp

BankAccount.o: BankAccount.cpp BankAccount.h
	g++ -c BankAccount.cpp

BankMember.o: BankMember.cpp BankMember.h
	g++ -c BankMember.cpp

BankMemberDatabase.o: BankMemberDatabase.cpp BankMember.h BankClient.h BankManager.h BankMaintainer.h IdManager.h BankMemberDatabase.h
	g++ -c BankMemberDatabase.cpp

BankProfile.o: BankProfile.h
	g++ -c BankProfile.cpp

BankClient.o: BankAccount.h BankMember.h IdManager.h BankClient.h BankClient.cpp
	g++ -c BankClient.cpp 

BankManager.o: BankManager.cpp BankManager.h BankMember.h
	g++ -c BankManager.cpp

IdManager.o: IdManager.cpp IdManager.h BankMember.h BankAccount.h
	g++ -c IdManager.cpp

InputParser.o: InputParser.cpp InputParser.h
	g++ -c InputParser.cpp

TextUI.o: TextUI.cpp Bank.h BankMember.h TextUI.h BankClient.h BankMaintainer.h BankManager.h BankMemberDatabase.h
	g++ -c TextUI.cpp

BankMaintainer.o: BankMaintainer.cpp BankMember.h BankMaintainer.h
	g++ -c BankMaintainer.cpp

clean:
	rm -rf *o main
