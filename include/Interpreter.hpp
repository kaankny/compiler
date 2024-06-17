#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Parser.hpp"

class Interpreter
{
	private:
		int interpretAST(ASTNode *node);
		Parser *parser;
	public:
		void interpret();
		void setParser(Parser *parser);
};

#endif