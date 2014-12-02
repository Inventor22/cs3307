#include <iostream>
#include <sstream>
#include <stdexcept>

#include "InputParser.h"

bool InputParser::getInt(int& io){
    std::string strIn;
  std::cin >> strIn;
  if (strIn.length() > 0){  //Check that string is not 0 length.
    try{
      
      //Doesn't work in C98
      //io = std::stoi(strIn);  //Attempt to parse to an int.

      io = strToInt(strIn);

      std::cout << "\n";  //Print an extra line to look nice
      return true;
    }
    catch (std::invalid_argument e){
      return false;  //If an exception is thrown, parsing probably failed.
    }
  }
  else{  //I don't think cin will allow this to happen, but just in case.
    return false;
  }
}

bool InputParser::getLong(long& io){
  std::string strIn;
  std::cin >> strIn;
  if (strIn.length() > 0){  //Check that string is not 0 length.
    try{
      //Doesn't work in C98
      //io = std::stol(strIn);  //Attempt to parse to a long.
      io = strToLng(strIn);

      std::cout << "\n";  //Print an extra line to look nice
      return true;
    }
    catch (std::invalid_argument e){
      return false;  //If an exception is thrown, parsing probably failed.
    }
  }
  else{  //I don't think cin will allow this to happen, but just in case.
    return false;
  }
}

bool InputParser::getChar(char& io){
  std::string strIn;
  std::cin >> strIn;
  if (strIn.length() > 0){
    io = strIn.at(0);
    std::cout << "\n";  //Print an extra line to look nice
  }
  else
    return false;
  return true;
}

bool InputParser::getString(std::string& io){
  std::cin >> io;
  if (io.length() == 0)
    return false;
  std::cout << "\n";  //Print an extra line to look nice
  return true;
}

bool InputParser::getMoney(long& io){
  //Note that money is stored as cents as a long
  std::string strIn;
  std::cin >> strIn;
  int idx = strIn.find("$", 0);
  if (idx != std::string::npos){
    if (idx == 0){
      strIn = strIn.substr(idx+1);
    }
    else{
      return false; //Not at the first index
    }
  }
  idx = strIn.find(".", 0);
  if (strIn.length() > 0)
    if (idx != std::string::npos){
      try{
        //Doesn't work in C98
        //io = std::stol(strIn);  //Attempt to parse to a long.
        io = strToLng(strIn);

        io *= 100; //Shift to dollars
        std::string cents = strIn.substr(idx+1);

        //Doesn't work in C98
        //io += std::stol(cents);

        io += strToLng(cents);
        std::cout << "\n";  //Print an extra line to look nice
        return true;
      }
      catch (std::invalid_argument e){
        return false;  //If an exception is thrown, parsing probably failed.
      }
    }
    else{ //No '.', but not 0 length
      try{
        //Doesn't work in C98
        //io = std::stol(strIn);  //Attempt to parse to a long.
        io = strToLng(strIn);

        io *= 100; //Shift to dollars
        std::cout << "\n";  //Print an extra line to look nice
        return true;
      }
      catch (std::invalid_argument e){
        return false;  //If an exception is thrown, parsing probably failed.
      }
    }
  else
    return false;
  return true;
}

bool InputParser::getLongOrString(bool& which, std::string& strIo, long& lngIo){
  std::cin >> strIo;
  if (strIo.length() > 0){  //Check that string is not 0 length.
    try{
      //Doesn't work in C98
      //lngIo = std::stol(strIo);  //Attempt to parse to a long.
      lngIo = strToLng(strIo);
    
      which = false; //Mark that it was a long
      std::cout << "\n";  //Print an extra line to look nice
      return true;
    }
    catch (std::invalid_argument e){
      //return the string instead
      which = true;
      std::cout << "\n";  //Print an extra line to look nice
      return true;  //If an exception is thrown, parsing probably failed.
    }
  }
  else{  //I don't think cin will allow this to happen, but just in case.
    return false;
  }
}

std::string InputParser::moneyToStr(long io){
  std::string strRet = "$" + strToLng(io / 100) + ".";
  if ((io % 100) <= 9){
    //If user has 0-9 cents, leading zero after decimal is dropped, make sure it is added.
    strRet += '0';
  }
  //Print cents
  strRet += strToLng(io % 100);
  return strRet;
}

//Very basic implementation -> placeholder!
std::string InputParser::intToStr(int i){
  std::stringstream s;
  s << i;
  return s.str();
}

//Very basic implementation -> placeholder!
std::string InputParser::lngToStr(long ln){
  std::stringstream s;
  s << ln;
  return s.str();
}

//Very basic implementation -> placeholder!
int InputParser::strToInt(std::string s){
  int retVal;
  // Check if the string is a valid int
  // TODO: Check length
  for (int i=0; i < s.length(); i++)  {
    if (i == 0 && s[i]=='-')
      continue;
    if (s[i] < '0' || s[i] > '9'){
      // Throw exception

      throw std::invalid_argument("recieved value was not an integer");
    }
  }
  std::istringstream(s) >> retVal;
  return retVal;
} 

//Very basic implementation -> placeholder!
long InputParser::strToLng(std::string s){
  long ln;
  // Check if the string is a valid long
  // TODO: Check length
  for (int i=0; i < s.length(); i++)  {
    if (i == 0 && s[i]=='-')
      continue;
    if (s[i] < '0' || s[i] > '9'){
      // Throw exception

      throw std::invalid_argument("recieved value was not an integer");
    }
  }
  std::istringstream(s) >> ln;
  return ln;
}


