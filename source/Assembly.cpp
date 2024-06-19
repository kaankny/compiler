#include "../include/Assembly.hpp"
#include "../include/Parser.hpp"

Assembly::Assembly()
{
}

void Assembly::setParser(Parser *parser)
{
	this->parser = parser;
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
	exit(errorHandler.notRegisterAvailable());
}

void Assembly::freeRegister(int reg)
{
	if (registers[reg].second == 0)
		registers[reg].second = 1;
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
			exit(errorHandler.invalidNodeType(node->type));
	}
}

void Assembly::generateHeader()
{
	outputFile << "global main" << std::endl;
	outputFile << "extern printf\n" << std::endl;
	outputFile << "section .text\n" << std::endl;
	outputFile << "main:" << std::endl;
	outputFile << "	sub rsp, 60" << std::endl;
	outputFile << std::endl;
}

void Assembly::generateFooter()
{
	outputFile << "	add rsp, 60" << std::endl;
	outputFile << "	ret" << std::endl;
	outputFile << std::endl;
	outputFile << "section .data" << std::endl;
	outputFile << "	format db \"%d\", 10, 0" << std::endl;
	outputFile << std::endl;
}

int Assembly::generateLoad(int value)
{
	int reg = alocateRegister();
	outputFile << "	mov " << registers[reg].first << ", " << value << std::endl;
	outputFile << std::endl;
	return reg;
}

int Assembly::generateAdd(int register1, int register2)
{
	outputFile << "	add " << registers[register1].first << ", " << registers[register2].first << std::endl;
	outputFile << std::endl;
	freeRegister(register2);
	return register1;
}

int Assembly::generateSub(int register1, int register2)
{
	outputFile << "	sub " << registers[register1].first << ", " << registers[register2].first << std::endl;
	outputFile << std::endl;
	freeRegister(register2);
	return register1;
}

int Assembly::generateMul(int register1, int register2)
{
	outputFile << "	imul " << registers[register1].first << ", " << registers[register2].first << std::endl;
	outputFile << std::endl;
	freeRegister(register2);
	return register1;
}

int Assembly::generateDiv(int register1, int register2)
{
	outputFile << "	mov rax, " << registers[register1].first << std::endl;
	outputFile << "	cqo" << std::endl;
	outputFile << "	idiv " << registers[register2].first << std::endl;
	outputFile << "	mov " << registers[register1].first << ", rax" << std::endl;
	outputFile << std::endl;
	freeRegister(register2);
	return register1;
}

void Assembly::generatePrintInt(int value)
{
	outputFile << "	lea rcx, [rel format]" << std::endl;
	outputFile << "	mov rdx, " << registers[value].first << std::endl;
	outputFile << "	call printf" << std::endl;
	outputFile << std::endl;
	freeRegister(value);
}

void Assembly::compile(std::string fileName)
{
	int reg;
	outputFile.open(fileName);

	generateHeader();
	handleStatement();
	generateFooter();
	outputFile.close();

	system("nasm -o output.obj -fwin64 output.asm");
	system("gcc -m64 output.obj -o a.exe");
}

void Assembly::handleStatement()
{
	ASTNode *tree;
	int reg;

	while (1)
	{
		this->parser->eatToken(T_PRINT);
		tree = this->parser->parseTerm(0);
		reg = generateAssembly(tree);
		generatePrintInt(reg);
		freeRegisters();
		this->parser->eatToken(T_SEMI);
		if (this->parser->getLexer()->getCurrentToken().token == T_EOF)
			return ;
	}
}
