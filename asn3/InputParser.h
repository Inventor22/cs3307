#ifndef _INPUTPARSER_H
#define _INPUTPARSER_H

#include <iostream>
#include <string>

class InputParser{
public:
  static bool getInt(int& io);
  static bool getLong(long& io);
  static bool getChar(char& io);
  static bool getString(std::string& io);
  static bool getMoney(long& io);
  //Used for inputting a name or ID, retruns true if string.
  static bool getLongOrString(bool& which, std::string& strIo, long& lngIo);

  static std::string moneyToStr(long io);

private:
  // Conversion functions
  static std::string intToStr(int i);
  static std::string lngToStr(long ln);
  static int strToInt(std::string s);
  static long strToLng(std::string s);

};

#endif