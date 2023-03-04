#include <string>
#include <iostream>

#include "../incs/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
		_Ideas[i] = other._Ideas[i];
	std::cout << "Brain created copy" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destroyed" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	for (int i = 0; i < 100; i++)
		_Ideas[i] = other._Ideas[i];
	return *this;
}

std::string &Brain::idea(int index)
{
	if (index < 0)
		return _Ideas[0];
	if (index >= 100)
		return _Ideas[0];
	return _Ideas[index];
}
