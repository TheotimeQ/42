#include <string>
#include <iostream>

#include "../incs/Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Cat created." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy created." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destroyed." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "miaou" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	Animal::operator=(other);
	return *this;
}
