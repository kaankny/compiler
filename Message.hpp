#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <iostream>

class Message
{
	public:
		int invalidArguments();
		int invalidFile(std::string);
		int unrecognizedCharacter(int, int, char);
};


#endif