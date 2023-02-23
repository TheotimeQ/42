#include <string>
#include <iostream>

#include "../incs/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) :
	type(other.type)
{
	std::cout << "WrongAnimal copy created." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destroyed." << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "..." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	type = other.type;
	return (*this);
}

const std::string &WrongAnimal::getType() const
{
	return type;
}
