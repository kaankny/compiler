#include "Compiler.hpp"

Compiler::Compiler()
{
}

void Compiler::compile(std::string fileName)
{
	this->readFile(fileName);
	this->lexer.initLexer(this->code);
	while (1)
	{
		TokenValue token = this->lexer.getNextToken();
		if (token.token == T_EOF)
			break;
		if (token.token == T_PLUS)
			std::cout << "PLUS" << std::endl;
		else if (token.token == T_MINUS)
			std::cout << "MINUS" << std::endl;
		else if (token.token == T_STAR)
			std::cout << "STAR" << std::endl;
		else if (token.token == T_SLASH)
			std::cout << "SLASH" << std::endl;
		else if (token.token == T_INTLIT)
			std::cout << "INTLIT " << token.value << std::endl;
	}
}

void Compiler::readFile(std::string fileName)
{
	this->fileName = fileName;
	std::ifstream inputFile(fileName);
	if (!inputFile.is_open())
		exit(this->errorHandler.invalidFile(fileName));
	std::string line;
	while (std::getline(inputFile, line))
		this->code.push_back(line);
	inputFile.close();
}