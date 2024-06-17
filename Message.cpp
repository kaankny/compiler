#include "Message.hpp"
#include "color.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void printTime()
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time (&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer,sizeof(buffer),"%I:%M:%S",timeinfo);
	printf("%s[ %s ]%s ", C_BOLD, buffer, C_RESET);
}

int Message::invalidArguments()
{
	printTime();
	printf("%s[ Error ]%s%s Invalid number of arguments%s\n", C_RED,C_RESET, C_BOLD, C_RESET);
	return 1;
}

int Message::invalidFile(std::string fileName)
{
	printTime();
	printf("%s[ Error ]%s%s Could not open file %s%s\n", C_RED,C_RESET, C_BOLD, fileName.c_str(), C_RESET);
	return 1;
}

int Message::unrecognizedCharacter(int line, int index, char c)
{
	printTime();
	printf("%s[ Error ]%s%s Unrecognized character %c at line %d, index %d%s\n", C_RED,C_RESET, C_BOLD, c, line, index, C_RESET);
	return 1;
}