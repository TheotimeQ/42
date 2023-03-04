#include <iostream>
#include "../incs/iter.hpp"

void printInt(int& val)
{
	std::cout << val << std::endl;
}

void printString(std::string& val)
{
	std::cout << val << std::endl;
}

int main()
{
	int intArray[5] = {
		5, 4, 3, 2, 1
	};
	iter(intArray, 5, printInt);

	std::cout << std::endl;

	std::string stringArray[4] = {
		"HEY",
		"OY",
		"WUT",
		"WHAT"
	};
	iter(stringArray, 4, printString);

	return 0;
}
