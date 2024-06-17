#ifndef COMPILER_H
#define COMPILER_H

#include <iostream>
#include <fstream>
#include <vector>

#include "Lexer.hpp"
#include "Message.hpp"

class Lexer;
class Message;

class Compiler
{
	private:
		
		std::string fileName;
		std::vector<std::string> code;

		Lexer lexer;
		Message errorHandler;
		void readFile(std::string fileName);
	public:
		Compiler();
		void compile(std::string fileName);
};

#endif