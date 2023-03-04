#include <string>
#include <iostream>

#include "../incs/Cat.hpp"

Cat::Cat() : Animal(), _Brain(new Brain)
{
	type = "Cat";
	std::cout << "Cat created." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), _Brain(new Brain)
{
	*_Brain = *other._Brain;
	std::cout << "Cat copy created." << std::endl;
}

Cat::~Cat()
{
	delete _Brain;
	std::cout << "Cat destroyed." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "miaou" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	Animal::operator=(other);
	*_Brain = *other._Brain;
	return *this;
}

Brain *Cat::brain() const
{
	return _Brain;
}