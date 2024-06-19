#include "../include/Lexer.hpp"
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

TokenValue Lexer::getCurrentToken()
{
	return tokenValue;
}

Token get_keyword(std::string keyword)
{
	switch (keyword[0])
	{
		case 'p':
			if (keyword == "print")
				return T_PRINT;
		default:
			break;
	}
	return T_UNKNOWN;
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
		case ';':
			tokenValue.token = T_SEMI;
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
				break;
			}
			else if (isalpha(c) || c == '_')
			{
				std::string identifier = "";
				identifier += c;
				while (currentColumn < line.length() && (isalnum(line[currentColumn]) || line[currentColumn] == '_'))
				{
					identifier += line[currentColumn];
					currentColumn++;
				}
				tokenValue.token = get_keyword(identifier);
				if (tokenValue.token == T_UNKNOWN)
					exit(errorHandler.unrecognizedKeyword(currentLine + 1, currentColumn, identifier));
				break;
			}
			else
				exit(errorHandler.unrecognizedCharacter(currentLine + 1, currentColumn, c));
			break;
	}
	return tokenValue;
}