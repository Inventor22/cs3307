#include "BankMember.h"

// Deprecated
BankMember::BankMember(std::ifstream& is) {
  readFromFile(is);
}

BankMember::BankMember(std::string firstName,
             std::string lastName,
             unsigned int pin,
             BankMember::MemberType memberType) :
             _firstName(firstName),
             _lastName(lastName),
             _pin(pin),
             _memberType(memberType) {
}

BankMember::BankMember(std::string firstName,
       std::string lastName,
       unsigned long id,
       unsigned int pin,
       BankMember::MemberType memberType) :
       _firstName(firstName),
       _lastName(lastName),
       _id(id), _pin(pin),
       _memberType(memberType) {
}

void BankMember::setPin(unsigned int pin) {
  _pin = pin;
}

unsigned int BankMember::getPin() const {
  return _pin;
}

unsigned long BankMember::getId() {
  return _id;
}

std::string BankMember::getFirstName() const {
  return _firstName;
}

std::string BankMember::getLastName() const {
  return _lastName;
}

std::string BankMember::getFullName() const {
  std::string fN = _firstName;
  fN = fN.append(" ").append(_lastName);
  return fN;
}

void BankMember::setFirstName(std::string firstName) {
  _firstName = firstName;
}

void BankMember::setLastName(std::string lastName) {
  _lastName = lastName;
}

BankMember::MemberType BankMember::getMemberType() {
  return _memberType;
}

void BankMember::writeToFile(std::ofstream& o) {
  // For some reason my IDE wants this done on two lines
  o << _memberType << " " << _id << " " << _pin << " ";
  o << _firstName << " " << _lastName;
};

void BankMember::readFromFile(std::ifstream& i) {
  i >> _id >> _pin >> _firstName >> _lastName;
}

