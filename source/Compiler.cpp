#include "../include/Compiler.hpp"

Compiler::Compiler()
{
	this->lexer = Lexer();
	this->parser = Parser();
	this->interpreter = Interpreter();
	this->errorHandler = ErrorHandler();
	this->parser.setLexer(&this->lexer);
	this->interpreter.setParser(&this->parser);
}


void Compiler::compile(std::string fileName)
{
	this->readFile(fileName);
	this->lexer.initLexer(this->code);
	lexer.getNextToken();
	this->interpreter.interpret();
	this->assembly.compile("output.asm");
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
