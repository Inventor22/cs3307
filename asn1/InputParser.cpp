
#include <iostream>
#include <string>

#include "InputParser.h"

bool InputParser::getInt(int& io){
	std::string strIn;
	std::cin >> strIn;
	if (strIn.length() > 0){  //Check that string is not 0 length.
		try{
			io = std::stoi(strIn);  //Attempt to parse to an int.
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
			io = std::stol(strIn);  //Attempt to parse to a long.
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
				io = std::stol(strIn);  //Attempt to parse to a long.
				io *= 100; //Shift to dollars
				std::string cents = strIn.substr(idx+1);
				io += std::stol(cents);
				std::cout << "\n";  //Print an extra line to look nice
				return true;
			}
			catch (std::invalid_argument e){
				return false;  //If an exception is thrown, parsing probably failed.
			}
		}
		else{ //No '.', but not 0 length
			try{
				io = std::stol(strIn);  //Attempt to parse to a long
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
			lngIo = std::stol(strIo);  //Attempt to parse to a long.
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
	std::string strRet = "$" + std::to_string(io / 100) + ".";
	if ((io % 100) <= 9){
		//If user has 0-9 cents, leading zero after decimal is dropped, make sure it is added.
		strRet += '0';
	}
	//Print cents
	strRet += std::to_string(io % 100);
	return strRet;
}