#include <iostream>
#include "array.hpp"

int main()
{
	Array<int> arrA(3);

	for (size_t i = 0; i < arrA.size(); i++)
		std::cout << arrA[i] << ' ';
	std::cout << std::endl << std::endl;

	arrA[0] = 42;
	arrA[1] = 101;
	arrA[2] = 21;

	for (size_t i = 0; i < arrA.size(); i++)
		std::cout << arrA[i] << ' ';
	std::cout << std::endl << std::endl;

	Array<int> arrB(arrA);

	for (size_t i = 0; i < arrA.size(); i++)
		std::cout << arrA[i] << ' ';
	std::cout << std::endl;
	for (size_t i = 0; i < arrB.size(); i++)
		std::cout << arrB[i] << ' ';
	std::cout << std::endl << std::endl;

	arrA[0] = 12;
	arrB[2] = 89;

	for (size_t i = 0; i < arrA.size(); i++)
		std::cout << arrA[i] << ' ';
	std::cout << std::endl;
	for (size_t i = 0; i < arrB.size(); i++)
		std::cout << arrB[i] << ' ';
	std::cout << std::endl << std::endl;

	try
	{
		arrB[3] = 0;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
