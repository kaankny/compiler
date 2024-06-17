#include "../include/Compiler.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);

	Compiler compiler;
	compiler.compile(av[1]);

	return (0);
}