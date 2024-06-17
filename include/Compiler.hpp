#ifndef COMPILER_H
#define COMPILER_H

#include <iostream>
#include <fstream>
#include <vector>

#include "ErrorHandler.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"
#include "Interpreter.hpp"
#include "Assembly.hpp"

class Compiler
{
	private:
		ErrorHandler errorHandler;
		std::string fileName;
		std::vector<std::string> code;

		Lexer lexer;
		Parser parser;
		Interpreter interpreter;
		Assembly assembly;
		void readFile(std::string fileName);

	public:
		Compiler();
		void compile(std::string fileName);
};

#endif