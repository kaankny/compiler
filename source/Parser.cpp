#include "../include/Parser.hpp"

void Parser::setLexer(Lexer *lexer)
{
	this->lexer = lexer;
}

ASTNode *Parser::generateAST(ASTNodeType type, ASTNode *left, ASTNode *right, int value)
{
	ASTNode *node = new ASTNode();
	node->type = type;
	node->left = left;
	node->right = right;
	node->intValue = value;
	return node;
}

ASTNode *Parser::generateLeaf(ASTNodeType type, int value)
{
	return generateAST(type, nullptr, nullptr, value);
}

ASTNode *Parser::generateUnary(ASTNodeType type, ASTNode *left, int value)
{
	return generateAST(type, left, nullptr, value);
}

ASTNodeType Parser::getTokenASTType(Token token)
{
	switch (token)
	{
		case T_PLUS:
			return A_ADD;
		case T_MINUS:
			return A_SUB;
		case T_STAR:
			return A_MUL;
		case T_SLASH:
			return A_DIV;
		case T_INTLIT:
			return A_INTLIT;
		default:
			exit(errorHandler.invalidToken(token));
	}
}

ASTNode *Parser::parsePrimary()
{
	ASTNode *node;
	TokenValue token = lexer->getCurrentToken();
	switch (token.token)
	{
		case T_INTLIT:
			node = generateLeaf(A_INTLIT, token.value);
			this->lexer->getNextToken();
			return node;
		default:
			exit(errorHandler.invalidToken(token.token));
	}
}

ASTNode *Parser::parseTerm(int predenceLevel)
{
	ASTNode *node, *left, *right;
	ASTNodeType type;

	left = parsePrimary();

	TokenValue token = lexer->getCurrentToken();
	if (token.token == T_SEMI)
		return left;

	while (precedence(token.token) > predenceLevel)
	{
		lexer->getNextToken();
		right = parseTerm(precedence(token.token));
		left = generateAST(getTokenASTType(token.token), left, right, 0);
		token = lexer->getCurrentToken();
		if (token.token == T_SEMI)
			break;
	}
	return left;
}

ASTNode *Parser::parseAddition()
{
	/*
	ASTNode *left, *right;

	left = parseMultiplication();

	TokenValue token = lexer->getCurrentToken();
	if (token.token == T_SEMI)
		return left;
	
	while (1)
	{
		lexer->getNextToken();
		right = parseMultiplication();
		left = generateAST(getTokenASTType(token.token), left, right, 0);
		token = lexer->getCurrentToken();
		if (token.token == T_SEMI)
			break;
	}
	return left;
	*/
	return nullptr;
}

ASTNode *Parser::parseMultiplication()
{
	/*
	ASTNode *left, *right;

	left = parsePrimary();

	TokenValue token = lexer->getCurrentToken();
	if (token.token == T_EOF)
		return left;

	while (token.token == T_STAR || token.token == T_SLASH)
	{
		lexer->getNextToken();
		right = parsePrimary();
		left = generateAST(getTokenASTType(token.token), left, right, 0);
		token = lexer->getCurrentToken();
		if (token.token == T_EOF)
			break;
	}
	return left;
	*/
	return nullptr;
}

int Parser::precedence(Token token)
{
	switch (token)
	{
		case T_PLUS:
			return 1;
		case T_MINUS:
			return 1;
		case T_STAR:
			return 2;
		case T_SLASH:
			return 2;
		default:
			exit(errorHandler.invalidToken(token));
	}
}

void Parser::eatToken(Token token)
{
	if (lexer->getCurrentToken().token == token)
		lexer->getNextToken();
	else
		exit(errorHandler.unexpectedToken(lexer->getCurrentToken().token, token));
}

Lexer *Parser::getLexer()
{
	return lexer;
}