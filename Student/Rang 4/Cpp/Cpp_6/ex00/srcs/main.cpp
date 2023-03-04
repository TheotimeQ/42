#include <iostream>
#include <cstdlib>
#include <climits>

#include "../incs/inc.hpp"

int print_char(const char c)
{
	std::cout << "char   : '" << c <<  "'" << std::endl;
	std::cout << "int    : " << (int)c << std::endl;
	std::cout << "float  : " << (int)c << ".f" << std::endl;
	std::cout << "double : " << (int)c << std::endl;
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error : invalid arguments" << std::endl;
		return 1;
	}
	std::string 	arg = argv[1];

	if (arg.size() == 1 && !std::isdigit(arg[0]))
		return (print_char(arg[0]));

	to_char(arg);
	to_int(arg);
	to_float(arg);
	to_double(arg);

	return 0;
}
