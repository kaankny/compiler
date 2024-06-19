#ifndef ASSEMBLY_HPP
#define ASSEMBLY_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include "Parser.hpp"
#include "ErrorHandler.hpp"

class Assembly
{
	private:
		Parser *parser;
		ErrorHandler errorHandler;
		std::ofstream outputFile;

		/*
		 * Registers vector
		 * first: register name
		 * second: register status
		 * 0: free
		 * 1: used
		*/
		std::vector<std::pair<std::string, int> > registers = {
			{"r8", 1},
			{"r9", 1},
			{"r10", 1},
			{"r11", 1}
		};

		void freeRegisters();
		int	alocateRegister();
		void freeRegister(int reg);

		void generateHeader();
		void generateFooter();

		int generateLoad(int value);
		int generateAdd(int register1, int register2);
		int generateSub(int register1, int register2);
		int generateMul(int register1, int register2);
		int generateDiv(int register1, int register2);

		void generatePrintInt(int value);
		void handleStatement();



	public:
		Assembly();
		void setParser(Parser *parser);
		int generateAssembly(ASTNode *node);

		void compile(std::string fileName);
};

#endif