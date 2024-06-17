#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <iostream>
#include <ctime>
#include "color.h"

class ErrorHandler
{
	public:

		void printTime()
		{
			time_t rawtime;
			struct tm * timeinfo;
			char buffer[80];

			time (&rawtime);
			timeinfo = localtime(&rawtime);

			strftime(buffer,sizeof(buffer),"%I:%M:%S",timeinfo);
			std::cout << C_BOLD << "[ " << buffer << " ]" << C_RESET << " ";
		}

		int invalidArguments()
		{
			printTime();
			std::cout << C_RED << "[ Error ]" << C_RESET << C_BOLD << " Invalid number of arguments" << C_RESET << std::endl;
			return 1;
		}

		int invalidFile(std::string fileName)
		{
			printTime();
			std::cout << C_RED << "[ Error ]" << C_RESET << C_BOLD << " Could not open file " << fileName << C_RESET << std::endl;
			return 1;
		}

		int unrecognizedCharacter(int line, int index, char c)
		{
			printTime();
			std::cout << C_RED << "[ Error ]" << C_RESET << C_BOLD << " Unrecognized character " << c << " at line " << line << ", index " << index << C_RESET << std::endl;
			return 1;
		}

		int invalidToken(int token)
		{
			printTime();
			std::cout << C_RED << "[ Error ]" << C_RESET << C_BOLD << " Invalid token " << token << C_RESET << std::endl;
			return 1;
		}
};

#endif