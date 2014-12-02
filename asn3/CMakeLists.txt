cmake_minimum_required(VERSION 2.8.4)
project(asn3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Bank.cpp
    Bank.h
    BankAccount.cpp
    BankAccount.h
    BankClient.cpp
    BankClient.h
    BankCreditCard.cpp
    BankCreditCard.h
    BankMaintainer.cpp
    BankMaintainer.h
    BankManager.cpp
    BankManager.h
    BankMember.cpp
    BankMember.h
    BankMemberDatabase.cpp
    BankMemberDatabase.h
    BankProfile.cpp
    BankProfile.h
    IdManager.cpp
    IdManager.h
    InputParser.cpp
    InputParser.h
    main.cpp
    TextUI.cpp
    TextUI.h)

add_executable(asn3 ${SOURCE_FILES})