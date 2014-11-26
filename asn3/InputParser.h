#pragma once

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
	static std::string trn_string(int i);
	static int to_int(std::string s);
	static int to_long(std::string s);

};

