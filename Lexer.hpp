#ifndef LEXER_H
#define LEXER_H

/*
 * Token is an enumeration of all the tokens that the lexer can return.
 * T_PLUS, T_MINUS, T_STAR, and T_SLASH are the four arithmetic operators.
 * T_INTLIT is a token that represents an integer literal.
*/
typedef enum
{
	T_PLUS,
	T_MINUS,
	T_STAR,
	T_SLASH,
	T_INTLIT,
	T_EOF
} Token;

/*
 * TokenValue is a struct that contains a Token and an integer value.
 * This struct is used to return a token and its associated value from the lexer.
*/
typedef struct
{
	Token token;
	int value;
} TokenValue;

/*
 * getNextToken is a function that reads the next token from the input file.
 * It returns 1 if a token was successfully read, and 0 if there are no more tokens.
 * The token is stored in the TokenValue struct pointed to by the token parameter.
 */

#include <iostream>
#include <vector>

class Lexer
{
	private:
		int currentLine;
		int currentColumn;

		TokenValue tokenValue;
		std::vector<std::string> code;
	public:
		Lexer();
		void initLexer(std::vector<std::string>);
		TokenValue getNextToken();
};

#endif