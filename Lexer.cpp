#include "Lexer.hpp"
#include "Message.hpp"
#include <fstream>

Lexer::Lexer()
{
	currentLine = 0;
	currentColumn = 0;
}

void Lexer::initLexer(std::vector<std::string> code)
{
	this->code = code;
}

TokenValue Lexer::getNextToken()
{
	if (code.empty())
	{
		tokenValue.token = T_EOF;
		return tokenValue;
	}
	std::string line = code[currentLine];
	while (currentColumn < line.length() && line[currentColumn] == ' ')
		currentColumn++;
	if (currentColumn >= line.length())
	{
		currentLine++;
		currentColumn = 0;
		if (currentLine >= code.size())
		{
			tokenValue.token = T_EOF;
			return tokenValue;
		}
		line = code[currentLine];
	}
	char c = line[currentColumn];
	currentColumn++;
	switch (c)
	{
		case '+':
			tokenValue.token = T_PLUS;
			break;
		case '-':
			tokenValue.token = T_MINUS;
			break;
		case '*':
			tokenValue.token = T_STAR;
			break;
		case '/':
			tokenValue.token = T_SLASH;
			break;
		default:
			if (c >= '0' && c <= '9')
			{
				int value = c - '0';
				while (currentColumn < line.length() && line[currentColumn] >= '0' && line[currentColumn] <= '9')
				{
					value = value * 10 + (line[currentColumn] - '0');
					currentColumn++;
				}
				tokenValue.token = T_INTLIT;
				tokenValue.value = value;
			}
			else
			{
				Message errorHandler;
				exit(errorHandler.unrecognizedCharacter(currentLine, currentColumn, c));
			}
			break;
	}
	return tokenValue;
}