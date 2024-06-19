#ifndef PARSER_HPP
#define PARSER_HPP

/*
     *
    / \
   2   +
      / \
     3   *
        / \
       4   5

*/

/*
 * ASTNodeType is an enumeration of all the types of nodes that the abstract syntax tree can contain.
*/
typedef enum
{
	A_ADD,
	A_SUB,
	A_MUL,
	A_DIV,
	A_INTLIT
}	ASTNodeType;

/*
 * ASTNode is a struct that represents a node in the abstract syntax tree.
 * It contains the type of the node, as well as pointers to the left and right children.
 * If the node is an integer literal, it also contains the integer value.
*/
typedef struct s_ASTNode
{
	ASTNodeType type;
	struct s_ASTNode *left;
	struct s_ASTNode *right;

	int intValue;
}	ASTNode;

#include "Lexer.hpp"
#include "ErrorHandler.hpp"

class Parser
{
	private:
		Lexer *lexer;
		ErrorHandler errorHandler;
	
		ASTNode *generateAST(ASTNodeType type, ASTNode *left, ASTNode *right, int value);
		ASTNode *generateLeaf(ASTNodeType type, int value);
		ASTNode *generateUnary(ASTNodeType type, ASTNode *left, int value);

		ASTNodeType getTokenASTType(Token token);

		ASTNode *parsePrimary();

		int precedence(Token token);

	public:
		ASTNode *parseTerm(int predenceLevel);
		ASTNode *parseAddition();
		ASTNode *parseMultiplication();
		void setLexer(Lexer *lexer);

		void eatToken(Token token);

		Lexer *getLexer();
};

#endif