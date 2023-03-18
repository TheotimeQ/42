#include <iostream>

#include "../incs/easyfind.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(4);
	vec.push_back(2);
	vec.push_back(12);
	vec.push_back(69);
	vec.push_back(0);

	std::cout << easyfind(vec, 4) << std::endl;
	std::cout << easyfind(vec, 2) << std::endl;
	std::cout << easyfind(vec, 69) << std::endl;
	std::cout << easyfind(vec, 0) << std::endl;
	std::cout << easyfind(vec, 2365) << std::endl;
	std::cout << easyfind(vec, 42) << std::endl;

	return 0;
}
