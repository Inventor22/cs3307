#ifndef BANKMEMBER_H
#define BANKMEMBER_H

#include <iostream>
#include <fstream>
#include <string>

class BankMember {

public:
  typedef enum MemberType { MANAGER = 0, CLIENT = 1, MAINTENANCE = 2 };

protected:
  std::string _firstName;
  std::string _lastName;
  int _phoneNumber;
  unsigned long _id;
  unsigned int _pin;
  MemberType _memberType;

public:
  BankMember(std::ifstream& is);

  BankMember(std::string firstName,
         std::string lastName,
         unsigned int pin,
         MemberType memberType);

  BankMember(std::string firstName,
         std::string lastName,
         unsigned long id,
         unsigned int pin,
         MemberType memberType);

  void setPin(unsigned int pin);

  unsigned int getPin() const;

  unsigned long getId();

  std::string getFirstName() const;

  std::string getLastName() const;

  std::string getFullName() const;

  void setFirstName(std::string firstName);

  void setLastName(std::string lastName);

  MemberType getMemberType();

protected:
  virtual void writeToFile(std::ofstream& o);

  void readFromFile(std::ifstream& i);
};

#endif

