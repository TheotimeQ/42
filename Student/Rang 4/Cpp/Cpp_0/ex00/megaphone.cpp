#include <iostream>
#include <cstring>

int		main(int argc, char **argv)
{
	size_t i;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (--argc)
	{
		argv++;
		i = 0;
		while ((*argv)[i])
		{
			(*argv)[i] = std::toupper((*argv)[i]);
			i++;
		}
		std::cout << *argv;
	}
	std::cout << std::endl;
	return (0);
}