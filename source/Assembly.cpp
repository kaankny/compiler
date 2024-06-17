#include "../include/Assembly.hpp"

Assembly::Assembly()
{
}

int Assembly::generateAssembly(ASTNode *node)
{
	int leftval, rightval;

	if (node->left != nullptr)
		leftval = generateAssembly(node->left);
	if (node->right != nullptr)
		rightval = generateAssembly(node->right);

	switch (node->type)
	{
		case A_ADD:
			return generateAdd(node);
		case A_SUB:
			return generateSub(node);
		case A_MUL:
			return generateMul(node);
		case A_DIV:
			return generateDiv(node);
		case A_INTLIT:
			return generateIntLit(node);
		default:
			exit(1);
	}
}

int Assembly::generateAdd(ASTNode *node)
{
	outputFile << "ADD R0, R1, R2" << std::endl;
	return 0;
}

int Assembly::generateSub(ASTNode *node)
{
	outputFile << "SUB R0, R1, R2" << std::endl;
	return 0;
}

int Assembly::generateMul(ASTNode *node)
{
	outputFile << "MUL R0, R1, R2" << std::endl;
	return 0;
}

int Assembly::generateDiv(ASTNode *node)
{
	outputFile << "DIV R0, R1, R2" << std::endl;
	return 0;
}

int Assembly::generateIntLit(ASTNode *node)
{
	outputFile << "MOV R0, " << node->intValue << std::endl;
	return 0;
}

void Assembly::generatePrintInt(int value)
{
	outputFile << "MOV R0, " << value << std::endl;
	outputFile << "PRT R0" << std::endl;
}

void Assembly::generateHeader()
{
	outputFile << ".section .text" << std::endl;
	outputFile << ".global _start" << std::endl;
	outputFile << "_start:" << std::endl;
}

void Assembly::generateFooter()
{
	outputFile << "	MOV R7, 1" << std::endl;
	outputFile << "	MOV R0, 0" << std::endl;
	outputFile << "	SWI 0" << std::endl;
}

void Assembly::compile(std::string fileName)
{
}