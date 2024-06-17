#ifndef ASSEMBLY_HPP
#define ASSEMBLY_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include "Parser.hpp"

class Assembly
{
	private:
		std::ofstream outputFile;

		void generateHeader();
		void generateFooter();

		int generateAdd(ASTNode *node);
		int generateSub(ASTNode *node);
		int generateMul(ASTNode *node);
		int generateDiv(ASTNode *node);
		int generateIntLit(ASTNode *node);

		void generatePrintInt(int value);

	public:
		Assembly();
		int generateAssembly(ASTNode *node);

		void compile(std::string fileName);
};

#endif