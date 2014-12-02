#include "BankMember.h"

BankMember::BankMember(std::ifstream& is) {
  readFromFile(is);
}

BankMember::BankMember(std::ifstream& is, int memType) {
  is >> _id >> _pin >> _firstName >> _lastName;
  _memberType = (BankMember::MemberType) memType;
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
  o << getId() << " " << getPin() << " " << getFirstName() << " " << getLastName() << std::endl;
};

void BankMember::readFromFile(std::ifstream& i) {
  int memberType;
  i >> memberType >> _id >> _pin >> _firstName >> _lastName;
  _memberType = (BankMember::MemberType) memberType;
}

