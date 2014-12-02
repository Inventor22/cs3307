#include "BankMemberDatabase.h"

void printAccountDetails(BankClient* bc, BankAccount::AccountType accountType);

BankMemberDatabase::BankMemberDatabase() {

}

// return enum for user type, take in id.
//BankMember::MemberType getMemberType(unsigned long id) {
//  BankMemberItr bankMemberItr = bankMembers.find(id);
//  if (bankMemberItr != bankMembers.end()) {
//    return bankMemberItr->second.getMemberType();
//  }
//  return BankMember::UNASSIGNED;
//}

BankMember* BankMemberDatabase::getBankMember(unsigned long id) {
  BankMemberItr bankMemberItr = bankMembers.find(id);
  if (bankMemberItr != bankMembers.end()) {
    return (bankMemberItr->second);
  }
  return NULL;
}

bool BankMemberDatabase::addBankMember(BankMember* bankMember) {
  bankMembers.insert(MemberPair(bankMember->getId(), bankMember));
  if (bankMember->getMemberType() == BankMember::CLIENT) {
    //if (BankClient* client = dynamic_cast<BankClient*>(bankMember)) {
    //  BankAccount* ba = NULL;
    //  if (client->hasChequing()) {
    //    ba = client->getAccount(BankAccount::CHECKING);
    //    bankAccounts.insert(AccountPair(ba->getAccountId(), ba));
    //  }
    //  if (client->hasSavings()) {
    //    ba = client->getAccount(BankAccount::SAVING);
    //    bankAccounts.insert(AccountPair(ba->getAccountId(), ba));
    //  }
    //}
  }
  return true;
}

bool BankMemberDatabase::deleteBankMember(unsigned long id) {
  BankMemberItr bankMemberItr = bankMembers.find(id);
  if (bankMemberItr != bankMembers.end()) {
    //BankMember deletedMember = BankMember(bankMemberItr->second);
    bankMembers.erase(bankMemberItr);
    return true;
  }
  return false;
}

bool BankMemberDatabase::addBankAccount(unsigned long bankMemberId, BankAccount::AccountType accountType) {
  unsigned long id = BankMemberDatabase::generateNewBankAccountId();
  if (BankClient* member = dynamic_cast<BankClient*>(getBankMember(bankMemberId))) {
    member->addAccount(accountType, id);
    bankAccounts.insert(AccountPair(id, member->getAccount(accountType)));
    return true;
  }
  return false;
}

bool BankMemberDatabase::deleteBankAccount(unsigned long id) {
  BankAccountItr bankAccountItr = bankAccounts.find(id);
  if (bankAccountItr != bankAccounts.end()) {
    //BankMember deletedMember = BankMember(bankMemberItr->second);
    bankAccounts.erase(bankAccountItr);
    return true;
  }
  return false;
}

void BankMemberDatabase::loadDatabaseFromFile(std::ifstream& is) {

  BankMember::MemberType memberType;
  int memInt;

  // First string cannot be an account - eat it for now
  std::string type;

  is >> type;

  while (is >> memInt) {

    if (0 <= memInt && memInt <= 4)
      memberType = (BankMember::MemberType)memInt;

    switch (memberType) {
      case BankMember::CLIENT:
        {
          BankClient* bankClient = new BankClient(is);
          bankMembers.insert(MemberPair(bankClient->getId(), bankClient));
          is >> type;
          if (type.compare("Account") == 0)
          {
            // TODO: Parse accounts
            BankAccount bankAccount(is);
            bankClient->setAccount(bankAccount);
          }
        }
        break;
      case BankMember::MANAGER:
        {
          BankManager* bankManager = new BankManager(is);
          bankMembers.insert(MemberPair(bankManager->getId(), bankManager));
          // Eat the next line
          is >> type;
        }
        break;
      case BankMember::MAINTENANCE:
        {
          BankMaintainer* bankMaintainer = new BankMaintainer(is);
          bankMembers.insert(MemberPair(bankMaintainer->getId(), bankMaintainer));
          // Eat the next line
          is >> type;
        }
        break;
      default:
        break;
    }
  }

}

void BankMemberDatabase::writeDatabaseToFile(std::ofstream& os) {
  for (BankMemberItr itr = bankMembers.begin(); itr != bankMembers.end(); ++itr) {
    BankMember *bankMember = itr->second;

    // Again, my IDE is only ok with this on two lines.
    os << bankMember->getMemberType() << " " << bankMember->getId();
    os << " " << bankMember->getPin() << " " << bankMember->getFullName() << " ";

    if (bankMember->getMemberType() == BankMember::CLIENT) {
      if (BankClient *bankClient = dynamic_cast<BankClient*>(bankMember)) {
        BankAccount* ba = NULL;
        if (bankClient->hasChequing()) {
          ba = bankClient->getAccount(BankAccount::CHECKING);
          os << "Account " << ba->getAccountType() << " " << ba->getAccountId() << " " << ba->getBalance() << " ";
        }
        if (bankClient->hasSavings()) {
          ba = bankClient->getAccount(BankAccount::SAVING);
          os << "Account " << ba->getAccountType() << " " << ba->getAccountId() << " " << ba->getBalance() << " ";
        }
      }
    }
    os << std::endl;
  }
}

// Unknown usage, deprecated
//void printAccountDetails(BankClient* bc, BankAccount::AccountType accountType, std::ofstream& os) {
//  BankAccount* ba = bc->getAccount(accountType);
//  os << " " << ba->getAccountType() << " " << ba->getAccountId() << ba->getBalance() << " ";
//}

unsigned long BankMemberDatabase::generateNewBankMemberId() {
  return IdManager::generateNewUniqueId(bankMembers);
}

unsigned long BankMemberDatabase::generateNewBankAccountId() {
  return IdManager::generateNewUniqueId(bankAccounts);
}

void BankMemberDatabase::processMonthlyCreditPayments() {
    for (BankMemberItr itr = bankMembers.begin(); itr != bankMembers.end(); ++itr) {
        BankMember* b = itr->second;
        if (BankClient* member = dynamic_cast<BankClient*>(b)) {
            if (member->hasChequing()) {
                member->payCreditCard();
            }
        }
    }
}

