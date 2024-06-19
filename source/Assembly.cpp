#include "../include/Assembly.hpp"

Assembly::Assembly()
{
}

void Assembly::freeRegisters()
{
	for (int i = 0; i < registers.size(); i++)
	{
		registers[i].second = 1;
	}
}

int Assembly::alocateRegister()
{
	for (int i = 0; i < registers.size(); i++)
	{
		if (registers[i].second == 1)
		{
			registers[i].second = 0;
			return i;
		}
	}
	std::cout << "No registers available" << std::endl;
	exit(1);
}

void Assembly::freeRegister(int reg)
{
	if (registers[reg].second == 0)
		registers[reg].second = 1;
	else
	{
		std::cout << "Register already free" << std::endl;
		exit(1);
	}
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
			return generateAdd(leftval, rightval);
		case A_SUB:
			return generateSub(leftval, rightval);
		case A_MUL:
			return generateMul(leftval, rightval);
		case A_DIV:
			return generateDiv(leftval, rightval);
		case A_INTLIT:
			return generateLoad(node->intValue);
		default:
			exit(1);
	}
}

void Assembly::generateHeader()
{
	outputFile << "global main" << std::endl;
	outputFile << "extern printf" << std::endl;
	outputFile << "section .text" << std::endl;
	outputFile << "main:" << std::endl;
}

void Assembly::generateFooter()
{
}

int Assembly::generateLoad(int value)
{
	return 0;
}

int Assembly::generateAdd(int register1, int register2)
{
	return 0;
}

int Assembly::generateSub(int register1, int register2)
{
	return 0;
}

int Assembly::generateMul(int register1, int register2)
{
	return 0;
}

int Assembly::generateDiv(int register1, int register2)
{
	return 0;
}

void Assembly::generatePrintInt(int value)
{
}

void Assembly::compile(std::string fileName)
{
	outputFile.open(fileName);

	generateHeader();
	generatePrintInt(42);
	generateFooter();
	outputFile.close();
}