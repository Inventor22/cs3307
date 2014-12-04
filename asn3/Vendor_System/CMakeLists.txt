cmake_minimum_required(VERSION 2.8.4)
project(Vendor_System)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

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
    CreditState.cpp
    CreditState.h
    IdManager.cpp
    IdManager.h
    InputParser.cpp
    InputParser.h
    main.cpp
    NormalCreditState.cpp
    NormalCreditState.h
    TextUI_Vendor.cpp
    TextUI_Vendor.h)

add_executable(vendor ${SOURCE_FILES})