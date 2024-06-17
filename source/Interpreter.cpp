#include "../include/Interpreter.hpp"

void Interpreter::interpret()
{
	ASTNode *root = parser->parseTerm(0);
	std::cout << interpretAST(root) << std::endl;
}

void Interpreter::setParser(Parser *parser)
{
	this->parser = parser;
}

int Interpreter::interpretAST(ASTNode *node)
{
	int leftval, rightval;

	if (node->left != nullptr)
		leftval = interpretAST(node->left);
	if (node->right != nullptr)
		rightval = interpretAST(node->right);

	switch (node->type)
	{
		case A_ADD:
			return leftval + rightval;
		case A_SUB:
			return leftval - rightval;
		case A_MUL:
			return leftval * rightval;
		case A_DIV:
			return leftval / rightval;
		case A_INTLIT:
			return node->intValue;
		default:
			exit(1);
	}
}